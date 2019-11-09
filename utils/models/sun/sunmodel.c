
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sunmodel.h"

#define RAD2DEG(X) (180.0 * (X) / M_PI)
#define DEG2RAD(X) (M_PI * (X) / 180.0)

static double sunmodel_time_julian_cent(double jd) {
    return (jd - 2451545.0) / 36525.0;
}

static double sunmodel_jd_from_julian_cent(double t) {
    return t * 36525.0 + 2451545.0;
}

static int sunmodel_is_leap_year(int yr) {
    return (yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0);
}

static double sunmodel_doy_from_jd(double jd) {
    double z, f, alpha;
    double a, b, c, d, e, k;
    double day, month, year;

    z = floor(jd + 0.5);
    f = (jd + 0.5) - z;

    if (z < 2299161.0) {
        a = z;
    } else {
        alpha = floor((z - 1867216.25) / 36524.25);
        a = z + 1.0 + alpha - floor(alpha * 0.25);
    }

    b = a + 1524.0;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor((b - d) / 30.6001);

    day = b - d - floor(30.6001 * e) + f;
    month = (e < 14.0) ? e - 1.0 : e - 13.0;
    year = (month > 2.0) ? c - 4716.0 : c - 4715.0;

    k = sunmodel_is_leap_year(year) ? 1.0 : 2.0;

    return floor((275.0 * month) / 9.0) - k * floor((month + 9.0) / 12.0) + day - 30.0;
}

static double sunmodel_geom_mean_long_sun(double t) {
    double lon;

    lon = 280.46646 + t * (36000.76983 + t * 0.0003032);

    lon = fmod(lon, 360.0);
    if (lon < 0.0) {
        lon += 360.0;
    }

    lon = DEG2RAD(lon);
    return lon; // in radians
}

static double sunmodel_geom_mean_anomaly_sun(double t) {
    double m;
    m = DEG2RAD(357.52911 + t * (35999.05029 - 0.0001537 * t));
    return m; // in radians
}

static double sunmodel_eccentricity_earth_orbit(double t) {
    double e;
    e = 0.016708634 - t * (0.000042037 + 0.0000001267 * t);
    return e; // unitless
}

static double sunmodel_sun_rad_vector(double t, double m, double seoc, double e) {
    double v, r;
    v = m + seoc;
    r = (1.000001018 * (1.0 - e * e)) / (1.0 + e * cos(v));
    return r; // in AUs
}

static double sunmodel_sun_apparent_long(double t, double true_long) {
    double omega, lambda;
    omega = DEG2RAD(125.04 - 1934.136 * t);
    lambda = true_long - DEG2RAD(0.00569 + 0.00478 * sin(omega));
    return lambda; // in radians
}

static double sunmodel_mean_obliquity_of_ecliptic(double t) {
    double seconds, e0;
    seconds = 21.448 - t * (46.8150 + t * (0.00059 - t * 0.001813));
    e0 = DEG2RAD(23.0 + (26.0 + seconds / 60.0) / 60.0);
    return e0; // in radians
}

static double sunmodel_obliquity_correction(double t) {
    double e0, omega, e;
    e0 = sunmodel_mean_obliquity_of_ecliptic(t);
    omega = DEG2RAD(125.04 - 1934.136 * t);
    e = e0 + DEG2RAD(0.00256 * cos(omega));
    return e; // in radians
}

static double sunmodel_sun_declination(double t, double true_long) {
    double e, lambda, sint, theta;
    e = sunmodel_obliquity_correction(t);
    lambda = sunmodel_sun_apparent_long(t, true_long);

    sint = sin(e) * sin(lambda);
    theta = asin(sint);
    return theta; // in radians
}

