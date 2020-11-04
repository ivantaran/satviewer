#ifndef ROTATOR_H_
#define ROTATOR_H_

#include "Location.h"
#include "Satellite.h"

#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <QTimerEvent>

class Rotator : public QTcpSocket {
    Q_OBJECT

private:
    static const quint16 DEFAULT_PORT = 4533;
    static const QString DEFAULT_HOST;

    const Location *m_loc;
    const Satellite *m_sat;
    QHostAddress m_host;
    QMap<QString, QString> m_valuesMap;
    QStringList m_initList;
    quint16 m_port;
    bool m_tracking;

    typedef enum {
        StatusUnknown = 0x00,
        StatusIdle = 0x01,
        StatusMoving = 0x02,
        StatusPointing = 0x04,
        StatusError = 0x08,
        StatusHoming = 0x10,
        StatusUnhoming = 0x20,
    } ControllerStatus;

    typedef enum {
        ErrorOk = 0x00,
        ErrorSensor = 0x01,
        ErrorJam = 0x02,
        ErrorHoming = 0x04,
    } ControllerError;

    int m_timerSlowId;
    int m_timerFastId;

    QString m_stateLine;
    int m_status[2] = {StatusUnknown, StatusUnknown};
    int m_error[2] = {ErrorOk, ErrorOk};
    qreal m_pwm[2] = {0.0, 0.0};
    uint m_currentSensor[2] = {0, 0};
    uint m_diag[2] = {0, 0};
    uint m_direction[2] = {0, 0};
    qreal m_angle[2] = {0.0, 0.0};
    bool m_endstop[2] = {true, true};

    void readConfig(uint index, const QJsonObject &jsonObject);
    void requestPosition();
    void doTracking();

public:
    Rotator();
    virtual ~Rotator();

    bool isEndstop(uint index);
    bool isTracking() const;
    bool setTracking(bool value);
    const Location *getLocation() const;
    const QHostAddress getHost() const;
    const QString getDirectionString(uint index) const;
    const QString getErrorString(uint index) const;
    const QString getStatusString(uint index) const;
    const Satellite *getSatellite() const;
    qreal getAngle(uint index);
    qreal getCurrentAmp(uint index);
    qreal getPwm(uint index);
    quint16 getPort() const;
    uint getCurrentAdc(uint index);
    uint getDiag(uint index) const;
    uint getDirection(uint index) const;
    void clearError(uint index);
    void readSettings(const QString &fileName);
    void reconnect();
    void setHost(const QHostAddress &host);
    void setLocation(const Location *loc);
    void setMotion(uint index, qreal value);
    void setPort(quint16 port);
    void setSatellite(const Satellite *sat);
    void writeLine(const QString &line);
    void setPosition(double azimuth, double elevation);

    const QMap<QString, QString> getValuesMap() {
        return m_valuesMap;
    }

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void readyReadSlot();
    void connectedSlot();

public slots:
    void park();
    void requestConfigSlot();
    void resetAll();
    void stop();

signals:
    void updatedState(const QString &line);
};

#endif /* ROTATOR_H_ */