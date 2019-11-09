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
    void updateTable();

public:
    RotatorSettings(QWidget *parent = nullptr, QWidget *mainWindow = nullptr);
    virtual ~RotatorSettings();

private slots:
    void addConnection();
    void removeConnection();
};

#endif /* ROTATORSETTINGS_H_ */