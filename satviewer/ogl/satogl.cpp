/*
 * satglutils.cpp
 *
 *  Created on: 21.05.2009
 *      Author: Yan Coduemat
 */
#include "satogl.h"
#include "math.h"
//#include "GL/gl.h"
#include "GL/glu.h"
#include <QtOpenGL>
#include "locutils/Location.h"
#include "satutils/Satellite.h"

//---------------------------------------------------------------------------
float vertex[VRTX_COUNT][2]; //�������� ����� ��������� ���, ���

//---------------------------------------------------------------------------
void initSatOgl() {
    for (int i = 0; i < VRTX_COUNT; ++i) {
        vertex[i][0] = 0;
        vertex[i][1] = 0;
    }
}

//������� ����������� ����� ���, ���
void glZoneLines(float lat) {
	uint8_t type = 0;
	int breakpoint[2];
	float polar;
	glShadeModel(GL_SMOOTH);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);

    if (fabs(vertex[0][0] - vertex[VRTX_COUNT - 1][0]) > 1) {
    	breakpoint[type] = 0;
		type++;
	}
	for (int i = 0; i < VRTX_COUNT - 1; i++)
		if (fabs(vertex[i][0] - vertex[i + 1][0]) > 1) {
			breakpoint[type] = i + 1;
			type++;
		}

	if (lat < 0) polar = 1.0f;
	else polar = -1.0f;
	switch (type) {

		case 0:
		glBegin(GL_LINE_STRIP);
			for (int i = 0; i < VRTX_COUNT; i++) glVertex2fv(vertex[i]);
			glVertex2fv(vertex[0]);
		glEnd();
		break;

		case 1:
			glBegin(GL_LINE_STRIP);
				glVertex2f(polar, vertex[breakpoint[0]][1]);
				for (int i = breakpoint[0]; i < VRTX_COUNT; i++) {
					glVertex2fv(vertex[i]);
				}
				for (int i = 0; i < breakpoint[0]; i++) {
					glVertex2fv(vertex[i]);
				}
				glVertex2f(-polar, vertex[breakpoint[0]][1]);
			glEnd();
		break;

		case 2:
			if (vertex[breakpoint[0]][0] < 0) polar = -1;
			else polar = 1;
			glBegin(GL_LINE_STRIP);
				glVertex2f(polar, vertex[breakpoint[0]][1]);
				for (int i = breakpoint[0] + 1; i < breakpoint[1] - 1; i++) glVertex2fv(vertex[i]);
				glVertex2f(polar, vertex[breakpoint[1] - 1][1]);
			glEnd();

			if (vertex[breakpoint[1]][0] < 0) polar = -1;
			else polar = 1;
			glBegin(GL_LINE_LOOP);
				glVertex2f(polar, vertex[breakpoint[1]][1]);
				for (int i = breakpoint[1] + 1; i < VRTX_COUNT; i++) glVertex2fv(vertex[i]);
				if (breakpoint[0] > 0) {
					for (int i = 0; i < breakpoint[0] - 1; i++) glVertex2fv(vertex[i]);
					glVertex2f(polar, vertex[breakpoint[0] - 1][1]);
				}
				else glVertex2f(polar, vertex[VRTX_COUNT - 1][1]);
			glEnd();
		break;
		}
	glDisable(GL_BLEND);
	glDisable(GL_LINE_SMOOTH);
}
//---------------------------------------------------------------------------
//������� ����������� ����
void glZoneNight(float lat) {
	int breakpoint = 0;
	float polar;

	if (fabs(vertex[0][0] - vertex[VRTX_COUNT - 1][0]) > 1) {
		breakpoint = 0;
	}
	for (int i = 0; i < VRTX_COUNT - 1; i++)
		if (fabs(vertex[i][0] - vertex[i + 1][0]) > 1) {
			breakpoint = i + 1;
		}

	if (lat > 0) polar = 1.0f;
	else polar = -1.0f;

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-polar, vertex[breakpoint][1]);
		glVertex2f(-polar, polar);
		for (int i = breakpoint; i < VRTX_COUNT; i++) {
			glVertex2fv(vertex[i]);
			glVertex2f(vertex[i][0], polar);
		}
		for (int i = 0; i < breakpoint; i++) {
			glVertex2fv(vertex[i]);
			glVertex2f(vertex[i][0], polar);
		}
		glVertex2f(polar, vertex[breakpoint][1]);
		glVertex2f(polar, polar);
	glEnd();

}
//---------------------------------------------------------------------------