static double sunmodel_get_jd(struct tm *gmt) {
    int month, year;
    double a, b, jd;

    month = gmt->tm_mon + 1;
    year = gmt->tm_year + 1900;

    if (month <= 2) {
        year -= 1;
        month += 12;
    }

    a = floor(year * 0.01);
    b = 2.0 - a + floor(a * 0.25);
    jd = floor(365.25 * (year + 4716.0)) + floor(30.6001 * (month + 1.0)) + gmt->tm_mday + b -
         1524.5;
    return jd;
}

static double sunmodel_atmo_refraction_correction(double elevation) {
    double value, te;
    /* Atmospheric refraction correction */
    if (elevation > DEG2RAD(85.0)) {
        value = 0.0;
    } else {
        te = tan(elevation);
        if (elevation > DEG2RAD(5.0)) {
            value = 58.1 / te - 0.07 / (te * te * te) + 0.000086 / (te * te * te * te * te);
        } else {
            if (elevation > DEG2RAD(-0.575)) {
                value =
                    1735.0 +
                    elevation *
                        (-518.2 + elevation * (103.4 + elevation * (-12.79 + elevation * 0.711)));
            } else {
                value = -20.774 / te;
            }
        }
        value = DEG2RAD(value / 3600.0);
    }
    return value;
}

static void sunmodel_ae_0(double slat, double slon, double lat, double lon, double *azm,
                          double *elv, char use_arc) {
    double azimuth;
    double omega, csz, elevation, az_denom;
    double sinlat, coslat, sinslat, cosslat;

    omega = lon - slon;
    sinlat = sin(lat);
    coslat = cos(lat);
    sinslat = sin(slat);
    cosslat = cos(slat);

    csz = sinlat * sinslat + coslat * cosslat * cos(omega);

    if (csz > 1.0) {
        csz = 1.0;
    } else {
        if (csz < -1.0) {
            csz = -1.0;
        }
    }

    elevation = asin(csz);
    az_denom = coslat * cos(elevation);

    if (fabs(az_denom) > DBL_EPSILON) { // TODO check relatyvely nominator
        azimuth = (sinlat * csz - sinslat) / az_denom;

        if (fabs(azimuth) > 1.0) {
            if (azimuth < 0.0) {
                azimuth = -1.0;
            } else {
                azimuth = 1.0;
            }
        }

        azimuth = M_PI - acos(azimuth);
        if (omega > 0.0) {
            azimuth = -azimuth;
        }
    } else {
        if (lat > 0.0) {
            azimuth = M_PI;
        } else {
            azimuth = 0.0;
        }
    }

    if (azimuth < 0.0) {
        azimuth += 2.0 * M_PI;
    }

    if (use_arc == 1 || use_arc == 'y') {
        elevation += sunmodel_atmo_refraction_correction(elevation);
    }

    //    if (elevation < DEG2RAD(-18.0)) {
    //        puts("A Night at the Roxbury");
    //    }

    if (azm != NULL) {
        (*azm) = azimuth;
    }

    if (elv != NULL) {
        (*elv) = elevation;
    }
}

static void sunmodel_ll_0(double t, double localtime, double *lat, double *lon) {
    double epsilon, l0, y, sin2l0, sinm, cos2l0, sin4l0, sin2m, sin3m, etime;
    double eq_time, true_long, m, e, seoc, slat, slon;

    m = sunmodel_geom_mean_anomaly_sun(t);
    e = sunmodel_eccentricity_earth_orbit(t);

    /* equation_of_time */
    epsilon = sunmodel_obliquity_correction(t);
    l0 = sunmodel_geom_mean_long_sun(t);

    y = tan(epsilon * 0.5);
    y *= y;

    sin2l0 = sin(2.0 * l0);
    sin4l0 = sin(4.0 * l0);
    cos2l0 = cos(2.0 * l0);
    sinm = sin(m);
    sin2m = sin(2.0 * m);
    sin3m = sin(3.0 * m);

    etime = y * sin2l0 - 2.0 * e * sinm + 4.0 * e * y * sinm * cos2l0 - 0.5 * y * y * sin4l0 -
            1.25 * e * e * sin2m;
    eq_time = RAD2DEG(etime) * 4.0; // in minutes of time
    /* equation_of_time */

    /* sun_eq_of_center */
    seoc = sinm * (1.914602 - t * (0.004817 + 0.000014 * t)) + sin2m * (0.019993 - 0.000101 * t) +
           sin3m * 0.000289;
    seoc = DEG2RAD(seoc);
    /* sun_eq_of_center */

    true_long = seoc + l0;

    slat = sunmodel_sun_declination(t, true_long);
    slon = 180.0 - (eq_time + localtime) * 0.25;
    slon = fmod(slon + 180.0, 360.0);
    if (slon < 0.0) {
        slon += 360.0;
    }
    slon -= 180.0;
    slon = DEG2RAD(slon);

    if (lat != NULL) {
        (*lat) = slat;
    }

    if (lon != NULL) {
        (*lon) = slon;
    }
}

