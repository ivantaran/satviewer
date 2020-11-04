#ifndef ROTATORSETTINGS_H_
#define ROTATORSETTINGS_H_

#include "RotatorWidget.h"
#include "ui_rotatorSettings.h"

#include <QHostAddress>
#include <QString>
#include <QWidget>

class RotatorSettings : public QWidget {
    Q_OBJECT
private:
    QWidget *m_mainWindow;
    Ui::RotatorSettings ui;
    QMap<QString, RotatorWidget *> m_settings;
    const Satellite *m_sat;
    const Location *m_loc;
    void updateTable();

public:
    RotatorSettings(QWidget *parent = nullptr, QWidget *mainWindow = nullptr);
    virtual ~RotatorSettings();
    void setSatellite(const Satellite *sat);
    void setLocation(const Location *loc);

private slots:
    void addConnection();
    void removeConnection();
    void trackSlot();
};

#endif /* ROTATORSETTINGS_H_ */