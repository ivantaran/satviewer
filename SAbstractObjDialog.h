/* 
 * File:   SAbstractObjDialog.h
 * Author: yanco
 *
 * Created on 8 Июль 2012 г., 19:32
 */

#ifndef SABSTRACTOBJDIALOG_H
#define	SABSTRACTOBJDIALOG_H

#include <QDialog>

#include "satutils/Satellite.h"
#include "ogl/GLSatAbstractWidget.h"

class SAbstractObjDialog : public QDialog {
public:
    SAbstractObjDialog(GLSatAbstractWidget *satWidget);
    virtual ~SAbstractObjDialog();

    Satellite defaultSat;
    
    virtual Satellite *sat() { return 0; }
    virtual void makeSat(Satellite *sat, bool fromlist = true) { Q_UNUSED(sat) Q_UNUSED(fromlist) }
    virtual void setSatWidget(GLSatAbstractWidget *satWidget) { Q_UNUSED(satWidget) }
    virtual void retranslateUi(QDialog *dialog) { Q_UNUSED(dialog) }
};

#endif	/* SABSTRACTOBJDIALOG_H */

