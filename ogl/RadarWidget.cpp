/* 
 * File:   RadarWidget.cpp
 * Author: Ivan Ryazanov
 * 
 * Created on April 13, 2019, 6:58 PM
 */

#include "RadarWidget.h"

RadarWidget::RadarWidget(QWidget *parent) : GLSatAbstractWidget(parent) {
}

//RadarWidget::RadarWidget(const RadarWidget& orig) {
//}

RadarWidget::~RadarWidget() {
}

//void RadarWidget::initializeGL() {
//    GLSatAbstractWidget::initializeGL();
//}

void RadarWidget::compileMapList() {
    
    glNewList(list_map, GL_COMPILE);
    glEndList();

    glNewList(list_net, GL_COMPILE);
    glLineWidth(1.0);
    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4ubv((GLubyte *)&m_colorNet);

    int c = 128;
    int d = 3;
    glColor4ub(128, 128, 128, 0);

    for (int j = 0; j < d; j++) {
        GLfloat r = (GLfloat)(j + 1) / (GLfloat)d;
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < c; i++) {
            GLfloat theta = 2.0f * (GLfloat)M_PI * (GLfloat)i / (GLfloat)c;
            GLfloat x = r * cosf(theta);
            GLfloat y = r * sinf(theta);
            glVertex2f(x, y);
        }
        glEnd();
    }

//    glColor4ub(192, 64, 64, 192);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF0F0);
    glBegin(GL_LINES);
    glVertex2f(-1.0,  0.0);
    glVertex2f( 1.0,  0.0);
    glVertex2f( 0.0, -1.0);
    glVertex2f( 0.0,  1.0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    glDisable(GL_BLEND);
    glEndList();
}
