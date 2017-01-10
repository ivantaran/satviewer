/*
 * GLSprite.h
 *
 *  Created on: 11.03.2011
 *      Author: Yan Coduemat
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
	inline uint32_t width() { return m_width; }
	inline uint32_t height() { return m_height; }
	inline uint32_t angle() { return m_angle; }

	void load(QString fileName, QOpenGLWidget *parentWidget);
	void resize(uint32_t w, uint32_t h);
	void make();
	void exec(float x = 0, float y = 0, float z = 0);

private:
	QImage image;
	int32_t m_width, m_height, wgt_width, wgt_height;
	float m_x, m_y;
	uint32_t m_list_index;
	float m_angle;
	QOpenGLTexture *texture;
	QOpenGLWidget *widget;
};

#endif /* GLSPRITE_H_ */
