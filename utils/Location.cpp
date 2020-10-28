// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * Location.cpp
 *
 *  Created on: 27.06.2009
 *      Author: Ivan Ryazanov
 */

#include "Location.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Location::Location(const QString &name, double latitude, double longitude, double altitude) {
    m_name = name;
    icon_name = "";

    icon_index = (uint32_t)-1;
    icon_width = 0;
    icon_height = 0;

    name_x = 0;
    name_y = 0;
    lines_width = 1;

    show_label = true;
    show_zrv = false;
    show_lines = false;
    active_zone = true;

    _color = 0x000000FF;
    color_label = 0x00FFFF00;
    color_zrv = 0xFF608080;
    color_lines = 0x0000FFFF;
    m_latitude = latitude;
    m_longitude = longitude;
    m_altitude = altitude;
    _zrlWidth = 0.0;
    _zrlAzimuth = 0.0;
    _zrlRange = 0.0;
    m_rg[0] = 0.0;
    m_rg[1] = 0.0;
    m_rg[2] = 0.0;
    m_rg[3] = 0.0;
    m_rg[4] = 0.0;
    m_rg[5] = 0.0;
}

Location::~Location(void) {
    qWarning("location is removed");
}

void Location::copy(Location *src) {
    setName(src->name());
    m_latitude = src->latitude();
    m_longitude = src->longitude();
    m_altitude = src->altitude();
    calcXYZ();

    visibleLabel(src->isVisibleLabel());
    visibleLines(src->isVisibleLines());
    visibleZrv(src->isVisibleZrv());

    setColorLabel(src->colorLabel());
    setColorLines(src->colorLines());
    setColorZrv(src->colorZrv());

    setFont(src->font());

    setNameX(src->nameX());
    setNameY(src->nameY());

    setLinesWidth(src->linesWidth());

    setZrlAzimuth(src->zrlAzimuth());
    setZrlRange(src->zrlRange());
    setZrlWidth(src->zrlWidth());
}

void Location::setName(const QString &name) {
    m_name = name;
}

void Location::calcXYZ() {
    // TODO this not valid
    double const a_axis = 6378137.0;  // WGS-84 earth's semi major axis
    double const b_axis = 6356752.31; // WGS-84 earth's semi minor axis
    double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    double N = a_axis /
               sqrt(1.0 - e1sqr * sin(m_latitude * M_PI / 180.0) * sin(m_latitude * M_PI / 180.0));
    // TODO
    m_rg[0] = (N + m_altitude) * cos(m_latitude * M_PI / 180.0) * cos(m_longitude * M_PI / 180.0);
    m_rg[1] = (N + m_altitude) * cos(m_latitude * M_PI / 180.0) * sin(m_longitude * M_PI / 180.0);
    m_rg[2] = (N * (1.0 - e1sqr) + m_altitude) * sin(m_latitude * M_PI / 180.0);
}

void Location::setLatitude(double latitude) {
    m_latitude = latitude;
    calcXYZ();
}

void Location::setLongitude(double longitude) {
    m_longitude = longitude;
    calcXYZ();
}

void Location::setAltitude(double height) {
    m_altitude = height;
    calcXYZ();
}

void Location::setIcon(const QString &name) {
    icon_name = name;
}

void Location::setFont(const QFont &font) {
    _font = font;
}

void Location::setNameX(double value) {
    name_x = value;
}

void Location::setNameY(double value) {
    name_y = value;
}

void Location::setLinesWidth(double value) {
    lines_width = value;
}
