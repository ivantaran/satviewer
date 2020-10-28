/*
 * Satellite.h
 *
 *  Created on: 27.06.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SATELLITE_H_
#define SATELLITE_H_

#include "TleReader.h"
#include <QFont>
#include <QString>
#include <inttypes.h>

class Satellite {

public:
    static const double RadiusEarth;
    Satellite(const QString &name = "");
    virtual ~Satellite();

    void copy(Satellite *src);
    void setEcef(double *ecef);
    void setEcef(double r0, double r1 = 0.0, double r2 = 0.0, double r3 = 0.0, double r4 = 0.0,
                 double r5 = 0.0);
    void setFont(QFont font);
    void setIcon(QString name);
    void setLinesWidth(double value);
    void setName(QString name);
    void setNameX(double value);
    void setNameY(double value);
    void setSatnum(int value);
    void setTrack(double value);
    void setTrackPoint(const double point[6], size_t index);
    void setZrv(double value);
    void setTrackSize(size_t size);
    const double *trackPointLla(size_t index);
    const double *trackPointEcef(size_t index);

    size_t trackSize() const {
        return m_track_size;
    }
    QString name() const {
        return m_name;
    }
    double nameX() const {
        return name_x;
    }
    double nameY() const {
        return name_y;
    }
    const double *ecef() {
        return m_ecef;
    }
    double latitude() const {
        return m_lla[0];
    }
    double longitude() const {
        return m_lla[1];
    }
    double altitude() const {
        return m_lla[2];
    }
    double zrvWidth() const {
        return zrv;
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
        return show_track && (trackSize() > 0);
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
    // lla[3] latitude, longitude, altitude
    double m_lla[3] = {0.0, 0.0, 0.0};
    double m_ecef[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double zrv;
    void ecef2lla(const double *ecef, double *lla);

private:
    double *m_track;
    double *m_trackLla;
    size_t m_track_size;
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
