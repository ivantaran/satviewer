// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * GLSatAbstractWidget.cpp
 *
 *  Created on: 24.03.2010
 *      Author: Ivan Ryazanov
 */

#include "GLSatAbstractWidget.h"

#include <QDir>
#include <QPainter>
#include <QMouseEvent>
#include <QDateTime>
#include <QCoreApplication>
#include <QtMath>
#include "satogl.h"
#include "../models/sgp4/Sgp4Model.h"

GLSatAbstractWidget::GLSatAbstractWidget(SatViewer *satviewer, QWidget *parent) : QOpenGLWidget(parent) {
    m_satviewer = satviewer;
//    initSatOgl();
    setMouseTracking(true);

    settingsWidget = new QWidget();

    m_colorNet = 0xFF8B8B8B;
    clrNetFont = 0x0;
    clrNight = 0x00666666;

    m_zoom = 1.0;
    m_dx = 0.0;
    m_dy = 0.0;
    m_dz = 0.0;
    
    m_cursorOnSatellite = false;
    m_cursorOnLocation = false;
    
    textureID = NULL;

    shwSun = true;
    shwNight = true;
    
    setSatModel();
    
    list_map_ready       = true;
    list_net_ready       = true;
    list_events_ready    = true;
    list_sun_ready       = true;
    list_loc_ready       = true;
    list_sat_ready       = true;
    list_labels_ready    = true;
//    setSunModel();
//    sun = getSunModel();
//    sun->modelInit(WGS84, 0, 0, 0, 0, 0, 0, 0, 0);
//    sun->modelInit(0, 0);
//    sun->setName("Sun");
}

GLSatAbstractWidget::~GLSatAbstractWidget() {
    makeCurrent();
    // TODO delete tex
    doneCurrent();
}

void GLSatAbstractWidget::initializeGL() {
    
    bool ok = initializeOpenGLFunctions();
    
    assert(ok);

//    setAutoBufferSwap(false); //TODO
    glClearColor(0.1, 0.1, 0.1, 0.0);
    //glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    glOrtho(-1, 1, 1, -1, -1, 1);
    //glFrustum(-1, 1, 1, -1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glTranslatef(0.0, 0.0, 0.0);
    glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
//    glBlendFunc(GL_DST_COLOR, GL_SRC_COLOR);
//    loadTexture();
    list_map = glGenLists(6);
    qWarning() << "list_map" << list_map << endl;
    assert(list_map > 0);

    list_net    = list_map + 1;
    list_sat    = list_map + 2;
    list_loc    = list_map + 3;
    list_sun    = list_map + 4;
    list_events = list_map + 5;
    
    emit initialized();
    
    readSettings();
    
    connect(m_satviewer, SIGNAL(timeChanged()), this, SLOT(refresh()));
}

void GLSatAbstractWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(m_dx, m_dy, m_dz);
    glScalef(m_zoom, m_zoom, 0.0);

    if (list_map_ready   ) glCallList(list_map); // map
    if (list_net_ready   ) glCallList(list_net); //net
    if (list_sun_ready   ) glCallList(list_sun); //sun
    if (list_events_ready) glCallList(list_events); //locList events
    if (list_loc_ready   ) glCallList(list_loc); //locList zrl names
    if (list_sat_ready   ) glCallList(list_sat); //satList
}

void GLSatAbstractWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    refreshAll();
}

void GLSatAbstractWidget::refreshAll() {
    if (!isValid()) {
        return;
    }
    compileMapList();
    compileSatList();
    compileLocList();
    compileEventsList();
    compileSunList();
    update();
}

void GLSatAbstractWidget::loadTexture(QString filePath) {
    if (filePath.isEmpty()) {
        QDir dir = QDir::home();
        dir.cd("satviewer");
        filePath = dir.filePath("map.png");
    }
    if (textureID) delete textureID;
    textureID = new QOpenGLTexture(QImage(filePath), QOpenGLTexture::GenerateMipMaps);
}

void GLSatAbstractWidget::refresh() {
    if (!isValid()) {
        qWarning("GLSatAbstractWidget::refresh invalid");
        return;
    }
//	compileMapList();
    compileSatList();
    compileEventsList();
//	compileLocList();
    compileSunList();
//	refreshAll();
//	paintGL();
    update();
}

void GLSatAbstractWidget::setFontNet(QFont font) {
    fntNet = font;
    refreshAll();
}

void GLSatAbstractWidget::setColorNet(uint32_t color) {
    m_colorNet = color;
    refreshAll();
}

void GLSatAbstractWidget::setColorNetFont(uint32_t color) {
    clrNetFont = color;
    refreshAll();
}

void GLSatAbstractWidget::setColorNight(uint32_t color) {
    clrNight = color;
    refreshAll();
}

void GLSatAbstractWidget::showSun(bool value) {
    shwSun = value;
    refreshAll();
}

void GLSatAbstractWidget::showNight(bool value) {
    shwNight = value;
    refreshAll();
}

void GLSatAbstractWidget::setSatModel(int index) {
    Q_UNUSED(index);
    getSatModel = (CustomSat)Sgp4Model::getSatModel; // TODO: drop this method
}

void GLSatAbstractWidget::compileMapList() {
    glNewList(list_map, GL_COMPILE);
    glEndList();
    glNewList(list_net, GL_COMPILE);
    glEndList();
}

void GLSatAbstractWidget::compileSatList() {
    glNewList(list_sat, GL_COMPILE);
    glEndList();
}

void GLSatAbstractWidget::compileLocList() {
    glNewList(list_loc, GL_COMPILE);
    glEndList();
}

void GLSatAbstractWidget::compileSunList() {
    glNewList(list_sun, GL_COMPILE);
    glEndList();
}

void GLSatAbstractWidget::compileEventsList() {
    glNewList(list_events, GL_COMPILE);
    glEndList();
}

float GLSatAbstractWidget::zoom(float value) {
    m_zoom += value;
    if (m_zoom < 1) m_zoom = 1;
    if (m_zoom > 30) m_zoom = 30;
    moveX();
    moveY();
    emit zoomed(m_zoom);
    return m_zoom;
}

float GLSatAbstractWidget::moveX(float value) {
    m_dx += value;
    if (m_zoom < m_dx + 1) m_dx = m_zoom - 1;
    if (m_zoom < -m_dx + 1) m_dx = 1 - m_zoom;
    emit movedX(m_dx);
    return m_dx;
}

float GLSatAbstractWidget::moveY(float value) {
    m_dy += value;
    if (m_zoom < m_dy + 1) m_dy = m_zoom - 1;
    if (m_zoom < -m_dy + 1) m_dy = 1 - m_zoom;
    emit movedY(m_dy);
    return m_dy;
}
