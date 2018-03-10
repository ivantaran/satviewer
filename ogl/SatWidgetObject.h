/* 
 * File:   SatWidgetObject.h
 * Author: Ivan Ryazanov
 *
 * Created on 17 Март 2011 г., 15:16
 */

#ifndef SATWIDGETOBJECT_H
#define	SATWIDGETOBJECT_H

#include <QtCore>
#include <QString>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>

class SatWidgetObject : protected QOpenGLFunctions_2_0 {
public:
    SatWidgetObject(QString fileName = QString(), QOpenGLWidget *parentWidget = 0);
    virtual ~SatWidgetObject();
    inline QString fileName() { return file_name; }
    virtual void exec(float x, float y, float z) {}
    virtual void load(QString fileName, QOpenGLWidget *parentWidget) {}
    virtual void make() {}

private:
    QString file_name;
protected:
};

#endif	/* SATWIDGETOBJECT_H */