void sunmodel_ll(time_t t, double *lat, double *lon) {
    struct tm *gmt;
    double jday, tl, tt;
    double slon, slat;

    gmt = gmtime(&t);

    if (gmt == NULL) {
        return;
    }

    jday = sunmodel_get_jd(gmt);
    tl = gmt->tm_hour / 24.0 + gmt->tm_min / 1440.0 + gmt->tm_sec / 86400.0;
    tt = sunmodel_time_julian_cent(jday + tl);

    sunmodel_ll_0(tt, tl * 1440.0, &slat, &slon);

    if (lat != NULL) {
        (*lat) = slat;
    }

    if (lon != NULL) {
        (*lon) = slon;
    }
}

void sunmodel_ae(time_t t, double lat, double lon, double *azm, double *elv, char use_arc) {
    double slon, slat;

    sunmodel_ll(t, &slat, &slon);
    sunmodel_ae_0(slat, slon, lat, lon, azm, elv, use_arc);
}

void sunmodel_test(void) {
    time_t t;
    struct tm gmt;
    double lat, lon;
    double slat, slon;
    double azm, elv;

    memset(&gmt, 0, sizeof(gmt));

    gmt.tm_year = 2018 - 1900;
    gmt.tm_mon = 0;
    gmt.tm_mday = 1;
    gmt.tm_hour = 6;
    gmt.tm_min = 0;
    gmt.tm_sec = 0;

    t = mktime(&gmt) - __timezone;

    setenv("TZ", "UTC", 1);
    printf("%s%s\n", ctime(&t), getenv("TZ"));
    unsetenv("TZ");

    lat = DEG2RAD(58.0);
    lon = DEG2RAD(63.0);

    sunmodel_ll(t, &slat, &slon);
    printf("slat: %8.2f\n", floor(RAD2DEG(slat) * 100.0 + 0.5) * 0.01);
    printf("slon: %8.2f\n\n", floor(RAD2DEG(slon) * 100.0 + 0.5) * 0.01);

    sunmodel_ae(t, lat, lon, &azm, &elv, 'y');

    const double azm0 = DEG2RAD(154.384634974813025110051967203617095947265625);
    const double elv0 = DEG2RAD(5.8779458855349417945035384036600589752197265625);

    double dazm = fabs(azm - azm0);
    double delv = fabs(elv - elv0);
    double eazm = 20.0 * DBL_EPSILON * fmax(fabs(azm), fabs(azm0));
    double eelv = 20.0 * DBL_EPSILON * fmax(fabs(elv), fabs(elv0));

    printf("azm: %8.2f\n", floor(RAD2DEG(azm) * 100.0 + 0.5) * 0.01);
    printf("elv: %8.2f\n", floor(RAD2DEG(elv) * 100.0 + 0.5) * 0.01);
    printf("dazm: %16g\t%16g\n", dazm, eazm);
    printf("delv: %16g\t%16g\n", delv, eelv);

    assert(dazm <= eazm);
    assert(delv <= eelv);

    puts("test passed\n");
}
