/*
 * Location.cpp
 *
 *  Created on: 27.06.2009
 *      Author: Yan Coduemat
 */

#include "Location.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


Location::Location(void) {
    _name = "";
    icon_name = "";

    icon_index = (uint32_t) -1;
    icon_width = 0;
    icon_height = 0;

    name_x = 0;
    name_y = 0;
    lines_width = 1;

    show_label  = true;
    show_zrv    = false;
    show_lines  = false;
    active_zone = true;

    _color      = 0x000000FF;
    color_label = 0x0000FFFF;
    color_zrv   = 0xFF608080;
    color_lines = 0x0000FFFF;
    satWObject = 0;
}

Location::~Location(void) {
	puts("location is removed");
}

void Location::copy(Location *src) {
	setName(src->name());
	lat = src->latitude();
	lon = src->longitude();
	_height = src->height();
	calcXYZ();

	visibleLabel( src->isVisibleLabel() );
	visibleLines( src->isVisibleLines() );
	visibleZrv  ( src->isVisibleZrv()   );

	setColorLabel( src->colorLabel() );
	setColorLines( src->colorLines() );
	setColorZrv  ( src->colorZrv()   );

	setFont( src->font() );

	setNameX( src->nameX() );
	setNameY( src->nameY() );

	setLinesWidth( src->linesWidth() );

	setZrlAzimuth( src->zrlAzimuth() );
	setZrlRange  ( src->zrlRange()   );
	setZrlWidth  ( src->zrlWidth()   );
}

void Location::setName(QString name) {
	_name = name;
}

void Location::calcXYZ() {
	//this not valid
	double const a_axis = 6378137.0;   //WGS-84 earth's semi major axis
	double const b_axis = 6356752.31;  //WGS-84 earth's semi minor axis
	double const e1sqr = ((a_axis * a_axis - b_axis * b_axis) / (a_axis * a_axis));
    double N = a_axis / sqrt(1.0 - e1sqr * sin(lat*M_PI/180.0) * sin(lat*M_PI/180.0));

	r[0] = (N + _height)*cos(lat*M_PI/180.0)*cos(lon*M_PI/180.0);
	r[1] = (N + _height)*cos(lat*M_PI/180.0)*sin(lon*M_PI/180.0);
	r[2] = (N*(1.0 - e1sqr) + _height)*sin(lat*M_PI/180.0);
}

void Location::setLatitude(double latitude) {
	lat = latitude;
	calcXYZ();
}

void Location::setLongitude(double longitude) {
	lon = longitude;
	calcXYZ();
}

void Location::setHeight(double height) {
	_height = height;
	calcXYZ();
}

void Location::setIcon(QString name) {
    icon_name = name;
}

void Location::setFont(QFont font) {
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
