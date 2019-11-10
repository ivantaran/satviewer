// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * GLSatWidget.cpp
 *
 *  Created on: 15.05.2009
 *      Author: Ivan Ryazanov
 */

#include "GLSatWidget.h"

#include "../models/sun/sunmodel.h"
#include "satogl.h"
#include <QColorDialog>
#include <QDateTime>
#include <QDir>
#include <QFileDialog>
#include <QFont>
#include <QFontDialog>
#include <QMouseEvent>
#include <QPainter>
#include <math.h>

GLSatWidget::GLSatWidget(SatViewer *satviewer, QWidget *parent)
    : GLSatAbstractWidget(satviewer, parent) {
    ui.setupUi(settingsWidget);

    initSatOgl();

    connect(ui.btnColor, SIGNAL(clicked()), this, SLOT(btnColorClicked()));
    connect(ui.btnFontNet, SIGNAL(clicked()), this, SLOT(btnFontNetClicked()));
    connect(ui.btnMapFile, SIGNAL(clicked()), this, SLOT(onBtnMapFileClicked()));
    connect(ui.comboBoxColor, SIGNAL(currentIndexChanged(int)), this,
            SLOT(onColorTypeChanged(int)));
    connect(ui.checkSun, SIGNAL(clicked(bool)), this, SLOT(onCheckSun(bool)));
    connect(ui.checkNight, SIGNAL(clicked(bool)), this, SLOT(onCheckNight(bool)));
    connect(ui.spinZoom, SIGNAL(valueChanged(double)), this, SLOT(changeZoom(double)));
    connect(ui.spinX, SIGNAL(valueChanged(double)), this, SLOT(changeX(double)));
    connect(ui.spinY, SIGNAL(valueChanged(double)), this, SLOT(changeY(double)));
}

GLSatWidget::~GLSatWidget() {
}

void GLSatWidget::initSatOgl() {
    for (int i = 0; i < VertexCount; ++i) {
        vertex[i][0] = 0.0;
        vertex[i][1] = 0.0;
    }
}

void GLSatWidget::glZoneLines(float lat) {
    uint8_t type = 0;
    int breakpoint[2];
    float polar;

    glShadeModel(GL_SMOOTH);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);

    if (fabsf(vertex[0][0] - vertex[VertexCount - 1][0]) > 1) {
        breakpoint[type] = 0;
        type++;
    }

    for (int i = 0; i < VertexCount - 1; i++) {
        if (fabsf(vertex[i][0] - vertex[i + 1][0]) > 1) {
            breakpoint[type] = i + 1;
            type++;
        }
    }

    polar = lat < 0.0 ? 1.0 : -1.0;

    switch (type) {

    case 0:
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < VertexCount; i++)
            glVertex2fv(vertex[i]);
        glVertex2fv(vertex[0]);
        glEnd();
        break;

    case 1:
        glBegin(GL_LINE_STRIP);
        glVertex2f(polar, vertex[breakpoint[0]][1]);
        for (int i = breakpoint[0]; i < VertexCount; i++) {
            glVertex2fv(vertex[i]);
        }
        for (int i = 0; i < breakpoint[0]; i++) {
            glVertex2fv(vertex[i]);
        }
        glVertex2f(-polar, vertex[breakpoint[0]][1]);
        glEnd();
        break;

    case 2:
        polar = vertex[breakpoint[0]][0] < 0.0 ? -1.0 : 1.0;
        glBegin(GL_LINE_STRIP);
        glVertex2f(polar, vertex[breakpoint[0]][1]);
        for (int i = breakpoint[0] + 1; i < breakpoint[1] - 1; i++) {
            glVertex2fv(vertex[i]);
        }
        glVertex2f(polar, vertex[breakpoint[1] - 1][1]);
        glEnd();

        polar = vertex[breakpoint[1]][0] < 0.0 ? -1.0 : 1.0;
        glBegin(GL_LINE_LOOP);
        glVertex2f(polar, vertex[breakpoint[1]][1]);
        for (int i = breakpoint[1] + 1; i < VertexCount; i++) {
            glVertex2fv(vertex[i]);
        }
        if (breakpoint[0] > 0) {
            for (int i = 0; i < breakpoint[0] - 1; i++) {
                glVertex2fv(vertex[i]);
            }
            glVertex2f(polar, vertex[breakpoint[0] - 1][1]);
        } else {
            glVertex2f(polar, vertex[VertexCount - 1][1]);
        }
        glEnd();
        break;
    }
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
}

