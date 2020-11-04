
#include "satmath.h"

#include <float.h>
#include <math.h>

void satmath_aerv(const double loc_rg[], const double sat_rg[], double aerv[]) {
    double m[3][3];
    double d[3];
    double p = sqrt(loc_rg[0] * loc_rg[0] + loc_rg[1] * loc_rg[1]);
    double r = sqrt(loc_rg[0] * loc_rg[0] + loc_rg[1] * loc_rg[1] + loc_rg[2] * loc_rg[2]);

    double dd[] = {loc_rg[0] - sat_rg[0], loc_rg[1] - sat_rg[1], loc_rg[2] - sat_rg[2],
                   loc_rg[3] - sat_rg[3], loc_rg[4] - sat_rg[4], loc_rg[5] - sat_rg[5]};

    aerv[2] = sqrt(dd[0] * dd[0] + dd[1] * dd[1] + dd[2] * dd[2]);

    if ((p < DBL_EPSILON) || (r < DBL_EPSILON)) {
        aerv[0] = 0.0;
        aerv[1] = 0.0;
        aerv[2] = 0.0;
        aerv[3] = 0.0;
        return;
    }

    m[0][0] = -loc_rg[1] / p;
    m[0][1] = loc_rg[0] / p;
    m[0][2] = 0.0;
    m[1][0] = -(loc_rg[0] * loc_rg[2] / (p * r));
    m[1][1] = -(loc_rg[1] * loc_rg[2] / (p * r));
    m[1][2] = p / r;
    m[2][0] = loc_rg[0] / r;
    m[2][1] = loc_rg[1] / r;
    m[2][2] = loc_rg[2] / r;

    for (int j = 0; j < 3; j++) {
        d[j] = 0.0;
        for (int i = 0; i < 3; i++) {
            d[j] += (sat_rg[i] - loc_rg[i]) * m[j][i];
        }
    }

    double s = d[2] / sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);

    aerv[0] = atan2(d[0], d[1]);
    aerv[1] = atan2(s, sqrt(1.0 - s * s));
    aerv[3] = (dd[0] * dd[3] + dd[1] * dd[4] + dd[2] * dd[5]) / aerv[2];
}
