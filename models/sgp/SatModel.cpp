/*
 * Sgp.cpp
 *
 *  Created on: 26.10.2009
 *      Author: Yan Coduemat
 */

#include "SatModel.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define temp4 1.0 + cos(PI-1.0e-9)
#define twopi 2.0*PI
#define x2o3 2.0/3.0


SatModel::SatModel() {

}

SatModel::~SatModel() {

}

int SatModel::modelInit(int whichconst, double _jdsatepoch, double _bstar, double _inclo, double _argpo, double _ecco, double _nodeo, double _mo, double _no) {
	/* ------------------------ initialization --------------------- */
	/* ----------- set all near earth variables to zero ------------ */
	isimp   = 0;   method = 'n'; aycof    = 0.0;
	con41   = 0.0; cc1    = 0.0; cc4      = 0.0;
	cc5     = 0.0; d2     = 0.0; d3       = 0.0;
	d4      = 0.0; delmo  = 0.0; eta      = 0.0;
	argpdot = 0.0; omgcof = 0.0; sinmao   = 0.0;
	t       = 0.0; t2cof  = 0.0; t3cof    = 0.0;
	t4cof   = 0.0; t5cof  = 0.0; x1mth2   = 0.0;
	x7thm1  = 0.0; mdot   = 0.0; nodedot  = 0.0;
	xlcof   = 0.0; xmcof  = 0.0; nodecf   = 0.0;

	/* ----------- set all deep space variables to zero ------------ */
	irez  = 0;   d2201 = 0.0; d2211 = 0.0;
	d3210 = 0.0; d3222 = 0.0; d4410 = 0.0;
	d4422 = 0.0; d5220 = 0.0; d5232 = 0.0;
	d5421 = 0.0; d5433 = 0.0; dedt  = 0.0;
	del1  = 0.0; del2  = 0.0; del3  = 0.0;
	didt  = 0.0; dmdt  = 0.0; dnodt = 0.0;
	domdt = 0.0; e3    = 0.0; ee2   = 0.0;
	peo   = 0.0; pgho  = 0.0; pho   = 0.0;
	pinco = 0.0; plo   = 0.0; se2   = 0.0;
	se3   = 0.0; sgh2  = 0.0; sgh3  = 0.0;
	sgh4  = 0.0; sh2   = 0.0; sh3   = 0.0;
	si2   = 0.0; si3   = 0.0; sl2   = 0.0;
	sl3   = 0.0; sl4   = 0.0; gsto  = 0.0;
	xfact = 0.0; xgh2  = 0.0; xgh3  = 0.0;
	xgh4  = 0.0; xh2   = 0.0; xh3   = 0.0;
	xi2   = 0.0; xi3   = 0.0; xl2   = 0.0;
	xl3   = 0.0; xl4   = 0.0; xlamo = 0.0;
	zmol  = 0.0; zmos  = 0.0; atime = 0.0;
	xli   = 0.0; xni   = 0.0;

	// sgp4fix - note the following variables are also passed directly via satrec.
	// it is possible to streamline the sgp4init call by deleting the "x"
	// variables, but the user would need to set the satrec.* values first. we
	// include the additional assignments in case twoline2rv is not used.
	ecco       = _ecco;
	argpo      = _argpo;
	inclo      = _inclo;
	mo	       = _mo;
	no	       = _no;
	nodeo      = _nodeo;
	Satellite::modelInit( whichconst, _jdsatepoch, _bstar, _inclo, _argpo, _ecco,  _nodeo,  _mo,  _no);

	/* ------------------------ earth constants ----------------------- */
	// sgp4fix identify constants and allow alternate values
	Satellite::getgravconst(whichconst);
	ss     = 78.0 / radius_earth_km + 1.0;
	qzms2t = pow(((120.0 - 78.0) / radius_earth_km), 4);

//        init = 'y';
	t = 0.0;
	initl(jdsatepoch);
	error = 0;

	if (rp < 1.0) error = 5;

	if ((omeosq >= 0.0 ) || ( no >= 0.0)) {
		isimp = 0;
		if (rp < (220.0/radius_earth_km + 1.0)) isimp = 1;
		sfour  = ss;
		qzms24 = qzms2t;
		perige = (rp - 1.0)*radius_earth_km;

		/* - for perigees below 156 km, s and qoms2t are altered - */
		if (perige < 156.0) {
			sfour = perige - 78.0;
			if (perige < 98.0) sfour = 20.0;
			qzms24 = pow(((120.0 - sfour)/radius_earth_km), 4.0);
			sfour  = sfour/radius_earth_km + 1.0;
		}
		pinvsq = 1.0 / posq;

		tsi  = 1.0/(ao - sfour);
		eta  = ao*ecco*tsi;
		etasq = eta*eta;
		eeta  = ecco*eta;
		psisq = fabs(1.0 - etasq);
		coef  = qzms24*pow(tsi, 4.0);
		coef1 = coef/pow(psisq, 3.5);
		cc2   = coef1*no*(ao*(1.0 + 1.5*etasq + eeta*(4.0 + etasq)) +
				0.375*j2*tsi/psisq*con41*(8.0 + 3.0*etasq*(8.0 + etasq)));
		cc1   = bstar*cc2;
		cc3   = 0.0;
		if (ecco > 1.0e-4) cc3 = -2.0*coef*tsi*j3oj2*no*sinio/ecco;
		x1mth2 = 1.0 - cosio2;
		cc4 = 2.0*no*coef1*ao*omeosq*(eta*(2.0 + 0.5*etasq) + ecco*(0.5 + 2.0*etasq) - j2*tsi/(ao*psisq)*(-3.0*con41*(1.0 - 2.0*eeta + etasq*(1.5 - 0.5*eeta)) + 0.75*x1mth2*(2.0*etasq - eeta*(1.0 + etasq))*cos(2.0*argpo)));
		cc5 = 2.0*coef1*ao*omeosq*(1.0 + 2.75*(etasq + eeta) + eeta*etasq);
		cosio4 = cosio2*cosio2;
		temp1 = 1.5*j2*pinvsq*no;
		temp2 = 0.5*temp1*j2*pinvsq;
		temp3 = -0.46875*j4*pinvsq*pinvsq*no;
		mdot = no + 0.5*temp1*rteosq*con41 +
			   0.0625*temp2*rteosq*(13.0 - 78.0*cosio2 + 137.0*cosio4);
		argpdot  = -0.5*temp1*con42 + 0.0625*temp2*(7.0 - 114.0*cosio2 + 395.0*cosio4) +
				   temp3*(3.0 - 36.0*cosio2 + 49.0*cosio4);
		xhdot1 = -temp1*cosio;
		nodedot = xhdot1 + (0.5*temp2*(4.0 - 19.0*cosio2) +
				  2.0*temp3*(3.0 - 7.0*cosio2))*cosio;
		xpidot = argpdot + nodedot;
		omgcof = bstar*cc3*cos(argpo);
		xmcof = 0.0;
		if (ecco > 1.0e-4) xmcof = -x2o3*coef*bstar/eeta;
		nodecf = 3.5*omeosq*xhdot1*cc1;
		t2cof   = 1.5*cc1;
		// sgp4fix for divide by zero with xinco = 180 deg
		if (fabs(cosio+1.0) > 1.5e-12) xlcof = -0.25*j3oj2*sinio*(3.0 + 5.0*cosio)/(1.0 + cosio);
		else xlcof = -0.25*j3oj2*sinio*(3.0 + 5.0*cosio)/temp4;
		aycof = -0.5*j3oj2*sinio;
		delmo = pow((1.0 + eta*cos(mo)), 3);
		sinmao = sin(mo);
		x7thm1 = 7.0*cosio2 - 1.0;


		/* --------------- deep space initialization ------------- */
		if ((2*PI/no) >= 225.0) {
			method = 'd';
			isimp  = 1;
			tc    =  0.0;
			inclm = inclo;

			dscom(jdsatepoch);
			dpper('y', ecco, inclo, nodeo, argpo, mo);

			argpm  = 0.0;
			nodem  = 0.0;
			mm     = 0.0;

			dsinit();
		}
		/* ----------- set variables if not deep space ----------- */
		if (isimp != 1) {
		   cc1sq          = cc1 * cc1;
		   d2    = 4.0 * ao * tsi * cc1sq;
		   temp           = d2 * tsi * cc1 / 3.0;
		   d3    = (17.0 * ao + sfour) * temp;
		   d4    = 0.5 * temp * ao * tsi * (221.0 * ao + 31.0 * sfour) *
							cc1;
		   t3cof = d2 + 2.0 * cc1sq;
		   t4cof = 0.25 * (3.0 * d3 + cc1 *
							(12.0 * d2 + 10.0 * cc1sq));
		   t5cof = 0.2 * (3.0 * d4 +
							12.0 * cc1 * d3 +
							6.0 * d2 * d2 +
							15.0 * cc1sq * (2.0 * d2 + cc1sq));
		}
	} // if omeosq = 0 ...
	/* finally propogate to zero epoch to initialise all others. */
	if (error == 0) model(0.0);
//        init = 'n';

	return error;
}

