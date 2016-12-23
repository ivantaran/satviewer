/* 
 * File:   sgp_struct.h
 * Author: yanco
 *
 * Created on 7 Октябрь 2012 г., 20:08
 */

#ifndef SGP_STRUCT_H
#define	SGP_STRUCT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define WGS72OLD 0
#define WGS72 1
#define WGS84 2

struct ms {
        int consttype;
        double jdsatepoch; 
        double bstar; 
        double inclo; 
        double argpo; 
        double ecco; 
        double nodeo; 
        double mo; 
        double no;    
};


#ifdef	__cplusplus
}
#endif

#endif	/* SGP_STRUCT_H */

