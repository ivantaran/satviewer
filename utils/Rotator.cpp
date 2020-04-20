
#include "Rotator.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtMath>

Rotator::Rotator() {
    m_host = QHostAddress::LocalHost;
    m_port = DEFAULT_PORT;

    connect(this, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));
    connect(this, SIGNAL(connected()), this, SLOT(connectedSlot()));

    m_timerSlowId = startTimer(5000);
    m_timerFastId = startTimer(1000);
}

Rotator::~Rotator() {
    qWarning() << __func__ << endl;
}

void Rotator::timerEvent(QTimerEvent *event) {
    if (event->timerId() == m_timerSlowId) {
        requestConfigSlot();
        reconnect();
    } else if (event->timerId() == m_timerFastId) {
        requestPosition();
    }
}

void Rotator::setHost(const QHostAddress &host) {
    m_host = host;
}

void Rotator::setPort(quint16 port) {
    m_port = port;
}

QHostAddress Rotator::getHost() const {
    return m_host;
}

quint16 Rotator::getPort() const {
    return m_port;
}

void Rotator::reconnect() {
    if (state() == QTcpSocket::ConnectedState || state() == QTcpSocket::ConnectingState) {

    } else {
        connectToHost(m_host, m_port);
    }
}

void Rotator::writeLine(const QString &line) {
    if (state() == ConnectedState && isOpen() && isWritable()) {
        write((line + "\n").toUtf8());
        qWarning() << (line + "\n");
        flush();
    }
}

void Rotator::connectedSlot() {
    for (const auto &line : m_initList) {
        writeLine(line);
    }
}

void Rotator::readyReadSlot() {
    bool ok_addr, ok_value;
    uint addr;
    int vi;
    qreal vr;

    while (canReadLine()) {
        m_stateLine = QString::fromUtf8(readLine()).trimmed();
        
        if (m_stateLine.isEmpty()) {
            continue;
        }

        QStringList list = m_stateLine.split(QChar(' '));
        QRegExp r("([A-Z]{2})([-+]?[0-9a-z]+\\.?[0-9]*)?(\\,)?([-+]?[0-9]*\\.?[0-9]*)");
        for (const auto &sub : list) {
            r.exactMatch(sub);
            if (r.cap(1) == "GS") {
                vi = r.cap(2).toInt(&ok_value);
                m_status[0] = vi & 0xff;
                m_status[1] = (vi >> 8) & 0xff;
            } else if (r.cap(1) == "GE") {
                vi = r.cap(2).toInt(&ok_value);
                m_error[0] = vi & 0xff;
                m_error[1] = (vi >> 8) & 0xff;
            } else if (r.cap(1) == "AZ") {
                vr = r.cap(2).toDouble(&ok_value);
                if (ok_value) {
                    m_angle[0] = qDegreesToRadians(vr);
                }
            } else if (r.cap(1) == "EL") {
                vr = r.cap(2).toDouble(&ok_value);
                if (ok_value) {
                    m_angle[1] = qDegreesToRadians(vr);
                }
            }
            if (r.cap(3) == ",") {
                m_valuesMap[r.cap(1) + r.cap(2)] = r.cap(4);
            } else if (!r.cap(2).isEmpty()) {
                m_valuesMap[r.cap(1)] = r.cap(2);
            }
        }

        emit updatedState(m_stateLine);
    }
}

qreal Rotator::getPwm(uint index) {
    return index < 2 ? m_pwm[index] : 0;
}

uint Rotator::getCurrentAdc(uint index) {
    return index < 2 ? m_currentSensor[index] : 0;
}

qreal Rotator::getCurrentAmp(uint index) {
    qreal voltage = 5.0 / 1024.0 * (qreal)getCurrentAdc(index);
    qreal current = voltage / 1500.0;
    current *= 4700.0 / 700.0 * 1500.0;
    return current;
}

uint Rotator::getDiag(uint index) {
    return index < 2 ? m_diag[index] : 0;
}

uint Rotator::getDirection(uint index) {
    return index < 2 ? m_direction[index] : 0;
}

const QString Rotator::getDirectionString(uint index) {
    QString result;
    switch (getDirection(index)) {
    case 0:
        result = "Brakedown";
        break;
    case 1:
        result = "Positive";
        break;
    case 2:
        result = "Negative";
        break;
    case 3:
        result = "Breakup";
        break;
    default:
        result = "Unknown";
        break;
    }
    return result;
}

const QString Rotator::getStatusString(uint index) {
    QString result;

    if (index < 2) {
        switch (m_status[index]) {
        case StatusIdle:
            result = "Idle";
            break;
        case StatusMoving:
            result = "Moving";
            break;
        case StatusPointing:
            result = "Pointing";
            break;
        case StatusHoming:
            result = "Homing";
            break;
        case StatusUnhoming:
            result = "Unhoming";
            break;
        case StatusError:
            result = "Error";
            break;
        default:
            result = QString("Unknown [0x%1]").arg(m_status[index], 2, 16, QChar('0'));
            break;
        }
    }

    return result;
}

const QString Rotator::getErrorString(uint index) {
    QString result;

    if (index < 2) {
        result = QString("%1").arg(m_error[index], 8, 2, QChar('0'));
    }

    return result;
}

qreal Rotator::getAngle(uint index) {
    return index < 2 ? m_angle[index] : 0.0;
}

void Rotator::clearError(uint index) {
    writeLine(QString("%1").arg(index == 0 ? "AC" : "EC"));
}

void Rotator::requestConfigSlot() {
    writeLine(QString("w AR0 AR1 AR2 AR3 AR4 AR5 AR6 AR7 AR8 AR9 ARa ARb"));
    writeLine(QString("w ER0 ER1 ER2 ER3 ER4 ER5 ER6 ER7 ER8 ER9 ERa ERb"));
    writeLine(QString("w GE GS"));
}

void Rotator::requestPosition() {
    writeLine(QString("w AZ EL"));
}

void Rotator::park() {
    writeLine(QString("K"));
}

void Rotator::resetAll() {
    writeLine(QString("R 1"));
}

void Rotator::stop() {
    writeLine(QString("S"));
}

void Rotator::readSettings(const QString &fileName) {
    QString text;
    QJsonValue value;

    QFile file(fileName);
    file.open(QFile::ReadOnly | QFile::Text);
    text = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(text.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();

    m_initList.clear();
    value = jsonObject.value("init");
    QJsonArray jsonArray = value.toArray();
    for (const auto &item: jsonArray) {
        m_initList.append(item.toString());
    }

    value = jsonObject.value("host");
    m_host = QHostAddress(value.toString(DEFAULT_HOST));
    value = jsonObject.value("port");
    m_port = value.toInt(DEFAULT_PORT);
}

const QString Rotator::DEFAULT_HOST = QHostAddress(QHostAddress::LocalHost).toString();
