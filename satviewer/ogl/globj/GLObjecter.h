/*
 * GLObjecter.h
 *
 *  Created on: 28.03.2010
 *      Author: Yan Coduemat
 */

#ifndef GLOBJECTER_H_
#define GLOBJECTER_H_

#include <inttypes.h>
#include <QtOpenGL>
#include <fstream>
#include <iostream>
#include <vector>
#include "GLObjMaterial.h"

#define BUF_SIZE 256

using namespace std;

class GLObjecter {
public:
	GLObjecter(QGLWidget *parent, int index, char *path, char *fileName);
	virtual ~GLObjecter();
	void move(float x, float y, float z);
	void moveX(float value);
	void moveY(float value);
	void moveZ(float value);
	void rotateX(float value);
	void rotateY(float value);
	void rotateZ(float value);
	void exec();

private:
	iostream *file;
	std::string m_path;
	float m_xyz[3];
	float m_angle[3];
	uint32_t m_index;
	vector<float *> vertex, tex_vertex, normals;
	char line[BUF_SIZE];
	char type[BUF_SIZE];
	GLObjMaterial *mtlLib;
	QGLWidget *m_parent;
	void init();
	void addVertex();
	void addTexVertex();
	void addNormal();
	void addFace();
	void clear();
};

#endif /* GLOBJECTER_H_ */
