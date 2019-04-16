/* 
 * File:   RadarWidget.cpp
 * Author: Ivan Ryazanov
 * 
 * Created on April 13, 2019, 6:58 PM
 */

#include <QPainter>

#include "RadarWidget.h"
#include "../models/sun/sunmodel.h"

RadarWidget::RadarWidget(SatViewer *satviewer, QWidget *parent) : GLSatAbstractWidget(satviewer, parent) {
    m_colorNet = 0x00808080;
}

//RadarWidget::RadarWidget(const RadarWidget& orig) {
//}

RadarWidget::~RadarWidget() {
}

void RadarWidget::initializeGL() {
    GLSatAbstractWidget::initializeGL();
    QDir dir = QDir::home();
    dir.cd("satviewer/icons");
    sprite_current.load(dir.filePath("current.png"), this);
    sprite_sun.load(dir.filePath("sun.png"), this);
    
    connect(
        m_satviewer, 
        SIGNAL(currentChanged(Satellite *, Location *, double *)), 
        this, 
        SLOT(onCurrentChanged(Satellite *, Location *, double *))
    );
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

//    glEnable(GL_LINE_STIPPLE);
//    glLineStipple(1, 0xF0F0);
    glBegin(GL_LINES);
    glVertex2f(-1.0,  0.0);
    glVertex2f( 1.0,  0.0);
    glVertex2f( 0.0, -1.0);
    glVertex2f( 0.0,  1.0);
    glEnd();
//    glDisable(GL_LINE_STIPPLE);
    
    glDisable(GL_BLEND);
    glEndList();
}

void RadarWidget::polar2ortho(GLfloat azm, GLfloat elv, GLfloat &x, GLfloat &y) {
    x = ((GLfloat)M_PI_2 - elv) * sinf(azm) / (GLfloat)M_PI_2;
    y = (elv - (GLfloat)M_PI_2) * cosf(azm) / (GLfloat)M_PI_2;
}

