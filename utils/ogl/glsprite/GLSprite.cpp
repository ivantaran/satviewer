
/*
 * GLSprite.cpp
 *
 *  Created on: 11.03.2011
 *      Author: Ivan Ryazanov
 */

#include "GLSprite.h"

GLSprite::GLSprite(QString fileName, QOpenGLWidget *parentWidget)
    : SatWidgetObject(fileName, parentWidget) {
    widget = nullptr;
    texture = nullptr;
    m_x = 0.0;
    m_y = 0.0;
    m_list_index = 0;
    m_width = 0;
    m_height = 0;
    m_angle = 0;

    load(fileName, parentWidget);
}

GLSprite::~GLSprite() {
    if (texture) {
        widget->makeCurrent();
        delete texture;
    }
    glDeleteLists(m_list_index, 1);
    qWarning() << __func__;
}

void GLSprite::load(QString fileName, QOpenGLWidget *parentWidget) {
    if ((parentWidget == nullptr) || (!parentWidget->isValid())) {
        //        qWarning("GLSprite::load: QOpenGLWidget is not valid");
        return;
    }

    widget = parentWidget;
    widget->makeCurrent();

    if (!initializeOpenGLFunctions()) {
        qWarning("error: SatWidgetObject initializeOpenGLFunctions");
        exit(-1);
    }

    if (!image.load(fileName)) {
        qWarning() << QString("pixmap not loaded: %0").arg(fileName);
        m_width = 0;
        m_height = 0;
        m_angle = 0;
    } else {
        m_width = image.width();
        m_height = image.height();
        m_angle = 0;
        if (texture) {
            delete texture;
        }
        texture = new QOpenGLTexture(image);
    }

    if (glIsList(m_list_index)) {
        glDeleteLists(m_list_index, 1);
    }

    m_list_index = glGenLists(1);
    if (glIsList(m_list_index)) {
        make();
    } else {
        qWarning("error: GLSprite::load glGenLists");
    }
}

void GLSprite::resize(int w, int h) {
    m_width = w;
    m_height = h;
}

void GLSprite::make() {

    if (!m_width || !m_height || !widget->width() || !widget->height()) {
        qWarning("GLSprite::make: invalid QOpenGLWidget");
        glNewList(m_list_index, GL_COMPILE);
        glEndList();
        return;
    }

    GLfloat w = (GLfloat)m_width / widget->width();
    GLfloat h = (GLfloat)m_height / widget->height();

    glNewList(m_list_index, GL_COMPILE);
    glPushAttrib(GL_ENABLE_BIT);
    texture->bind();
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(-w, -h);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(-w, h);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(w, h);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(w, -h);
    glEnd();
    glPopAttrib();
    glEndList();
}

void GLSprite::exec(float x, float y, float z) {
    Q_UNUSED(z)

    if (!widget || !widget->isValid()) {
        return;
    }

    m_x = x;
    m_y = y;

    glPushMatrix();
    glTranslatef(m_x, m_y, 0);
    glCallList(m_list_index);
    glPopMatrix();
}
