/*
 * kepler model
 *
 *  Created on: 26.10.2009
 *      Author: Ivan T.
 */

#ifndef KEPMODEL_H_
#define KEPMODEL_H_

#include "../../satviewer/satutils/satellite.h"

class KepModel : public Satellite {
public:
    KepModel();
    virtual ~KepModel();
    int modelInit(int consttype, double jdsatepoch, double bstar, double inclo, double argpo,
                  double ecco, double nodeo, double mo, double no);
    int model(double time);

private:
    double inclo, nodeo, ecco, argpo, mo, ao, no;
    double gstime(double jdut1);
};
extern "C" KepModel *getSatModel() {
    puts("kepler model sat added");
    return new KepModel();
}

#endif /* KEPMODEL_H_ */
