/* 
 * File:   RadarWidget.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 6:58 PM
 */

#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include "GLSatAbstractWidget.h"

class RadarWidget : public GLSatAbstractWidget {
    Q_OBJECT
public:
    RadarWidget(SatViewer *satviewer, QWidget *parent = nullptr);
//    RadarWidget(const RadarWidget& orig);
    virtual ~RadarWidget();
private:
//    void initializeGL();
//    void paintGL();
//    void resizeGL(int width, int height) {}
    void compileMapList();
    void compileSatList();
//    void compileLocList() {}
//    void compileSunList() {GLSatAbstractWidget::compileSunList();}
//    void compileEventsList() {}
//    float zoom(float value = 0.0) {}
//    float moveX(float value = 0.0) {}
//    float moveY(float value = 0.0) {}

};

#endif /* RADARWIDGET_H */

