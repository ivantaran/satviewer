/*
 * GLObjMaterial.h
 *
 *  Created on: 30.03.2010
 *      Author: Yan Coduemat
 */

#ifndef GLOBJMATERIAL_H_
#define GLOBJMATERIAL_H_

//#include "GL/gl.h"
//#include "GL/glu.h"
//#include "GL/glext.h"
#include <inttypes.h>
#include <QtOpenGL>
#include <QImage>
#include <fstream>
#include <iostream>
#include <vector>

#define BUF_SIZE 256
using namespace std;

class mtl{
public:
	mtl() {
		m_kaOn = false;
		m_kdOn = false;
		m_ksOn = false;
		m_keOn = false;
		m_nsOn = false;
		m_mapKaOn = false;
		m_mapKdOn = false;
		m_mapKsOn = false;
		m_mapKeOn = false;
		m_mapNsOn = false;
//		float amb[4] = {0.2, 0.2, 0.2, 1};
//		float diff[4] = {0.8, 0.8, 0.8, 1};
//		float zero[4] = {0, 0, 0, 1};
		m_ka[0] = 0.2;
		m_ka[1] = 0.2;
		m_ka[2] = 0.2;
		m_ka[3] = 1.0;
		m_kd[0] = 0.8;
		m_kd[1] = 0.8;
		m_kd[2] = 0.8;
		m_kd[3] = 1.0;
		m_ks[0] = 0.0;
		m_ks[1] = 0.0;
		m_ks[2] = 0.0;
		m_ks[3] = 1.0;
		m_ke[0] = 0.0;
		m_ke[1] = 0.0;
		m_ke[2] = 0.0;
		m_ke[3] = 1.0;
		m_ns = 0;
	}
	virtual ~mtl() {}
	inline char *name() { return m_name; }
	inline float *ka() { return m_ka; }
	inline float *kd() { return m_kd; }
	inline float *ks() { return m_ks; }
	inline float *ke() { return m_ke; }
	inline float *ns() { return &m_ns; }
	inline uint32_t *mapKa() { return &m_mapKa; }
	inline uint32_t *mapKd() { return &m_mapKd; }
	inline uint32_t *mapKs() { return &m_mapKs; }
	inline uint32_t *mapKe() { return &m_mapKe; }
	inline uint32_t *mapNs() { return &m_mapNs; }
	inline bool kaOn() { return m_kaOn; }
	inline bool kdOn() { return m_kdOn; }
	inline bool ksOn() { return m_ksOn; }
	inline bool keOn() { return m_keOn; }
	inline bool nsOn() { return m_nsOn; }
	inline bool mapKaOn() { return m_mapKaOn; }
	inline bool mapKdOn() { return m_mapKdOn; }
	inline bool mapKsOn() { return m_mapKsOn; }
	inline bool mapKeOn() { return m_mapKeOn; }
	inline bool mapNsOn() { return m_mapNsOn; }

	void  setNs(float value) { m_ns = value; }
	void setMapKa(uint32_t value) { m_mapKa = value; }
	void setMapKd(uint32_t value) { m_mapKd = value; }
	void setMapKs(uint32_t value) { m_mapKs = value; }
	void setMapKe(uint32_t value) { m_mapKe = value; }
	void setMapNs(uint32_t value) { m_mapNs = value; }
	void setKaOn(bool value) { m_kaOn = value; }
	void setKdOn(bool value) { m_kdOn = value; }
	void setKsOn(bool value) { m_ksOn = value; }
	void setKeOn(bool value) { m_keOn = value; }
	void setNsOn(bool value) { m_nsOn = value; }
	void setMapKaOn(bool value) { m_mapKaOn = value; }
	void setMapKdOn(bool value) { m_mapKdOn = value; }
	void setMapKsOn(bool value) { m_mapKsOn = value; }
	void setMapKeOn(bool value) { m_mapKeOn = value; }
	void setMapNsOn(bool value) { m_mapNsOn = value; }
private:
	float m_ka[4], m_kd[4], m_ks[4], m_ke[4];
	float m_ns;
	char m_name[BUF_SIZE];
	uint32_t m_mapKa, m_mapKd, m_mapKs, m_mapKe, m_mapNs;
	bool m_kaOn, m_kdOn, m_ksOn, m_keOn, m_nsOn, m_mapKaOn, m_mapKdOn, m_mapKeOn, m_mapKsOn, m_mapNsOn;
};


class GLObjMaterial {
public:
	GLObjMaterial(QGLWidget *parent, const char *path, const char *fileName = "");
	virtual ~GLObjMaterial();
	void set(char *mtlName);
	bool mapKaOn();
	bool mapKdOn();
	bool mapKsOn();
	bool mapKeOn();
	bool mapNsOn();

private:
	ifstream file;
	std::string m_path;
	vector <mtl *> materials;
	mtl *material;
	mtl defMtl;
	char line[BUF_SIZE];
	char type[BUF_SIZE];
	char name[BUF_SIZE];
	QGLWidget *m_parent;
	void init();
	void addMaterial();
};

#endif /* GLOBJMATERIAL_H_ */
