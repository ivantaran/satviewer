
#include "RotatorWidget.h"
#include <QMainWindow>

RotatorWidget::RotatorWidget(QWidget *parent) : QDockWidget(parent) {
    ui.setupUi(this);
    QMainWindow *mainWindow = reinterpret_cast<QMainWindow *>(parent);
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, this);
    m_rotator.readSettings("rotator.json");

    connect(&m_rotator, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,
            SLOT(stateChangedSlot(QAbstractSocket::SocketState)));
    connect(&m_rotator, SIGNAL(updatedState(const QString &)), this,
            SLOT(updatedStateSlot(const QString &)));
}

RotatorWidget::~RotatorWidget() {
}

Rotator *RotatorWidget::getRotator() {
    return &m_rotator;
}

void RotatorWidget::stateChangedSlot(QAbstractSocket::SocketState socketState) {
    QPalette palette = ui.labelConnection->palette();
    if (socketState == QTcpSocket::ConnectedState) {
        palette.setColor(QPalette::Window, Qt::green);
    } else {
        palette.setColor(QPalette::Window, Qt::yellow);
    }
    ui.labelConnection->setPalette(palette);
}
