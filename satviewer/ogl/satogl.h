/*
 * satogl.h
 *
 *  Created on: 21.05.2009
 *      Author: Yan Coduemat
 */

#ifndef SATOGL_H_
#define SATOGL_H_

#include <inttypes.h>
#include "../zrvutils/ZrvIoList.h"

#define VRTX_COUNT 128
extern float vertex[VRTX_COUNT][2];

void initSatOgl();
void compileZRV(Satellite *sat, bool poly, bool lines, uint32_t colorPoly, uint32_t colorLines);
int testIOZRV(Satellite *sat, Location *loc, ZrvIoList *list, double &time);
void compileZrl(Location *loc);
//void glZone(float lat);
void gluZone(float lat);
void glZoneLines(float lat);
void glZoneNight(float lat);
bool testShadow(Satellite *sat, Satellite *sun);
#endif /* SATGLUTILS_H_ */
