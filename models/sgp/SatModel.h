/*
 * Sgp.h
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
	int modelInit(int consttype, double jdsatepoch, double bstar, double inclo, double argpo, double ecco, double nodeo, double mo, double no);
	int model(double time);

private:
    int error;
    char method;
    double inclo, nodeo, ecco, argpo, mo, ao, no;
    /* Near Earth */
    int isimp;
    double aycof  , con41  , cc1    , cc4      , cc5    , d2      , d3   , d4 ,
        delmo  , eta    , argpdot, omgcof   , sinmao ,  t2cof, t3cof ,
        t4cof  , t5cof  , x1mth2 , x7thm1   , mdot   , nodedot, xlcof , xmcof ,
        nodecf;

    /* Deep Space */
    int irez;
    double d2201  , d2211  , d3210  , d3222    , d4410  , d4422   , d5220 , d5232 ,
         d5421  , d5433  , dedt   , del1     , del2   , del3    , didt  , dmdt  ,
         dnodt  , domdt  , e3     , ee2      , peo    , pgho    , pho   , pinco ,
         plo    , se2    , se3    , sgh2     , sgh3   , sgh4    , sh2   , sh3   ,
         si2    , si3    , sl2    , sl3      , sl4    , xfact , xgh2  ,
         xgh3   , xgh4   , xh2    , xh3      , xi2    , xi3     , xl2   , xl3   ,
         xl4    , xlamo  , zmol   , zmos     , atime  , xli     , xni;

	double con42, cosio, cosio2, eccsq, omeosq, posq, rp, rteosq, sinio;

    double
        cnodm , snodm , cosim , sinim , cosomm, sinomm, cc1sq ,
        cc2   , cc3   , coef  , coef1 , cosio4, day   , dndt  ,
        em    , emsq  , eeta  , etasq , gam   , argpm , nodem ,
        inclm , mm    , nm    , perige, pinvsq, psisq , qzms24,
        rtemsq, s1    , s2    , s3    , s4    , s5    , s6    ,
        s7    , sfour , ss1   , ss2   , ss3   , ss4   , ss5   ,
        ss6   , ss7   , sz1   , sz2   , sz3   , sz11  , sz12  ,
        sz13  , sz21  , sz22  , sz23  , sz31  , sz32  , sz33  ,
        tc    , temp  , temp1 , temp2 , temp3 , tsi   , xpidot,
        xhdot1, z1    , z2    , z3    , z11   , z12   , z13   ,
        z21   , z22   , z23   , z31   , z32   , z33,
        qzms2t, ss;

    double ep, xincp, nodep, argpp, mp;

	void initl(double epoch);
	double gstime(double jdut1);
	void dscom(double epoch);
	void dpper(char init, double ecc, double incl, double node,  double argp, double m);
	void dsinit();
	void dspace();
};
extern "C" SatModel *getSatModel() {
		puts("sgp model sat added");
		return new SatModel();
	}

#endif /* SATMODEL_H_ */

