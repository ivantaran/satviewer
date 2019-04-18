/* 
 * File:   RadarWidget.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 6:58 PM
 */

#ifndef RADARWIDGET_H
#define RADARWIDGET_H

#include <QMouseEvent>

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
    void compileMapList();
    void compileSatList();
    static void polar2ortho(GLfloat azm, GLfloat elv, GLfloat &x, GLfloat &y);
    void compileSunList();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
private slots:
    void onCurrentChanged(Satellite *sat, Location *loc, double *time);
};

#endif /* RADARWIDGET_H */

