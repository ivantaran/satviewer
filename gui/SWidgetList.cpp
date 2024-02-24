
/*
 * SWidgetList.cpp
 *
 *  Created on: 21.03.2010
 *      Author: Ivan Ryazanov
 */

#include "SWidgetList.h"
#include <QStandardItemModel>

SWidgetList::SWidgetList(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);
    clear();
    connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this,
            SLOT(changeState(const QModelIndex &)));
}

SWidgetList::~SWidgetList() {
}

void SWidgetList::init(QWidget *desktop, const QString &path) {
    QStandardItemModel *model = new QStandardItemModel();
    QDir dir(path);
    QStringList list = dir.entryList(QDir::Files);
    QFileInfo info;

    for (const auto &line : list) {
        info.setFile(line);
        if (info.suffix() == "js") {
            SWidget *sWidget = new SWidget(desktop, dir.filePath(line));
            this->append(sWidget);
            QStandardItem *item = new QStandardItem(sWidget->title());
            model->appendRow(item);
            item->setCheckable(true);
            item->setCheckState(Qt::Checked);
        }
    }

    ui.listView->setModel(model);
    stateFile.setFileName(dir.filePath("state.lst"));
    load();
}

void SWidgetList::setVars(Satellite *sat, Location *loc, double *time) {
    for (const auto &widget : (*this)) {
        widget->set(sat, loc, time);
    }
}

void SWidgetList::save() {
    if (!stateFile.open(QFile::WriteOnly | QFile::Text)) {
        qWarning() << stateFile.errorString();
        return;
    }
    QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
    QString line = "";

    for (int i = 0; i < model->rowCount(); i++) {
        if (model->item(i)->checkState() == Qt::Checked) {
            line.append('1');
        } else {
            line.append('0');
        }
    }

    stateFile.write(line.toLocal8Bit());
    stateFile.close();
}

void SWidgetList::load() {
    if (!stateFile.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << stateFile.errorString();
        return;
    }

    QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
    QString line = QString(stateFile.readLine());

    for (int i = 0; (i < line.length()) && (i < model->rowCount()); i++) {
        if (line.at(i) == '0') {
            model->item(i)->setCheckState(Qt::Unchecked);
            this->at(i)->activate(false);
        }
    }

    stateFile.close();
}

void SWidgetList::changeState(const QModelIndex &index) {
    QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
    if ((index.row() < 0) || (index.row() >= this->count())) {
        return;
    }
    if (model->item(index.row())->checkState() == Qt::Checked) {
        this->at(index.row())->activate();
    } else {
        this->at(index.row())->activate(false);
    }
}

void SWidgetList::setDesktop(QWidget *desktop) {
    for (const auto &widget : (*this)) {
        widget->setParent(desktop);
    }
}
