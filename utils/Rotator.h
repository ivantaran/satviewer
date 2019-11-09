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

    qreal m_pwmHoming[2] = {0.0, 0.0};
    qreal m_pwmMin[2] = {0.0, 0.0};
    qreal m_pwmMax[2] = {0.0, 0.0};
    qreal m_angleMin[2] = {0.0, 0.0};
    qreal m_angleMax[2] = {0.0, 0.0};
    qreal m_tolerance[2] = {0.0, 0.0};

    void readConfig(uint index, const QJsonObject &jsonObject);
    void acceptConfigRegister(uint index, uint addr, int value);
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
    qreal getPwmHoming(uint index);
    qreal getPwmMin(uint index);
    qreal getPwmMax(uint index);
    qreal getAngleMin(uint index);
    qreal getAngleMax(uint index);
    qreal getTolerance(uint index);

    void setMotion(uint index, qreal value);
    void setController(uint index, int kp, int ki, int kd);
    void setTarget(uint index, qreal angle);
    void setModeDefault(uint index);
    void setModePid(uint index, int kp, int ki, int kd);
    void setModeHoming(uint index);

    void setPwmHoming(uint index, qreal value);
    void setPwmMin(uint index, qreal value);
    void setPwmMax(uint index, qreal value);
    void setAngleMin(uint index, qreal value);
    void setAngleMax(uint index, qreal value);
    void setTolerance(uint index, qreal value);
    void setKp(uint index, int value);
    void setKi(uint index, int value);
    void setKd(uint index, int value);

    void writeLine(const QString &line);
    void clearError(uint index);
    void readSettings(const QString &fileName);
    void setConfig(uint index, qreal pwmHoming, qreal pwmMin, qreal pwmMax, qreal angleMin,
                   qreal angleMax, qreal tolerance, int rate, int kp, int ki, int kd);

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void readyReadSlot();

public slots:
    void requestConfigSlot();

signals:
    void updatedState(const QString &line);
};

#endif /* ROTATOR_H_ */