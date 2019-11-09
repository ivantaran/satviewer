
#include "RotatorSettings.h"

RotatorSettings::RotatorSettings(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    ui.buttonAdd->setDefaultAction(ui.actionAdd);
    ui.buttonRemove->setDefaultAction(ui.actionRemove);
    connect(ui.actionAdd, SIGNAL(triggered()), this, SLOT(addConnection()));
    connect(ui.actionRemove, SIGNAL(triggered()), this, SLOT(removeConnection()));
}

RotatorSettings::~RotatorSettings() {
}

void RotatorSettings::updateTable() {
    ui.tableWidget->setRowCount(0);
    ui.tableWidget->setRowCount(m_settings.count());
    int i = 0;
    for (const auto &name : m_settings.keys()) {
        ui.tableWidget->setItem(i, 0, new QTableWidgetItem(name));
        RotatorConnection *s = m_settings.value(name);
        ui.tableWidget->setItem(i, 1, new QTableWidgetItem(s->host.toString()));
        ui.tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(s->port)));
        i++;
    }
}

void RotatorSettings::addConnection() {
    m_settings.insert(QString("Name%1").arg(m_settings.count()), new RotatorConnection());
    updateTable();
    // ui.tableWidget->insertRow(ui.tableWidget->currentRow() + 1);
}

void RotatorSettings::removeConnection() {
    QModelIndexList list = ui.tableWidget->selectionModel()->selectedRows();
    for (const auto &row : list) {
        QString name = ui.tableWidget->item(row.row(), 0)->text();
        if (m_settings.contains(name)) {
            m_settings.remove(name);
        }
        // ui.tableWidget->removeRow(row.row());
    }
    updateTable();
}
