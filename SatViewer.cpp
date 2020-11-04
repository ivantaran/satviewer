/*
 * File:   SatViewer.cpp
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 9:45 PM
 */

#include "SatViewer.h"
#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QtMath>
#include <float.h>

SatViewer::SatViewer() {
    m_host = QHostAddress::LocalHost;
    m_port = DefaultPort;

    m_satellites.clear();
    m_locations.clear();
    m_currentSatellite = nullptr;
    m_currentLocation = nullptr;
    m_time.setTime_t(0);

    QString path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    m_appDataDir = QDir(path);
    m_appDataDir.mkpath(m_appDataDir.absolutePath());

    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
    connect(this, SIGNAL(connected()), this, SLOT(connectedSlot()));

    m_timerSlowId = startTimer(5000);
    m_timerFastId = startTimer(1000);
    loadSatellitesJson();
    loadLocationsJson();
    loadLlas(m_appDataDir.absoluteFilePath("cities15000.txt"));
}

SatViewer::~SatViewer() {
    saveSatellitesJson();
    clearLlas();
    clearLocations();
    clearSatellites();
    clearTles();
}

void SatViewer::readyReadSlot() {
    QJsonParseError parseError;

    if (m_byteArray.size() > 0) { // TODO: check warning
        qWarning() << "m_byteArray isn't null:" << m_byteArray.size();
    }

    while (canReadLine()) {
        m_byteArray.append(readLine());
        QJsonDocument jsonDoc = QJsonDocument::fromJson(m_byteArray, &parseError);
        if (parseError.error != QJsonParseError::NoError) {
            break;
        }
        m_byteArray.clear();

        QJsonObject jsonObject = jsonDoc.object();
        if (jsonObject.contains("SatMap")) {
            for (const auto &item : jsonObject.value("SatMap").toObject()) {
                QJsonObject satelliteObject = item.toObject();
                QJsonArray coordsArray = satelliteObject.value("Coords").toArray();
                QJsonValue name = satelliteObject.value("Title");
                QJsonValue satnum = satelliteObject.value("Satnum");
                QJsonArray trackArray = satelliteObject.value("Track").toArray();

                // qWarning() << trackArray.size() << name;
                if (m_satellites.contains(name.toString())) {
                    Satellite *sat = m_satellites[name.toString()];
                    sat->setEcef(
                        coordsArray[0].toDouble() * 1000.0, coordsArray[1].toDouble() * 1000.0,
                        coordsArray[2].toDouble() * 1000.0, coordsArray[3].toDouble() * 1000.0,
                        coordsArray[4].toDouble() * 1000.0, coordsArray[5].toDouble() * 1000.0);

                    size_t i = 0;
                    sat->setTrackSize(trackArray.size());
                    for (auto jsonPoint : trackArray) {
                        QJsonArray jsonPointArray = jsonPoint.toArray();
                        double point[6] = {
                            jsonPointArray[0].toDouble() * 1000.0,
                            jsonPointArray[1].toDouble() * 1000.0,
                            jsonPointArray[2].toDouble() * 1000.0,
                            jsonPointArray[3].toDouble() * 1000.0,
                            jsonPointArray[4].toDouble() * 1000.0,
                            jsonPointArray[5].toDouble() * 1000.0,
                        };
                        sat->setTrackPoint(point, i);
                        i++;
                    }

                } else {
                    write(QString("{\"%0\": [\"%1\"]}\n")
                              .arg(KeyRemoveId)
                              .arg(name.toString())
                              .toUtf8());
                }
            }
        }
        if (jsonObject.contains("Sun")) {
            QJsonObject sunObject = jsonObject.value("Sun").toObject();
            QJsonArray coords = sunObject.value("Coords").toArray();
            m_sunEcef[0] = coords[0].toDouble();
            m_sunEcef[1] = coords[1].toDouble();
            m_sunEcef[2] = coords[2].toDouble();
            m_sunEcef[3] = coords[3].toDouble();
            m_sunEcef[4] = coords[4].toDouble();
            m_sunEcef[5] = coords[5].toDouble();
        }
        if (jsonObject.contains("TleMap")) {
            QJsonObject tleMap = jsonObject.value("TleMap").toObject();
            clearTles();
            for (const auto &jsonTle : tleMap) {
                QJsonObject tleObject = jsonTle.toObject();
                Tle *tle = new Tle();
                tle->satnum = tleObject.value("Satnum").toInt();
                QString id = tleObject.value("Title").toString();
                m_tles[id] = tle;
            }
            emit updatedTles();
        }
    }
}

