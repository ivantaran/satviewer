/*
 * Satellite.h
 *
 *  Created on: 27.06.2009
 *      Author: Yan Coduemat
 */


#ifndef SATELLITE_H_
#define SATELLITE_H_

#include <inttypes.h>
#include "TleReader.h"
#include <stdio.h>
#include <QString>
#include <QFont>
#include "../ogl/SatWidgetObject.h"

#define WGS72OLD 0
#define WGS72 1
#define WGS84 2

class Satellite {

public:
    Satellite(void);
    virtual ~Satellite(void);
    SatWidgetObject *satWObject;
    virtual int model(double) {return 0;}
    virtual int modelInit(int consttype, double jdsatepoch, double bstar, double inclo, double argpo, double ecco, double nodeo, double mo, double no) {
    	this->ecc0 		 = ecco;
    	this->argp0      = argpo;
    	this->incl0      = inclo;
    	this->m0	     = mo;
    	this->n0	     = no;
    	this->node0      = nodeo;
    	this->jdsatepoch = jdsatepoch;
    	this->bstar      = bstar;
    	return 0;
    }

	void copy(Satellite *src);
	void setName(QString name);
	void setZRV(double value);
	void setFont ( QFont  font  );
	void setTrack( double value );
	void setNameX( double value );
	void setNameY( double value );
	void setIcon(QString name);
	void setLinesWidth( double value );
	inline QString name() { return _name;  }
	inline double nameX() { return name_x; }
	inline double nameY() { return name_y; }

	double* xyz () { return r; }
	double* vxyz() { return v; }

	inline double latitude     () { return lat;          }
	inline double longitude    () { return lon;          }
	inline double height       () { return _height;      }
	inline double radiusEarth  () { return radius_earth; }
	inline double eccentricity () { return ecc0;         }
	inline double inclination  () { return incl0;        }
	inline double meanAnomaly  () { return m0;           }
	inline double meanMotion   () { return n0;           }
	inline double argLatPerigee() { return argp0;        }
	inline double latAscNode   () { return node0;        }
	inline double bStar        () { return bstar;        }
	inline double jEpoch       () { return jdsatepoch;   }
	inline double zrvWidth     () { return zrv;          }

	inline QString  iconName() { return icon_name;   }
	inline double linesWidth() { return lines_width; }

	inline QFont font() { return _font; }

	inline uint32_t color     () { return _color;      }
	inline uint32_t colorTrack() { return color_track; }
	inline uint32_t colorLabel() { return color_label; }
	inline uint32_t colorZrv  () { return color_zrv;   }
	inline uint32_t colorLines() { return color_lines; }
	inline uint32_t colorTrackShadow() { return color_track_shadow; }

	inline void setColor     (uint32_t color) { _color      = color; }
	inline void setColorTrack(uint32_t color) { color_track = color; }
	inline void setColorLabel(uint32_t color) { color_label = color; }
	inline void setColorZrv  (uint32_t color) { color_zrv   = color; }
	inline void setColorLines(uint32_t color) { color_lines = color; }
	inline void setColorTrackShadow(uint32_t color) { color_track_shadow = color; }

	inline double track() { return _track; }

	inline void visibleLabel(bool value = true) { show_label  = value; }
	inline void visibleTrack(bool value = true) { show_track  = value; }
	inline void visibleZrv  (bool value = true) { show_zrv    = value; }
	inline void visibleLines(bool value = true) { show_lines  = value; }
	inline void activeZone  (bool value = true) { active_zone = value; }
	inline void visibleTrackShadow(bool value = true) { show_track_shadow = value; }

	inline bool isVisibleLabel() { return show_label;  }
	inline bool isVisibleTrack() { return show_track;  }
	inline bool isVisibleZrv  () { return show_zrv;    }
	inline bool isVisibleLines() { return show_lines;  }
	inline bool isAtctiveZone () { return active_zone; }
	inline bool isVisibleTrackShadow() { return show_track_shadow; }

	double* xyz_g ();
	double* vxyz_g();

	inline int modelIndex() { return model_index; }
	void setModelIndex(int index) { model_index = index; }

protected:
    double lon, lat, _height;
	double r[3], v[3], r_g[3], v_g[3];
    double incl0, node0, ecc0, argp0, m0, n0, jdsatepoch, bstar;
    double zrv;
    double gsto; //current sidereal time
    double t;    //current model time in minutes
    double tumin, mu, radius_earth_km, xke, j2, j3, j4, j3oj2;
    double radius_earth;
	void getgravconst(int whichconst);
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
};
#endif /* SATELLITE_H_ */