int SatModel::model(double tsince) {

	double am   , axnl  , aynl , betal ,  cnod  ,
     cos2u, coseo1 = 0.0, cosi , cosip ,  cosisq, cossu , cosu,
     delm , delomg, ecose , el2   , eo1 ,
     esine, argpdf, pl,     mrt = 0.0,
     mvt  , rdotl , rl   , rvdot ,  rvdotl,
     sin2u, sineo1 = 0.0, sini , sinip ,  sinsu , sinu  ,
     snod , su    , t2   , t3    ,  t4    , tem5  ,
     tempa, tempe ,  templ , u     , ux  ,
     uy   , uz    , vx   , vy    ,  vz    , xinc  , xl  , xlm   ,
     xmdf , xmx   , xmy  , nodedf, xnode ,
     vkmpersec;
	int ktr;

 /* ------------------ set mathematical constants --------------- */
//     getgravconst(whichconst);
	vkmpersec     = radius_earth_km * xke/60.0;

 /* --------------------- clear sgp4 error flag ----------------- */
	error = 0;

	double const jd1970 = 2440587.5;
	t = (jd1970 - jdsatepoch + tsince/86400.0)*1440;
	//t = tsince/60.0; //sec's to min's

 /* ------- update for secular gravity and atmospheric drag ----- */
 xmdf    = mo + mdot * t;
 argpdf  = argpo + argpdot * t;
 nodedf  = nodeo + nodedot * t;
 argpm   = argpdf;
 mm      = xmdf;
 t2      = t * t;
 nodem   = nodedf + nodecf * t2;
 tempa   = 1.0 - cc1 * t;
 tempe   = bstar * cc4 * t;
 templ   = t2cof * t2;

 if (isimp != 1)
   {
     delomg = omgcof * t;
     delm   = xmcof *
              (pow((1.0 + eta * cos(xmdf)), 3) -
              delmo);
     temp   = delomg + delm;
     mm     = xmdf + temp;
     argpm  = argpdf - temp;
     t3     = t2 * t;
     t4     = t3 * t;
     tempa  = tempa - d2 * t2 - d3 * t3 -
                      d4 * t4;
     tempe  = tempe + bstar * cc5 * (sin(mm) -
                      sinmao);
     templ  = templ + t3cof * t3 + t4 * (t4cof +
                      t * t5cof);
   }

 nm    = no;
 em    = ecco;
 inclm = inclo;
 if (method == 'd')
   {
     tc = t;
     dspace();
   } // if method = d

 if (nm <= 0.0)
   {
//         printf("# error nm %f\n", nm);
     error = 2;
   }
 am = pow((xke / nm),x2o3) * tempa * tempa;
 nm = xke / pow(am, 1.5);
 em = em - tempe;

 // fix tolerance for error recognition
 if ((em >= 1.0) || (em < -0.001) || (am < 0.95))
   {
//         printf("# error em %f\n", em);
     error = 1;
   }
 if (em < 0.0)
     em  = 1.0e-6;
 mm     = mm + no * templ;
 xlm    = mm + argpm + nodem;
 emsq   = em * em;
 temp   = 1.0 - emsq;

 nodem  = fmod(nodem, twopi);
 argpm  = fmod(argpm, twopi);
 xlm    = fmod(xlm, twopi);
 mm     = fmod(xlm - argpm - nodem, twopi);

 /* ----------------- compute extra mean quantities ------------- */
 sinim = sin(inclm);
 cosim = cos(inclm);

 /* -------------------- add lunar-solar periodics -------------- */
 ep     = em;
 xincp  = inclm;
 argpp  = argpm;
 nodep  = nodem;
 mp     = mm;
 sinip  = sinim;
 cosip  = cosim;
 if (method == 'd')
   {
     dpper
         (
           'n', ep, xincp, nodep, argpp, mp
         );
     if (xincp < 0.0)
       {
         xincp  = -xincp;
         nodep = nodep + PI;
         argpp  = argpp - PI;
       }
     if ((ep < 0.0 ) || ( ep > 1.0))
       {
//            printf("# error ep %f\n", ep);
         error = 3;
       }
   } // if method = d

 /* -------------------- long period periodics ------------------ */
 if (method == 'd')
   {
     sinip =  sin(xincp);
     cosip =  cos(xincp);
     aycof = -0.5*j3oj2*sinip;
     // sgp4fix for divide by zero for xincp = 180 deg
     if (fabs(cosip+1.0) > 1.5e-12)
         xlcof = -0.25 * j3oj2 * sinip * (3.0 + 5.0 * cosip) / (1.0 + cosip);
       else
         xlcof = -0.25 * j3oj2 * sinip * (3.0 + 5.0 * cosip) / temp4;
   }
 axnl = ep * cos(argpp);
 temp = 1.0 / (am * (1.0 - ep * ep));
 aynl = ep* sin(argpp) + temp * aycof;
 xl   = mp + argpp + nodep + temp * xlcof * axnl;

 /* --------------------- solve kepler's equation --------------- */
 u    = fmod(xl - nodep, twopi);
 eo1  = u;
 tem5 = 9999.9;
 ktr = 1;
 //   sgp4fix for kepler iteration
 //   the following iteration needs better limits on corrections
 while (( fabs(tem5) >= 1.0e-12) && (ktr <= 10) )
   {
     sineo1 = sin(eo1);
     coseo1 = cos(eo1);
     tem5   = 1.0 - coseo1 * axnl - sineo1 * aynl;
     tem5   = (u - aynl * coseo1 + axnl * sineo1 - eo1) / tem5;
     if(fabs(tem5) >= 0.95)
         tem5 = tem5 > 0.0 ? 0.95 : -0.95;
     eo1    = eo1 + tem5;
     ktr = ktr + 1;
   }

 /* ------------- short period preliminary quantities ----------- */
 ecose = axnl*coseo1 + aynl*sineo1;
 esine = axnl*sineo1 - aynl*coseo1;
 el2   = axnl*axnl + aynl*aynl;
 pl    = am*(1.0-el2);
 if (pl < 0.0)
   {
//         printf("# error pl %f\n", pl);
     error = 4;
   }
   else
   {
     rl     = am * (1.0 - ecose);
     rdotl  = sqrt(am) * esine/rl;
     rvdotl = sqrt(pl) / rl;
     betal  = sqrt(1.0 - el2);
     temp   = esine / (1.0 + betal);
     sinu   = am / rl * (sineo1 - aynl - axnl * temp);
     cosu   = am / rl * (coseo1 - axnl + aynl * temp);
     su     = atan2(sinu, cosu);
     sin2u  = (cosu + cosu) * sinu;
     cos2u  = 1.0 - 2.0 * sinu * sinu;
     temp   = 1.0 / pl;
     temp1  = 0.5 * j2 * temp;
     temp2  = temp1 * temp;

     /* -------------- update for short period periodics ------------ */
     if (method == 'd')
       {
         cosisq                 = cosip * cosip;
         con41  = 3.0*cosisq - 1.0;
         x1mth2 = 1.0 - cosisq;
         x7thm1 = 7.0*cosisq - 1.0;
       }
     mrt   = rl * (1.0 - 1.5 * temp2 * betal * con41) +
             0.5 * temp1 * x1mth2 * cos2u;
     su    = su - 0.25 * temp2 * x7thm1 * sin2u;
     xnode = nodep + 1.5 * temp2 * cosip * sin2u;
     xinc  = xincp + 1.5 * temp2 * cosip * sinip * cos2u;
     mvt   = rdotl - nm * temp1 * x1mth2 * sin2u / xke;
     rvdot = rvdotl + nm * temp1 * (x1mth2 * cos2u +
             1.5 * con41) / xke;

     /* --------------------- orientation vectors ------------------- */
     sinsu =  sin(su);
     cossu =  cos(su);
     snod  =  sin(xnode);
     cnod  =  cos(xnode);
     sini  =  sin(xinc);
     cosi  =  cos(xinc);
     xmx   = -snod * cosi;
     xmy   =  cnod * cosi;
     ux    =  xmx * sinsu + cnod * cossu;
     uy    =  xmy * sinsu + snod * cossu;
     uz    =  sini * sinsu;
     vx    =  xmx * cossu - cnod * sinsu;
     vy    =  xmy * cossu - snod * sinsu;
     vz    =  sini * cossu;

     /* --------- position and velocity (in km and km/sec) ---------- */
     r[0] = (mrt * ux)* radius_earth_km*1000.0;
     r[1] = (mrt * uy)* radius_earth_km*1000.0;
     r[2] = (mrt * uz)* radius_earth_km*1000.0;
     v[0] = (mvt * ux + rvdot * vx) * vkmpersec*1000.0;
     v[1] = (mvt * uy + rvdot * vy) * vkmpersec*1000.0;
     v[2] = (mvt * uz + rvdot * vz) * vkmpersec*1000.0;
   }  // if pl > 0

 // sgp4fix for decaying satellites
 if (mrt < 1.0)
   {
//         printf("# decay condition %11.6f \n",mrt);
     error = 6;
   }

   Satellite::getGeod();
 return error;
}  // end sgp4