void SatViewer::connectedSlot() {
    write(QJsonDocument(jsonIdList()).toJson());
    write("\n");
    write("{\"Names\": true}\n");
}

void SatViewer::reconnect() {
    if (state() == QTcpSocket::ConnectedState || state() == QTcpSocket::ConnectingState) {
    } else {
        connectToHost(m_host, m_port);
    }
}

void SatViewer::requestGosat() {
    if (state() == QTcpSocket::ConnectedState) {
        if (m_time.isNull()) {
            write("{}\n");
        } else {
            QString timeLine = m_time.toString("yyyy-MM-ddThh:mm:ss.zzzZ");
            QString timeJson = QString("{\"Time\":\"%0\"}\n").arg(timeLine);
            write(timeJson.toUtf8());
        }
    }
}

void SatViewer::timerEvent(QTimerEvent *event) {
    if (event->timerId() == m_timerSlowId) {
        reconnect();
    } else if (event->timerId() == m_timerFastId) {
        // requestGosat();
    }
}

void SatViewer::appendSatellite(const QString &name) {
    if (m_satellites.contains(name)) {
        // nothing
    } else {
        Satellite *sat = new Satellite(name);
        m_satellites[name] = sat;
        write(QString("{\"%0\": [\"%1\"]}\n").arg(KeyAppendId).arg(name).toUtf8());
    }
}

void SatViewer::appendLocation(const QString &name) {
}

void SatViewer::removeSatellite(const QString &name) {
    if (m_satellites.contains(name)) {
        Satellite *sat = m_satellites[name];
        m_satellites.remove(name);
        if (sat == currentSatellite()) {
            setCurrentSatelliteIndex(0);
        }
        delete sat;
    }
    emit updatedSatellites();
    //    ioList.deleteSat(satList.at(pos));
}

void SatViewer::removeLocation(int index) {
    // TODO 0 <= index < size()
    m_locations.removeAt(index);

    // if (m_locations.contains(name)) {
    //     Location *loc = m_locations[name];
    //     m_satellites.remove(name);
    //     if (loc == currentLocation()) {
    //         setCurrentLocationIndex(0);
    //     }
    //     delete loc;
    // }
    emit updatedLocations();
}

void SatViewer::clearSatellites() {
    for (auto &item : m_satellites) {
        if (item != nullptr) {
            delete item;
        }
    }
    m_satellites.clear();
}

void SatViewer::clearLocations() {
    for (auto &item : m_locations) {
        if (item != nullptr) {
            delete item;
        }
    }
    m_locations.clear();
}

void SatViewer::clearTles() {
    for (auto &item : m_tles) {
        if (item != nullptr) {
            delete item;
        }
    }
    m_tles.clear();
}

void SatViewer::clearLlas() {
    for (auto &item : m_llas) {
        if (item != nullptr) {
            delete item;
        }
    }
    m_llas.clear();
}

void SatViewer::loadLlas(const QString &fileName) {
    QFile file(fileName);
    bool ok = file.open(QFile::ReadOnly | QFile::Text);
    if (!ok) {
        qWarning() << __func__ << file.errorString();
        return;
    }
    QTextStream ts(&file);
    QString line = ts.readLine();
    while (!line.isNull()) {
        QStringList list = line.split(',');
        if (list.size() >= 3) {
            QString name = list[0].remove('"');
            double latitude = list[1].toDouble();
            double longitude = list[2].toDouble();
            double altitude = list[3].toDouble();
            m_llas.append(new Lla({name, {latitude, longitude, altitude}}));
        }
        line = ts.readLine();
    }
    file.close();
}

