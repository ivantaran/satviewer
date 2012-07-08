/*
 * SLocDialog.h
 *
 *  Created on: 03.01.2010
 *      Author: Yan Coduemat
 */

#ifndef SLOCDIALOG_H_
#define SLOCDIALOG_H_

#include <inttypes.h>
#include "ui_loc.h"
#include <QDialog>
#include <QPixmapCache>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include "locutils/Location.h"
#include "ogl/GLSatAbstractWidget.h"

class SLocDialog:  public QDialog, public Ui::LocDialog {
    Q_OBJECT
public:
    Location defaultLoc;
    SLocDialog(GLSatAbstractWidget *satWidget);
    virtual ~SLocDialog();

    inline Location *loc() { return m_loc; }
    void setLoc(Location *loc) { m_loc = loc; }
    void makeLoc(Location *loc);
    void setSatWidget(GLSatAbstractWidget *satWidget);

protected:
    void showEvent(QShowEvent *event);

private:
    Location *m_loc;
    GLSatAbstractWidget *satWidget;
    void setBtnColor(QWidget *widget);
    uint32_t flipRgb(uint32_t rgb);

private slots:
    void setColorLocName();
    void setColorLocZrv();
    void setColorLocLines();
    void setLocFont();
    void setDefault();
    void setIcon();

};

#endif /* SLOCDIALOG_H_ */
