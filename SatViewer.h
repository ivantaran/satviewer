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
    SatViewer();
    virtual ~SatViewer();
    static void aerv(const double loc_rg[], const double sat_rg[], double aerv[]);
    void appendLocation(Location *loc);
    void appendSatellite(Satellite *sat);
    void clearLocations();
    void clearSatellites();
    void reconnect();
    void removeLocation(Location *loc);
    void removeSatellite(Satellite *sat);
    void setCurrentLocation(Location *loc);
    void setCurrentLocationIndex(long unsigned int index);
    void setCurrentSatellite(Satellite *sat);
    void setCurrentSatelliteIndex(long unsigned int index);
    void setTime(double value);
    void loadSatellitesJson();
    void saveSatellitesJson();

    const QMap<int, Satellite *> &satellites() {
        return m_satellites;
    }
    const std::list<Location *> &locations() {
        return m_locations;
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

protected:
    void timerEvent(QTimerEvent *event);

private:
    static const QString DEFAULT_HOST;
    static const quint16 DEFAULT_PORT = 8080;
    double m_time;
    int m_timerFastId;
    int m_timerSlowId;
    Location *m_currentLocation;
    QHostAddress m_host;
    quint16 m_port;
    Satellite *m_currentSatellite;
    std::list<Location *> m_locations;
    // std::list<Satellite *> m_satellites;
    QMap<int, Satellite *> m_satellites;
    ZrvIoList m_ioList;
    void requestGosat();

private slots:
    void readyReadSlot();
    void connectedSlot();
};

#endif /* SATVIEWER_H */
