
#include "RotatorWidget.h"
#include <QMainWindow>
#include <QtMath>

RotatorWidget::RotatorWidget(QWidget *parent) : QDockWidget(parent) {
    ui.setupUi(this);
    if (parent != nullptr && parent->isWindow()) {
        QMainWindow *mainWindow = reinterpret_cast<QMainWindow *>(parent);
        mainWindow->addDockWidget(Qt::LeftDockWidgetArea, this);
    }
    m_rotator.readSettings("rotator.json");
    ui.layoutRadar->addWidget(&m_radar);
    ui.tableValues->verticalHeader()->setDefaultSectionSize(ui.tableValues->verticalHeader()->minimumSectionSize());
    ui.tableRotator->verticalHeader()->setDefaultSectionSize(ui.tableRotator->verticalHeader()->minimumSectionSize());
    for (int j = 0; j < ui.tableRotator->horizontalHeader()->count(); j++) {
        ui.tableRotator->horizontalHeader()->setSectionResizeMode(j, QHeaderView::Stretch);
        for (int i = 0; i < ui.tableRotator->verticalHeader()->count(); i++) {
            QTableWidgetItem *item = new QTableWidgetItem("");
            item->setTextAlignment(Qt::AlignRight);
            ui.tableRotator->setItem(i, j, item);
        }
    }
    m_radar.setMinimumHeight(100);
    connect(&m_rotator, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,
            SLOT(stateSocketChangedSlot(QAbstractSocket::SocketState)));
    connect(&m_rotator, SIGNAL(updatedState(const QString &)), this,
            SLOT(updatedStateSlot(const QString &)));
    connect(ui.buttonSendLine, SIGNAL(clicked()), this, SLOT(sendLine()));
    connect(ui.buttonPark, SIGNAL(clicked()), &m_rotator, SLOT(park()));
    connect(ui.buttonReset, SIGNAL(clicked()), &m_rotator, SLOT(resetAll()));
    connect(ui.buttonStop, SIGNAL(clicked()), &m_rotator, SLOT(stop()));
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
    QString s;

    s = QString("%1").arg(qRadiansToDegrees(m_rotator.getAngle(0)), 7, 'f', 2);
    ui.tableRotator->item(0, 0)->setText(s);
    s = QString("%1").arg(qRadiansToDegrees(m_rotator.getAngle(1)), 7, 'f', 2);
    ui.tableRotator->item(0, 1)->setText(s);

    ui.tableRotator->item(3, 0)->setText(m_rotator.getStatusString(0));
    ui.tableRotator->item(3, 1)->setText(m_rotator.getStatusString(1));

    ui.tableRotator->item(4, 0)->setText(m_rotator.getErrorString(0));
    ui.tableRotator->item(4, 1)->setText(m_rotator.getErrorString(1));

    auto values = m_rotator.getValuesMap();
    int i = 0;
    if (values.count() != ui.tableValues->rowCount()) {
        ui.tableValues->clear();
        ui.tableValues->setRowCount(values.count());
        ui.tableValues->setColumnCount(2);
        ui.tableValues->setHorizontalHeaderItem(0, new QTableWidgetItem("Key"));
        ui.tableValues->setHorizontalHeaderItem(1, new QTableWidgetItem("Value"));
        for (auto key : values.keys()) {
            ui.tableValues->setItem(i, 0, new QTableWidgetItem(key));
            ui.tableValues->setItem(i, 1, new QTableWidgetItem(values[key]));
            i++;
        }
    } else {
        for (auto key : values.keys()) {
            QTableWidgetItem *item0 = ui.tableValues->item(i, 0);
            QTableWidgetItem *item1 = ui.tableValues->item(i, 1);
            if (item0 != nullptr && item1 != nullptr) {
                item0->setText(key);
                item1->setText(values[key]);
            }
            i++;
        }
    }
    m_radar.setSensor(m_rotator.getAngle(0), m_rotator.getAngle(1), true);
    // qWarning() << line;
}

void RotatorWidget::sendLine() {
    m_rotator.writeLine(ui.lineEdit->text());
}
