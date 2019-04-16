/* 
 * File:   RadarWidget.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 6:58 PM
 */

#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include "GLSatAbstractWidget.h"
#include "glsprite/GLSprite.h"

class RadarWidget : public GLSatAbstractWidget {
    Q_OBJECT
public:
    RadarWidget(SatViewer *satviewer, QWidget *parent = nullptr);
//    RadarWidget(const RadarWidget& orig);
    virtual ~RadarWidget();

protected:
    void paintEvent(QPaintEvent *event);
        
private:
    GLSprite sprite_current, sprite_sun;
    void initializeGL();
//    void paintGL();
//    void resizeGL(int width, int height) {}
    void compileMapList();
    void compileSatList();
    static void polar2ortho(GLfloat azm, GLfloat elv, GLfloat &x, GLfloat &y);
//    void compileLocList() {}
    void compileSunList();
//    void compileEventsList() {}
//    float zoom(float value = 0.0) {}
//    float moveX(float value = 0.0) {}
//    float moveY(float value = 0.0) {}
private slots:
    void onCurrentChanged(Satellite *sat, Location *loc, double *time);
};

#endif /* RADARWIDGET_H */

