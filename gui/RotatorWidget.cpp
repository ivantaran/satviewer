
#include "RotatorWidget.h"
#include <QMainWindow>
#include <QtMath>

RotatorWidget::RotatorWidget(QWidget *parent) : QDockWidget(parent) {
    ui.setupUi(this);
    QMainWindow *mainWindow = reinterpret_cast<QMainWindow *>(parent);
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, this);
    m_rotator.readSettings("rotator.json");

    connect(&m_rotator, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,
            SLOT(stateSocketChangedSlot(QAbstractSocket::SocketState)));
    connect(&m_rotator, SIGNAL(updatedState(const QString &)), this,
            SLOT(updatedStateSlot(const QString &)));
    connect(ui.buttonSendLine, SIGNAL(clicked()), this, SLOT(sendLine()));
}

RotatorWidget::~RotatorWidget() {
}

Rotator *RotatorWidget::getRotator() {
    return &m_rotator;
}

void RotatorWidget::stateSocketChangedSlot(QAbstractSocket::SocketState socketState) {
    QPalette palette = ui.labelConnection->palette();
    if (socketState == QTcpSocket::ConnectedState) {
        palette.setColor(QPalette::Window, Qt::green);
    } else {
        palette.setColor(QPalette::Window, Qt::yellow);
    }
    ui.labelConnection->setPalette(palette);
}

void RotatorWidget::updatedStateSlot(const QString &line) {
    ui.lineEditAzimuth->setText(
        QString("%1").arg(qRadiansToDegrees(m_rotator.getAngle(0)), 7, 'f', 2));
    ui.lineEditElevation->setText(
        QString("%1").arg(qRadiansToDegrees(m_rotator.getAngle(1)), 7, 'f', 2));
    qWarning() << line;
}

void RotatorWidget::sendLine() {
    m_rotator.writeLine(ui.lineEdit->text());
}