void compileZRV(Satellite *sat, bool poly, bool lines, uint32_t colorPoly, uint32_t colorLines)
{
	double fiz = 0;
	double z = sat->zrvWidth();
	if (fabs(cos(z)*sat->radiusEarth()) > (sat->height() + sat->radiusEarth())) fiz = -z;
	else fiz = (M_PI/2 - z - asin(cos(z)*sat->radiusEarth()/(sat->height() + sat->radiusEarth())));
	double x, y;
	double polar, angle = 0;
	if (fabs(sat->latitude()) + fiz < M_PI/2) polar = 1;
	else polar = -1;
	for (int i = 0; i < VRTX_COUNT; i++) {
		y = asin(cos(fiz)*sin(sat->latitude()) + sin(fiz)*cos(sat->latitude())*cos(angle));
		x = sin(fiz)*sin(angle)/cos(y);
		if (x > 1) x = 1.0;
		if (x < -1) x = -1.0;
		x = sat->longitude() + polar*asin(x);
		if ((cos(fiz) - sin(sat->latitude())*sin(y)) < 0 ) {x = 2*sat->longitude() - x + M_PI;}
		x = fmod(x + M_PI, 2*M_PI);
		if (x < 0) x += 2*M_PI;
		vertex[i][0] = (float)(x/M_PI - 1);
		vertex[i][1] = (float)(-2*y/M_PI);
		angle += 2*M_PI/(double)VRTX_COUNT;
	}
	if (poly) {
		glColor4ubv((uint8_t *)&colorPoly);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
//		glZone(sat->latitude());
		gluZone(sat->latitude());
		glDisable(GL_BLEND);
	}

	if (lines){
		glColor4ubv((uint8_t *)&colorLines);
	    glLineWidth(sat->linesWidth());
		glZoneLines(sat->latitude());
	}
}

//---------------------------------------------------------------------------

void lfi_ort(double fi, double lam, double* xyz)
{
	xyz[0] = cos(fi)*cos(lam);
	xyz[1] = cos(fi)*sin(lam);
	xyz[2] = sin(fi);
}

//---------------------------------------------------------------------------
bool testZRV(double* crd1, double* crd2, double fiz)
{
  double fi = 2*asin(0.5*sqrt(pow(crd2[0]-crd1[0], 2) +
                              pow(crd2[1]-crd1[1], 2) +
                              pow(crd2[2]-crd1[2], 2)));
  if (fabs(fi) > fiz) return false; else return true;
}

//---------------------------------------------------------------------------

int testIOZRV(Satellite *sat, Location *loc, ZrvIoList *list, double &time)
{
	int result = -1;
	if (time == 0) return result;  // o_O
	bool inZRV;
	double fiz = 0;
	double z = sat->zrvWidth();
	//---------------------
	if (fabs(cos(z)*sat->radiusEarth()) > (sat->height() + sat->radiusEarth())) fiz = -z;
	else fiz = (M_PI/2 - z - asin(cos(z)*sat->radiusEarth()/(sat->height() + sat->radiusEarth())));
	//---------------------
	double ortl[3], orts[3];
	lfi_ort(loc->latitude()*M_PI/180, loc->longitude()*M_PI/180, ortl);
	lfi_ort(sat->latitude(), sat->longitude(), orts);
	inZRV = testZRV(orts, ortl, fiz);
	if (inZRV) result = 0;

	int ioIndex = list->find(sat, loc);
	if (inZRV && (ioIndex == -1)) {
			result = 1;
			list->add(sat, loc, time);
	}
	else if (!inZRV && (ioIndex != -1)) {
		result = 2;
		time = list->item(ioIndex)->time;
		list->del(ioIndex);
	}
	/**/
	return result;
}

//---------------------------------------------------------------------------