void SatModel::initl(double epoch) {
    /* --------------------- local variables ------------------------ */
    double ak, d1, del, adel, po;

    /* ------------- calculate auxillary epoch quantities ---------- */
    eccsq  = ecco*ecco;
    omeosq = 1.0 - eccsq;
    rteosq = sqrt(omeosq);
    cosio  = cos(inclo);
    cosio2 = cosio*cosio;

    /* ------------------ un-kozai the mean motion ----------------- */
    ak    = pow(xke/no, x2o3);
    d1    = 0.75*j2*(3.0*cosio2 - 1.0)/(rteosq*omeosq);
    del   = d1/(ak*ak);
    adel  = ak*(1.0 - del*del - del*(1.0/3.0 + 134.0*del*del/81.0));
    del   = d1/(adel*adel);
    no    = no/(1.0 + del);

    ao    = pow(xke/no, x2o3);
    sinio = sin(inclo);
    po    = ao*omeosq;
    con42 = 1.0 - 5.0*cosio2;
    con41 = -con42 - cosio2 - cosio2;
    posq  = po*po;
    rp    = ao*(1.0 - ecco);
    method = 'n';

    gsto = gstime(epoch);  // epoch - J1950
}  // end initl

double SatModel::gstime(double jdut1) {

    const double deg2rad = PI/180.0;
    double tut1;

    tut1 = (jdut1 - 2451545.0) / 36525.0;
    temp = -6.2e-6*tut1*tut1*tut1 + 0.093104*tut1*tut1 + (876600.0*3600 + 8640184.812866)*tut1 + 67310.54841;  // sec
    temp = fmod(temp*deg2rad/240.0, twopi); //360/86400 = 1/240, to deg, to rad

    // ------------------------ check quadrants ---------------------
    if (temp < 0.0) temp += twopi;

    return temp;
}  // end gstime