void GLSatWidget::glZoneNight(float lat) {
    int breakpoint = 0;
    GLfloat polar;

    if (fabs(vertex[0][0] - vertex[VertexCount - 1][0]) > 1) {
        breakpoint = 0;
    }
    for (int i = 0; i < VertexCount - 1; i++)
        if (fabs(vertex[i][0] - vertex[i + 1][0]) > 1) {
            breakpoint = i + 1;
        }

    if (lat > 0)
        polar = 1.0f;
    else
        polar = -1.0f;

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(-polar, vertex[breakpoint][1]);
    glVertex2f(-polar, polar);
    for (int i = breakpoint; i < VertexCount; i++) {
        glVertex2fv(vertex[i]);
        glVertex2f(vertex[i][0], polar);
    }
    for (int i = 0; i < breakpoint; i++) {
        glVertex2fv(vertex[i]);
        glVertex2f(vertex[i][0], polar);
    }
    glVertex2f(polar, vertex[breakpoint][1]);
    glVertex2f(polar, polar);
    glEnd();
}

void GLSatWidget::lfi_ort(double fi, double lam, double *xyz) {
    xyz[0] = cos(fi) * cos(lam);
    xyz[1] = cos(fi) * sin(lam);
    xyz[2] = sin(fi);
}

bool GLSatWidget::testZRV(double *crd1, double *crd2, double fiz) {
    double fi = 2 * asin(0.5 * sqrt(pow(crd2[0] - crd1[0], 2) + pow(crd2[1] - crd1[1], 2) +
                                    pow(crd2[2] - crd1[2], 2)));
    if (fabs(fi) > fiz)
        return false;
    else
        return true;
}

int GLSatWidget::testIOZRV(Satellite *sat, Location *loc, ZrvIoList *list, double &time) {
    int result = -1;
    if (time == 0)
        return result; // TODO: o_O
    bool inZRV;
    double fiz = 0;
    double z = sat->zrvWidth();
    //---------------------
    if (fabs(cos(z) * sat->radiusEarth()) > (sat->altitude() + sat->radiusEarth()))
        fiz = -z;
    else
        fiz = (M_PI / 2 - z -
               asin(cos(z) * sat->radiusEarth() / (sat->altitude() + sat->radiusEarth())));
    //---------------------
    double ortl[3], orts[3];
    lfi_ort(loc->latitude() * M_PI / 180, loc->longitude() * M_PI / 180, ortl);
    lfi_ort(sat->latitude(), sat->longitude(), orts);
    inZRV = testZRV(orts, ortl, fiz);
    if (inZRV)
        result = 0;

    int ioIndex = list->find(sat, loc);
    if (inZRV && (ioIndex == -1)) {
        result = 1;
        list->add(sat, loc, time);
    } else if (!inZRV && (ioIndex != -1)) {
        result = 2;
        time = list->item(ioIndex)->time;
        list->del(ioIndex);
    }
    /**/
    return result;
}

void GLSatWidget::compileZrl(Location *loc) {
    if (!(loc->isVisibleZrv() || loc->isVisibleLines()))
        return;

    double const deg2rad = M_PI / 180;
    double z = loc->zrlRange() * deg2rad;
    double a1 = M_PI - loc->zrlAzimuth() * deg2rad;
    double a2 = loc->zrlWidth() * deg2rad;
    double b = -loc->latitude() * deg2rad;
    double l = loc->longitude() * deg2rad + M_PI;

    int cntRadius = VertexCount / 4;
    int cntFront = VertexCount - 2 * cntRadius;
    if (a2 >= 2 * M_PI) {
        cntFront = VertexCount;
        cntRadius = 0;
    }

    double fiz = 0;
    for (int i = 0; i < cntRadius; i++) {
        double y0 = asin(cos(fiz) * sin(b) + sin(fiz) * cos(b) * cos(a1 - a2 / 2));
        double x0 = l + asin(sin(fiz) * sin(a1 - a2 / 2) / cos(y0));
        if ((cos(fiz) - sin(b) * sin(y0)) < 0)
            x0 = 2 * l - x0 + M_PI;
        x0 = fmod(x0 / M_PI + 4, 2) - 1;
        y0 = 2 * y0 / M_PI;
        vertex[i][0] = x0;
        vertex[i][1] = y0;
        fiz += z / cntRadius;
    }

    double a = a1 - a2 / 2;
    for (int i = 0; i < cntFront; i++) {
        double y0 = asin(cos(z) * sin(b) + sin(z) * cos(b) * cos(a));
        double x0 = l + asin(sin(z) * sin(a) / cos(y0));
        if ((cos(z) - sin(b) * sin(y0)) < 0)
            x0 = 2 * l - x0 + M_PI;
        x0 = fmod(x0 / M_PI + 4, 2) - 1;
        y0 = 2 * y0 / M_PI;
        vertex[i + cntRadius][0] = x0;
        vertex[i + cntRadius][1] = y0;
        a += a2 / cntFront;
    }

    fiz = z;
    for (int i = 0; i < cntRadius; i++) {
        double y0 = asin(cos(fiz) * sin(b) + sin(fiz) * cos(b) * cos(a1 + a2 / 2));
        double x0 = l + asin(sin(fiz) * sin(a1 + a2 / 2) / cos(y0));
        if ((cos(fiz) - sin(b) * sin(y0)) < 0)
            x0 = 2 * l - x0 + M_PI;
        x0 = fmod(x0 / M_PI + 4, 2) - 1;
        y0 = 2 * y0 / M_PI;
        vertex[i + cntFront + cntRadius][0] = x0;
        vertex[i + cntFront + cntRadius][1] = y0;
        fiz -= z / cntRadius;
    }

    GLuint clr = loc->colorZrv();
    glColor4ubv((GLubyte *)&clr);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    if (loc->isVisibleZrv())
        fillFootprint(loc->latitude());
    glDisable(GL_BLEND);
    if (loc->isVisibleLines()) {
        clr = loc->colorLines();
        glColor4ubv((GLubyte *)&clr);
        glLineWidth(loc->linesWidth());
        glZoneLines(loc->latitude());
    }
}

