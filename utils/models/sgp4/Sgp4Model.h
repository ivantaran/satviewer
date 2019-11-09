/*
 * Sgp.h
 *
 *  Created on: 26.10.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SGP4MODEL_H_
#define SGP4MODEL_H_

#include "../utils/Satellite.h"
#include "../utils/TleReader.h"
#include "SGP4.h"

class Sgp4Model : public Satellite {
public:
    Sgp4Model();
    static Sgp4Model *getSatModel();
    virtual ~Sgp4Model();
    bool modelInit(char *state, int size) override;
    bool model(double time) override;
    char *getState() override;
    int getStateSize() override;
    double gsto() override {
        return elset.gsto;
    };
    double minutes() override {
        return elset.t;
    };
    double eccentricity() const {
        return state.ecc;
    }
    double inclination() const {
        return state.incl;
    }
    double meanAnomaly() const {
        return state.m;
    }
    double meanMotion() override {
        return state.n;
    }
    double argLatPerigee() const {
        return state.argp;
    }
    double latAscNode() const {
        return state.node;
    }
    double bStar() const {
        return state.bstar;
    }
    double jEpoch() const {
        return state.jdsatepoch;
    }

private:
    elsetrec elset;
    TleReader::sgp4_t state;
};

#endif /* SGP4MODEL_H_ */
