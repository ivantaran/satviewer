/*
 * Sgp.cpp
 *
 *  Created on: 26.10.2009
 *      Author: Yan Coduemat
 */

#include "SatModel.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MUE 3.98602e14
#define KSI 2.63410e25
#define twopi (2.0*PI)

inline double sqr(double __x) {return __x*__x;}

SatModel::SatModel() {
	// TODO Auto-generated constructor stub

}

SatModel::~SatModel() {
	// TODO Auto-generated destructor stub
}

int SatModel::modelInit(int whichconst, double _jdsatepoch, double _bstar, double _inclo, double _argpo, double _ecco, double _nodeo, double _mo, double _no) {
	ecco       = _ecco;
	argpo      = _argpo;
	inclo      = _inclo;
	mo	       = _mo;
	no	       = _no;
	nodeo      = _nodeo;
    gsto = gstime(_jdsatepoch);  // epoch - J1950
    Satellite::modelInit(whichconst, _jdsatepoch, _bstar, _inclo, _argpo, _ecco, _nodeo, _mo, _no);

	Satellite::getgravconst(whichconst);
	return 0;
}

int SatModel::model(double tsince) {
	//omg - 0, i - 1, w - 2, a - 3, e - 4, tau - 5 2*M_PI*
	if (ecco >= 1 && ecco < 0) return 1;
	double n = no/60.0;
	//double tau = -mo/(n);
    double a = pow(sqr(n)/MUE , -(1.0/3.0));
	double const jd1970 = 2440587.5;
	t = (jd1970 - jdsatepoch + tsince/86400.0)*1440.0;
//	double Mo = sqrt(MUE/pow(a, 3))*(t - tau);
	double Mo = n*t*60 + mo;

	double E = 0;
	double Eo = 1;
	while (fabs(Eo - E) > 1E-10) {
		Eo = E;
		E = Mo + ecco*sin(Eo);
	}

	double v = 2.0*atan(sqrt((1 + ecco)/(1 - ecco))*tan(E/2.0));
	double dn = 60*t*n/(2*PI);
	double dl = dn*(-2*PI*KSI*cos(inclo)/(MUE*sqr(a)*sqr(1 - sqr(ecco))));
	double dw = dn*(PI*KSI*(5*sqr(cos(inclo)) - 1)/(MUE*sqr(a)*sqr(1 - sqr(ecco))));

	double u = argpo + v + dw;
	double omg = nodeo + dl;
	double p = a*(1 - ecco*ecco);
	double raduis = p/(1 + ecco*cos(v));
	double Vv = sqrt(MUE/p)*(1 + ecco*cos(v));
	double Vr = sqrt(MUE/p)*ecco*sin(v);

	this->r[0] = raduis*(cos(omg)*cos(u) - sin(omg)*sin(u)*cos(inclo));
	this->r[1] = raduis*(sin(omg)*cos(u) + cos(omg)*sin(u)*cos(inclo));
	this->r[2] = raduis*sin(u)*sin(inclo);

	this->v[0] = Vr*(cos(omg)*cos(u) - sin(omg)*sin(u)*cos(inclo)) - Vv*(cos(omg)*sin(u) + sin(omg)*cos(u)*cos(inclo));
	this->v[1] = Vr*(sin(omg)*cos(u) + cos(omg)*sin(u)*cos(inclo)) - Vv*(sin(omg)*sin(u) - cos(omg)*cos(u)*cos(inclo));
	this->v[2] = Vr*sin(u)*sin(inclo) + Vv*cos(u)*sin(inclo);
   Satellite::getGeod();
 return 0;
}  // end kepler

double SatModel::gstime(double jdut1) {

    const double deg2rad = PI/180.0;
    double tut1, temp;
					//J2000???
    tut1 = (jdut1 - 2451545.0) / 36525.0;
    temp = -6.2e-6*tut1*tut1*tut1 + 0.093104*tut1*tut1 + (876600.0*3600 + 8640184.812866)*tut1 + 67310.54841;  // sec
    temp = fmod(temp*deg2rad/240.0, twopi); //360/86400 = 1/240, to deg, to rad

    // ------------------------ check quadrants ---------------------
    if (temp < 0.0) temp += twopi;

    return temp;
}  // end gstime