bool GLSatWidget::testShadow(Satellite *sat, Satellite *sun) {

    if ((sat == nullptr) || (sun == nullptr)) {
        return true;
    }

    double r_sat =
        sqrt(sat->r()[0] * sat->r()[0] + sat->r()[1] * sat->r()[1] + sat->r()[2] * sat->r()[2]);
    double r_sun =
        sqrt(sun->r()[0] * sun->r()[0] + sun->r()[1] * sun->r()[1] + sun->r()[2] * sun->r()[2]);

    if ((r_sat == 0.0) || (r_sun == 0.0) ||
        (sat->radiusEarth() > r_sat)) { // TODO: compare with epsilon
        return true;
    }

    double f = asin(sat->radiusEarth() / r_sat);
    double l =
        M_PI -
        acos((sat->r()[0] * sun->r()[0] + sat->r()[1] * sun->r()[1] + sat->r()[2] * sun->r()[2]) /
             (r_sat * r_sun));

    if ((-f < l) && (l < f)) {
        return false;
    }

    return true;
}

void GLSatWidget::fillFootprint(float lat) {
    int count = 0;
    int breakpoint[2], bp1;
    GLfloat polar, y;

    if (fabsf(vertex[0][0] - vertex[VertexCount - 1][0]) > 1.0) {
        breakpoint[count] = 0;
        count++;
    }

    for (int i = 0; i < VertexCount - 1; i++) {
        if (fabsf(vertex[i][0] - vertex[i + 1][0]) > 1.0) {
            breakpoint[count] = i + 1;
            count++;
        }
    }

    switch (count) {

    case 0:
        glBegin(GL_POLYGON);
        for (int i = 0; i < VertexCount; i++) {
            glVertex2fv(vertex[i]);
        }
        glEnd();
        break;

    case 1:
        polar = (lat < 0.0) ? 1.0 : -1.0;
        bp1 = (breakpoint[0] + VertexCount - 1) % VertexCount;
        y = 0.5 * (vertex[breakpoint[0]][1] + vertex[bp1][1]);
        glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(polar, y);
        glVertex2f(polar, polar);
        for (int i = breakpoint[0]; i < VertexCount; i++) {
            glVertex2fv(vertex[i]);
            glVertex2f(vertex[i][0], polar);
        }
        for (int i = 0; i < breakpoint[0]; i++) {
            glVertex2fv(vertex[i]);
            glVertex2f(vertex[i][0], polar);
        }
        glVertex2f(-polar, y);
        glVertex2f(-polar, polar);
        glEnd();
        break;

    case 2:
        polar = (vertex[breakpoint[0]][0] < 0.0) ? -1.0 : 1.0;
        glBegin(GL_POLYGON);
        glVertex2f(polar, vertex[breakpoint[0]][1]);
        for (int i = breakpoint[0]; i < breakpoint[1]; i++) {
            glVertex2fv(vertex[i]);
        }
        glVertex2f(polar, vertex[breakpoint[1]][1]); // TODO check index breakpoint[1] - 1
        glEnd();

        polar = (vertex[breakpoint[1]][0] < 0.0) ? -1.0 : 1.0;
        glBegin(GL_POLYGON);
        glVertex2f(polar, vertex[breakpoint[1]][1]);
        for (int i = breakpoint[1]; i < VertexCount; i++) {
            glVertex2fv(vertex[i]);
        }
        for (int i = 0; i < breakpoint[0]; i++) {
            glVertex2fv(vertex[i]);
        }
        glVertex2f(polar, vertex[breakpoint[0]][1]); // TODO check index breakpoint[0] - 1
        glEnd();
        break;
    }
}