void SatModel::dscom(double epoch) {
     /* -------------------------- constants ------------------------- */
     const double zes     =  0.01675;
     const double zel     =  0.05490;
     const double c1ss    =  2.9864797e-6;
     const double c1l     =  4.7968065e-7;
     const double zsinis  =  0.39785416;
     const double zcosis  =  0.91744867;
     const double zcosgs  =  0.1945905;
     const double zsings  = -0.98088458;

     /* --------------------- local variables ------------------------ */
     int lsflg;
     double a1    , a2    , a3    , a4    , a5    , a6    , a7    ,
        a8    , a9    , a10   , betasq, cc    , ctem  , stem  ,
        x1    , x2    , x3    , x4    , x5    , x6    , x7    ,
        x8    , xnodce, xnoi  , zcosg , zcosgl, zcosh , zcoshl,
        zcosi , zcosil, zsing , zsingl, zsinh , zsinhl, zsini ,
        zsinil, zx    , zy;

     nm     = no;
     em     = ecco;
     snodm  = sin(nodeo);
     cnodm  = cos(nodeo);
     sinomm = sin(argpo);
     cosomm = cos(argpo);
     sinim  = sin(inclo);
     cosim  = cos(inclo);
     emsq   = em*em;
     betasq = 1.0 - emsq;
     rtemsq = sqrt(betasq);

     /* ----------------- initialize lunar solar terms --------------- */
     peo    = 0.0;
     pinco  = 0.0;
     plo    = 0.0;
     pgho   = 0.0;
     pho    = 0.0;  /*epoch - J1950*/
     day    = epoch - 2433281.5 + 18261.5 + tc / 1440.0;
     xnodce = fmod(4.5236020 - 9.2422029e-4 * day, twopi);
     stem   = sin(xnodce);
     ctem   = cos(xnodce);
     zcosil = 0.91375164 - 0.03568096 * ctem;
     zsinil = sqrt(1.0 - zcosil * zcosil);
     zsinhl = 0.089683511 * stem / zsinil;
     zcoshl = sqrt(1.0 - zsinhl * zsinhl);
     gam    = 5.8351514 + 0.0019443680 * day;
     zx     = 0.39785416 * stem / zsinil;
     zy     = zcoshl * ctem + 0.91744867 * zsinhl * stem;
     zx     = atan2(zx, zy);
     zx     = gam + zx - xnodce;
     zcosgl = cos(zx);
     zsingl = sin(zx);

     /* ------------------------- do solar terms --------------------- */
     zcosg = zcosgs;
     zsing = zsings;
     zcosi = zcosis;
     zsini = zsinis;
     zcosh = cnodm;
     zsinh = snodm;
     cc    = c1ss;
     xnoi  = 1.0 / nm;

     for (lsflg = 1; lsflg <= 2; lsflg++)
       {
         a1  =   zcosg * zcosh + zsing * zcosi * zsinh;
         a3  =  -zsing * zcosh + zcosg * zcosi * zsinh;
         a7  =  -zcosg * zsinh + zsing * zcosi * zcosh;
         a8  =   zsing * zsini;
         a9  =   zsing * zsinh + zcosg * zcosi * zcosh;
         a10 =   zcosg * zsini;
         a2  =   cosim * a7 + sinim * a8;
         a4  =   cosim * a9 + sinim * a10;
         a5  =  -sinim * a7 + cosim * a8;
         a6  =  -sinim * a9 + cosim * a10;

         x1  =  a1 * cosomm + a2 * sinomm;
         x2  =  a3 * cosomm + a4 * sinomm;
         x3  = -a1 * sinomm + a2 * cosomm;
         x4  = -a3 * sinomm + a4 * cosomm;
         x5  =  a5 * sinomm;
         x6  =  a6 * sinomm;
         x7  =  a5 * cosomm;
         x8  =  a6 * cosomm;

         z31 = 12.0 * x1 * x1 - 3.0 * x3 * x3;
         z32 = 24.0 * x1 * x2 - 6.0 * x3 * x4;
         z33 = 12.0 * x2 * x2 - 3.0 * x4 * x4;
         z1  =  3.0 *  (a1 * a1 + a2 * a2) + z31 * emsq;
         z2  =  6.0 *  (a1 * a3 + a2 * a4) + z32 * emsq;
         z3  =  3.0 *  (a3 * a3 + a4 * a4) + z33 * emsq;
         z11 = -6.0 * a1 * a5 + emsq *  (-24.0 * x1 * x7-6.0 * x3 * x5);
         z12 = -6.0 *  (a1 * a6 + a3 * a5) + emsq *
                (-24.0 * (x2 * x7 + x1 * x8) - 6.0 * (x3 * x6 + x4 * x5));
         z13 = -6.0 * a3 * a6 + emsq * (-24.0 * x2 * x8 - 6.0 * x4 * x6);
         z21 =  6.0 * a2 * a5 + emsq * (24.0 * x1 * x5 - 6.0 * x3 * x7);
         z22 =  6.0 *  (a4 * a5 + a2 * a6) + emsq *
                (24.0 * (x2 * x5 + x1 * x6) - 6.0 * (x4 * x7 + x3 * x8));
         z23 =  6.0 * a4 * a6 + emsq * (24.0 * x2 * x6 - 6.0 * x4 * x8);
         z1  = z1 + z1 + betasq * z31;
         z2  = z2 + z2 + betasq * z32;
         z3  = z3 + z3 + betasq * z33;
         s3  = cc * xnoi;
         s2  = -0.5 * s3 / rtemsq;
         s4  = s3 * rtemsq;
         s1  = -15.0 * em * s4;
         s5  = x1 * x3 + x2 * x4;
         s6  = x2 * x3 + x1 * x4;
         s7  = x2 * x4 - x1 * x3;

         /* ----------------------- do lunar terms ------------------- */
         if (lsflg == 1)
           {
             ss1   = s1;
             ss2   = s2;
             ss3   = s3;
             ss4   = s4;
             ss5   = s5;
             ss6   = s6;
             ss7   = s7;
             sz1   = z1;
             sz2   = z2;
             sz3   = z3;
             sz11  = z11;
             sz12  = z12;
             sz13  = z13;
             sz21  = z21;
             sz22  = z22;
             sz23  = z23;
             sz31  = z31;
             sz32  = z32;
             sz33  = z33;
             zcosg = zcosgl;
             zsing = zsingl;
             zcosi = zcosil;
             zsini = zsinil;
             zcosh = zcoshl * cnodm + zsinhl * snodm;
             zsinh = snodm * zcoshl - cnodm * zsinhl;
             cc    = c1l;
          }
       }

     zmol = fmod(4.7199672 + 0.22997150  * day - gam, twopi);
     zmos = fmod(6.2565837 + 0.017201977 * day, twopi);

     /* ------------------------ do solar terms ---------------------- */
     se2  =   2.0 * ss1 * ss6;
     se3  =   2.0 * ss1 * ss7;
     si2  =   2.0 * ss2 * sz12;
     si3  =   2.0 * ss2 * (sz13 - sz11);
     sl2  =  -2.0 * ss3 * sz2;
     sl3  =  -2.0 * ss3 * (sz3 - sz1);
     sl4  =  -2.0 * ss3 * (-21.0 - 9.0 * emsq) * zes;
     sgh2 =   2.0 * ss4 * sz32;
     sgh3 =   2.0 * ss4 * (sz33 - sz31);
     sgh4 = -18.0 * ss4 * zes;
     sh2  =  -2.0 * ss2 * sz22;
     sh3  =  -2.0 * ss2 * (sz23 - sz21);

     /* ------------------------ do lunar terms ---------------------- */
     ee2  =   2.0 * s1 * s6;
     e3   =   2.0 * s1 * s7;
     xi2  =   2.0 * s2 * z12;
     xi3  =   2.0 * s2 * (z13 - z11);
     xl2  =  -2.0 * s3 * z2;
     xl3  =  -2.0 * s3 * (z3 - z1);
     xl4  =  -2.0 * s3 * (-21.0 - 9.0 * emsq) * zel;
     xgh2 =   2.0 * s4 * z32;
     xgh3 =   2.0 * s4 * (z33 - z31);
     xgh4 = -18.0 * s4 * zel;
     xh2  =  -2.0 * s2 * z22;
     xh3  =  -2.0 * s2 * (z23 - z21);

}  // end dscom

