/* 
 * File:   RadarWidget.cpp
 * Author: Ivan Ryazanov
 * 
 * Created on April 13, 2019, 6:58 PM
 */

#include "RadarWidget.h"

RadarWidget::RadarWidget(SatViewer *satviewer, QWidget *parent) : GLSatAbstractWidget(satviewer, parent) {
    m_colorNet = 0x00808080;
}

//RadarWidget::RadarWidget(const RadarWidget& orig) {
//}

RadarWidget::~RadarWidget() {
}

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

void RadarWidget::compileSatList() {
    GLfloat px, py, tmpx, tmpy, tper = 0;
    GLfloat trackBegin, trackEnd;
    GLuint clr;
    
    Location *loc = m_satviewer->currentLocation();
    
    if (m_satviewer->satellites().empty() || (loc == nullptr)) {
        glNewList(list_sat, GL_COMPILE);
        glEndList();
        return;
    }

    glNewList(list_sat, GL_COMPILE);
    
    for (const auto& sat : m_satviewer->satellites()) {

        sat->model(m_time);

        if (sat->isVisibleTrack()) {
            glShadeModel(GL_SMOOTH);
            glEnable(GL_ALPHA_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glEnable(GL_LINE_SMOOTH);
            glLineWidth(sat->linesWidth());
            clr = 0xffffffff;//sat->colorTrack();
            glColor4ubv((GLubyte *)&clr);

            glBegin(GL_LINE_STRIP);
                tper = 120.0 * M_PI / sat->meanMotion(); //move this line
                trackBegin = sat->track() * (-0.5 * tper + tper / 180.0);
                trackEnd = sat->track() * (0.5 * tper + tper / 180.0);
                sat->model(trackBegin + m_time);
                tmpx = sat->longitude() / M_PI;
                tmpy = -2.0 * sat->latitude() / M_PI;
                for (GLfloat i = trackBegin; i < trackEnd; i += tper / 180.0) {
                    sat->model(i + m_time);
                    px = sat->longitude() / M_PI;
                    py = -2.0 * sat->latitude() / M_PI;
                    if (fabs(px - tmpx) > 1.75) {
                        if (px > tmpx) {
                            glVertex2f(-1.0, 0.5 * (py + tmpy));
                            glEnd(); glBegin(GL_LINE_STRIP);
                            glVertex2f( 1.0, 0.5 * (py + tmpy));
                        }
                        else {
                            glVertex2f( 1.0, 0.5 * (py + tmpy));
                            glEnd(); glBegin(GL_LINE_STRIP);
                            glVertex2f(-1.0, 0.5 * (py + tmpy));
                        }
                    }
                    glVertex2f(px, py);
                    tmpx = px;
                    tmpy = py;
                }
            glEnd();

            glDisable(GL_BLEND);
            glDisable(GL_LINE_SMOOTH);
        }

        sat->model(m_time);
        px = sat->longitude() / M_PI;
        py = -2.0 * sat->latitude() / M_PI;
        if (sat->satWObject) {
            sat->satWObject->exec(px, py, 0.0);
        }
    }

//    Satellite *sat = currentSat();
//    if (sat == nullptr) {
//        sat = satList.first();
//    }
//    sat->model(m_time);
//    px = sat->longitude() / M_PI;
//    py = -2.0 * sat->latitude() / M_PI;
//    sprite_current.exec(px, py, 0.0);
        
    glEndList();
}