void GLSatWidget::compileFootprint(double longitude, double latitude, double altitude,
                                   double zoneWidth, bool fill, bool lines, GLfloat linesWidth,
                                   GLuint colorPoly, GLuint colorLines) {
    double x, y;
    double fiz;
    double polar, angle = 0;
    double cosz = cos(zoneWidth);
    double radius = altitude + Satellite::RadiusEarth;

    if (fabs(cosz * Satellite::RadiusEarth) > radius) {
        fiz = -zoneWidth;
    } else {
        fiz = 0.5 * M_PI - zoneWidth - asin(cosz * Satellite::RadiusEarth / radius);
    }

    polar = (fabs(latitude) + fiz < M_PI * 0.5) ? 1.0 : -1.0;

    for (int i = 0; i < VertexCount; i++) {
        y = asin(cos(fiz) * sin(latitude) + sin(fiz) * cos(latitude) * cos(angle));
        x = sin(fiz) * sin(angle) / cos(y);

        if (x > 1.0) {
            x = 1.0;
        } else if (x < -1.0) {
            x = -1.0;
        }

        x = longitude + polar * asin(x);

        if ((cos(fiz) - sin(latitude) * sin(y)) < 0.0) {
            x = 2.0 * longitude - x + M_PI;
        }

        x = fmod(x + M_PI, 2.0 * M_PI);

        if (x < 0.0) {
            x += 2.0 * M_PI;
        }

        vertex[i][0] = x / M_PI - 1.0;
        vertex[i][1] = -2.0 * y / M_PI;
        angle += 2.0 * M_PI / (double)VertexCount;
    }

    if (fill) {
        glColor4ubv((GLubyte *)&colorPoly);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        fillFootprint(latitude);
        glDisable(GL_BLEND);
    }

    if (lines) {
        glColor4ubv((GLubyte *)&colorLines);
        glLineWidth(linesWidth);
        glZoneLines(latitude);
    }
}

void GLSatWidget::readSettings() {

    QDir dir = QDir::home();
    QSettings::setUserIniPath(dir.path());
    QSettings settings(QSettings::IniFormat, QSettings::UserScope, "satviewer", "satviewer");
    settings.setIniCodec("UTF-8");

    if (!isValid()) {
        return;
    }

    QFont font;
    font.fromString(settings.value("cylindrical/fontNet", QFont().toString()).toString());
    ui.btnFontNet->setFont(font);
    setFontNet(font);

    setColorNet(settings.value("cylindrical/colorNet", 0x20606060).toUInt());
    setColorNetFont(settings.value("cylindrical/colorNetFont", 0x0).toUInt());
    setColorNight(settings.value("cylindrical/colorNight", 0x40000000).toUInt());
    ui.comboBoxColor->setCurrentIndex(1);
    ui.comboBoxColor->setCurrentIndex(0);
    QString filePath = settings.value("cylindrical/mapFile", "").toString();
    loadTexture(filePath);
    ui.btnMapFile->setText(filePath);

    ui.checkSun->setChecked(settings.value("cylindrical/checkSun", true).toBool());
    showSun(ui.checkSun->isChecked());
    ui.checkNight->setChecked(settings.value("cylindrical/checkNight", true).toBool());
    showNight(ui.checkNight->isChecked());

    ui.spinZoom->setValue(settings.value("cylindrical/mapZoom", 1).toDouble());
    ui.spinX->setValue(settings.value("cylindrical/mapX", 0).toDouble());
    ui.spinY->setValue(settings.value("cylindrical/mapY", 0).toDouble());
}

void GLSatWidget::writeSettings(QSettings *settings) {
    settings->setValue("cylindrical/mapFile", ui.btnMapFile->text());
    settings->setValue("cylindrical/fontNet", fontNet().toString());

    settings->setValue("cylindrical/colorNet", colorNet());
    settings->setValue("cylindrical/colorNetFont", colorNetFont());
    settings->setValue("cylindrical/colorNight", colorNight());

    settings->setValue("cylindrical/checkSun", ui.checkSun->isChecked());
    settings->setValue("cylindrical/checkNight", ui.checkNight->isChecked());

    settings->setValue("cylindrical/mapZoom", ui.spinZoom->value());
    settings->setValue("cylindrical/mapX", ui.spinX->value());
    settings->setValue("cylindrical/mapY", ui.spinY->value());
}

