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

class Satellite {

public:
    Satellite(void);
    virtual ~Satellite(void);
    SatWidgetObject *satWObject;
    virtual bool model(double) { return false; }
    virtual bool modelInit(char *state, int size) { return false; }
    virtual char *getState() { return 0; }
    virtual int getStateSize() { return 0; }
    
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
    double zrvWidth     () const { return zrv;          }
    virtual double meanMotion() { return 0.0; }

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

    void setLocation(bool location);
    bool isLocation() const;
    void setSatellite(bool satellite);
    bool isSatellite() const;

protected:
    double lon, lat, _height;
    double r[3], v[3], r_g[3], v_g[3];
//    double jdsatepoch, bstar, inclo, nodeo, ecco, argpo, mo, ao, no;
    double zrv;
//    double gsto; //current sidereal time
//    double t;    //current model time in minutes
//    double tumin, mu, radius_earth_km, xke, j2, j3, j4, j3oj2;
    double radius_earth;
    void getGeod();
    virtual double gsto() { return 0.0; }
    virtual double minutes() { return 0.0; }

private:
    QString icon_name;
    QString _name;
    QFont _font;
    uint32_t _color, color_track, color_label, color_zrv, color_lines, color_track_shadow;
    double _track;
    double name_x, name_y;
    double lines_width;
    bool show_label, show_track, show_zrv, show_lines, active_zone, show_track_shadow;
    bool satellite, location;
};
#endif /* SATELLITE_H_ */
