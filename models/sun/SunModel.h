/*
 * sun model
 *
 *  Created on: 26.10.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SUNMODEL_H_
#define SUNMODEL_H_

#include "../../satviewer/satutils/Satellite.h"

class SunModel : public Satellite {
public:
	SunModel();
	virtual ~SatModel();
	int modelInit(int consttype, double jdsatepoch, double, double, double, double, double, double, double);
	int model(double time);

private:
    double inclo, nodeo, ecco, argpo, mo, ao, no;
    double gstime(double jdut1);
};
extern "C" SunModel *getSatModel() {
		puts("sun1980 model added");
		return new SunModel();
	}

#endif /* SATMODEL_H_ */

