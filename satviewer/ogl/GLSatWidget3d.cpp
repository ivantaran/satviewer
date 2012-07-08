/*
 * GLSatWidget3d.cpp
 *
 *  Created on: 24.03.2010
 *      Author: Yan Coduemat
 */

#include "GLSatWidget3d.h"
#include "math.h"
#include <QDir>

GLSatWidget3d::GLSatWidget3d(QWidget *parent) : GLSatAbstractWidget(parent) {

	ui.setupUi(settingsWidget);
	gluObj = gluNewQuadric();

	m_angle[0] = 0;
	m_angle[1] = 0;
	m_angle[2] = 0;

	QDir dir = QDir::home();
	dir.cd("satviewer");
	dir.cd("3d");
	QString path = dir.path();
	makeCurrent();

	globjEarth = new GLObjecter(this, 1, path.toLocal8Bit().data(), "earth.obj");
	globjSat = new GLObjecter(this, 2, path.toLocal8Bit().data(), "glok.obj");

	connect(ui.spinZoom, SIGNAL(valueChanged(double)), this, SLOT(zoom   (double)));
	connect(ui.spinX   , SIGNAL(valueChanged(double)), this, SLOT(moveX  (double)));
	connect(ui.spinY   , SIGNAL(valueChanged(double)), this, SLOT(moveY  (double)));
	connect(ui.spinRotX, SIGNAL(valueChanged(double)), this, SLOT(rotateX(double)));
	connect(ui.spinRotY, SIGNAL(valueChanged(double)), this, SLOT(rotateY(double)));
	connect(ui.spinRotZ, SIGNAL(valueChanged(double)), this, SLOT(rotateZ(double)));
}

GLSatWidget3d::~GLSatWidget3d() {

}

void GLSatWidget3d::readSettings(QSettings *settings) {
	QString filePath = settings->value("mapFile", "").toString();
	loadTexture(filePath);
	ui.btnMapFile->setText(filePath);

	ui.spinZoom->setValue(settings->value("3d/mapZoom", 4).toDouble());
	ui.spinX->setValue   (settings->value("3d/mapX"   , 0).toDouble());
	ui.spinY->setValue   (settings->value("3d/mapY"   , 0).toDouble());
	ui.spinRotX->setValue(settings->value("3d/mapRotX", 0).toDouble());
	ui.spinRotY->setValue(settings->value("3d/mapRotY", 0).toDouble());
	ui.spinRotZ->setValue(settings->value("3d/mapRotZ", 0).toDouble());
}

void GLSatWidget3d::writeSettings(QSettings *settings) {
	settings->setValue( "mapFile", ui.btnMapFile->text() );

	settings->setValue("3d/mapZoom", ui.spinZoom->value());
	settings->setValue("3d/mapX"   , ui.spinX->value   ());
	settings->setValue("3d/mapY"   , ui.spinY->value   ());
	settings->setValue("3d/mapRotX", ui.spinRotX->value());
	settings->setValue("3d/mapRotY", ui.spinRotY->value());
	settings->setValue("3d/mapRotZ", ui.spinRotZ->value());
}

void GLSatWidget3d::initializeGL() {
	makeCurrent();
	setAutoBufferSwap(false);
	glClearColor(0.3, 0.3, 0.3, 0.0);
    //glShadeModel(GL_FLAT);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, 1, -1, -30, 30);
    double k = 1;
    if ((width() != 0) && (height() != 0)) {
    	if (width() > height()) {
    		k = (double)width()/height();
    	    glFrustum(-k, k, -1, 1, 3, 30);
    	}
    	else {k = (double)height()/width();
    		glFrustum(-1, 1, -k, k, 3, 30);
    	}
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glTranslatef(0.0, 0.0, 0.0);

//    const float mat1_dif[3] = {0.8, 0.8, 0.0};
//    const float mat1_amb[3] = {0.2, 0.2, 0.2};
//    const float mat1_spec[3] = {0.6, 0.6, 0.6};
//    const float mat1_shininess = 0.5*128;
//
//    glMaterialfv(GL_FRONT, GL_AMBIENT  , mat1_amb);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE  , mat1_dif);
//    glMaterialfv(GL_FRONT, GL_SPECULAR , mat1_spec);
//    glMaterialf (GL_FRONT, GL_SHININESS, mat1_shininess);

//    const float light_ambient [4] = { 0.5, 0.5, 0.5, 1.0};
//    const float light_diffuse [4] = { 1.0, 1.0, 1.0, 1.0};
//    const float light_specular[4] = { 2.0, 2.0, 2.0, 1.0};
//    const float light_position[4] = { 2.0, 1.0, 3.0, 1.0};
//    const float light_emission[4] = { 1.0, 1.0, 1.0, 1.0};
//    const float light_spotdirection[4] = { 1.0, 1.0, 1.0, 1.0 };
//    const float lm[4] = {0.5, 0.5, 0.5, 1.0};

//    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, true);
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lm);
//    glLightfv(GL_LIGHT0, GL_AMBIENT , light_ambient );
//    glLightfv(GL_LIGHT0, GL_DIFFUSE , light_diffuse );
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_spotdirection);
//    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 8);
//    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF  , 170);

    glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void GLSatWidget3d::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
