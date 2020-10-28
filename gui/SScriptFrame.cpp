// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * SScriptFrame.cpp
 *
 *  Created on: 21.02.2010
 *      Author: Ivan Ryazanov
 */

#include "SScriptFrame.h"
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QTextStream>

SScriptFrame::SScriptFrame(QString fileName) {
    widget.setupUi(this);

    m_sat = NULL;
    m_loc = NULL;
    m_time = 0.0;

    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        widget.textEdit->append(file.errorString() + ": " + file.fileName());
    }

    QTextStream stream(&file);
    script = stream.readAll();
    file.close();
    document = engine.newQObject(widget.textEdit);
    engine.globalObject().setProperty("document", document);

    connect(widget.btnRefresh, SIGNAL(clicked()), this, SLOT(reload()));
}

SScriptFrame::~SScriptFrame() {
}

void SScriptFrame::reload() {
    if (m_sat == NULL || m_loc == NULL) {
        return;
    }

    widget.textEdit->clear();

    QJSValue ascSat = engine.newArray(6);
    QJSValue ascLoc = engine.newArray(6);

    for (int i = 0; i < 6; i++) {
        ascSat.setProperty(i, m_sat->ecef()[i]);
        ascLoc.setProperty(i, m_loc->ecef()[i]);
    }

    engine.globalObject().setProperty("ascSat", ascSat);
    engine.globalObject().setProperty("ascLoc", ascLoc);
    engine.globalObject().setProperty("nameSat", m_sat->name());
    engine.globalObject().setProperty("nameLoc", m_loc->name());
    engine.globalObject().setProperty(
        "timeCurrent",
        QDateTime::fromTime_t(int(m_time)).toUTC().toString("dd.MM.yyyy H:mm:ss.zzz"));

    QJSValue sVal = engine.evaluate(script);

    if (sVal.isError()) {
        widget.textEdit->append(sVal.toString());
    }
}

void SScriptFrame::exec(Satellite *sat, Location *loc, double time) {
    m_sat = sat;
    m_loc = loc;
    m_time = time;
    reload();
}
