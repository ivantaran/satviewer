/*
 * Location.h
 *
 *  Created on: 27.06.2009
 *      Author: Yan Coduemat
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include <inttypes.h>
#include <QString>
#include <QFont>
#include "../ogl/SatWidgetObject.h"

class Location {
public:
    Location(void);
    virtual ~Location(void);
    SatWidgetObject *satWObject;
    void copy(Location *src);

    void setName     ( QString name     );
    void setLatitude ( double latitude  );
    void setLongitude( double longitude );
    void setHeight   ( double height    );
    void setFont     ( QFont  font      );
    void setNameX    ( double value     );
    void setNameY    ( double value     );
    void setIcon(QString name);
    void setLinesWidth( double value );

    void setZrlWidth  ( double value ) { _zrlWidth   = value; }
    void setZrlAzimuth( double value ) { _zrlAzimuth = value; }
    void setZrlRange  ( double value ) { _zrlRange   = value; }

    inline QString name    () { return _name;   }
    inline double nameX    () { return name_x;  }
    inline double nameY    () { return name_y;  }
    inline double latitude () { return lat;     }
    inline double longitude() { return lon;     }
    inline double height   () { return _height; }
    inline double *xyz     () { return r;       }

    inline double zrlWidth  () { return _zrlWidth;   }
    inline double zrlAzimuth() { return _zrlAzimuth; }
    inline double zrlRange  () { return _zrlRange;   }

    inline int iconIndex   () { return icon_index;  }
    inline int iconWidth   () { return icon_width;  }
    inline int iconHeight  () { return icon_height; }
    inline QString iconName() { return icon_name;   }
    inline double linesWidth() { return lines_width; }

    inline QFont font() { return _font; }

    inline uint32_t color     () { return _color;      }
    inline uint32_t colorLabel() { return color_label; }
    inline uint32_t colorZrv  () { return color_zrv;   }
    inline uint32_t colorLines() { return color_lines; }

    inline void setColor     ( uint32_t color ) { _color      = color; }
    inline void setColorLabel( uint32_t color ) { color_label = color; }
    inline void setColorZrv  ( uint32_t color ) { color_zrv   = color; }
    inline void setColorLines( uint32_t color ) { color_lines = color; }

    inline void visibleLabel( bool value = true ) { show_label  = value; }
    inline void visibleZrv  ( bool value = true ) { show_zrv    = value; }
    inline void visibleLines( bool value = true ) { show_lines  = value; }
    inline void activeZone  ( bool value = true ) { active_zone = value; }

    inline bool isVisibleLabel() { return show_label;  }
    inline bool isVisibleZrv  () { return show_zrv;    }
    inline bool isVisibleLines() { return show_lines;  }
    inline bool isActiveZone  () { return active_zone; }

private:
    void calcXYZ();
    uint32_t icon_index, icon_width, icon_height;
    QString icon_name;
    QString _name;
    QFont _font;
    uint32_t _color, color_label, color_zrv, color_lines;
    bool show_label, show_zrv, show_lines, active_zone;

    double name_x, name_y;
    double lines_width;
    double lat, lon, _height;
    double _zrlWidth, _zrlAzimuth, _zrlRange;
    double r[3];
};
#endif /* LOCATION_H_ */
