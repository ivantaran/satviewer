
/*
 * File:   SatWidgetObject.cpp
 * Author: Ivan Ryazanov
 *
 * Created on 17 Март 2011 г., 15:16
 */

#include "SatWidgetObject.h"

SatWidgetObject::SatWidgetObject(QString fileName, QOpenGLWidget *parentWidget) {
    Q_UNUSED(parentWidget);
    file_name = fileName;
}

SatWidgetObject::~SatWidgetObject() {
}
