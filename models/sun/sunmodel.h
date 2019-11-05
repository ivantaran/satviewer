/*
 * File:   sunmodel.h
 * Author: taran
 *
 * Created on July 29, 2018, 4:01 PM
 */

#ifndef SUNMODEL_H
#define SUNMODEL_H

#ifdef __cplusplus
extern "C" {
#endif

void sunmodel_ll(time_t t, double *lat, double *lon);

/**
 * @param[in] use_arc Atmospheric refraction correction flag, 1 or 'y' if set.
 */
void sunmodel_ae(time_t t, double lat, double lon, double *azm, double *elv, char use_arc);
void sunmodel_test(void);

#ifdef __cplusplus
}
#endif

#endif /* SUNMODEL_H */