void GLSatWidget::setIcon(Satellite *sat, const QString &fileName) {
    if (sat->satWObject != nullptr) {
        delete sat->satWObject;
    }
    if (!fileName.isEmpty()) {
        sat->setIcon(fileName);
    }
    sat->satWObject = new GLSprite(sat->iconName(), this);
}

void GLSatWidget::setIcon(Location *loc, const QString &fileName) {
    if (loc->satWObject != nullptr) {
        delete loc->satWObject;
    }
    if (!fileName.isEmpty()) {
        loc->setIcon(fileName);
    }
    loc->satWObject = new GLSprite(loc->iconName(), this);
}

void GLSatWidget::btnColorClicked() {
    QPalette pal = ui.btnColor->palette();
    QColor color =
        QColorDialog::getColor(pal.color(QPalette::Button), this, "", // TODO: set caption
                               QColorDialog::ShowAlphaChannel);
    if (!color.isValid()) {
        return;
    }

    pal.setColor(QPalette::Button, color);
    ui.btnColor->setPalette(pal);
    QRgb rgb = color.rgba();

    // OpenGL 0xAABBGGRR //Qt 0xAARRGGBB
    uint8_t a, r, g, b;
    b = rgb;
    g = rgb >> 8;
    r = rgb >> 16;
    a = rgb >> 24;
    rgb = (a << 24) | (b << 16) | (g << 8) | (r);

    switch (ui.comboBoxColor->currentIndex()) {
    case 0:
        setColorNet(rgb);
        break;
    case 1:
        setColorNetFont(rgb);
        break;
    case 2:
        setColorNight(rgb);
        break;
    }
}

void GLSatWidget::btnFontNetClicked() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui.btnFontNet->font(), this);
    if (ok) {
        ui.btnFontNet->setFont(font);
        setFontNet(font);
    }
    puts(ui.btnFontNet->font().toString().toLocal8Bit().data());
}

void GLSatWidget::onColorTypeChanged(int index) {
    QPalette pal = ui.btnColor->palette();
    QRgb rgb = pal.color(QPalette::Button).rgba();

    switch (index) {
    case 0:
        rgb = colorNet();
        break;
    case 1:
        rgb = colorNetFont();
        break;
    case 2:
        rgb = colorNight();
        break;
    }

    // OpenGL 0xAABBGGRR //Qt 0xAARRGGBB
    uint8_t a, r, g, b;
    r = rgb;
    g = rgb >> 8;
    b = rgb >> 16;
    a = rgb >> 24;
    rgb = (a << 24) | (r << 16) | (g << 8) | (b);

    pal.setColor(QPalette::Button, QColor::fromRgb(rgb));
    ui.btnColor->setPalette(pal);
}

void GLSatWidget::onBtnMapFileClicked() {
    QDir dir = QDir::home();
    dir.cd("satviewer");
    QString filePath = QFileDialog::getOpenFileName(this, "Open Map File", dir.path(),
                                                    "Images (*.jpg *.png *.svg)", nullptr,
                                                    QFileDialog::DontUseNativeDialog);
    if (filePath == "")
        return;
    loadTexture(filePath);
    ui.btnMapFile->setText(filePath);
}

void GLSatWidget::onCheckSun(bool value) {
    showSun(value);
}

void GLSatWidget::onCheckNight(bool value) {
    showNight(value);
}

void GLSatWidget::initializeGL() {
    GLSatAbstractWidget::initializeGL();
    QDir dir = QDir::home();
    dir.cd("satviewer/icons");
    sprite_current.load(dir.filePath("current.png"), this);
    sprite_active.load(dir.filePath("active.png"), this);
    sprite_sun.load(dir.filePath("sun.png"), this);
}