void SatModel::dpper(char init, double ecc, double incl, double node,  double argp, double m) {
     /* --------------------- local variables ------------------------ */
     double alfdp, betdp, cosip, cosop, dalf, dbet, dls,
          f2,    f3,    pe,    pgh,   ph,   pinc, pl ,
          sel,   ses,   sghl,  sghs,  shll, shs,  sil,
          sinip, sinop, sinzf, sis,   sll,  sls,  xls,
          xnoh,  zf,    zm,    zel,   zes,  znl,  zns;

     /* ---------------------- constants ----------------------------- */
     zns   = 1.19459e-5;
     zes   = 0.01675;
     znl   = 1.5835218e-4;
     zel   = 0.05490;

     /* --------------- calculate time varying periodics ----------- */
     zm    = zmos + zns * t;
     // be sure that the initial call has time set to zero
     if (init == 'y')
         zm = zmos;
     zf    = zm + 2.0 * zes * sin(zm);
     sinzf = sin(zf);
     f2    =  0.5 * sinzf * sinzf - 0.25;
     f3    = -0.5 * sinzf * cos(zf);
     ses   = se2* f2 + se3 * f3;
     sis   = si2 * f2 + si3 * f3;
     sls   = sl2 * f2 + sl3 * f3 + sl4 * sinzf;
     sghs  = sgh2 * f2 + sgh3 * f3 + sgh4 * sinzf;
     shs   = sh2 * f2 + sh3 * f3;
     zm    = zmol + znl * t;
     if (init == 'y')
         zm = zmol;
     zf    = zm + 2.0 * zel * sin(zm);
     sinzf = sin(zf);
     f2    =  0.5 * sinzf * sinzf - 0.25;
     f3    = -0.5 * sinzf * cos(zf);
     sel   = ee2 * f2 + e3 * f3;
     sil   = xi2 * f2 + xi3 * f3;
     sll   = xl2 * f2 + xl3 * f3 + xl4 * sinzf;
     sghl  = xgh2 * f2 + xgh3 * f3 + xgh4 * sinzf;
     shll  = xh2 * f2 + xh3 * f3;
     pe    = ses + sel;
     pinc  = sis + sil;
     pl    = sls + sll;
     pgh   = sghs + sghl;
     ph    = shs + shll;

     if (init == 'n')
       {
       pe    = pe - peo;
       pinc  = pinc - pinco;
       pl    = pl - plo;
       pgh   = pgh - pgho;
       ph    = ph - pho;
       incl = incl + pinc;
       ecc    = ecc + pe;
       sinip = sin(incl);
       cosip = cos(incl);

       /* ----------------- apply periodics directly ------------ */
       //  sgp4fix for lyddane choice
       //  strn3 used original inclination - this is technically feasible
       //  gsfc used perturbed inclination - also technically feasible
       //  probably best to readjust the 0.2 limit value and limit discontinuity
       //  0.2 rad = 11.45916 deg
       //  use next line for original strn3 approach and original inclination
       //  if (incl >= 0.2)
       //  use next line for gsfc version and perturbed inclination
       if (incl >= 0.2)
         {
           ph     = ph / sinip;
           pgh    = pgh - cosip * ph;
           argp  = argp + pgh;
           node  = node + ph;
           m     = m + pl;
         }
         else
         {
           /* ---- apply periodics with lyddane modification ---- */
           sinop  = sin(node);
           cosop  = cos(node);
           alfdp  = sinip * sinop;
           betdp  = sinip * cosop;
           dalf   =  ph * cosop + pinc * cosip * sinop;
           dbet   = -ph * sinop + pinc * cosip * cosop;
           alfdp  = alfdp + dalf;
           betdp  = betdp + dbet;
           node  = fmod(node, twopi);
           xls    = m + argp + cosip * node;
           dls    = pl + pgh - pinc * node * sinip;
           xls    = xls + dls;
           xnoh   = node;
           node  = atan2(alfdp, betdp);
           if (fabs(xnoh - node) > PI)
             if (node < xnoh)
                node = node + twopi;
               else
                node = node - twopi;
           m    = m + pl;
           argp = xls - m - cosip * node;
         }
       }   // if init == 'n'

     //init, &ecco, &inclo, &nodeo, &argpo, &mo
     //'n',  &ep,   &xincp, &nodep, &argpp, &mp
    if (init == 'y') {
        ecco = ecc;
        inclo = incl;
        nodeo = node;
        argpo = argp;
        mo = m;
    }
    else {
         ep = ecc;
         xincp = incl;
         nodep = node;
         argpp = argp;
         mp = m;
    }

}  // end dpper

