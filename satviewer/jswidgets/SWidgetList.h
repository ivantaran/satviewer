/*
 * SWidgetList.h
 *
 *  Created on: 21.03.2010
 *      Author: Yan Coduemat
 */

#ifndef SWIDGETLIST_H_
#define SWIDGETLIST_H_

#include "SWidget.h"
#include <QList>
#include <QWidget>
#include "ui_jswidgetlist.h"

class SWidgetList : public QWidget, private QList <SWidget *> {
	Q_OBJECT
public:
	SWidgetList(QWidget *parent = 0);
	void init(QWidget *desktop = 0, QString path = "");
	virtual ~SWidgetList();
	void setVars(Satellite *sat, Location *loc, double *time);
	inline void retranslateUi() { ui.retranslateUi(this); }
	void setDesktop(QWidget *desktop);
private:
	Ui::JsWidgetList ui;
	QFile *stateFile;
	void load();
private slots:
	void save();
	void changeState(const QModelIndex &index);
};

#endif /* SWIDGETLIST_H_ */
