/*
 * GLSatWidget.h
 *
 *  Created on: 15.05.2009
 *      Author: Ivan Ryazanov
 */

#ifndef GLSATWIDGET_H_
#define GLSATWIDGET_H_

#include "GLSatAbstractWidget.h"
#include "ui_mapsettings.h"
#include <QSettings>
#include "glsprite/GLSprite.h"

class GLSatWidget : public GLSatAbstractWidget {
	Q_OBJECT
public:
    GLSatWidget(QWidget *parent = 0);
    virtual ~GLSatWidget();
    void readSettings();
    void writeSettings(QSettings *settings);
    inline void retranslateUi() { ui.retranslateUi(this); }
    void addSat(Satellite *sat);
    void addLoc(Location *loc);
    void setIcon(Satellite *sat, QString  fileName = QString());
    void setIcon(Location *loc, QString  fileName = QString());
    
private:
    static const int VertexCount = 128;
    GLfloat vertex[VertexCount][2];

    Ui::MapWidgetSettings ui;
    GLSprite sprite_current, sprite_active;

    void initializeGL();
    void compileMapList();
    void compileSatList();
    void compileLocList();
    void compileSunList();
    void compileEventsList();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    float zoom(float value = 0);
    float moveX(float value = 0);
    float moveY(float value = 0);
    void initSatOgl();
    void glZoneLines(float lat);
    void glZoneNight(float lat);
    void compileZRV(Satellite *sat, bool poly, bool lines, uint32_t colorPoly, uint32_t colorLines);
    void lfi_ort(double fi, double lam, double* xyz);
    bool testZRV(double* crd1, double* crd2, double fiz);
    int testIOZRV(Satellite *sat, Location *loc, ZrvIoList *list, double &time);
    void fillFootprint(float lat);
    void compileZrl(Location *loc);
    bool testShadow(Satellite *sat, Satellite *sun);
    
protected:
    void paintEvent(QPaintEvent *event) override;    
        
private slots:
    void btnColorClicked();
    void onBtnMapFileClicked();
    void btnFontNetClicked();
    void onColorTypeChanged(int index);
    void onCheckSun(bool value);
    void onCheckNight(bool value);
    void changeZoom(double value);
    void changeX(double value);
    void changeY(double value);
};

#endif /* GLSATWIDGET_H_ */
