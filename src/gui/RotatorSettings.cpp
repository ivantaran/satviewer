
#include "RotatorSettings.h"

RotatorSettings::RotatorSettings(QWidget *parent, QWidget *mainWindow) : QWidget(parent) {
    ui.setupUi(this);
    m_mainWindow = mainWindow;
    ui.buttonAdd->setDefaultAction(ui.actionAdd);
    ui.buttonRemove->setDefaultAction(ui.actionRemove);
    connect(ui.actionAdd, SIGNAL(triggered()), this, SLOT(addConnection()));
    connect(ui.actionRemove, SIGNAL(triggered()), this, SLOT(removeConnection()));
    addConnection();
}

RotatorSettings::~RotatorSettings() {
}

void RotatorSettings::updateTable() {
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setRowCount(m_settings.count());
    int i = 0;
    for (const auto &name : m_settings.keys()) {
        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        Rotator *rotator = m_settings.value(name)->getRotator();
        m_settings.value(name)->show();
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(rotator->getHost().toString()));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(rotator->getPort())));
        i++;
    }
}

void RotatorSettings::addConnection() {
    m_settings.insert(QString("Name%1").arg(m_settings.count()), new RotatorWidget(m_mainWindow));
    updateTable();
}

void RotatorSettings::removeConnection() {
    QModelIndexList list = ui.tableWidget->selectionModel()->selectedRows();
    for (const auto &row : list) {
        QString name = ui.tableWidget->item(row.row(), 0)->text();
        if (m_settings.contains(name)) {
            RotatorWidget *rotator = m_settings.value(name);
            m_settings.remove(name);
            rotator->deleteLater();
        }
    }
    updateTable();
}
