/*
 * GLSatWidget3d.h
 *
 *  Created on: 24.03.2010
 *      Author: Yan Coduemat
 */

#ifndef GLSATWIDGET3D_H_
#define GLSATWIDGET3D_H_

#include "GLSatAbstractWidget.h"
//#include "GL/gl.h"
#include "GL/glu.h"
//#include "GL/glext.h"
#include <QtOpenGL>
#include "../ui_earthsettings.h"
#include "globj/GLObjecter.h"

class GLSatWidget3d : public GLSatAbstractWidget
{
	Q_OBJECT

public:
	GLSatWidget3d(QWidget *parent = 0);
	virtual ~GLSatWidget3d();
	void readSettings(QSettings *settings);
	void writeSettings(QSettings *settings);

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void renderText(float x, float y, const QString& text, int color = 0, const QFont &font = QFont());
private:
	Ui::EarthWidgetSettings ui;
	GLUquadric *gluObj;
	GLObjecter *globjEarth;
	GLObjecter *globjSat;
	float m_angle[3];
	void compileMapList();
	void compileSatList();
	void compileLocList() {}
	void compileSunList() {}
	void compileEventsList() {}
private slots:
	void moveX(double value);
	void moveY(double value);
	void rotateX(double value);
	void rotateY(double value);
	void rotateZ(double value);
	void zoom(double value);
};

#endif /* GLSATWIDGET3D_H_ */
