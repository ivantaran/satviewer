/*
 * GLSprite.cpp
 *
 *  Created on: 11.03.2011
 *      Author: Yan Coduemat
 */

#include "GLSprite.h"

GLSprite::GLSprite(QString fileName, QGLWidget *parentWidget) : SatWidgetObject(fileName, parentWidget) {
    widget = 0;
    m_list_index = 0;
    texture_id = 0;
    if (parentWidget == 0) return;
    load(fileName, parentWidget);
}

GLSprite::~GLSprite() {
//    widget->deleteTexture(texture_id);
    glDeleteLists(m_list_index, 1);
    puts("sprite is removed");
}

void GLSprite::load(QString fileName, QGLWidget *parentWidget) {
    if ((parentWidget == 0) || (!parentWidget->isValid())) {
        puts("QGLWidget is not valid");
        return;
    }
    widget = parentWidget;
    wgt_width = widget->width();
    wgt_height = widget->height();
    widget->makeCurrent();

    if (!pixmap.load(fileName)) {
        puts(QString("pixmap not loaded: %0").arg(fileName).toLocal8Bit().data());
        m_width = 0;
        m_height = 0;
        m_angle = 0;
    }
    else {
        m_width = pixmap.width();
        m_height = pixmap.height();
        m_angle = 0;
        texture_id = widget->bindTexture(pixmap);
    }
    if (glIsList(m_list_index)) glDeleteLists(m_list_index, 1);
    m_list_index = glGenLists(1);
    if (!glIsList(m_list_index)) return;
    make();
}

void GLSprite::resize(uint32_t w, uint32_t h) {
    m_width = w;
    m_height = h;
}

void GLSprite::make() {
    if ((m_width == 0) || (m_height == 0) || (wgt_width == 0) || (wgt_height == 0)) {
            glNewList(m_list_index, GL_COMPILE);
            glEndList();
            return;
    }
    float w = (float)m_width/wgt_width;
    float h = (float)m_height/wgt_height;

    glNewList(m_list_index, GL_COMPILE);
    glEndList();

    glNewList(m_list_index, GL_COMPILE);
            glPushAttrib(GL_ENABLE_BIT);
            glBindTexture(GL_TEXTURE_2D, texture_id);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
            glEnable(GL_TEXTURE_2D);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glBegin(GL_QUADS);
                    glTexCoord2f(0.0, 1.0); glVertex2f(-w, -h);
                    glTexCoord2f(1.0, 1.0); glVertex2f( w, -h);
                    glTexCoord2f(1.0, 0.0); glVertex2f( w,  h);
                    glTexCoord2f(0.0, 0.0); glVertex2f(-w,  h);
            glEnd();
            glPopAttrib();
    glEndList();
}

void GLSprite::exec(float x, float y, float z) {
    if ((widget == 0) || (!widget->isValid())) return;
    if ((wgt_width != widget->width()) || (wgt_height != widget->height())) {
        wgt_width = widget->width();
        wgt_height = widget->height();
        make();
    }
    m_x = x;
    m_y = y;
    glPushMatrix();
    glTranslatef(m_x, m_y, 0);
    glCallList(m_list_index);
    glPopMatrix();
}
