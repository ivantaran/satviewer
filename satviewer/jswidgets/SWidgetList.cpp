/*
 * SWidgetList.cpp
 *
 *  Created on: 21.03.2010
 *      Author: Yan Coduemat
 */

#include "SWidgetList.h"
#include <QStandardItemModel>

SWidgetList::SWidgetList(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);
	connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(save()));
	connect(ui.listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(changeState(const QModelIndex &)));
}

SWidgetList::~SWidgetList() {

}

void SWidgetList::init(QWidget *desktop, QString path) {
	QStandardItemModel *model = new QStandardItemModel();
	QDir dir(path);
	QStringList list = dir.entryList(QDir::Files);
	QFileInfo info;
	SWidget *sWidget;
	QStandardItem *item;
	for (int i = 0; i < list.count(); i++) {
		info.setFile(list.at(i));
		if (info.suffix() == "js") {
			sWidget = new SWidget(desktop, dir.filePath(list.at(i)));
			this->append(sWidget);
			item = new QStandardItem(sWidget->title());
			model->appendRow(item);
			item->setCheckable(true);
			item->setCheckState(Qt::Checked);
		}
	}
	ui.listView->setModel(model);
	stateFile = new QFile(dir.filePath("state.lst"));
	load();
}

void SWidgetList::setVars(Satellite *sat, Location *loc, double *time) {
	for (int i = 0; i < this->count(); i++)
		this->at(i)->set(sat, loc, time);
}

void SWidgetList::save() {
	if (!stateFile->open(QFile::WriteOnly | QFile::Text)) {
		puts(stateFile->errorString().toLocal8Bit().data());
		return;
	}
	QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
	QString line = "";

	for (int i = 0; i < model->rowCount(); i++) {
		if (model->item(i)->checkState() == Qt::Checked) line.append('1');
		else line.append('0');
	}

	stateFile->write(line.toLocal8Bit());
	stateFile->close();
}

void SWidgetList::load() {
	if (!stateFile->open(QFile::ReadOnly | QFile::Text)) {
		puts(stateFile->errorString().toLocal8Bit().data());
		return;
	}

	QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
	QString line = QString(stateFile->readLine());

	for (int i = 0; (i < line.length()) && (i < model->rowCount()); i++) {
		if (line.at(i) == '0') {
			model->item(i)->setCheckState(Qt::Unchecked);
			this->at(i)->activate(false);
		}
	}

	stateFile->close();
}

void SWidgetList::changeState(const QModelIndex &index) {
	QStandardItemModel *model = (QStandardItemModel *)ui.listView->model();
	if ((index.row() < 0) || (index.row() >= this->count())) return;
	if (model->item(index.row())->checkState() == Qt::Checked) this->at(index.row())->activate();
	else this->at(index.row())->activate(false);
}

void SWidgetList::setDesktop(QWidget *desktop) {
	for(int i = 0; i < count(); i++) at(i)->setParent(desktop);
}
