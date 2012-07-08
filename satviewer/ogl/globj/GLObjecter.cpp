/*
 * GLObjecter.cpp
 *
 *  Created on: 28.03.2010
 *      Author: Yan Coduemat
 */

#include "GLObjecter.h"

GLObjecter::GLObjecter(QGLWidget *parent, int index, char *path, char *fileName) {
	m_xyz[0] = 0;
	m_xyz[1] = 0;
	m_xyz[2] = 0;
	m_angle[0] = 0;
	m_angle[1] = 0;
	m_angle[2] = 0;
	m_path = path;
	m_index = index;
	m_parent = parent;
	m_parent->makeCurrent();
	string fullname = path;
	fullname.append("/").append(fileName);
	filebuf fbuf;
	fbuf.open(fullname.c_str(), _S_in);
	if (!fbuf.is_open()) {
		cout << "obj file not open " << fileName << endl;
		return;
	}
	ifstream f(fullname.c_str());
	if (!f.is_open()) {
		cout << "obj file not open " << fileName << endl;
		return;
	}

	iostream strm(&fbuf);
	file = &strm;
	mtlLib = 0;
	setlocale(LC_NUMERIC, "C");
	init();
	clear();
}

void GLObjecter::clear() {
	for (vector<float *>::iterator i = vertex.begin(); i != vertex.end(); i++) delete[] *i;
	for (vector<float *>::iterator i = tex_vertex.begin(); i != tex_vertex.end(); i++) delete[] *i;
	for (vector<float *>::iterator i = normals.begin(); i != normals.end(); i++) delete[] *i;
	vertex.clear();
	tex_vertex.clear();
	normals.clear();
	file->clear();
	if (mtlLib != 0) delete mtlLib; //как бы там еще и текстуры надо бы удалять
}

GLObjecter::~GLObjecter() {
	clear();
}

void GLObjecter::init() {
	glNewList(m_index, GL_COMPILE);
	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

	while (!file->eof()) {
		memset(type, 20, sizeof(type) - 1);
//		strset(type, 20);
		file->getline(line, sizeof(line));
		sscanf(line, "%s", type);
		if (strcmp(type, "v") == 0) {
			addVertex();
			continue;
		}
		if (strcmp(type, "vt") == 0) {
			addTexVertex();
			continue;
		}
		if (strcmp(type, "vn") == 0) {
			addNormal();
			continue;
		}
		if (strcmp(type, "f") == 0) {
			addFace();
			continue;
		}
		if (strcmp(type, "mtllib") == 0) {
			sscanf(line, "%s %s", type, type);
			if (mtlLib != 0) {
				delete mtlLib;
				mtlLib = 0;
			}
			mtlLib = new GLObjMaterial(m_parent, m_path.c_str(), type);
			continue;
		}
		if (strcmp(type, "usemtl") == 0) {
			sscanf(line, "%s %s", type, type);
			if (mtlLib != 0) mtlLib->set(type);
			continue;
		}
		if (strcmp(type, "g") == 0) {
			sscanf(line, "%s %s", type, type);
			cout << type << endl;
			continue;
		}
	}
	glPopAttrib();
	glEndList();
	exec();
}

void GLObjecter::addVertex() {
	float *v = new float[3];
	sscanf(line, "%s %f %f %f", type, &v[0], &v[1], &v[2]);
	vertex.push_back(v);
}

void GLObjecter::addTexVertex() {
	float *v = new float[3];
	sscanf(line, "%s %f %f %f", type, &v[0], &v[1], &v[2]);
	tex_vertex.push_back(v);
}

void GLObjecter::addNormal() {
	float *v = new float[3];
	sscanf(line, "%s %f %f %f", type, &v[0], &v[1], &v[2]);
	normals.push_back(v);
}

void GLObjecter::addFace() {
	char *token = strtok(line, " ");
	token = strtok(0, " ");
	char test = 0;

	glBegin(GL_POLYGON);
	while (token != 0) {
//		int *tmp = new int[3];
		int tmp[3];
		test = sscanf(token, "%d/%d/%d", &tmp[0], &tmp[1], &tmp[2]);
		switch (test) {
			default: case 0:
				cout << (int)test << " bad face " << token << endl;
				return;
			break;
			break;
			case 1:
				if (sscanf(token, "%d//%d", &tmp[0], &tmp[2]) == 2) {
					glNormal3fv(normals.at(tmp[2] - 1));
					glVertex3fv(vertex.at(tmp[0] - 1));
				}
				else glVertex3fv(vertex.at(tmp[0] - 1));
			break;
			case 2:
				if (mtlLib->mapKdOn()) glTexCoord3fv(tex_vertex.at(tmp[1] - 1));
				glVertex3fv(vertex.at(tmp[0] - 1));
			break;
			case 3:
				glNormal3fv(normals.at(tmp[2] - 1));
				if (mtlLib->mapKdOn()) glTexCoord3fv(tex_vertex.at(tmp[1] - 1));
				glVertex3fv(vertex.at(tmp[0] - 1));
			break;
		}
		token = strtok(0, " ");
	}

	glEnd();
}

void GLObjecter::exec() {
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glTranslatef(m_xyz[0], m_xyz[1], m_xyz[2]);
	glRotatef(m_angle[0], 1, 0, 0);
	glRotatef(m_angle[1], 0, 1, 0);
	glRotatef(m_angle[2], 0, 0, 1);
	glCallList(m_index);
	glPopMatrix();
	glPopAttrib();
}

void GLObjecter::move(float x, float y, float z) {
	m_xyz[0] = x;
	m_xyz[1] = y;
	m_xyz[2] = z;
}

void GLObjecter::moveX(float value) {
	m_xyz[0] = value;
}

void GLObjecter::moveY(float value) {
	m_xyz[1] = value;
}

void GLObjecter::moveZ(float value) {
	m_xyz[2] = value;
}

void GLObjecter::rotateX(float value) {
	m_angle[0] = value;
}

void GLObjecter::rotateY(float value) {
	m_angle[1] = value;
}

void GLObjecter::rotateZ(float value) {
	m_angle[2] = value;
}
