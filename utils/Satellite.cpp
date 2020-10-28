// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "Satellite.h"

#include <QtMath>
#include <stdlib.h>
#include <string.h>

Satellite::Satellite(const QString &name) {
    m_name = name;
    m_satnum = 0;
    icon_name = "";
    zrv = 0.0;

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
    color_zrv = 0x408E9E80;
    color_lines = 0xFF45772D;
    color_track_shadow = 0xFF407464;

    _track = 0.5;
    satellite = true;
    location = false;
    m_track = nullptr;
    m_trackLla = nullptr;
    m_track_size = 0;
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

int Satellite::satnum() const {
    return m_satnum;
}

Satellite::~Satellite(void) {
    if (m_track != nullptr) {
        delete m_track;
    }
    if (m_trackLla != nullptr) {
        delete m_trackLla;
    }
    qWarning("satellite is removed");
}

/*
 * convert earth-centered earth-fixed (ECEF) cartesian coordinates to latitude, longitude, and
 * altitude
 */
void Satellite::ecef2lla(const double *ecef, double *lla) {
    double p, t, sint, cost, n, sinlat;
    // WGS-84 earth's semi major axis
    double const a_axis = 6378137.0;
    // WGS-84 earth's semi minor axis
    double const b_axis = 6356752.31;
    // first  numerical eccentricity
    double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    // second numerical eccentricity
    double const e2sqr = ((a_axis * a_axis - b_axis * b_axis) / (b_axis * b_axis));

    p = sqrt(ecef[0] * ecef[0] + ecef[1] * ecef[1]);
    t = atan(ecef[2] * a_axis / (p * b_axis));
    sint = sin(t);
    cost = cos(t);

    lla[0] = atan2(ecef[2] + e2sqr * b_axis * sint * sint * sint,
                   p - e1sqr * a_axis * cost * cost * cost);
    lla[1] = atan2(ecef[1], ecef[0]);

    lla[1] = fmod(lla[1] + 3.0 * M_PI, 2.0 * M_PI) - M_PI;
    if (lla[1] < -M_PI) {
        lla[1] += 2.0 * M_PI;
    }
    sinlat = sin(lla[0]);
    n = a_axis / sqrt(1.0 - e1sqr * sinlat * sinlat);
    lla[2] = p / cos(lla[0]) - n;
}

void Satellite::copy(Satellite *src) {

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
    m_name = name;
}

void Satellite::setEcef(double *ecef) {
    memcpy(m_ecef, ecef, sizeof(m_ecef) / sizeof(m_ecef[0]));
    ecef2lla(m_ecef, m_lla);
}

void Satellite::setEcef(double r0, double r1, double r2, double r3, double r4, double r5) {
    m_ecef[0] = r0;
    m_ecef[1] = r1;
    m_ecef[2] = r2;
    m_ecef[3] = r3;
    m_ecef[4] = r4;
    m_ecef[5] = r5;
    ecef2lla(m_ecef, m_lla);
}

void Satellite::setSatnum(int value) {
    m_satnum = value;
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

void Satellite::setTrackSize(size_t size) {
    if (size == m_track_size && m_track != nullptr) {
        // nothing
    } else if (m_track == nullptr) {
        m_track = new double[size * 6];
        m_trackLla = new double[size * 3];
        m_track_size = size;
    } else {
        delete m_track;
        m_track = new double[size * 6];
        m_trackLla = new double[size * 3];
        m_track_size = size;
    }
}

void Satellite::setTrackPoint(const double point[6], size_t index) {
    size_t indexLla = index * 3;
    index *= 6;
    m_track[index] = point[0];
    m_track[index + 1] = point[1];
    m_track[index + 2] = point[2];
    m_track[index + 3] = point[3];
    m_track[index + 4] = point[4];
    m_track[index + 5] = point[5];
    ecef2lla(&m_track[index], &m_trackLla[indexLla]);
}

const double *Satellite::trackPointLla(size_t index) {
    return &m_trackLla[index * 3];
}

const double *Satellite::trackPointEcef(size_t index) {
    return &m_track[index * 6];
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
