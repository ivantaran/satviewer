/*
 * Satellite.h
 *
 *  Created on: 27.06.2009
 *      Author: Ivan Ryazanov
 */


#ifndef SATELLITE_H_
#define SATELLITE_H_

#include <inttypes.h>
#include "TleReader.h"
#include <stdio.h>
#include <QString>
#include <QFont>
#include "../ogl/SatWidgetObject.h"

//#define WGS72OLD 0
//#define WGS72 1
//#define WGS84 2

class Satellite {

public:
    Satellite(void);
    virtual ~Satellite(void);
    SatWidgetObject *satWObject;
    virtual int model(double) { return 0; }
    virtual int modelInit(char *state, int size) { return 0; }
    virtual char *getState() { return 0; }
    virtual int getStateSize() { return 0; }
    
//    virtual int modelInit(int consttype, double jdsatepoch, double bstar, double inclo, double argpo, double ecco, double nodeo, double mo, double no) {
//        this->ecc0 		 = ecco;
//        this->argp0      = argpo;
//        this->incl0      = inclo;
//        this->m0	     = mo;
//        this->n0	     = no;
//        this->node0      = nodeo;
//        this->jdsatepoch = jdsatepoch;
//        this->bstar      = bstar;
//        return 0;
//    }

    void copy(Satellite *src);
    void setName(QString name);
    void setZrv(double value);
    void setFont ( QFont  font  );
    void setTrack( double value );
    void setNameX( double value );
    void setNameY( double value );
    void setIcon(QString name);
    void setLinesWidth( double value );
    QString name() const { return _name;  }
    double nameX() const { return name_x; }
    double nameY() const { return name_y; }

    double* xyz () { return r; }
    double* vxyz() { return v; }

    double latitude     () const { return lat;          }
    double longitude    () const { return lon;          }
    double height       () const { return _height;      }
    double radiusEarth  () const { return radius_earth; }
    double eccentricity () const { return ecco;         }
    double inclination  () const { return inclo;        }
    double meanAnomaly  () const { return mo;           }
    double meanMotion   () const { return no;           }
    double argLatPerigee() const { return argpo;        }
    double latAscNode   () const { return nodeo;        }
    double bStar        () const { return bstar;        }
    double jEpoch       () const { return jdsatepoch;   }
    double zrvWidth     () const { return zrv;          }

    QString  iconName() const { return icon_name;   }
    double linesWidth() const { return lines_width; }

    inline QFont font() { return _font; }

    uint32_t color     () const { return _color;      }
    uint32_t colorTrack() const { return color_track; }
    uint32_t colorLabel() const { return color_label; }
    uint32_t colorZrv  () const { return color_zrv;   }
    uint32_t colorLines() const { return color_lines; }
    uint32_t colorTrackShadow() const { return color_track_shadow; }

    void setColor     (uint32_t color) { _color      = color; }
    void setColorTrack(uint32_t color) { color_track = color; }
    void setColorLabel(uint32_t color) { color_label = color; }
    void setColorZrv  (uint32_t color) { color_zrv   = color; }
    void setColorLines(uint32_t color) { color_lines = color; }
    void setColorTrackShadow(uint32_t color) { color_track_shadow = color; }

    double track() const { return _track; }

    void visibleLabel(bool value = true) { show_label  = value; }
    void visibleTrack(bool value = true) { show_track  = value; }
    void visibleZrv  (bool value = true) { show_zrv    = value; }
    void visibleLines(bool value = true) { show_lines  = value; }
    void activeZone  (bool value = true) { active_zone = value; }
    void visibleTrackShadow(bool value = true) { show_track_shadow = value; }

    bool isVisibleLabel() const { return show_label;  }
    bool isVisibleTrack() const { return show_track;  }
    bool isVisibleZrv  () const { return show_zrv;    }
    bool isVisibleLines() const { return show_lines;  }
    bool isAtctiveZone () const { return active_zone; }
    bool isVisibleTrackShadow() const { return show_track_shadow; }

    double* xyz_g ();
    double* vxyz_g();

    int modelIndex() const { return model_index; }
    void setModelIndex(int index) { model_index = index; }
    void setLocation(bool location);
    bool isLocation() const;
    void setSatellite(bool satellite);
    bool isSatellite() const;
//    int stateSize() const;
//    char* getState() const;

protected:
    double lon, lat, _height;
    double r[3], v[3], r_g[3], v_g[3];
    double jdsatepoch, bstar, inclo, nodeo, ecco, argpo, mo, ao, no;
    double zrv;
    double gsto; //current sidereal time
    double t;    //current model time in minutes
    double tumin, mu, radius_earth_km, xke, j2, j3, j4, j3oj2;
    double radius_earth;
//    void getgravconst(int whichconst);
    void getGeod();

private:
    QString icon_name;
    QString _name;
    QFont _font;
    uint32_t _color, color_track, color_label, color_zrv, color_lines, color_track_shadow;
    double _track;
    double name_x, name_y;
    double lines_width;
    bool show_label, show_track, show_zrv, show_lines, active_zone, show_track_shadow;
    int model_index;
    bool satellite, location;
};
#endif /* SATELLITE_H_ */