void gluZone(float lat) {
	uint8_t type = 0;
	int breakpoint[2];
	float polar;
	double point[5][3];

	if (fabs(vertex[0][0] - vertex[VRTX_COUNT - 1][0]) > 1) {
		breakpoint[type] = 0;
		type++;
	}
	for (int i = 0; i < VRTX_COUNT - 1; i++) {
		if (fabs(vertex[i][0] - vertex[i + 1][0]) > 1) {
			breakpoint[type] = i + 1;
			type++;
		}
	}
	if (lat < 0) polar = 1.0f;
	else polar = -1.0f;

	GLUtesselator *tess = gluNewTess();
	gluTessProperty(tess, GLU_TESS_WINDING_RULE, GLU_TESS_WINDING_ODD);
	gluTessProperty(tess, GLU_TESS_BOUNDARY_ONLY, GL_FALSE);
	gluTessProperty(tess, GLU_TESS_TOLERANCE, 0);

	gluTessCallback(tess, GLU_TESS_BEGIN , (_GLUfuncptr)glBegin    );
	gluTessCallback(tess, GLU_TESS_END   ,              glEnd      );
	gluTessCallback(tess, GLU_TESS_VERTEX, (_GLUfuncptr)glVertex2dv);

	gluTessBeginPolygon(tess, 0);
	gluTessBeginContour(tess);

	GLdouble dvertex[VRTX_COUNT][3];
	for (int i = 0; i < VRTX_COUNT; i++) {
		dvertex[i][0] = vertex[i][0];
		dvertex[i][1] = vertex[i][1];
		dvertex[i][2] = 0;
	}

	switch (type) {

		case 0:
//		glBegin(GL_POLYGON);
//			for (int i = 0; i < VRTX_COUNT; i++) glVertex2fv(vertex[i]);
//		glEnd();
			for (int i = 0; i < VRTX_COUNT; i++)
				gluTessVertex(tess, dvertex[i], dvertex[i]);
		break;

		case 1:
			point[0][0] = -polar;
			point[0][1] = vertex[breakpoint[0]][1];
			point[0][2] = 0;
			point[1][0] = -polar;
			point[1][1] = polar;
			point[1][2] = 0;

			point[2][0] = polar;
			point[2][1] = polar;
			point[2][2] = 0;
			point[3][0] = polar;
			point[3][1] = vertex[breakpoint[0]][1];
			point[3][2] = 0;

			for (int i = 0; i < 4; i++)
				gluTessVertex(tess, point[i], point[i]);

			for (int i = breakpoint[0]; i < VRTX_COUNT; i++) {
				gluTessVertex(tess, dvertex[i], dvertex[i]);
			}

			for (int i = 0; i < breakpoint[0]; i++) {
				gluTessVertex(tess, dvertex[i], dvertex[i]);
			}

		break;

		case 2:
			if (vertex[breakpoint[0]][0] < 0) polar = -1;
			else polar = 1;
			point[0][0] = polar;
			point[0][1] = dvertex[breakpoint[0]][1];
			point[0][2] = 0;
			gluTessVertex(tess, point[0], point[0]);
			for (int i = breakpoint[0] + 1; i < breakpoint[1] - 1; i++)
				gluTessVertex(tess, dvertex[i], dvertex[i]);
			point[1][0] = polar;
			point[1][1] = vertex[breakpoint[1] - 1][1];
			point[1][2] = 0;
			gluTessVertex(tess, point[1], point[1]);
			gluTessEndContour(tess);
			gluTessBeginContour(tess);

			if (vertex[breakpoint[1]][0] < 0) polar = -1;
			else polar = 1;
			point[2][0] = polar;
			point[2][1] = dvertex[breakpoint[1]][1];
			point[2][2] = 0;
			gluTessVertex(tess, point[2], point[2]);
			point[3][0] = polar;
			point[3][1] = dvertex[breakpoint[0] - 1][1];
			point[3][2] = 0;
			point[4][0] = polar;
			point[4][1] = dvertex[VRTX_COUNT - 1][1];
			point[4][2] = 0;
				for (int i = breakpoint[1] + 1; i < VRTX_COUNT; i++)
					gluTessVertex(tess, dvertex[i], dvertex[i]);
				if (breakpoint[0] > 0) {
					for (int i = 0; i < breakpoint[0] - 1; i++)
						gluTessVertex(tess, dvertex[i], dvertex[i]);
					gluTessVertex(tess, point[3], point[3]);
				}
				else gluTessVertex(tess, point[4], point[4]);
		break;
	}
	gluTessEndContour(tess);
	gluTessEndPolygon(tess);
	gluDeleteTess(tess);
}

