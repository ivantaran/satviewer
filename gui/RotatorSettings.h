#ifndef ROTATORSETTINGS_H_
#define ROTATORSETTINGS_H_

#include "ui_rotatorSettings.h"
#include <QHostAddress>
#include <QString>
#include <QWidget>

class RotatorSettings : public QWidget {
    Q_OBJECT
private:
    Ui::RotatorSettings ui;

    class RotatorConnection {
    public:
        QHostAddress host = QHostAddress::LocalHost;
        quint16 port = 4533;
    };
    QMap <QString, RotatorConnection *> m_settings;
    void updateTable();
    
public:
    RotatorSettings(QWidget *parent = nullptr);
    virtual ~RotatorSettings();

private slots:
    void addConnection();
    void removeConnection();
};

#endif /* ROTATORSETTINGS_H_ */