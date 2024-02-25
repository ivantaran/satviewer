
#include "satellite.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

Satellite::Satellite(void) {
    _name = "";
    icon_name = "";
    zrv = 0.0;
    lon = 0.0;
    lat = 0.0;
    _altitude = 0.0;

    name_x = 0;
    name_y = 0;
    lines_width = 1;

    show_label = true;
    show_track = true;
    show_zrv = true;
    show_lines = true;
    active_zone = true;
    show_track_shadow = true;

    _color = 0x000000FF;
    color_track = 0xFF90B4A4;
    color_label = 0x00FFFF00;
    color_zrv = 0xFF8E9E80;
    color_lines = 0xFF45772D;
    color_track_shadow = 0xFF407464;

    _track = 0.5;
    satWObject = nullptr;
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
    if (satWObject != 0)
        delete satWObject;
    qWarning("satellite is removed");
}

void Satellite::makeGeod() {
    double p, T, sT, cT, N;
    double const WZ = 7.2921151467e-5;
    double const a_axis = 6378137.0;  // WGS-84 earth's semi major axis
    double const b_axis = 6356752.31; // WGS-84 earth's semi minor axis

    // first  numerical eccentricity
    double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    // second numerical eccentricity
    double const e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));

    p = sqrt(m_r[0] * m_r[0] + m_r[1] * m_r[1]);
    T = atan(m_r[2] * a_axis / (p * b_axis));
    sT = sin(T);
    cT = cos(T);

    lat = atan2(m_r[2] + e2sqr * b_axis * sT * sT * sT, p - e1sqr * a_axis * cT * cT * cT);
    lon = atan2(m_r[1], m_r[0]);

    lon -= WZ * minutes() * 60.0 + gsto();
    lon = fmod(lon + 3.0 * M_PI, 2.0 * M_PI) - M_PI;
    if (lon < -M_PI)
        lon += 2.0 * M_PI;

    N = a_axis / sqrt(1.0 - e1sqr * sin(lat) * sin(lat));
    _altitude = p / cos(lat) - N;
}

void Satellite::copy(Satellite *src) {

    modelInit(src->getState(), src->getStateSize());

    visibleLabel(src->isVisibleLabel());
    visibleLines(src->isVisibleLines());
    visibleTrack(src->isVisibleTrack());
    visibleZrv(src->isVisibleZrv());

    setColorLabel(src->colorLabel());
    setColorLines(src->colorLines());
    setColorTrack(src->colorTrack());
    setColorZrv(src->colorZrv());

    setFont(src->font());
    setTrack(src->track());
    setZrv(src->zrvWidth());

    setName(src->name());
    setNameX(src->nameX());
    setNameY(src->nameY());

    setLinesWidth(src->linesWidth());
    setIcon(src->iconName());
}

void Satellite::setName(QString name) {
    _name = name;
}

void Satellite::makeRg() {
    double const WZ = 7.2921151467e-5; // TODO
    double alpha = WZ * minutes() * 60.0 + gsto();
    m_rg[0] = cos(alpha) * m_r[0] + sin(alpha) * m_r[1];
    m_rg[1] = -sin(alpha) * m_r[0] + cos(alpha) * m_r[1];
    m_rg[2] = m_r[2];
    m_rg[3] = cos(alpha) * m_r[3] + sin(alpha) * m_r[4] + WZ * m_rg[1];
    m_rg[4] = -sin(alpha) * m_r[3] + cos(alpha) * m_r[4] - WZ * m_rg[0];
    m_rg[5] = m_r[5];
}

void Satellite::setZrv(double value) {
    if (value > M_PI_2) {
        value = M_PI_2;
    } else {
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
    if (value > 0)
        _track = value;
    else
        show_track = false;
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

const double Satellite::RadiusEarth = 6378137.0;