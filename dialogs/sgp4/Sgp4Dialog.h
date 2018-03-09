/*
 * Sgp4Dialog.h
 *
 *  Created on: 09.12.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SGP4DIALOG_H_
#define SGP4DIALOG_H_

#include <inttypes.h>
#include "ui_sgp4.h"
#include <QDialog>
#include <QPixmapCache>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include "../../satviewer/satutils/Satellite.h"
#include "../../satviewer/ogl/GLSatAbstractWidget.h"
#include "../../satviewer/SAbstractObjDialog.h"

class Sgp4Dialog: public SAbstractObjDialog, public Ui::SatDialog {
    Q_OBJECT
public:
    Satellite defaultSat;
    Sgp4Dialog(GLSatAbstractWidget *satWidget);
    virtual ~Sgp4Dialog();

    inline Satellite *sat() { return m_sat; }
    void makeSat(Satellite *sat, bool fromlist = true);
    void setSatWidget(GLSatAbstractWidget *satWidget);

protected:
    void showEvent(QShowEvent *event);

private:
    Satellite *m_sat;
    GLSatAbstractWidget *satWidget;
    bool m_fromlist;
    void setBtnColor(QWidget *widget);
    uint32_t flipRgb(uint32_t rgb);

private slots:
    void setColorSatName();
    void setColorSatZrv();
    void setColorSatLines();
    void setColorSatTrack();
    void setSatFont();
    void setDefault();
    void selectModel(int index);
    void setIcon();
};

#endif /* SGP4DIALOG_H_ */
