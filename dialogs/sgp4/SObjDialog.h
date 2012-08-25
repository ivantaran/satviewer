/*
 * SSatDialog.h
 *
 *  Created on: 09.12.2009
 *      Author: Yan Coduemat
 */

#ifndef SOBJDIALOG_H_
#define SOBJDIALOG_H_

#include <inttypes.h>
#include "ui_sat.h"
#include <QDialog>
#include <QPixmapCache>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include "../../satviewer/satutils/Satellite.h"
#include "../../satviewer/ogl/GLSatAbstractWidget.h"
#include "../../satviewer/SAbstractObjDialog.h"

class SObjDialog: public SAbstractObjDialog, public Ui::SatDialog {
    Q_OBJECT
public:
    Satellite defaultSat;
    SObjDialog(GLSatAbstractWidget *satWidget);
    virtual ~SObjDialog();

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

extern "C" SObjDialog * getSObjDialog(GLSatAbstractWidget *satWidget);
#endif /* SOBJDIALOG_H_ */
