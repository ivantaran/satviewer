/*
 * SDlgOptions.h
 *
 *  Created on: 29.08.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SDLGOPTIONS_H_
#define SDLGOPTIONS_H_

#include <inttypes.h>
#include "ui_options.h"
#include "SLocDialog.h"
#include "satutils/Satellite.h"
#include "zrvutils/ZrvIoList.h"
//#include "jscalc/SScriptFrame.h"
#include "ogl/GLSatWidget.h"
#include "crd/crd.h"
#include "tleupd/SUpdater.h"
//#include "jswidgets/SWidgetList.h"

#include <QtSql>
#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include "SAbstractObjDialog.h"

class SDlgOptions: public QDialog {
	Q_OBJECT
public:
    typedef SAbstractObjDialog * (*CustomObjDialog)(GLSatAbstractWidget *satWidget);
    CustomObjDialog getSObjDialog;
    SAbstractObjDialog *satDialog;
    SLocDialog *locDialog;
//    SScriptFrame *scriptFrame;
    SUpdater *tleFrame;
//    SWidgetList *jswList;

    QSqlDatabase db;

    SDlgOptions(GLSatAbstractWidget *satWidget);
    virtual ~SDlgOptions();

    void setSatWidget(GLSatAbstractWidget *satWidget);

    inline GLSatAbstractWidget* getSatWidget() const { return satWidget; }
    inline Ui::Dialog* getWidget() { return &widget; }

    void saveListViewSat();
    void saveListViewLoc();
    void loadListViewSat();
    void loadListViewLoc();

private:
    Ui::Dialog widget;
    QDataWidgetMapper mapperSat, mapperLoc;
    QSqlTableModel *modelDbSat, *modelDbLoc;
    GLSatAbstractWidget *satWidget;
    void setDb();
    void setSat(Satellite *sat, QSqlRecord record);
    void setLoc(Location *loc, QSqlRecord record);
    void updateListViewSat();
    void updateListViewLoc();
    void setBtnColor(QWidget *widget);
    uint32_t flipRgb(uint32_t rgb);


private slots:
    void aboutQt();
    void addToSatList();
    void deleteSatList();
    void addToLocList();
    void deleteLocList();
    void selectPage(const QModelIndex &current, const QModelIndex &previous);
    void selectSatPage();
    void selectLocPage();
    void selectZrvPage();
    void selectParamsPage();
    void selectSettingsPage();
    void selectTlePage();
    void selectWidgetsPage();
    void selectMapPage();
    void selectAboutPage();
    void selectDbSat(const QModelIndex &current, const QModelIndex &previous);
    void selectDbLoc(const QModelIndex &current, const QModelIndex &previous);
    void selectSat(const QModelIndex &current, const QModelIndex &previous);
    void selectLoc(const QModelIndex &current, const QModelIndex &previous);
    void clearSatList();
    void clearLocList();
    void setFilterSatName(const QString &line);
    void setFilterLocName(const QString &line);
    void setFilterSat();
    void setFilterLoc();
    void loadDbFromTle();
    void addDbLoc();
    void loadDbLoc();
    void clearDbSat();
    void clearDbLoc();
    void deleteDbSat();
    void deleteDbLoc();
    void addToSatList(const QModelIndex &index);
    void addToLocList(const QModelIndex &index);
    void delFromSatList(const QModelIndex &index);
    void delFromLocList(const QModelIndex &index);
    void scriptParameters();
    void changeDbSat();
    void changeDbLoc();
    void helpSatSql();
    void helpLocSql();
};

#endif /* SDLGOPTIONS_H_ */
