/*
 * GLSprite.h
 *
 *  Created on: 11.03.2011
 *      Author: Ivan Ryazanov
 */

#ifndef GLSPRITE_H_
#define GLSPRITE_H_
#include <inttypes.h>
#include <QOpenGLTexture>
#include <QImage>
#include <QtCore>
#include "../SatWidgetObject.h"

class GLSprite : public SatWidgetObject {
public:
    GLSprite(QString fileName = QString(), QOpenGLWidget *parentWidget = 0);
    virtual ~GLSprite();
    inline int width() { return m_width; }
    inline int height() { return m_height; }
    inline int angle() { return m_angle; }

    void load(QString fileName, QOpenGLWidget *parentWidget);
    void make();
    void exec(float x = 0, float y = 0, float z = 0);

private:
    QImage image;
    int m_width, m_height, wgt_width, wgt_height;
    float m_x, m_y;
    GLuint m_list_index;
    float m_angle;
    QOpenGLTexture *texture;
    QOpenGLWidget *widget;
    void resize(int w, int h);
};

#endif /* GLSPRITE_H_ */
