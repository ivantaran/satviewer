/*
 * SSatDialog.h
 *
 *  Created on: 09.12.2009
 *      Author: Yan Coduemat
 */

#ifndef SSATDIALOG_H_
#define SSATDIALOG_H_

#include <inttypes.h>
#include "ui_sat.h"
#include <QDialog>
#include <QPixmapCache>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include "satutils/Satellite.h"
#include "ogl/GLSatAbstractWidget.h"

class SSatDialog: public QDialog, public Ui::SatDialog {
    Q_OBJECT
public:
    Satellite defaultSat;
    SSatDialog(GLSatAbstractWidget *satWidget);
    virtual ~SSatDialog();

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

#endif /* SSATDIALOG_H_ */
