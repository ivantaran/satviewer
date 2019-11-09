#ifndef ROTATOR_WIDGET_H_
#define ROTATOR_WIDGET_H_

#include "../utils/Rotator.h"
#include "ui_rotator.h"
#include <QDockWidget>

class RotatorWidget : public QDockWidget {
    Q_OBJECT

private:
    Ui::Rotator ui;
    Rotator m_rotator;

public:
    RotatorWidget(QWidget *parent = nullptr);
    virtual ~RotatorWidget();
    Rotator *getRotator();

private slots:
    void stateChangedSlot(QAbstractSocket::SocketState socketState);
};

#endif /* ROTATOR_WIDGET_H_ */