void GLSatWidget::compileMapList() {

    glNewList(list_map, GL_COMPILE);
    if (textureID) {
        textureID->bind();
    }

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-1.0, -1.0);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(1.0, -1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEndList();

    glNewList(list_net, GL_COMPILE);
    glLineWidth(1.0);
    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4ubv((GLubyte *)&m_colorNet);

    glBegin(GL_LINES);
    for (GLfloat i = -1.0; i < 1.0; i += 1.0 / 12.0) {
        glVertex2f(i, -1.0);
        glVertex2f(i, 1.0);
    }
    for (GLfloat i = -1 + 1.0 / 6.0; i < 1; i = i + 1.0 / 6.0) {
        glVertex2f(-1.0, i);
        glVertex2f(1.0, i);
    }
    glEnd();

    glColor4ub(192, 64, 64, 192); // TODO: parametrize color

    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    // The equator, 23 1/2 degrees north of the Tropic of Capricorn,
    // and 23 1/2 degrees south of the Tropic of Cancer.
    glColor4ubv((GLubyte *)&m_colorNet);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF0F0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, -23.43684 / 90.0);
    glVertex2f(1.0, -23.43684 / 90.0);
    glVertex2f(-1.0, 23.43684 / 90.0);
    glVertex2f(1.0, 23.43684 / 90.0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    glDisable(GL_BLEND);
    glEndList();
}

