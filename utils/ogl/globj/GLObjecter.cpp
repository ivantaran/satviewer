
/*
 * GLObjecter.cpp
 *
 *  Created on: 28.03.2010
 *      Author: Ivan Ryazanov
 */

#include "GLObjecter.h"

GLObjecter::GLObjecter(QOpenGLWidget *parent, int index, const char *path, const char *fileName) {
    if (!parent || !parent->isValid()) {
        qWarning("error: GLObjecter, invalid QOpenGLWidget");
        return;
    }
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

    if (!initializeOpenGLFunctions()) {
        puts("error: GLObjecter initializeOpenGLFunctions");
        exit(-1);
    }
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

    file = new iostream(&fbuf);
    mtlLib = 0;
    setlocale(LC_NUMERIC, "C");
    init();
    clear();
}

void GLObjecter::clear() {
    for (const auto &i : vertex) {
        delete[] i;
    }
    for (const auto &i : tex_vertex) {
        delete[] i;
    }
    for (const auto &i : normals) {
        delete[] i;
    }
    vertex.clear();
    tex_vertex.clear();
    normals.clear();
    file->clear();
    if (mtlLib != NULL) {
        delete mtlLib; // TODO add remove textures
    }
}

GLObjecter::~GLObjecter() {
    clear();
    delete file;
}

void GLObjecter::init() {
    glNewList(m_index, GL_COMPILE);
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

    while (!file->eof()) {
        memset(type, 20, sizeof(type)); // TODO remove this two lines
        type[BUF_SIZE - 1] = '\0';
        file->getline(line, sizeof(line));
        sscanf(line, "%64s", type);
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
            sscanf(line, "%*s %64s", type);
            if (mtlLib != NULL) {
                delete mtlLib;
                mtlLib = NULL;
            }
            mtlLib = new GLObjMaterial(m_parent, m_path.c_str(), type);
            continue;
        }
        if (strcmp(type, "usemtl") == 0) {
            sscanf(line, "%*s %64s", type);
            if (mtlLib != NULL)
                mtlLib->set(type);
            continue;
        }
        if (strcmp(type, "g") == 0) {
            sscanf(line, "%*s %64s", type);
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
    sscanf(line, "%*s %f %f %f", &v[0], &v[1], &v[2]);
    vertex.push_back(v);
}

void GLObjecter::addTexVertex() {
    float *v = new float[3];
    sscanf(line, "%*s %f %f %f", &v[0], &v[1], &v[2]);
    tex_vertex.push_back(v);
}

void GLObjecter::addNormal() {
    float *v = new float[3];
    sscanf(line, "%*s %f %f %f", &v[0], &v[1], &v[2]);
    normals.push_back(v);
}

void GLObjecter::addFace() {
    char *token;
    int tmp[3];

    strtok(line, " ");
    token = strtok(NULL, " ");

    glBegin(GL_POLYGON);
    while (token != 0) {
        int c = sscanf(token, "%d/%d/%d", &tmp[0], &tmp[1], &tmp[2]);
        switch (c) {
        default:
        case 0:
            cout << c << " bad face " << token << endl;
            break;
        case 1:
            if (sscanf(token, "%d//%d", &tmp[0], &tmp[2]) == 2) {
                glNormal3fv(normals.at(tmp[2] - 1));
                glVertex3fv(vertex.at(tmp[0] - 1));
            } else
                glVertex3fv(vertex.at(tmp[0] - 1));
            break;
        case 2:
            if (mtlLib->mapKdOn())
                glTexCoord3fv(tex_vertex.at(tmp[1] - 1));
            glVertex3fv(vertex.at(tmp[0] - 1));
            break;
        case 3:
            glNormal3fv(normals.at(tmp[2] - 1));
            if (mtlLib->mapKdOn())
                glTexCoord3fv(tex_vertex.at(tmp[1] - 1));
            glVertex3fv(vertex.at(tmp[0] - 1));
            break;
        }
        token = strtok(NULL, " ");
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
