/*
 * Sgp4Dialog.h
 *
 *  Created on: 09.12.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SGP4DIALOG_H_
#define SGP4DIALOG_H_

#include "../models/sgp4/Sgp4Model.h"
#include "../ogl/GLSatAbstractWidget.h"
#include "ui_sgp4.h"
#include <inttypes.h>

class Sgp4Dialog : public QDialog {
    Q_OBJECT
public:
    Sgp4Model defaultSat;
    Sgp4Dialog(GLSatAbstractWidget *satWidget);
    virtual ~Sgp4Dialog();

    inline Satellite *sat() {
        return m_sat;
    }
    void makeSat(Satellite *sat, bool fromlist = true);
    void setSatWidget(GLSatAbstractWidget *satWidget);
    inline Ui::SatDialog *getWidget() {
        return &widget;
    }

protected:
    void showEvent(QShowEvent *event);

private:
    Ui::SatDialog widget;
    Sgp4Model *m_sat;
    GLSatAbstractWidget *satWidget;
    QDoubleValidator m_doubleValidator;
    void setBtnColor(QWidget *widget);
    uint32_t flipRgb(uint32_t rgb);

private slots:
    void setColorSatName();
    void setColorSatZrv();
    void setColorSatLines();
    void setColorSatTrack();
    void setSatFont();
    void setDefault();
    void setIcon();
};

#endif /* SGP4DIALOG_H_ */
