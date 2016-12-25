/*
 * GLSatAbstractWidget.cpp
 *
 *  Created on: 24.03.2010
 *      Author: Yan Coduemat
 */

#include "GLSatAbstractWidget.h"

#include <QDir>
#include <QPainter>
#include <QMouseEvent>
#include <QDateTime>
#include <QCoreApplication>
#include "math.h"
#include "satogl.h"
#include "../../models/sgp4/Sgp4Model.h"

GLSatAbstractWidget::GLSatAbstractWidget(QWidget *parent) : QOpenGLWidget(parent) {
//    initSatOgl();
    satList.clear();
    locList.clear();
    setMouseTracking(true);
    enumSatModelList();

    settingsWidget = new QWidget();

    m_indexLoc = -1;
    m_indexSat = -1;

    clrNet = 0xFF8B8B8B;
    clrNetFont = 0x0;
    clrNight = 0x00666666;

    m_zoom = 1.0;
    m_dx = 0.0;
    m_dy = 0.0;
    m_dz = 0.0;
    
    textureID = NULL;
    m_time = 0;
    shwSun = true;
    shwNight = true;
    setSatModel();
//    setSunModel();
//    sun = getSunModel();
//    sun->modelInit(WGS84, 0, 0, 0, 0, 0, 0, 0, 0);
//    sun->modelInit(0, 0);
//    sun->setName("Sun");
//    makeCurrent();
}

GLSatAbstractWidget::~GLSatAbstractWidget() {
    makeCurrent();
    satList.clear();
    locList.clear();
    ioList.clear();
    // TODO delete tex
    doneCurrent();
}

void GLSatAbstractWidget::initializeGL() {
//    makeCurrent();
    initializeOpenGLFunctions();
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
    //loadTexture();
    list_map    = glGenLists(7);
    printf("list_map %d\n", (int)list_map);
    list_net    = list_map + 1;
    list_labels = list_map + 2;
    list_sat    = list_map + 3;
    list_loc    = list_map + 4;
    list_sun    = list_map + 5;
    list_events = list_map + 6;
    readSettings();
}

void GLSatAbstractWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(m_dx, m_dy, m_dz);
    glScalef(m_zoom, m_zoom, 0.0);

    glCallList(list_map); // map
//    glCallList(list_net); //net
//    glCallList(list_sun); //sun
//    glCallList(list_events); //locList events
//    glCallList(list_loc); //locList zrl names
//    glCallList(list_sat); //satList
//    glCallList(list_labels); // net labels
//    swapBuffers(); //TODO
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
    paintGL();
}

void GLSatAbstractWidget::loadTexture(QString filePath) {
    if (filePath.isEmpty()) {
        QDir dir = QDir::home();
        dir.cd("satviewer");
        filePath = dir.filePath("map.png");
    }
    //	puts(filePath.toLocal8Bit().data());
//    makeCurrent();
    if (textureID) delete textureID;
    textureID = new QOpenGLTexture(QImage(filePath), QOpenGLTexture::GenerateMipMaps);
}

void GLSatAbstractWidget::setTime(double secs) {
    m_time = secs;
    refresh();
}

void GLSatAbstractWidget::refresh() {
    if (!isValid()) {
        return;
    }
//	compileMapList();
	compileSatList();
	compileEventsList();
//	compileLocList();
	compileSunList();
//	refreshAll();
	paintGL();
}

void GLSatAbstractWidget::setFontNet(QFont font) {
    fntNet = font;
    refreshAll();
}

void GLSatAbstractWidget::setColorNet(uint32_t color) {
    clrNet = color;
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

void GLSatAbstractWidget::enumSatModelList() {
    QDir dir = QCoreApplication::applicationDirPath();
    dir.cd("plugins");
    QStringList list = dir.entryList(QDir::Files | QDir::NoSymLinks);
    m_satModelList.clear();
    m_satModelList.append("default");
    for (int i = 0; i < list.count(); i++)
        if (QLibrary::resolve(dir.filePath(list.at(i)), "getSatModel") != NULL)
            m_satModelList.append(list.at(i));
    list.clear();
}

void GLSatAbstractWidget::setSatModel(int index) {
    getSatModel = (CustomSat)Sgp4Model::getSatModel;
    printf("%s [getSatModel %x]\n", lib.fileName().toLocal8Bit().data(), getSatModel);
    if (getSatModel == 0) exit(-1);
}

void GLSatAbstractWidget::setSunModel(QString fileName) {
    QString path = qApp->applicationDirPath() + "/plugins/";
    QRegExp re("*sun*");
    re.setPatternSyntax(QRegExp::Wildcard);
    int def = m_satModelList.indexOf(re);
    if (def == -1) {
        puts("Error: basic sun model not found");
        exit(-1);
    }
    if (fileName.isEmpty()) fileName = path + m_satModelList.at(def);
    else fileName = path + fileName;
    lib.setFileName(fileName);
    getSunModel = (CustomSat)lib.resolve(fileName, "getSatModel");
    printf("%s [getSunModel %x]\n", lib.fileName().toLocal8Bit().data(), getSunModel);
    if (getSunModel == 0) exit(-1);
}

void GLSatAbstractWidget::setIndexSat(int index) {
    m_indexSat = index;
    emit currentChanged(currentSat(), currentLoc(), &m_time);
}

void GLSatAbstractWidget::setIndexLoc(int index) {
    m_indexLoc = index;
    refreshAll();
    emit currentChanged(currentSat(), currentLoc(), &m_time);
}

void GLSatAbstractWidget::selectSatModel(int index, int pos) {
    setSatModel(index);
    if (pos == -1) return;
    Satellite *old_sat = satList.at(pos);
    Satellite *new_sat = getSatModel();
    
    if ((old_sat == 0) || (new_sat == 0)) return;
    new_sat->copy(old_sat);
    new_sat->setModelIndex(index);
    setIcon(new_sat);
    satList.replace(pos, new_sat);
    delete old_sat;
    setIndexSat(pos);
}

void GLSatAbstractWidget::addSat(Satellite* sat) {
    satList.append(sat);
}

void GLSatAbstractWidget::addLoc(Location* loc) {
    locList.append(loc);
}

void GLSatAbstractWidget::removeSat(Satellite *sat) {
    int pos = satList.indexOf(sat);
    if (pos == -1) return;
    ioList.deleteSat(satList.at(pos));
    satList.removeAt(pos);
    delete sat;
    setIndexSat(pos - 1);
}

void GLSatAbstractWidget::removeLoc(Location *loc) {
    int pos = locList.indexOf(loc);
    if (pos == -1) return;
    ioList.deleteLoc(locList.at(pos));
    locList.removeAt(pos);
    delete loc;
    setIndexLoc(pos - 1);
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
