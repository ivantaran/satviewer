#ifndef ROTATOR_WIDGET_H_
#define ROTATOR_WIDGET_H_

#include "../Rotator.h"
#include "RotatorRadar.h"

#include "ui_rotator.h"
#include <QDockWidget>

class RotatorWidget : public QDockWidget {
    Q_OBJECT

private:
    Ui::Rotator ui;
    Rotator m_rotator;
    RotatorRadar m_radar;

public:
    RotatorWidget(QWidget *parent = nullptr);
    virtual ~RotatorWidget();
    Rotator *getRotator();

private slots:
    void stateSocketChangedSlot(QAbstractSocket::SocketState socketState);
    void updatedStateSlot(const QString &line);
    void sendLine();
};

#endif /* ROTATOR_WIDGET_H_ */