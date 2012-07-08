/*
 * sun model
 *
 *  Created on: 26.10.2009
 *      Author: Yan Coduemat
 */

#ifndef SATMODEL_H_
#define SATMODEL_H_

#include "../../satviewer/satutils/Satellite.h"

class SatModel : public Satellite {
public:
	SatModel();
	virtual ~SatModel();
	int modelInit(int consttype, double jdsatepoch, double, double, double, double, double, double, double);
	int model(double time);

private:
    double inclo, nodeo, ecco, argpo, mo, ao, no;
    double gstime(double jdut1);
};
extern "C" SatModel *getSatModel() {
		puts("sun1980 model added");
		return new SatModel();
	}

#endif /* SATMODEL_H_ */

