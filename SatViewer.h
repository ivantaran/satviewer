/*
 * File:   SatViewer.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 9:45 PM
 */

#ifndef SATVIEWER_H
#define SATVIEWER_H

#include "utils/Location.h"
#include "utils/Satellite.h"
#include "utils/ZrvIoList.h"
#include <QHostAddress>
#include <QTcpSocket>

class SatViewer : public QTcpSocket {
    Q_OBJECT
public:
    struct Tle {
        int satnum;
    };

    SatViewer();
    virtual ~SatViewer();
    static void aerv(const double loc_rg[], const double sat_rg[], double aerv[]);
    void appendLocation(Location *loc);
    void appendSatellite(const QString &name);
    void clearLocations();
    void clearSatellites();
    void reconnect();
    void removeLocation(Location *loc);
    void removeSatellite(const QString &name);
    void setCurrentLocation(Location *loc);
    void setCurrentLocationIndex(long unsigned int index);
    void setCurrentSatellite(Satellite *sat);
    void setCurrentSatelliteIndex(long unsigned int index);
    void setTime(double value);
    void loadSatellitesJson();
    void saveSatellitesJson();

    const QMap<QString, Satellite *> &satellites() {
        return m_satellites;
    }
    const std::list<Location *> &locations() {
        return m_locations;
    }
    const QMap<QString, Tle *> &tles() {
        return m_tles;
    }
    Satellite *currentSatellite();
    Location *currentLocation();
    ZrvIoList *ioList() {
        return &m_ioList;
    }
    double time() {
        return m_time;
    }

signals:
    void currentChanged(Satellite *sat, Location *loc, double *time);
    void timeChanged();
    void updatedTles();
    void updatedSatellites();

protected:
    void timerEvent(QTimerEvent *event);

private:
    static const QString KeyAppendId;
    static const QString KeyRemoveId;
    static const quint16 DefaultPort = 8080;

    double m_time;
    int m_timerFastId;
    int m_timerSlowId;
    Location *m_currentLocation;
    QByteArray m_byteArray;
    QHostAddress m_host;
    QMap<QString, Satellite *> m_satellites;
    QMap<QString, Tle *> m_tles;
    quint16 m_port;
    Satellite *m_currentSatellite;
    std::list<Location *> m_locations;
    ZrvIoList m_ioList;
    QJsonObject jsonIdList();
    void requestGosat();

private slots:
    void readyReadSlot();
    void connectedSlot();
};

#endif /* SATVIEWER_H */
