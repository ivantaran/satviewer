/*
 *
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
    Satellite::modelInit(whichconst, _jdsatepoch, _bstar, _inclo, _argpo, _ecco,  _nodeo,  _mo,  _no);

	Satellite::getgravconst(whichconst);
	return 0;
}

int SatModel::model(double tsince) {
	double const deg2rad = M_PI/180;
											  //J1980 2444239.5
	double mean_ecl_lon = 278.833540*deg2rad; //on 1980 year epoch
	double eps 			= 23.441884*deg2rad;  //on 1980 year epoch
	double lon_per 		= 282.596403*deg2rad;
	double r0			= 1.495985e8;         //������� ������� ������ �����
	double ecc 			= 0.016718;
	double days 		= (tsince/86400.0 - 3652.0); //on 1980 year epoch

	gsto = gstime(tsince/86400.0 + 2440587.5);  //+ J1970


	double m = (2*M_PI/365.2422)*days + mean_ecl_lon - lon_per;

	double e = 0;
	double e0 = 1;
	while (fabs(e0 -e) > 1e-10) {
		e0 = e;
		e = m + ecc*sin(e0);
	}
	double v = 2.0*atan(sqrt((1 + ecc)/(1 - ecc))*tan(e/2.0));

	double lon = v + lon_per;
	lon = fmod(lon, 2*M_PI);

	double radius = r0*(1 - ecc*ecc)/(1 + ecc*cos(v));
	r[0] = radius*cos(lon);
	r[1] = radius*cos(eps)*sin(lon);
	r[2] = radius*sin(eps)*sin(lon);
	//printf("x %f; y %f; z %f\n", r[0]/1000.0, r[1]/1000.0, r[2]/1000.0);

   Satellite::getGeod();
   return 0;
}  // end sun

double SatModel::gstime(double jdut1) {

    const double deg2rad = PI/180.0;
    double tut1, temp;

    tut1 = (jdut1 - 2451545.0) / 36525.0;
    temp = -6.2e-6*tut1*tut1*tut1 + 0.093104*tut1*tut1 + (876600.0*3600 + 8640184.812866)*tut1 + 67310.54841;  // sec
    temp = fmod(temp*deg2rad/240.0, twopi); //360/86400 = 1/240, to deg, to rad

    // ------------------------ check quadrants ---------------------
    if (temp < 0.0) temp += twopi;

    return temp;
}  // end gstime