void compileZrl(Location *loc) {
	if (!(loc->isVisibleZrv() | loc->isVisibleLines())) return;

	double const deg2rad = M_PI/180;
	double z = loc->zrlRange()*deg2rad;
	double a1 = M_PI -loc->zrlAzimuth()*deg2rad;
	double a2 = loc->zrlWidth()*deg2rad;
	double b = -loc->latitude()*deg2rad;
	double l = loc->longitude()*deg2rad + M_PI;

	int cntRadius = VRTX_COUNT/4;
	int cntFront = VRTX_COUNT - 2*cntRadius;
	if (a2 >= 2*M_PI) {
		cntFront = VRTX_COUNT;
		cntRadius = 0;
	}

	double fiz = 0;
	for (int i = 0; i < cntRadius; i++) {
		double y0 = asin(cos(fiz)*sin(b) + sin(fiz)*cos(b)*cos(a1 - a2/2));
		double x0 = l + asin(sin(fiz)*sin(a1 - a2/2)/cos(y0));
		if ((cos(fiz) - sin(b)*sin(y0)) < 0 ) x0 = 2*l - x0 + M_PI;
		x0 = fmod(x0/M_PI + 4, 2) - 1;
		y0 = 2*y0/M_PI;
		vertex[i][0] = x0;
		vertex[i][1] = y0;
		fiz += z/cntRadius;
	}

	double a = a1 - a2/2;
	for (int i = 0; i < cntFront; i++) {
		double y0 = asin(cos(z)*sin(b) + sin(z)*cos(b)*cos(a));
		double x0 = l + asin(sin(z)*sin(a)/cos(y0));
		if ((cos(z) - sin(b)*sin(y0)) < 0 ) x0 = 2*l - x0 + M_PI;
		x0 = fmod(x0/M_PI + 4, 2) - 1;
		y0 = 2*y0/M_PI;
		vertex[i + cntRadius][0] = x0;
		vertex[i + cntRadius][1] = y0;
		a += a2/cntFront;
	}

	fiz = z;
	for (int i = 0; i < cntRadius; i++) {
		double y0 = asin(cos(fiz)*sin(b) + sin(fiz)*cos(b)*cos(a1 + a2/2));
		double x0 = l + asin(sin(fiz)*sin(a1 + a2/2)/cos(y0));
		if ((cos(fiz) - sin(b)*sin(y0)) < 0 ) x0 = 2*l - x0 + M_PI;
		x0 = fmod(x0/M_PI + 4, 2) - 1;
		y0 = 2*y0/M_PI;
		vertex[i + cntFront + cntRadius][0] = x0;
		vertex[i + cntFront + cntRadius][1] = y0;
		fiz -= z/cntRadius;
	}

	GLuint clr = loc->colorZrv();
	glColor4ubv((GLubyte *)&clr);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	if (loc->isVisibleZrv()) gluZone(loc->latitude()*M_PI/180.0);
	glDisable(GL_BLEND);
	if (loc->isVisibleLines()) {
		clr = loc->colorLines();
		glColor4ubv((GLubyte *)&clr);
	    glLineWidth(loc->linesWidth());
	    glZoneLines(loc->latitude()*M_PI/180.0);
	}
}

bool testShadow(Satellite *sat, Satellite *sun) {
	if ((sat == 0) || (sun == 0)) return true;
	double r_sat = sqrt(sat->xyz()[0]*sat->xyz()[0] + sat->xyz()[1]*sat->xyz()[1] + sat->xyz()[2]*sat->xyz()[2]);
	double r_sun = sqrt(sun->xyz()[0]*sun->xyz()[0] + sun->xyz()[1]*sun->xyz()[1] + sun->xyz()[2]*sun->xyz()[2]);
	if ((r_sat == 0) || (r_sun == 0) || (sat->radiusEarth() > r_sat)) return true;
	double f = asin(sat->radiusEarth()/r_sat);
	double l = M_PI - acos((sat->xyz()[0]*sun->xyz()[0] + sat->xyz()[1]*sun->xyz()[1] + sat->xyz()[2]*sun->xyz()[2])/(r_sat*r_sun));
	if ((-f < l) && (l < f)) return false;
	return true;
}