void SatModel::dsinit() {
     /* --------------------- local variables ------------------------ */

     double ainv2 , aonv=0.0, cosisq, eoc, f220 , f221  , f311  ,
          f321  , f322  , f330  , f441  , f442  , f522  , f523  ,
          f542  , f543  , g200  , g201  , g211  , g300  , g310  ,
          g322  , g410  , g422  , g520  , g521  , g532  , g533  ,
          ses   , sgs   , sghl  , sghs  , shs   , shll  , sis   ,
          sini2 , sls   , theta , xno2  , q22   ,
          q31   , q33   , root22, root44, root54, rptim , root32,
          root52, znl   , emo   , zns   , emsqo;

     q22    = 1.7891679e-6;
     q31    = 2.1460748e-6;
     q33    = 2.2123015e-7;
     root22 = 1.7891679e-6;
     root44 = 7.3636953e-9;
     root54 = 2.1765803e-9;
     rptim  = 4.37526908801129966e-3; // this equates to 7.29211514668855e-5 rad/sec
     root32 = 3.7393792e-7;
     root52 = 1.1428639e-7;
     znl    = 1.5835218e-4;
     zns    = 1.19459e-5;

     /* -------------------- deep space initialization ------------ */
     irez = 0;
     if ((nm < 0.0052359877) && (nm > 0.0034906585))
         irez = 1;
     if ((nm >= 8.26e-3) && (nm <= 9.24e-3) && (em >= 0.5))
         irez = 2;

     /* ------------------------ do solar terms ------------------- */
     ses  =  ss1 * zns * ss5;
     sis  =  ss2 * zns * (sz11 + sz13);
     sls  = -zns * ss3 * (sz1 + sz3 - 14.0 - 6.0 * emsq);
     sghs =  ss4 * zns * (sz31 + sz33 - 6.0);
     shs  = -zns * ss2 * (sz21 + sz23);
     // sgp4fix for 180 deg incl
     if ((inclm < 5.2359877e-2) || (inclm > PI - 5.2359877e-2))
       shs = 0.0;
     if (sinim != 0.0)
       shs = shs / sinim;
     sgs  = sghs - cosim * shs;

     /* ------------------------- do lunar terms ------------------ */
     dedt = ses + s1 * znl * s5;
     didt = sis + s2 * znl * (z11 + z13);
     dmdt = sls - znl * s3 * (z1 + z3 - 14.0 - 6.0 * emsq);
     sghl = s4 * znl * (z31 + z33 - 6.0);
     shll = -znl * s2 * (z21 + z23);
     // sgp4fix for 180 deg incl
     if ((inclm < 5.2359877e-2) || (inclm > PI - 5.2359877e-2))
         shll = 0.0;
     domdt = sgs + sghl;
     dnodt = shs;
     if (sinim != 0.0)
       {
         domdt = domdt - cosim / sinim * shll;
         dnodt = dnodt + shll / sinim;
       }

     /* ----------- calculate deep space resonance effects -------- */
     dndt   = 0.0;
     theta  = fmod(gsto + tc * rptim, twopi);
     em     = em + dedt * t;
     inclm  = inclm + didt * t;
     argpm  = argpm + domdt * t;
     nodem  = nodem + dnodt * t;
     mm     = mm + dmdt * t;

     /* -------------- initialize the resonance terms ------------- */
     if (irez != 0)
       {
         aonv = pow(nm / xke, x2o3);

         /* ---------- geopotential resonance for 12 hour orbits ------ */
         if (irez == 2)
           {
             cosisq = cosim * cosim;
             emo    = em;
             em     = ecco;
             emsqo  = emsq;
             emsq   = eccsq;
             eoc    = em * emsq;
             g201   = -0.306 - (em - 0.64) * 0.440;

             if (em <= 0.65)
               {
                 g211 =    3.616  -  13.2470 * em +  16.2900 * emsq;
                 g310 =  -19.302  + 117.3900 * em - 228.4190 * emsq +  156.5910 * eoc;
                 g322 =  -18.9068 + 109.7927 * em - 214.6334 * emsq +  146.5816 * eoc;
                 g410 =  -41.122  + 242.6940 * em - 471.0940 * emsq +  313.9530 * eoc;
                 g422 = -146.407  + 841.8800 * em - 1629.014 * emsq + 1083.4350 * eoc;
                 g520 = -532.114  + 3017.977 * em - 5740.032 * emsq + 3708.2760 * eoc;
               }
               else
               {
                 g211 =   -72.099 +   331.819 * em -   508.738 * emsq +   266.724 * eoc;
                 g310 =  -346.844 +  1582.851 * em -  2415.925 * emsq +  1246.113 * eoc;
                 g322 =  -342.585 +  1554.908 * em -  2366.899 * emsq +  1215.972 * eoc;
                 g410 = -1052.797 +  4758.686 * em -  7193.992 * emsq +  3651.957 * eoc;
                 g422 = -3581.690 + 16178.110 * em - 24462.770 * emsq + 12422.520 * eoc;
                 if (em > 0.715)
                     g520 =-5149.66 + 29936.92 * em - 54087.36 * emsq + 31324.56 * eoc;
                   else
                     g520 = 1464.74 -  4664.75 * em +  3763.64 * emsq;
               }
             if (em < 0.7)
               {
                 g533 = -919.22770 + 4988.6100 * em - 9064.7700 * emsq + 5542.21  * eoc;
                 g521 = -822.71072 + 4568.6173 * em - 8491.4146 * emsq + 5337.524 * eoc;
                 g532 = -853.66600 + 4690.2500 * em - 8624.7700 * emsq + 5341.4  * eoc;
               }
               else
               {
                 g533 =-37995.780 + 161616.52 * em - 229838.20 * emsq + 109377.94 * eoc;
                 g521 =-51752.104 + 218913.95 * em - 309468.16 * emsq + 146349.42 * eoc;
                 g532 =-40023.880 + 170470.89 * em - 242699.48 * emsq + 115605.82 * eoc;
               }

             sini2=  sinim * sinim;
             f220 =  0.75 * (1.0 + 2.0 * cosim+cosisq);
             f221 =  1.5 * sini2;
             f321 =  1.875 * sinim  *  (1.0 - 2.0 * cosim - 3.0 * cosisq);
             f322 = -1.875 * sinim  *  (1.0 + 2.0 * cosim - 3.0 * cosisq);
             f441 = 35.0 * sini2 * f220;
             f442 = 39.3750 * sini2 * sini2;
             f522 =  9.84375 * sinim * (sini2 * (1.0 - 2.0 * cosim- 5.0 * cosisq) +
                     0.33333333 * (-2.0 + 4.0 * cosim + 6.0 * cosisq) );
             f523 = sinim * (4.92187512 * sini2 * (-2.0 - 4.0 * cosim +
                    10.0 * cosisq) + 6.56250012 * (1.0+2.0 * cosim - 3.0 * cosisq));
             f542 = 29.53125 * sinim * (2.0 - 8.0 * cosim+cosisq *
                    (-12.0 + 8.0 * cosim + 10.0 * cosisq));
             f543 = 29.53125 * sinim * (-2.0 - 8.0 * cosim+cosisq *
                    (12.0 + 8.0 * cosim - 10.0 * cosisq));
             xno2  =  nm * nm;
             ainv2 =  aonv * aonv;
             temp1 =  3.0 * xno2 * ainv2;
             temp  =  temp1 * root22;
             d2201 =  temp * f220 * g201;
             d2211 =  temp * f221 * g211;
             temp1 =  temp1 * aonv;
             temp  =  temp1 * root32;
             d3210 =  temp * f321 * g310;
             d3222 =  temp * f322 * g322;
             temp1 =  temp1 * aonv;
             temp  =  2.0 * temp1 * root44;
             d4410 =  temp * f441 * g410;
             d4422 =  temp * f442 * g422;
             temp1 =  temp1 * aonv;
             temp  =  temp1 * root52;
             d5220 =  temp * f522 * g520;
             d5232 =  temp * f523 * g532;
             temp  =  2.0 * temp1 * root54;
             d5421 =  temp * f542 * g521;
             d5433 =  temp * f543 * g533;
             xlamo =  fmod(mo + nodeo + nodeo - theta - theta, twopi);
             xfact =  mdot + dmdt + 2.0 * (nodedot + dnodt - rptim) - no;
             em    = emo;
             emsq  = emsqo;
           }

         /* ---------------- synchronous resonance terms -------------- */
         if (irez == 1)
           {
             g200  = 1.0 + emsq * (-2.5 + 0.8125 * emsq);
             g310  = 1.0 + 2.0 * emsq;
             g300  = 1.0 + emsq * (-6.0 + 6.60937 * emsq);
             f220  = 0.75 * (1.0 + cosim) * (1.0 + cosim);
             f311  = 0.9375 * sinim * sinim * (1.0 + 3.0 * cosim) - 0.75 * (1.0 + cosim);
             f330  = 1.0 + cosim;
             f330  = 1.875 * f330 * f330 * f330;
             del1  = 3.0 * nm * nm * aonv * aonv;
             del2  = 2.0 * del1 * f220 * g200 * q22;
             del3  = 3.0 * del1 * f330 * g300 * q33 * aonv;
             del1  = del1 * f311 * g310 * q31 * aonv;
             xlamo = fmod(mo + nodeo + argpo - theta, twopi);
             xfact = mdot + xpidot - rptim + dmdt + domdt + dnodt - no;
           }

         /* ------------ for sgp4, initialize the integrator ---------- */
         xli   = xlamo;
         xni   = no;
         atime = 0.0;
         nm    = no + dndt;
       }

}  // end dsinit