void RadarWidget::compileSatList() {
    GLfloat px, py;
    GLuint clr;
    double aerv[4];
    
    Location *loc = m_satviewer->currentLocation();
    
    if (m_satviewer->satellites().empty() || (loc == nullptr)) {
        glNewList(list_sat, GL_COMPILE);
        glEndList();
        return;
    }

    glNewList(list_sat, GL_COMPILE);
    
    for (const auto& sat : m_satviewer->satellites()) {

        sat->model(m_satviewer->time());

        if (sat->isVisibleTrack()) {
            glShadeModel(GL_SMOOTH);
            glEnable(GL_ALPHA_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glEnable(GL_LINE_SMOOTH);
            glLineWidth(sat->linesWidth());
            clr = sat->colorTrack();
            glColor4ubv((GLubyte *)&clr);

            glBegin(GL_LINE_STRIP);
            
            double tper = 120.0 * M_PI / sat->meanMotion(); //TODO move this line
            double trackBegin = sat->track() * (-0.5 * tper + tper / 180.0);
            double trackEnd = sat->track() * (0.5 * tper + tper / 180.0);
            bool inZone = false;
            for (double i = trackBegin; i < trackEnd; i += tper / 180.0) {
                sat->model(i + m_satviewer->time());
                SatViewer::aerv(loc->rg(), sat->rg(), aerv);
                if (aerv[1] < 0.0) {
                    if (inZone) {
                        inZone = false;
                        glEnd();
                        glBegin(GL_LINE_STRIP);
                    }
                }
                else {
                    inZone = true;
                    polar2ortho(aerv[0], aerv[1], px, py);
                    glVertex2f(px, py);
                }
            }
            
            glEnd();

            glDisable(GL_BLEND);
            glDisable(GL_LINE_SMOOTH);
        }

        sat->model(m_satviewer->time());
        SatViewer::aerv(loc->rg(), sat->rg(), aerv);
        if (aerv[1] >= 0.0) {
            polar2ortho(aerv[0], aerv[1], px, py);
            if (sat->satWObject) {
                sat->satWObject->exec(px, py, 0.0);
            }
        }
    }

    Satellite *sat = m_satviewer->currentSatellite();
    if (sat != nullptr) {
        sat->model(m_satviewer->time());
        SatViewer::aerv(loc->rg(), sat->rg(), aerv);
        if (aerv[1] >= 0.0) {
            polar2ortho(aerv[0], aerv[1], px, py);
            sprite_current.exec(px, py, 0.0);
        }
    }
        
    glEndList();
}

void RadarWidget::compileSunList() {
    
    Location *loc = m_satviewer->currentLocation();
    
    if (loc == nullptr) {
        glNewList(list_sun, GL_COMPILE);
        glEndList();
        return;
    }
    
    glNewList(list_sun, GL_COMPILE);

    if (shwSun) {
        double azm = 0.0;
        double elv = 0.0;
        sunmodel_ae((time_t)m_satviewer->time(), 
                qDegreesToRadians(loc->latitude()), 
                qDegreesToRadians(loc->longitude()), &azm, &elv, 'n');
        if (elv >= 0.0) {
            GLfloat px, py;
            polar2ortho(azm, elv, px, py);
            sprite_sun.exec(px, py, 0.0);
        }
    }
        
    glEndList();
}

void RadarWidget::paintEvent(QPaintEvent *event) {
    GLSatAbstractWidget::paintEvent(event);

    Location *loc = m_satviewer->currentLocation();
    if (loc == nullptr) {
        return;
    }
    
    QPainter painter(this);
//    painter.setPen(clrNetFont);
//    painter.setFont(fntNet);
//    painter.setCompositionMode(QPainter::CompositionMode_Screen); // TODO
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    
    int w = width();
    int h = height();
    double aerv[4];
    GLfloat px, py;
    
//    double dx = width() / 12.0;
//    double dy = height() / 6.0;
//
//    QFontMetrics fm(fntNet);
//    int bw = fm.width("00");
//    int bh = fm.height();
//    
//    for (int i = 1; i < 6; i++) {
//        painter.drawText(0     , dy * i, QString().number(abs(i * 30 - 90)));
//        painter.drawText(w - bw, dy * i, QString().number(abs(i * 30 - 90)));
//    }
//    
//    for (int i = 1; i < 12; i++) {
//        painter.drawText(dx * i, bh, QString().number(abs(i * 30 - 180)));
//        painter.drawText(dx * i,  h, QString().number(abs(i * 30 - 180)));
//    }
    
    for (const auto& sat : m_satviewer->satellites()) {
        if (sat->isVisibleLabel()) {
            painter.setPen(sat->colorLabel());
            painter.setFont(sat->font());

            SatViewer::aerv(loc->rg(), sat->rg(), aerv);
            if (aerv[1] >= 0.0) {
                polar2ortho(aerv[0], aerv[1], px, py);
                double dx = 0.5 * w * (1.0 + px) + sat->nameX();
                double dy = 0.5 * h * (1.0 + py) - sat->nameY();
                painter.drawText(dx, dy, sat->name());
            }
        }
    }
    
//    for (const auto& loc : m_satviewer->locations()) {
//        if (loc->isVisibleLabel()) {
//            painter.setPen(loc->colorLabel());
//            painter.setFont(loc->font());
//            
//            double dx = 0.5 * w * (1.0 + loc->longitude() / 180.0) + loc->nameX();
//            double dy = h * (0.5 - loc->latitude() / 180.0) - loc->nameY();
//
//            painter.drawText(dx,  dy, loc->name());
//        }
//    }
    
    painter.end();
}

void RadarWidget::onCurrentChanged(Satellite *sat, Location *loc, double *time) {
    Q_UNUSED(sat);
    Q_UNUSED(time);
    setWindowTitle(loc->name());
}
