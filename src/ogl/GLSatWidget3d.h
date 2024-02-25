/*
 * GLSatWidget3d.h
 *
 *  Created on: 24.03.2010
 *      Author: Ivan Ryazanov
 */

#ifndef GLSATWIDGET3D_H_
#define GLSATWIDGET3D_H_

#include "GLSatAbstractWidget.h"
//#include "GL/gl.h"
//#include "GL/glext.h"
//#include "GL/glu.h"
//#undef GLdouble
//#undef GLfloat
//#include <QtOpenGL>
#include "globj/GLObjecter.h"
#include "ui_earthsettings.h"

class GLSatWidget3d : public GLSatAbstractWidget {
    Q_OBJECT

public:
    GLSatWidget3d(SatViewer *satviewer, QWidget *parent = nullptr);
    virtual ~GLSatWidget3d();
    void readSettings(QSettings *settings);
    void writeSettings(QSettings *settings);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void renderText(float x, float y, const QString &text, int color = 0,
                    const QFont &font = QFont());

private:
    Ui::EarthWidgetSettings ui;
    //	GLUquadric *gluObj;
    GLObjecter *globjEarth;
    GLObjecter *globjSat;
    float m_angle[3];
    void compileMapList();
    void compileSatList();
    void compileLocList() {
    }
    void compileSunList() {
    }
    void compileEventsList() {
    }
    //    void setIcon(Satellite *sat, const QString& fileName = "") {}
    //    void setIcon(Location *loc, const QString& fileName = "") {}

private slots:
    void moveX(double value);
    void moveY(double value);
    void rotateX(double value);
    void rotateY(double value);
    void rotateZ(double value);
    void zoom(double value);
};

#endif /* GLSATWIDGET3D_H_ */
