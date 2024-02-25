#ifndef ROTATOR_H_
#define ROTATOR_H_

#include <QHostAddress>
#include <QTcpSocket>
#include <QString>
#include <QTimerEvent>

class Rotator : public QTcpSocket {
    Q_OBJECT

private:
    static const quint16 DEFAULT_PORT = 4533;
    static const QString DEFAULT_HOST;
    QHostAddress m_host;
    quint16 m_port;
    QStringList m_initList;
    QMap<QString, QString> m_valuesMap;

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

public:
    Rotator();
    virtual ~Rotator();
    void setHost(const QHostAddress &host);
    void setPort(quint16 port);

    void reconnect();
    QHostAddress getHost() const;
    quint16 getPort() const;
    qreal getPwm(uint index);
    uint getCurrentAdc(uint index);
    qreal getCurrentAmp(uint index);
    uint getDiag(uint index);
    uint getDirection(uint index);
    const QString getDirectionString(uint index);
    const QString getStatusString(uint index);
    const QString getErrorString(uint index);
    qreal getAngle(uint index);
    bool isEndstop(uint index);

    const QMap<QString, QString> getValuesMap() { return m_valuesMap; }

    void setMotion(uint index, qreal value);


    void writeLine(const QString &line);
    void clearError(uint index);
    void readSettings(const QString &fileName);

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