void GLSatWidget::compileSatList() {
    float px, py, tmpx, tmpy;
    GLuint clr;

    if (m_satviewer->satellites().empty()) {
        glNewList(list_sat, GL_COMPILE);
        glEndList();
        return;
    }

    glNewList(list_sat, GL_COMPILE);

    for (const auto &sat : m_satviewer->satellites()) {
        bool shadow_state = testShadow(sat, nullptr); // TODO: check sun shadow
        sat->model(m_satviewer->time());

        if (sat->isVisibleZrv() || sat->isVisibleLines()) {
            compileFootprint(sat->longitude(), sat->latitude(), sat->altitude(), sat->zrvWidth(),
                             sat->isVisibleZrv(), sat->isVisibleLines(), sat->linesWidth(),
                             sat->colorZrv(), sat->colorLines());
        }

        if (sat->isVisibleTrack()) {
            glShadeModel(GL_SMOOTH);
            glEnable(GL_ALPHA_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glEnable(GL_LINE_SMOOTH);
            glLineWidth(sat->linesWidth());

            glBegin(GL_LINE_STRIP);
            double tper = 120.0 * M_PI / sat->meanMotion(); // TODO move this line
            double trackBegin = sat->track() * (-0.5 * tper + tper / 180.0);
            double trackEnd = sat->track() * (0.5 * tper + tper / 180.0);
            sat->model(trackBegin + m_satviewer->time());
            tmpx = sat->longitude() / M_PI;
            tmpy = -2.0 * sat->latitude() / M_PI;
            for (double i = trackBegin; i < trackEnd; i += tper / 180.0) {
                sat->model(i + m_satviewer->time());
                if (sat->isVisibleTrackShadow()) {
                    if (shadow_state) {
                        clr = sat->colorTrack();
                        glColor4ubv((GLubyte *)&clr);
                    } else {
                        clr = sat->colorTrackShadow();
                        glColor4ubv((GLubyte *)&clr);
                    }
                } else {
                    clr = sat->colorTrack();
                    glColor4ubv((GLubyte *)&clr);
                }
                px = sat->longitude() / M_PI;
                py = -2.0 * sat->latitude() / M_PI;
                if (fabs(px - tmpx) > 1.75) {
                    if (px > tmpx) {
                        glVertex2f(-1.0, 0.5 * (py + tmpy));
                        glEnd();
                        glBegin(GL_LINE_STRIP);
                        glVertex2f(1.0, 0.5 * (py + tmpy));
                    } else {
                        glVertex2f(1.0, 0.5 * (py + tmpy));
                        glEnd();
                        glBegin(GL_LINE_STRIP);
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

        sat->model(m_satviewer->time());
        px = sat->longitude() / M_PI;
        py = -2.0 * sat->latitude() / M_PI;
        if (sat->satWObject) {
            sat->satWObject->exec(px, py, 0.0);
        }
    }

    Satellite *sat = m_satviewer->currentSatellite();
    if (sat != nullptr) {
        sat->model(m_satviewer->time());
        px = sat->longitude() / M_PI;
        py = -2.0 * sat->latitude() / M_PI;
        sprite_current.exec(px, py, 0.0);
    }

    glEndList();
}

void GLSatWidget::compileLocList() {
    float px, py;
    Location *loc;

    if (m_satviewer->locations().empty()) {
        glNewList(list_loc, GL_COMPILE);
        glEndList();
        return;
    }

    glNewList(list_loc, GL_COMPILE);

    for (const auto &loc : m_satviewer->locations()) {
        compileZrl(loc);
    }

    loc = m_satviewer->currentLocation();
    if (loc != nullptr) {
        px = loc->longitude() / 180.0;
        py = -loc->latitude() / 90.0;
        sprite_current.exec(px, py, 0.0);
    }

    glEndList();

    //    for (Satellite *sat : satList) {
    //        sat->satWObject->make();
    //    }
}

void GLSatWidget::compileEventsList() {
    float px, py;
    int inZRV, statusZRV;
    double oldTime;
    QString msg;
    QDateTime tmpTime;

    if (m_satviewer->locations().empty() || m_satviewer->satellites().empty()) {
        glNewList(list_events, GL_COMPILE);
        glEndList();
        return;
    }

    glNewList(list_events, GL_COMPILE);
    for (const auto &loc : m_satviewer->locations()) {
        inZRV = 0;
        if (loc->isActiveZone()) {
            for (const auto &sat : m_satviewer->satellites()) {
                if (!sat->isAtctiveZone())
                    continue;
                oldTime = m_satviewer->time();
                statusZRV = testIOZRV(sat, loc, m_satviewer->ioList(), oldTime);
                if (statusZRV > -1)
                    inZRV++;
                if (statusZRV == 1) {
                    tmpTime = QDateTime::fromTime_t((uint)m_satviewer->time());
                    msg = QString("%0|%1|%2|%3|%4")
                              .arg(sat->name())
                              .arg("i")
                              .arg(loc->name())
                              .arg((time_t)m_satviewer->time())
                              //                            .arg(tmpTime.time().toString())
                              .arg("*");
                    emit statusZRVChanged(msg);
                }
                if (statusZRV == 2) {
                    tmpTime = QDateTime::fromTime_t((uint)m_satviewer->time());
                    msg = QString("%0|%1|%2|%3|%4")
                              .arg(sat->name())
                              .arg("o")
                              .arg(loc->name())
                              .arg((time_t)m_satviewer->time())
                              //                            .arg(tmpTime.time().toString())
                              .arg(m_satviewer->time() - oldTime);
                    emit statusZRVChanged(msg);
                }
            }
        }

        px = loc->longitude() / 180.0;
        py = -loc->latitude() / 90.0;
        loc->satWObject->exec(px, py, 0.0);

        if (inZRV > 0.0)
            sprite_active.exec(px, py, 0.0);
    }
    glEndList();
}

void GLSatWidget::compileSunList() {
    double lat, lon;
    glNewList(list_sun, GL_COMPILE);

    sunmodel_ll((time_t)m_satviewer->time(), &lat, &lon);

    float px = lon / M_PI;
    float py = -2.0 * lat / M_PI;

    if (shwNight) {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        compileFootprint(lon, lat, 149597871000.0 - Satellite::RadiusEarth, 0.0, false, false,
                         1.0, // linesWidth
                         0, 0);
        glColor4ubv((GLubyte *)&clrNight);
        glZoneNight(lat);
        if (true) {
            glColor3f(0.4, 0.4, 0.4);
            glZoneLines(lat);
        }
        glDisable(GL_BLEND);
    }

    if (shwSun) {
        sprite_sun.exec(px, py, 0.0);
    }

    glEndList();
}

void GLSatWidget::paintEvent(QPaintEvent *event) {
    GLSatAbstractWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(clrNetFont);
    painter.setFont(fntNet);
    //    painter.setCompositionMode(QPainter::CompositionMode_Screen); // TODO
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    int w = width();
    int h = height();
    double dx = width() / 12.0;
    double dy = height() / 6.0;

    QFontMetrics fm(fntNet);
    int bw = fm.width("00");
    int bh = fm.height();

    for (int i = 1; i < 6; i++) {
        painter.drawText(0, dy * i, QString().number(abs(i * 30 - 90)));
        painter.drawText(w - bw, dy * i, QString().number(abs(i * 30 - 90)));
    }

    for (int i = 1; i < 12; i++) {
        painter.drawText(dx * i, bh, QString().number(abs(i * 30 - 180)));
        painter.drawText(dx * i, h, QString().number(abs(i * 30 - 180)));
    }

    for (const auto &sat : m_satviewer->satellites()) {
        if (sat->isVisibleLabel()) {
            painter.setPen(sat->colorLabel());
            painter.setFont(sat->font());

            dx = 0.5 * w * (1.0 + sat->longitude() / M_PI) + sat->nameX();
            dy = h * (0.5 - sat->latitude() / M_PI) - sat->nameY();

            painter.drawText(dx, dy, sat->name());
        }
    }

    for (const auto &loc : m_satviewer->locations()) {
        if (loc->isVisibleLabel()) {
            painter.setPen(loc->colorLabel());
            painter.setFont(loc->font());

            dx = 0.5 * w * (1.0 + loc->longitude() / 180.0) + loc->nameX();
            dy = h * (0.5 - loc->latitude() / 180.0) - loc->nameY();

            painter.drawText(dx, dy, loc->name());
        }
    }

    painter.end();
}

void GLSatWidget::resizeGL(int width, int height) {
    GLSatAbstractWidget::resizeGL(width, height);
    sprite_sun.make();
    sprite_current.make();
    sprite_active.make();
}

void GLSatWidget::mouseMoveEvent(QMouseEvent *event) {
    float px, py;
    float w = this->width();
    float h = this->height();

    float x = event->x();
    float y = event->y();
    float kxl = w / 360.0;
    float kyl = h / 180.0;
    float kxs = 0.5 * w / M_PI;
    float kys = h / M_PI;

    Location *currentLoc = nullptr;
    Satellite *currentSat = nullptr;

    for (const auto &loc : m_satviewer->locations()) {
        px = kxl * (180.0 + loc->longitude()) * m_zoom - 0.5 * (m_zoom - 1.0 - m_dx) * w;
        py = kyl * (90.0 - loc->latitude()) * m_zoom - 0.5 * (m_zoom - 1.0 - m_dy) * h;
        if (fabs(px - x) < 7.0 * m_zoom && fabs(py - y) < 7.0 * m_zoom) {
            currentLoc = loc;
            break;
        }
    }
    m_cursorOnLocation = (currentLoc != nullptr);

    if ((event->buttons() == Qt::LeftButton) && m_cursorOnLocation) {
        m_satviewer->setCurrentLocation(currentLoc);
    }

    for (const auto &sat : m_satviewer->satellites()) {
        px = kxs * (M_PI + sat->longitude()) * m_zoom - 0.5 * (m_zoom - 1.0 - m_dx) * w;
        py = kys * (0.5 * M_PI - sat->latitude()) * m_zoom - 0.5 * (m_zoom - 1.0 - m_dy) * h;
        if (fabs(px - x) < 7.0 * m_zoom && fabs(py - y) < 7.0 * m_zoom) {
            currentSat = sat;
            break;
        }
    }
    m_cursorOnSatellite = (currentSat != nullptr);

    if ((event->buttons() == Qt::LeftButton) && m_cursorOnSatellite) {
        m_satviewer->setCurrentSatellite(currentSat);
    }

    if (m_cursorOnSatellite || m_cursorOnLocation) {
        setCursor(Qt::PointingHandCursor);
    } else {
        setCursor(Qt::CrossCursor);
    }

    if (event->buttons() == Qt::RightButton) {
        moveX(2.0 * (event->x() - pointMoveMap.x()) / w);
        moveY(2.0 * (event->y() - pointMoveMap.y()) / h);
        pointMoveMap = event->pos();
        paintGL();
    }
    event->accept();
}

void GLSatWidget::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        mouseMoveEvent(event);
    }
    if (event->buttons() == Qt::RightButton) {
        pointMoveMap = event->pos();
    }
    event->accept();
}

void GLSatWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        if (m_cursorOnSatellite) {
            emit this->doubleClickedSat();
        } else if (m_cursorOnLocation) {
            emit this->doubleClickedLoc();
        }
    }
    event->accept();
}

void GLSatWidget::wheelEvent(QWheelEvent *event) {
    if (event->buttons() == Qt::RightButton) {
        zoom(0.001 * event->delta());
        paintGL();
    }
    event->accept();
}

float GLSatWidget::zoom(float value) {
    ui.spinZoom->blockSignals(true);
    ui.spinX->blockSignals(true);
    ui.spinY->blockSignals(true);
    GLSatAbstractWidget::zoom(value);
    ui.spinZoom->setValue(m_zoom);
    ui.spinX->setValue(m_dx);
    ui.spinY->setValue(m_dy);
    ui.spinZoom->blockSignals(false);
    ui.spinX->blockSignals(false);
    ui.spinY->blockSignals(false);
    return m_zoom;
}

float GLSatWidget::moveX(float value) {
    ui.spinX->blockSignals(true);
    GLSatAbstractWidget::moveX(value);
    ui.spinX->setValue(m_dx);
    ui.spinX->blockSignals(false);
    return m_dx;
}

float GLSatWidget::moveY(float value) {
    ui.spinY->blockSignals(true);
    GLSatAbstractWidget::moveY(value);
    ui.spinY->setValue(m_dy);
    ui.spinY->blockSignals(false);
    return m_dy;
}

void GLSatWidget::changeZoom(double value) {
    zoom(value - m_zoom);
}

void GLSatWidget::changeX(double value) {
    moveX(value - m_dx);
}

void GLSatWidget::changeY(double value) {
    moveY(value - m_dy);
}
