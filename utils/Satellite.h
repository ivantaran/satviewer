/*
 * Satellite.h
 *
 *  Created on: 27.06.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SATELLITE_H_
#define SATELLITE_H_

#include "TleReader.h"
#include "ogl/SatWidgetObject.h"
#include <QFont>
#include <QString>
#include <inttypes.h>
#include <stdio.h>

class Satellite {

public:
    static const double RadiusEarth;
    Satellite(const QString &name = "");
    virtual ~Satellite();
    SatWidgetObject *satWObject;
    virtual bool model(double) {
        return false;
    }

    void copy(Satellite *src);
    void setAbsoluteCoords(double *coords);
    void setAbsoluteCoords(double r0, double r1 = 0.0, double r2 = 0.0, double r3 = 0.0,
                           double r4 = 0.0, double r5 = 0.0);
    void setFont(QFont font);
    void setIcon(QString name);
    void setLinesWidth(double value);
    void setName(QString name);
    void setNameX(double value);
    void setNameY(double value);
    void setSatnum(int value);
    void setTrack(double value);
    void setZrv(double value);

    QString name() const {
        return m_name;
    }
    double nameX() const {
        return name_x;
    }
    double nameY() const {
        return name_y;
    }

    double *r() {
        return m_r;
    }
    double *rg() {
        return m_rg;
    }

    double latitude() const {
        return lat;
    }
    double longitude() const {
        return lon;
    }
    double altitude() const {
        return _altitude;
    }
    double zrvWidth() const {
        return zrv;
    }
    virtual double meanMotion() {
        return 0.0;
    }

    QString iconName() const {
        return icon_name;
    }
    double linesWidth() const {
        return lines_width;
    }

    inline QFont font() {
        return _font;
    }

    uint32_t color() const {
        return _color;
    }
    uint32_t colorTrack() const {
        return color_track;
    }
    uint32_t colorLabel() const {
        return color_label;
    }
    uint32_t colorZrv() const {
        return color_zrv;
    }
    uint32_t colorLines() const {
        return color_lines;
    }
    uint32_t colorTrackShadow() const {
        return color_track_shadow;
    }

    void setColor(uint32_t color) {
        _color = color;
    }
    void setColorTrack(uint32_t color) {
        color_track = color;
    }
    void setColorLabel(uint32_t color) {
        color_label = color;
    }
    void setColorZrv(uint32_t color) {
        color_zrv = color;
    }
    void setColorLines(uint32_t color) {
        color_lines = color;
    }
    void setColorTrackShadow(uint32_t color) {
        color_track_shadow = color;
    }

    double track() const {
        return _track;
    }

    void visibleLabel(bool value = true) {
        show_label = value;
    }
    void visibleTrack(bool value = true) {
        show_track = value;
    }
    void visibleZrv(bool value = true) {
        show_zrv = value;
    }
    void visibleLines(bool value = true) {
        show_lines = value;
    }
    void activeZone(bool value = true) {
        active_zone = value;
    }
    void visibleTrackShadow(bool value = true) {
        show_track_shadow = value;
    }

    bool isVisibleLabel() const {
        return show_label;
    }
    bool isVisibleTrack() const {
        return show_track;
    }
    bool isVisibleZrv() const {
        return show_zrv;
    }
    bool isVisibleLines() const {
        return show_lines;
    }
    bool isAtctiveZone() const {
        return active_zone;
    }
    bool isVisibleTrackShadow() const {
        return show_track_shadow;
    }

    void setLocation(bool location);
    bool isLocation() const;
    void setSatellite(bool satellite);
    bool isSatellite() const;
    int satnum() const;

protected:
    double lon, lat, _altitude;
    double m_r[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double m_rg[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double zrv;
    void makeGeod();
    void makeRg();
    virtual double gsto() {
        return 0.0;
    }
    virtual double minutes() {
        return 0.0;
    }

private:
    bool satellite, location;
    bool show_label, show_track, show_zrv, show_lines, active_zone, show_track_shadow;
    double _track;
    double lines_width;
    double name_x, name_y;
    int m_satnum;
    QFont _font;
    QString icon_name;
    QString m_name;
    uint32_t _color, color_track, color_label, color_zrv, color_lines, color_track_shadow;
};
#endif /* SATELLITE_H_ */
