#include "Satellite.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define temp4 1.0 + cos(PI-1.0e-9)
#define twopi 2.0*PI
#define x2o3 2.0/3.0


Satellite::Satellite(void) {
    _name = "";
    icon_name = "";
    zrv = 0.0;

    name_x = 0;
    name_y = 0;
    lines_width = 1;

    show_label  = true;
    show_track  = true;
    show_zrv    = true;
    show_lines  = true;
    active_zone = true;
    show_track_shadow = true;

    _color      = 0x000000FF;
    color_track = 0xFF90B4A4;
    color_label = 0x0000FFFF;
    color_zrv   = 0xFF8E9E80;
    color_lines = 0xFF45772D;
    color_track_shadow = 0xFF407464;

    _track = 0.5;
    model_index = 0;
    satWObject = 0;
}

Satellite::~Satellite(void)
{
    if (satWObject != 0) delete satWObject;
    puts("satellite is removed");
}

void Satellite::getgravconst(int whichconst) {

    switch (whichconst) {
    // -- wgs-72 low precision str#3 constants --
        case WGS72OLD:
            mu     = 398600.79964;        // in km3 / s2
            radius_earth_km = 6378.135;     // km
            radius_earth = 6378135.0;    //m
            xke    = 0.0743669161;
            tumin  = 1.0 / xke;
            j2     =   0.001082616;
            j3     =  -0.00000253881;
            j4     =  -0.00000165597;
            j3oj2  =  j3 / j2;
        break;
    // ------------ wgs-72 constants ------------
        case WGS72:
            mu     = 398600.8;            // in km3 / s2
            radius_earth_km = 6378.135;     // km
            radius_earth = 6378135.0;     // m
            xke    = 60.0 / sqrt(radius_earth_km*radius_earth_km*radius_earth_km/mu);
            tumin  = 1.0 / xke;
            j2     =   0.001082616;
            j3     =  -0.00000253881;
            j4     =  -0.00000165597;
            j3oj2  =  j3 / j2;
        break;
        // ------------ wgs-84 constants ------------
        case WGS84: default:

            mu     = 398600.5;            // in km3 / s2
            radius_earth_km = 6378.137;     // km
            radius_earth = 6378137.0;     // m
            xke    = 60.0 / sqrt(radius_earth_km*radius_earth_km*radius_earth_km/mu);
            tumin  = 1.0 / xke;
            j2     =   0.00108262998905;
            j3     =  -0.00000253215306;
            j4     =  -0.00000161098761;
            j3oj2  =  j3 / j2;
        break;
    }

}

void Satellite::getGeod() {
  	double p, T, sT, cT, N;
	double const WZ = 7.2921151467e-5;
	double const a_axis = 6378137.0;   //WGS-84 earth's semi major axis
	double const b_axis = 6356752.31;  //WGS-84 earth's semi minor axis
	//double const deg2rad = M_PI/180;
	//first  numerical eccentricity
	double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
	//second numerical eccentricity
	double const e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));

  	p = sqrt(r[0] * r[0] + r[1] * r[1]);
  	T = atan(r[2] * a_axis / (p * b_axis));
  	sT = sin(T);
  	cT = cos(T);
  	lat = atan((r[2] + e2sqr * b_axis * sT * sT * sT) / (p - e1sqr * a_axis * cT * cT * cT));
  	if (r[0] == 0.0)
    		lon = PI / 2.0;
  	else
    		lon = atan(r[1] / r[0]);

  	if (r[0] < 0 && r[1] > 0) lon += M_PI;
    if (r[0] < 0 && r[1] < 0) lon -= M_PI;

    lon += -WZ*t*60 - gsto;
    lon = fmod(lon + 3*PI, twopi) - PI;
    if (lon < -PI) lon += 2*PI;

    N = a_axis / sqrt(1.0 - e1sqr * sin(lat) * sin(lat));
  	_height = p / cos(lat) - N;
}

void Satellite::copy(Satellite *src) {
    modelInit(WGS84, src->jdsatepoch, src->bstar, src->incl0, src->argp0, src->ecc0, src->node0, src->m0, src->n0);

    visibleLabel(src->isVisibleLabel());
    visibleLines(src->isVisibleLines());
    visibleTrack(src->isVisibleTrack());
    visibleZrv  (src->isVisibleZrv  ());

    setColorLabel(src->colorLabel());
    setColorLines(src->colorLines());
    setColorTrack(src->colorTrack());
    setColorZrv  (src->colorZrv  ());

    setFont (src->font    ());
    setTrack(src->track   ());
    setZRV  (src->zrvWidth());

    setName (src->name ());
    setNameX(src->nameX());
    setNameY(src->nameY());

    setLinesWidth(src->linesWidth());
    setIcon(src->iconName());
    setModelIndex(src->modelIndex());
}

void Satellite::setName(QString name) {
    _name = name;
}

double* Satellite::xyz_g() {
    double const WZ = 7.2921151467e-5;
    double alpha = WZ*t*60 + gsto;
    r_g[0] =  cos(alpha)*r[0] + sin(alpha)*r[1];
    r_g[1] = -sin(alpha)*r[0] + cos(alpha)*r[1];
    r_g[2] =  r[2];
    return r_g;
}

double* Satellite::vxyz_g() {
    double const WZ = 7.2921151467e-5;
    double alpha = WZ*t*60 + gsto;
    xyz_g();
    v_g[0] =  cos(alpha)*v[0] + sin(alpha)*v[1] + WZ*r_g[1];
    v_g[1] = -sin(alpha)*v[0] + cos(alpha)*v[1] - WZ*r_g[0];
    v_g[2] =  v[2];
    return v_g;
}

void Satellite::setZRV(double value) {
    if (value > 0.5*PI) value = 0.5*PI;
    else if (value < 0) value = 0;
    this->zrv = value;
}

void Satellite::setIcon(QString name) {
    icon_name = name;
}

void Satellite::setFont(QFont font) {
    _font = font;
}

void Satellite::setTrack(double value) {
    if (value > 0) _track = value;
    else show_track = false;
}

void Satellite::setNameX(double value) {
    name_x = value;
}

void Satellite::setNameY(double value) {
    name_y = value;
}

void Satellite::setLinesWidth(double value) {
	lines_width = value;
}
