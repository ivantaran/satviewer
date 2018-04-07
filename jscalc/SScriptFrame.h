/*
 * SScriptFrame.h
 *
 *  Created on: 21.02.2010
 *      Author: Ivan Ryazanov
 */

#ifndef SSCRIPTFRAME_H_
#define SSCRIPTFRAME_H_

#include "ui_jscalc.h"
#include <QJSEngine>
#include "../satutils/Satellite.h"
#include "../locutils/Location.h"

class SScriptFrame : public QWidget, public Ui::JsWidget {
    Q_OBJECT;
public:
    SScriptFrame(QString fileName = "");
    virtual ~SScriptFrame();
    void exec(Satellite *sat, Location *loc, double time);
private:
    Satellite *m_sat;
    Location *m_loc;
    double m_time;
    QString script;
    QJSEngine engine;
    QJSValue document;
private slots:
    void reload();
};

#endif /* SSCRIPTFRAME_H_ */
