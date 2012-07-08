/*
 * GLObjMaterial.cpp
 *
 *  Created on: 30.03.2010
 *      Author: Yan Coduemat
 */

#include "GLObjMaterial.h"
#include <QPixmap>
#include <string>

GLObjMaterial::GLObjMaterial(QGLWidget *parent,  const char *path, const char *fileName) {
	m_path = path;
	m_parent = parent;
	m_parent->makeCurrent();
	string fullname = path;
	fullname.append("/").append(fileName);
	file.open(fullname.c_str());
	if (!file.is_open()) {
		cout << "mtl file not open " << fullname << endl;
		return;
	}
	setlocale(LC_NUMERIC, "C");
	material = 0;
	init();
}

GLObjMaterial::~GLObjMaterial() {
	for (vector<mtl *>::iterator i = materials.begin(); i != materials.end(); i++)
		delete *i;
}

void GLObjMaterial::init() {
	QImage img;
	while (!file.eof()) {
		file.getline(line, sizeof(line));
		sscanf(line, "%s %s", type, name);
		if (strcmp(type, "newmtl") == 0) {
			addMaterial();
			continue;
		}
		if ((strcmp(type, "Ka") == 0) && (material != 0)) {
			sscanf(line, "%s %f %f %f %f", type, &material->ka()[0], &material->ka()[1], &material->ka()[2], &material->ka()[3]);
			continue;
		}
		if ((strcmp(type, "Kd") == 0) && (material != 0)) {
			sscanf(line, "%s %f %f %f %f", type, &material->kd()[0], &material->kd()[1], &material->kd()[2], &material->kd()[3]);
			continue;
		}
		if ((strcmp(type, "Ks") == 0) && (material != 0)) {
			sscanf(line, "%s %f %f %f %f", type, &material->ks()[0], &material->ks()[1], &material->ks()[2], &material->ks()[3]);
			continue;
		}
		if ((strcmp(type, "Ke") == 0) && (material != 0)) {
			sscanf(line, "%s %f %f %f %f", type, &material->ke()[0], &material->ke()[1], &material->ke()[2], &material->ke()[3]);
			continue;
		}
		if ((strcmp(type, "Ns") == 0) && (material != 0)) {
			sscanf(line, "%s %f", type, material->ns());
			continue;
		}
//		if ((strcmp(type, "map_Ka") == 0) && (material != 0)) {
//			material->setMapKaOn(true);
//			sscanf(line, "%s %s", type, type);
//			img.load(type);
//			img = img.rgbSwapped();
//			glGenTextures(1, material->mapKa());
//			glBindTexture(GL_TEXTURE_2D, *material->mapKa());
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
//			continue;
//		}
		if ((strcmp(type, "map_Kd") == 0) && (material != 0)) {
			material->setMapKdOn(true);
			sscanf(line, "%s %s", type, type);
			string fullname = m_path;
			fullname.append("/").append(type);
			m_parent->makeCurrent();
			if (!img.load(fullname.c_str())) {
				puts("texture not loaded:");
				puts(fullname.c_str());
			}

			uint32_t tex = m_parent->bindTexture(img, GL_TEXTURE_2D, GL_RGBA, QGLContext::InvertedYBindOption | QGLContext::LinearFilteringBindOption);
			material->setMapKd(tex);
//			img = img.rgbSwapped();
//			img = img.mirrored(true, false);
//			img = m_parent->convertToGLFormat(img);
//			glGenTextures(1, material->mapKd());
//			glBindTexture(GL_TEXTURE_2D, *material->mapKd());
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
			continue;
		}
//		if ((strcmp(type, "map_Ks") == 0) && (material != 0)) {
//			material->setMapKsOn(true);
//			sscanf(line, "%s %s", type, type);
//			img.load(type);
//			img = img.rgbSwapped();
//			glGenTextures(1, material->mapKs());
//			glBindTexture(GL_TEXTURE_2D, *material->mapKs());
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
//			continue;
//		}
//		if ((strcmp(type, "map_Ke") == 0) && (material != 0)) {
//			material->setMapKeOn(true);
//			sscanf(line, "%s %s", type, type);
//			img.load(type);
//			img = img.rgbSwapped();
//			glGenTextures(1, material->mapKe());
//			glBindTexture(GL_TEXTURE_2D, *material->mapKe());
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
//			continue;
//		}
//		if ((strcmp(type, "map_Ns") == 0) && (material != 0)) {
//			material->setMapNsOn(true);
//			sscanf(line, "%s %s", type, type);
//			img.load(type);
//			img = img.rgbSwapped();
//			glGenTextures(1, material->mapNs());
//			glBindTexture(GL_TEXTURE_2D, *material->mapNs());
//			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, img.width(), img.height(), GL_RGBA, GL_UNSIGNED_BYTE, img.bits());
//			continue;
//		}
	}
}

void GLObjMaterial::addMaterial() {
	material = new mtl;
	strcpy(material->name(), name);
	materials.push_back(material);
}

void GLObjMaterial::set(char *mtlName) {
	vector <mtl *>::iterator current;
	material = 0;
	current = materials.begin();
	while (current != materials.end()) {
		if (strcmp((*current)->name(), mtlName) == 0) {
			material = (*current);
			break;
		}
		current++;
	}
	if (material == 0) material = &defMtl;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT  , material->ka());
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE  , material->kd());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR , material->ks());
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION , material->ke());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, material->ns());
//	printf("%f %f %f\n", material->kd()[0], material->kd()[1], material->kd()[2]);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//    if (material->mapKaOn()) {
//		glEnable(GL_TEXTURE_2D);
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//		glBindTexture(GL_TEXTURE_2D, *material->mapKa());
//	}

	if (material->mapKdOn()) {
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, *material->mapKd());
	}

//	if (material->mapKsOn()) {
//		glEnable(GL_TEXTURE_2D);
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glBindTexture(GL_TEXTURE_2D, *material->mapKs());
//	}
//
//	if (material->mapKeOn()) {
//		glEnable(GL_TEXTURE_2D);
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glBindTexture(GL_TEXTURE_2D, *material->mapKe());
//	}
//
//	if (material->mapNsOn()) {
//		glEnable(GL_TEXTURE_2D);
//		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glBindTexture(GL_TEXTURE_2D, *material->mapNs());
//	}

	if (!(material->mapKaOn() || material->mapKdOn() || material->mapKsOn() || material->mapNsOn()) ) glDisable(GL_TEXTURE_2D);
}

bool GLObjMaterial::mapKaOn() {
	if (material) return material->mapKaOn();
	return false;
}

bool GLObjMaterial::mapKdOn() {
	if (material) return material->mapKdOn();
	return false;
}

bool GLObjMaterial::mapKsOn() {
	if (material) return material->mapKsOn();
	return false;
}

bool GLObjMaterial::mapKeOn() {
	if (material) return material->mapKeOn();
	return false;
}

bool GLObjMaterial::mapNsOn() {
	if (material) return material->mapNsOn();
	return false;
}