//	glTranslatef(0.0, 0.0, -15.0);
	glTranslatef(m_dx, m_dy, -15.0);
//	glRotatef(-90.0, 0.0, 0.0, 1.0);
//	glRotatef(-90.0, 0.0, 1.0, 0.0);
	glRotatef(m_angle[0] - 90, 1, 0, 0);
	glRotatef(m_angle[1], 0, 1, 0);
	glRotatef(m_angle[2] - 90, 0, 0, 1);

	glScalef(m_zoom, m_zoom, m_zoom);

	globjEarth->exec();
    glCallList(4); //satList
    this->swapBuffers();
}

void GLSatWidget3d::resizeGL(int width, int height) {
	makeCurrent();
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double k = 1;
    if ((width != 0) && (height != 0)) {
    	if (width > height) {
    		k = (double)width/height;

    	    glFrustum(-k, k, -1, 1, 2, 36);
    	}
    	else {
    		k = (double)height/width;
    		glFrustum(-1, 1, -k, k, 2, 36);
    	}
    }
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
    refreshAll();
}

void GLSatWidget3d::compileMapList() {

}

void GLSatWidget3d::compileSatList() {
	const double radiusEarth = 6378137.0;
    if (satList.count() < 1) {
		glNewList(4, GL_COMPILE);
		glEndList();
		return;
    }
    Satellite *sat = 0;
    float tper, trackBegin, trackEnd;
    uint32_t clr;
	glNewList(4, GL_COMPILE);
		for (int i = 0; i < satList.count(); i++) {
			sat = satList.at(i);
			if (sat->isVisibleTrack()) {
				clr = sat->colorTrack();
				glPushAttrib(GL_ENABLE_BIT);
				glColor4ubv((uint8_t *)&clr);
//				glShadeModel(GL_SMOOTH);
//				glEnable(GL_ALPHA_TEST);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glEnable(GL_BLEND);
				glEnable(GL_LINE_SMOOTH);
				glDisable(GL_LIGHTING);
				glLineWidth(sat->linesWidth());
				glBegin(GL_LINE_STRIP);
					tper = 120*M_PI/sat->meanMotion();
					trackBegin = sat->track()*(-0.5*tper + tper/180.0);
					trackEnd = sat->track()*(0.5*tper + tper/180.0);
					for (float i = trackBegin; i < trackEnd; i += tper/180.0) {
						sat->model(i + m_time);
						glVertex3f(sat->xyz_g()[0]/radiusEarth, sat->xyz_g()[1]/radiusEarth, sat->xyz_g()[2]/radiusEarth);
					}
				glEnd();
				glPopAttrib();
			}

			sat->model(m_time);
			float r = sqrtf(sat->xyz_g()[0]*sat->xyz_g()[0] + sat->xyz_g()[1]*sat->xyz_g()[1] + sat->xyz_g()[2]*sat->xyz_g()[2]);
			float rz = sqrtf(sat->xyz_g()[0]*sat->xyz_g()[0] + sat->xyz_g()[1]*sat->xyz_g()[1]);
			glPushMatrix();
			globjSat->move(0, 0, 0);
			globjSat->rotateX(0);
			globjSat->rotateY(0);
			globjSat->rotateY(0);
			float arzx = acosf(sat->xyz_g()[0]/rz)*180/M_PI;
			float az = acosf(sat->xyz_g()[2]/r)*180/M_PI;
			if (sat->xyz_g()[1] < 0) arzx = -arzx;
			glRotatef(arzx, 0, 0, 1);
			glRotatef(az, 0, 1, 0);
			glRotatef(-arzx, 0, 0, 1);
			glTranslatef(0, 0, r/radiusEarth);
			globjSat->exec();
			glPopMatrix();
		}
	glEndList();
}

void GLSatWidget3d::renderText(float x, float y, const QString& text, int color, const QFont &font) {
	QFontMetrics fontMetrics(font);
	QRect rect = fontMetrics.boundingRect(text);

	QPixmap pixmap(rect.size());

	pixmap.fill(QColor((uint8_t)(color), (uint8_t)(color >> 8), (uint8_t)(color >> 16), 254));
	QPixmap apx = pixmap.alphaChannel();
	apx.fill(Qt::black);
	QPainter painter(&apx);
	painter.setPen(Qt::white);
	painter.setFont(font);
	painter.drawText(-rect.left(), -rect.top(), text);
	pixmap.setAlphaChannel(apx);

	QImage img = pixmap.toImage();

	img = QGLWidget::convertToGLFormat(img);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glRasterPos3f(x, 0, y);
	glDrawPixels(rect.width(), rect.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
	glDisable(GL_BLEND);
    glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
}

void GLSatWidget3d::zoom(double value) {
	m_zoom = value;
}

void GLSatWidget3d::moveX(double value) {
	m_dx = value;
}

void GLSatWidget3d::moveY(double value) {
	m_dy = value;
}

void GLSatWidget3d::rotateX(double value) {
	m_angle[0] = value;
}

void GLSatWidget3d::rotateY(double value) {
	m_angle[1] = value;
}

void GLSatWidget3d::rotateZ(double value) {
	m_angle[2] = value;
}
