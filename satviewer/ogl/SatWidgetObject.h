/* 
 * File:   SatWidgetObject.h
 * Author: Yan Coduemat
 *
 * Created on 17 Март 2011 г., 15:16
 */

#ifndef SATWIDGETOBJECT_H
#define	SATWIDGETOBJECT_H

#include <QtCore>
#include <QtOpenGL/QtOpenGL>

class SatWidgetObject {
public:
    SatWidgetObject(QString fileName = QString(), QGLWidget *parentWidget = 0);
    virtual ~SatWidgetObject();
    inline QString fileName() { return file_name; }
    virtual void exec(float x = 0, float y = 0, float z = 0) {}
    virtual void load(QString fileName, QGLWidget *parentWidget) {}
private:
    QString file_name;
protected:
};

#endif	/* SATWIDGETOBJECT_H */