void SatModel::dspace() {
     int iretn , iret;
     double delt, ft, theta, x2li, x2omi, xl, xldot = 0.0, xnddt = 0.0, xndt = 0.0, xomi, g22, g32,
          g44, g52, g54, fasx2, fasx4, fasx6, rptim , step2, stepn , stepp;

     ft    = 0.0;
     fasx2 = 0.13130908;
     fasx4 = 2.8843198;
     fasx6 = 0.37448087;
     g22   = 5.7686396;
     g32   = 0.95240898;
     g44   = 1.8014998;
     g52   = 1.0508330;
     g54   = 4.4108898;
     rptim = 4.37526908801129966e-3; // this equates to 7.29211514668855e-5 rad/sec
     stepp =    720.0;
     stepn =   -720.0;
     step2 = 259200.0;

     /* ----------- calculate deep space resonance effects ----------- */
     dndt   = 0.0;
     theta  = fmod(gsto + tc * rptim, twopi);
     em     = em + dedt * t;

     inclm  = inclm + didt * t;
     argpm  = argpm + domdt * t;
     nodem  = nodem + dnodt * t;
     mm     = mm + dmdt * t;

     //   sgp4fix for negative inclinations
     //   the following if statement should be commented out
     //  if (inclm < 0.0)
     // {
     //    inclm = -inclm;
     //    argpm = argpm - pi;
     //    nodem = nodem + pi;
     //  }

     /* - update resonances : numerical (euler-maclaurin) integration - */
     /* ------------------------- epoch restart ----------------------  */
     //   sgp4fix for propagator problems
     //   the following integration works for negative time steps and periods
     //   the specific changes are unknown because the original code was so convoluted

     ft    = 0.0;
     atime = 0.0;
     if (irez != 0)
       {
         if ((atime == 0.0) || ((t >= 0.0) && (atime < 0.0)) ||
             ((t < 0.0) && (atime >= 0.0)))
           {
             if (t >= 0.0)
                 delt = stepp;
               else
                 delt = stepn;
             atime  = 0.0;
             xni    = no;
             xli    = xlamo;
           }
         iretn = 381; // added for do loop
         iret  =   0; // added for loop
         while (iretn == 381)
           {
             if ((fabs(t) < fabs(atime)) || (iret == 351))
               {
                 if (t >= 0.0)
                     delt = stepn;
                   else
                     delt = stepp;
                 iret  = 351;
                 iretn = 381;
               }
               else
               {
                 if (t > 0.0)  // error if prev if has atime:=0.0 and t:=0.0 (ge)
                     delt = stepp;
                   else
                     delt = stepn;
                 if (fabs(t - atime) >= stepp)
                   {
                     iret  = 0;
                     iretn = 381;
                   }
                   else
                   {
                     ft    = t - atime;
                     iretn = 0;
                   }
               }

             /* ------------------- dot terms calculated ------------- */
             /* ----------- near - synchronous resonance terms ------- */
             if (irez != 2)
               {
                 xndt  = del1 * sin(xli - fasx2) + del2 * sin(2.0 * (xli - fasx4)) +
                         del3 * sin(3.0 * (xli - fasx6));
                 xldot = xni + xfact;
                 xnddt = del1 * cos(xli - fasx2) +
                         2.0 * del2 * cos(2.0 * (xli - fasx4)) +
                         3.0 * del3 * cos(3.0 * (xli - fasx6));
                 xnddt = xnddt * xldot;
               }
               else
               {
                 /* --------- near - half-day resonance terms -------- */
                 xomi  = argpo + argpdot * atime;
                 x2omi = xomi + xomi;
                 x2li  = xli + xli;
                 xndt  = d2201 * sin(x2omi + xli - g22) + d2211 * sin(xli - g22) +
                       d3210 * sin(xomi + xli - g32)  + d3222 * sin(-xomi + xli - g32)+
                       d4410 * sin(x2omi + x2li - g44)+ d4422 * sin(x2li - g44) +
                       d5220 * sin(xomi + xli - g52)  + d5232 * sin(-xomi + xli - g52)+
                       d5421 * sin(xomi + x2li - g54) + d5433 * sin(-xomi + x2li - g54);
                 xldot = xni + xfact;
                 xnddt = d2201 * cos(x2omi + xli - g22) + d2211 * cos(xli - g22) +
                       d3210 * cos(xomi + xli - g32) + d3222 * cos(-xomi + xli - g32) +
                       d5220 * cos(xomi + xli - g52) + d5232 * cos(-xomi + xli - g52) +
                       2.0 * (d4410 * cos(x2omi + x2li - g44) +
                       d4422 * cos(x2li - g44) + d5421 * cos(xomi + x2li - g54) +
                       d5433 * cos(-xomi + x2li - g54));
                 xnddt = xnddt * xldot;
               }

             /* ----------------------- integrator ------------------- */
             if (iretn == 381)
               {
                 xli   = xli + xldot * delt + xndt * step2;
                 xni   = xni + xndt * delt + xnddt * step2;
                 atime = atime + delt;
               }
           }  // while iretn = 381

         nm = xni + xndt * ft + xnddt * ft * ft * 0.5;
         xl = xli + xldot * ft + xndt * ft * ft * 0.5;
         if (irez != 1)
           {
             mm   = xl - 2.0 * nodem + 2.0 * theta;
             dndt = nm - no;
           }
           else
           {
             mm   = xl - nodem - argpm + theta;
             dndt = nm - no;
           }
         nm = no + dndt;
       }

}  // end dsspace
