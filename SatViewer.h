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
#include <QDateTime>
#include <QDir>
#include <QHostAddress>
#include <QTcpSocket>
#include <QTimerEvent>

class SatViewer : public QTcpSocket {
    Q_OBJECT
public:
    struct Tle {
        int satnum;
    };
    struct Lla {
        QString name;
        double lla[3];
    };

    SatViewer();
    virtual ~SatViewer();
    static void aerv(const double loc_rg[], const double sat_rg[], double aerv[]);
    void appendLocation(const QString &name);
    void appendSatellite(const QString &name);
    void clearLlas();
    void clearLocations();
    void clearSatellites();
    void clearTles();
    void loadLlas(const QString &fileName);
    void loadLocationsJson();
    void loadSatellitesJson();
    void reconnect();
    void removeLocation(int index);
    void removeSatellite(const QString &name);
    void saveLocationsJson();
    void saveSatellitesJson();
    void setCurrentLocation(Location *loc);
    void setCurrentLocationIndex(long unsigned int index);
    void setCurrentSatellite(Satellite *sat);
    void setCurrentSatelliteIndex(long unsigned int index);
    void setTime(const QDateTime &value);

    const double *sunEcef() {
        return m_sunEcef;
    }

    const QMap<QString, Satellite *> &satellites() {
        return m_satellites;
    }
    const QList<Location *> &locations() {
        return m_locations;
    }
    const QMap<QString, Tle *> &tles() {
        return m_tles;
    }
    const QList<Lla *> &llas() {
        return m_llas;
    }
    Satellite *currentSatellite();
    Location *currentLocation();
    ZrvIoList *ioList() {
        return &m_ioList;
    }
    const QDateTime &time() {
        return m_time;
    }

signals:
    void currentChanged(Satellite *sat, Location *loc, double *time);
    void timeChanged();
    void updatedLlas();
    void updatedLocations();
    void updatedSatellites();
    void updatedTles();

protected:
    void timerEvent(QTimerEvent *event);

private:
    static const QString KeyAppendId;
    static const QString KeyRemoveId;
    static const quint16 DefaultPort = 8080;

    QDateTime m_time;
    double m_delete_this_var = 0.0;
    double m_sunEcef[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    int m_timerFastId;
    int m_timerSlowId;
    Location *m_currentLocation;
    QByteArray m_byteArray;
    QDir m_appDataDir;
    QHostAddress m_host;
    QJsonObject jsonIdList();
    QList<Lla *> m_llas;
    QList<Location *> m_locations;
    QMap<QString, Satellite *> m_satellites;
    QMap<QString, Tle *> m_tles;
    quint16 m_port;
    Satellite *m_currentSatellite;
    ZrvIoList m_ioList;
    void requestGosat();

private slots:
    void readyReadSlot();
    void connectedSlot();
};

#endif /* SATVIEWER_H */
