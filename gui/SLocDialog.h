/*
 * SLocDialog.h
 *
 *  Created on: 03.01.2010
 *      Author: Ivan Ryazanov
 */

#ifndef SLOCDIALOG_H_
#define SLOCDIALOG_H_

#include "ui_loc.h"
#include <QColorDialog>
#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QPixmapCache>
#include <QValidator>
#include <inttypes.h>

#include "../utils/Location.h"
#include "../utils/ogl/GLSatAbstractWidget.h"

class SLocDialog : public QDialog {
    Q_OBJECT
public:
    Location defaultLoc;
    SLocDialog(GLSatAbstractWidget *satWidget);
    virtual ~SLocDialog();

    inline Location *loc() {
        return m_loc;
    }
    void setLoc(Location *loc) {
        m_loc = loc;
    }
    void makeLoc(Location *loc);
    void setSatWidget(GLSatAbstractWidget *satWidget);
    inline Ui::LocDialog *getWidget() {
        return &widget;
    }

protected:
    void showEvent(QShowEvent *event);

private:
    Ui::LocDialog widget;
    Location *m_loc;
    GLSatAbstractWidget *satWidget;
    QDoubleValidator m_doubleValidator;
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
