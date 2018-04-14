// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * Sgp.cpp
 *
 *  Created on: 26.10.2009
 *      Author: Ivan Ryazanov
 */

#include "Sgp4Model.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

Sgp4Model *Sgp4Model::getSatModel() {
    qWarning("sgp model sat added");
    return new Sgp4Model();
}

Sgp4Model::Sgp4Model() {
    double tmp;
    SGP4Funcs::getgravconst(gravconsttype::wgs84, tmp, tmp, radius_earth, tmp, 
            tmp, tmp, tmp, tmp);
    radius_earth *= 1000.0;
}

Sgp4Model::~Sgp4Model() {

}

char * Sgp4Model::getState() {
    return (char *)&state;
}

int Sgp4Model::getStateSize() {
    return sizeof(state);
}

bool Sgp4Model::modelInit(char *state, int size) {
    bool result;
    
    if (size != sizeof(TleReader::sgp4_t)) {
        qWarning("%s: size %d != %d", __func__, size, 
                (int)sizeof(TleReader::sgp4_t));
        return -1;
    }
    
    TleReader::sgp4_t *s = (TleReader::sgp4_t *)state;

    this->state.argp        = s->argp;
    this->state.bstar       = s->bstar;
    this->state.ecc         = s->ecc;
    this->state.incl        = s->incl;
    this->state.jdsatepoch  = s->jdsatepoch;
    this->state.m           = s->m;
    this->state.n           = s->n;
    this->state.node        = s->node;

    result = SGP4Funcs::sgp4init(gravconsttype::wgs84, 'i', 0, 
        this->state.jdsatepoch, 
        this->state.bstar, 0.0, 0.0, // TODO const double xndot, const double xnddot
        this->state.ecc, 
        this->state.argp, 
        this->state.incl, 
        this->state.m, 
        this->state.n, 
        this->state.node, 
        elset
    );
        
    return result;
}

bool Sgp4Model::model(double time) {
    bool result;

    time = (2440587.5 - state.jdsatepoch + time / 86400.0) * 1440.0;
    result = SGP4Funcs::sgp4(elset, time, r, v);
    
    r[0] *= 1000.0;
    r[1] *= 1000.0;
    r[2] *= 1000.0;
    
    v[0] *= 1000.0;
    v[1] *= 1000.0;
    v[2] *= 1000.0;

    getGeod();

    return result; 
}
