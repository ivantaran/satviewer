/*
 * crd.cpp
 *
 *  Created on: 03.09.2009
 *      Author: Yan Coduemat
 */

#include "crd.h"
#include "math.h"

inline double sqr(double x) {return x*x;}

void getaer(double xyzLoc[], double xyzSat[], double &elv, double &azm, double &range)
{
	double p = sqrt(xyzLoc[0]*xyzLoc[0] + xyzLoc[1]*xyzLoc[1]);
	double r = sqrt(xyzLoc[0]*xyzLoc[0] + xyzLoc[1]*xyzLoc[1] + xyzLoc[2]*xyzLoc[2]);
	range = sqrt(sqr(xyzLoc[0] - xyzSat[0]) + sqr(xyzLoc[1] - xyzSat[1]) + sqr(xyzLoc[2] - xyzSat[2]));

	double m[3][3];
	m[0][0] = -xyzLoc[1]/p;
	m[0][1] = xyzLoc[0]/p;
	m[0][2] = 0.0;
	m[1][0] = -(xyzLoc[0]*xyzLoc[2]/(p*r));
	m[1][1] = -(xyzLoc[1]*xyzLoc[2]/(p*r));
	m[1][2] = p/r;
	m[2][0] = xyzLoc[0]/r;
	m[2][1] = xyzLoc[1]/r;
	m[2][2] = xyzLoc[2]/r;

	double d[3] = {0, 0, 0};
	for (int j = 0; j < 3; j++)
		for (int i = 0; i < 3; i++) d[j] += (xyzSat[i] - xyzLoc[i])*m[j][i];

	double s = d[2]/sqrt(d[0]*d[0] + d[1]*d[1] + d[2]*d[2]);

	if (s == 1) elv = 0.5*M_PI; else elv = atan(s/sqrt(1 - s*s));

	if (d[1] == 0) {
		if (d[0] > 0) azm = 0.5*M_PI; else azm = 1.5*M_PI;
		return;
	}
	azm = atan(d[0]/d[1]);
	if (d[1] < 0) azm += M_PI;
	else if ((d[0] < 0)) azm += 2.0*M_PI;
}

