/*
 * SDlgOptions.h
 *
 *  Created on: 29.08.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SDLGOPTIONS_H_
#define SDLGOPTIONS_H_

#include "../Satellite.h"
#include "../ZrvIoList.h"
#include "../ogl/GLSatWidget.h"
#include "RotatorSettings.h"
#include "SLocDialog.h"
#include "SScriptFrame.h"
#include "SUpdater.h"
#include "SWidgetList.h"
#include "Sgp4Dialog.h"
#include "ui_options.h"
#include <QColorDialog>
#include <QDataWidgetMapper>
#include <QDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QtSql>
#include <inttypes.h>

class SDlgOptions : public QDialog {
    Q_OBJECT
public:
    Sgp4Dialog *satDialog;
    SLocDialog *locDialog;
    SScriptFrame *scriptFrame;
    SUpdater *tleFrame;
    SWidgetList *jswList;

    QSqlDatabase db;

    SDlgOptions(SatViewer *satviewer, GLSatAbstractWidget *w);
    virtual ~SDlgOptions();

    void setSatWidget(GLSatAbstractWidget *w);

    inline GLSatAbstractWidget *getSatWidget() const {
        return satWidget;
    }
    inline Ui::Dialog *getWidget() {
        return &widget;
    }

    void saveListViewSat();
    void saveListViewLoc();
    void loadListViewSat();
    void loadListViewLoc();
    void setRotatorSettings(RotatorSettings *rotatorSettings);

private:
    SatViewer *m_satviewer;
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
