// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Satellite.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>


Satellite::Satellite(void) {
    _name = "";
    icon_name = "";
    zrv = 0.0;
    lon = 0.0;
    lat = 0.0;
    _height = 0.0;
    
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
    color_label = 0x00FFFF00;
    color_zrv   = 0xFF8E9E80;
    color_lines = 0xFF45772D;
    color_track_shadow = 0xFF407464;

    _track = 0.5;
    satWObject = NULL;
    satellite = true;
    location = false;
    radius_earth = 0.0;
}

void Satellite::setLocation(bool value) {
    location = value;
}

bool Satellite::isLocation() const {
    return location;
}

void Satellite::setSatellite(bool value) {
    satellite = value;
}

bool Satellite::isSatellite() const {
    return satellite;
}

Satellite::~Satellite(void) {
    if (satWObject != 0) delete satWObject;
    qWarning("satellite is removed");
}

void Satellite::getGeod() {
    double p, T, sT, cT, N;
    double const WZ = 7.2921151467e-5;
    double const a_axis = 6378137.0;   //WGS-84 earth's semi major axis
    double const b_axis = 6356752.31;  //WGS-84 earth's semi minor axis

    //first  numerical eccentricity
    double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    //second numerical eccentricity
    double const e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));

    p = sqrt(r[0] * r[0] + r[1] * r[1]);
    T = atan(r[2] * a_axis / (p * b_axis));
    sT = sin(T);
    cT = cos(T);
  
    lat = atan2(r[2] + e2sqr * b_axis * sT * sT * sT, p - e1sqr * a_axis * cT * cT * cT);
    lon = atan2(r[1], r[0]);

    lon -= WZ * minutes() * 60 + gsto();
    lon = fmod(lon + 3.0 * M_PI, 2.0 * M_PI) - M_PI;
    if (lon < -M_PI) lon += 2.0 * M_PI;

    N = a_axis / sqrt(1.0 - e1sqr * sin(lat) * sin(lat));
    _height = p / cos(lat) - N;
}

void Satellite::copy(Satellite *src) {

    modelInit(src->getState(), src->getStateSize());
    
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
    setZrv  (src->zrvWidth());

    setName (src->name ());
    setNameX(src->nameX());
    setNameY(src->nameY());

    setLinesWidth(src->linesWidth());
    setIcon(src->iconName());
}

void Satellite::setName(QString name) {
    _name = name;
}

double* Satellite::xyz_g() {
    double const WZ = 7.2921151467e-5;
    double alpha = WZ * minutes() * 60 + gsto();
    r_g[0] =  cos(alpha) * r[0] + sin(alpha) * r[1];
    r_g[1] = -sin(alpha) * r[0] + cos(alpha) * r[1];
    r_g[2] =  r[2];
    return r_g;
}

double* Satellite::vxyz_g() {
    double const WZ = 7.2921151467e-5;
    double alpha = WZ * minutes() * 60 + gsto();
    xyz_g();
    v_g[0] =  cos(alpha) * v[0] + sin(alpha) * v[1] + WZ * r_g[1];
    v_g[1] = -sin(alpha) * v[0] + cos(alpha) * v[1] - WZ * r_g[0];
    v_g[2] =  v[2];
    return v_g;
}

void Satellite::setZrv(double value) {
    if (value > M_PI_2) {
        value = M_PI_2;
    }
    else {
        if (value < 0.0) {
            value = 0.0;
        }
    }
    zrv = value;
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