void SatViewer::loadSatellitesJson() {
    QString path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    QDir dir = QDir(path);
    dir.mkpath(dir.absolutePath());

    QFile file(dir.absoluteFilePath("satellites.json"));
    file.open(QFile::ReadOnly | QFile::Text);
    QString text = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    QJsonValue value = jsonObject.value(KeyAppendId);
    QJsonArray jsonArray = value.toArray();
    for (const auto &id : jsonArray) {
        QString name = id.toString();
        m_satellites[name] = new Satellite(name);
    }
}

void SatViewer::loadLocationsJson() {
    QString path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    QDir dir = QDir(path);
    dir.mkpath(dir.absolutePath());

    QFile file(dir.absoluteFilePath("locations.json"));
    file.open(QFile::ReadOnly | QFile::Text);
    QString text = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonArray jsonArray = jsonDoc.object().value("Locations").toArray();
    for (const auto &locValue : jsonArray) {
        QJsonObject locObject = locValue.toObject();
        QString name = locObject.value("Name").toString();
        double latitude = locObject.value("Latitude").toDouble();
        double longitude = locObject.value("Longitude").toDouble();
        double altitude = locObject.value("Altitude").toDouble();
        m_locations.append(new Location(name, latitude, longitude, altitude));
    }
}

QJsonObject SatViewer::jsonIdList() {
    QJsonArray jsonArray;
    for (const auto &id : m_satellites.keys()) {
        jsonArray.append(id);
    }
    QJsonObject jsonObject;
    jsonObject["IDList"] = jsonArray;
    return jsonObject;
}

void SatViewer::saveSatellitesJson() {
    QString path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    QDir dir = QDir(path);
    dir.mkpath(dir.absolutePath());

    QFile file(dir.absoluteFilePath("satellites.json"));
    file.open(QFile::WriteOnly | QFile::Text);

    file.write(QJsonDocument(jsonIdList()).toJson());
    file.close();
}

void SatViewer::saveLocationsJson() {
    // QString path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    // QDir dir = QDir(path);
    // dir.mkpath(dir.absolutePath());

    // QFile file(dir.absoluteFilePath("locations.json"));
    // file.open(QFile::WriteOnly | QFile::Text);

    // file.write(QJsonDocument(jsonIdList()).toJson());
    // file.close();
}

Satellite *SatViewer::currentSatellite() {
    return m_currentSatellite;
    //    if ((m_currentSatellite >= 0) &&
    //            ((long unsigned int)m_currentSatellite < m_satellites.size())) {
    //        auto item = m_satellites.begin();
    //        std::advance(item, m_currentSatellite);
    //        return (*item);
    //    }
    //    else {
    //        return nullptr;
    //    }
}

Location *SatViewer::currentLocation() {
    return m_currentLocation;
}

void SatViewer::setCurrentSatelliteIndex(long unsigned int index) {
    if (index < m_satellites.size()) {
        auto it = m_satellites.begin();
        std::advance(it, index);
        m_currentSatellite = (*it);
    } else {
        m_currentSatellite = nullptr;
    }
    emit currentChanged(m_currentSatellite, m_currentLocation, &m_delete_this_var);
}

void SatViewer::setCurrentLocationIndex(long unsigned int index) {
    if (index < m_locations.size()) {
        auto it = m_locations.begin();
        std::advance(it, index);
        m_currentLocation = (*it);
    } else {
        m_currentLocation = nullptr;
    }
    emit currentChanged(m_currentSatellite, m_currentLocation, &m_delete_this_var);
}

void SatViewer::setCurrentSatellite(Satellite *sat) {
    m_currentSatellite = sat;
    emit currentChanged(m_currentSatellite, m_currentLocation, &m_delete_this_var);
}

void SatViewer::setCurrentLocation(Location *loc) {
    m_currentLocation = loc;
    emit currentChanged(m_currentSatellite, m_currentLocation, &m_delete_this_var);
}

void SatViewer::setTime(const QDateTime &value) {
    m_time = value;
    requestGosat();
    emit timeChanged();
}

const QString SatViewer::KeyAppendId = "IDList";
const QString SatViewer::KeyRemoveId = "RemoveID";
