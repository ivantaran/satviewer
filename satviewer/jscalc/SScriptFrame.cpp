/*
 * SScriptFrame.cpp
 *
 *  Created on: 21.02.2010
 *      Author: Yan Coduemat
 */

#include <stdio.h>
#include <stdlib.h>
#include "SScriptFrame.h"

SScriptFrame::SScriptFrame(QString fileName) {
	this->setupUi(this);
	m_sat = 0;
	m_loc = 0;
	m_time = 0;
	QDir::setCurrent(QCoreApplication::applicationDirPath());
	QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) textEdit->append(file.errorString() + ": " + file.fileName());
	QTextStream stream(&file);
    script = stream.readAll();
    file.close();
    document = engine.newQObject(textEdit);
    engine.globalObject().setProperty("document", document);

    connect(btnRefresh, SIGNAL(clicked()), this, SLOT(reload()));
}

SScriptFrame::~SScriptFrame() {

}

void SScriptFrame::reload() {
	if (m_sat == 0 || m_loc == 0) return;
	textEdit->clear();

    QScriptValue ascSat =  engine.newArray(6);
    QScriptValue ascLoc =  engine.newArray(6);
    for (int i = 0; i < 3; i++) {
    	ascSat.setProperty(i, m_sat->xyz_g()[i]);
    	ascSat.setProperty(i + 3, m_sat->vxyz_g()[i]);
    	ascLoc.setProperty(i, m_loc->xyz()[i]);
    	ascLoc.setProperty(i + 3, 0.0);
    }

    engine.globalObject().setProperty("ascSat", ascSat, QScriptValue::ReadOnly);
    engine.globalObject().setProperty("ascLoc", ascLoc, QScriptValue::ReadOnly);
    engine.globalObject().setProperty("nameSat", m_sat->name(), QScriptValue::ReadOnly);
    engine.globalObject().setProperty("nameLoc", m_loc->name(), QScriptValue::ReadOnly);
    engine.globalObject().setProperty("timeCurrent", QDateTime::fromTime_t(int(m_time)).toUTC().toString("dd.MM.yyyy H:mm:ss.zzz"), QScriptValue::ReadOnly);
    QScriptValue sVal =  engine.evaluate(script);
    if (sVal.isError()) textEdit->append(sVal.toString());
}

void SScriptFrame::exec(Satellite *sat, Location *loc, double time) {
	m_sat = sat;
	m_loc = loc;
	m_time = time;
	reload();
}
