// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * SDlgOptions.cpp
 *
 *  Created on: 22.12.2009
 *      Author: Ivan Ryazanov
 */
#include "SDlgOptions.h"
#include "sql/dbsql.h"
#include <fstream>
#include "../dialogs/sgp4/Sgp4Dialog.h"

SDlgOptions::SDlgOptions(GLSatAbstractWidget *satWidget) {
    this->setupUi(this);

////    getSObjDialog(satWidget)->show();
//    satDialog = getSObjDialog(satWidget);
    satDialog = new Sgp4Dialog(satWidget);
    satDialog->setParent(this, Qt::Dialog | Qt::WindowTitleHint);
    satDialog->setWindowModality(Qt::WindowModal);

    locDialog = new SLocDialog(satWidget);
    locDialog->setParent(this, Qt::Dialog | Qt::WindowTitleHint);
    locDialog->setWindowModality(Qt::WindowModal);

    QDir dir = QDir::home();
//    dir.cd("satviewer/jsprm");
//    scriptFrame = new SScriptFrame(dir.filePath("prmlist.js"));
//    scriptFrame->setParent(tabWidget);
//    stackedWidget->insertWidget(4, scriptFrame);
//
//    jswList = new SWidgetList();
//    jswList->setParent(tabWidget);
//    stackedWidget->insertWidget(5, jswList);

    dir = QDir::home();
    dir.cd("satviewer/tle");
    tleFrame = new SUpdater(dir.filePath("tle_list.lst"));
    tleFrame->setParent(tabWidget);
    stackedWidget->insertWidget(4, tleFrame);// TODO 6

    setSatWidget(satWidget);

    //connect(listView->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(selectPage(const QModelIndex &, const QModelIndex &)));
    connect( btnToolSat     , SIGNAL(clicked()), this, SLOT(selectSatPage     ()) );
    connect( btnToolLoc     , SIGNAL(clicked()), this, SLOT(selectLocPage     ()) );
    connect( btnToolZRV     , SIGNAL(clicked()), this, SLOT(selectZrvPage     ()) );
    connect( btnToolParams  , SIGNAL(clicked()), this, SLOT(selectParamsPage  ()) );
    connect( btnInfo        , SIGNAL(clicked()), this, SLOT(selectAboutPage   ()) );
    connect( btnToolSettings, SIGNAL(clicked()), this, SLOT(selectSettingsPage()) );
    connect( btnToolTle     , SIGNAL(clicked()), this, SLOT(selectTlePage     ()) );
    connect( btnToolWidgets , SIGNAL(clicked()), this, SLOT(selectWidgetsPage ()) );
    connect( btnToolMap     , SIGNAL(clicked()), this, SLOT(selectMapPage     ()) );
    connect( btnAboutQt     , SIGNAL(clicked()), this, SLOT(aboutQt           ()) );
    
    setDb();
    
    connect(lineEditSatNameFilter, SIGNAL(textChanged(const QString &)), this, SLOT(setFilterSatName(const QString &)));
    connect(lineEditLocNameFilter, SIGNAL(textChanged(const QString &)), this, SLOT(setFilterLocName(const QString &)));
    connect(btnSatSqlHelp, SIGNAL(clicked()), this, SLOT(helpSatSql  ()));
    connect(btnLocSqlHelp, SIGNAL(clicked()), this, SLOT(helpLocSql  ()));
    connect(btnSatFilter , SIGNAL(clicked()), this, SLOT(setFilterSat()));
    connect(btnLocFilter , SIGNAL(clicked()), this, SLOT(setFilterLoc()));

    connect(btnOpenTle    , SIGNAL(clicked()), this, SLOT(loadDbFromTle()));
    connect(btnOpenLoc    , SIGNAL(clicked()), this, SLOT(loadDbLoc    ()));
    connect(btnAddDbLoc   , SIGNAL(clicked()), this, SLOT(addDbLoc     ()));
    connect(btnDeleteDbSat, SIGNAL(clicked()), this, SLOT(deleteDbSat  ()));
    connect(btnDeleteDbLoc, SIGNAL(clicked()), this, SLOT(deleteDbLoc  ()));
    connect(btnClearDbSat , SIGNAL(clicked()), this, SLOT(clearDbSat   ()));
    connect(btnClearDbLoc , SIGNAL(clicked()), this, SLOT(clearDbLoc   ()));


    connect(listViewDBSat, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addToSatList(const QModelIndex &)));
    connect(listViewDBLoc, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addToLocList(const QModelIndex &)));
    connect(listViewSat, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(changeDbSat()));
    connect(listViewLoc, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(changeDbLoc()));
//    connect(scriptFrame->btnRefresh, SIGNAL(clicked()), this, SLOT(scriptParameters()));
    connect(btnDeleteSatList, SIGNAL(clicked()), this, SLOT(deleteSatList()));
    connect(btnDeleteLocList, SIGNAL(clicked()), this, SLOT(deleteLocList()));
    connect(btnAddToSatList , SIGNAL(clicked()), this, SLOT(addToSatList ()));
    connect(btnAddToLocList , SIGNAL(clicked()), this, SLOT(addToLocList ()));
    connect(btnClearSatList , SIGNAL(clicked()), this, SLOT(clearSatList ()));
    connect(btnClearLocList , SIGNAL(clicked()), this, SLOT(clearLocList ()));
    connect(btnChangeDbSat  , SIGNAL(clicked()), this, SLOT(changeDbSat  ()));
    connect(btnChangeDbLoc  , SIGNAL(clicked()), this, SLOT(changeDbLoc  ()));
}

SDlgOptions::~SDlgOptions() {
    db.close();
}

void SDlgOptions::saveListViewSat() {
    db.exec("DELETE FROM sattemp;");
    if (satWidget->satList.count() < 1) return;

    double const deg2rad = M_PI/180.0;
    double const xpdotp = 1440.0/(2.0*M_PI);

    Satellite *sat;
    QString query;
    db.exec("BEGIN;");

	for (int i = 0; i < satWidget->satList.count(); i++) {
		sat = satWidget->satList.at(i);
		query = QString("INSERT INTO sattemp ('i', 'omg', 'e', 'w', 'm0', 'bstar', 'n', "
						"'time', 'name', 'zrv', 'icon', 'show_label', 'show_track', "
						"'show_zrv', 'show_lines', 'active_zone', 'color_track', "
						"'color_label', 'color_zrv', 'color_lines', 'track', 'font', "
						"'name_x', 'name_y', 'lines_width', 'model_index', 'model_state') "
						"VALUES(%0, %1, %2, %3, %4, %5, %6, %7, '%8', %9, '%10', %11, %12, "
						"%13, %14, %15, %16, %17, %18, %19, %20, '%21', %22, %23, %24, %25, :model_state);")
						.arg(sat->inclination()/deg2rad, 0, 'g', 16)
						.arg(sat->argLatPerigee()/deg2rad, 0, 'g', 16)
						.arg(sat->eccentricity(), 0, 'g', 16)
						.arg(sat->latAscNode()/deg2rad, 0, 'g', 16)
						.arg(sat->meanAnomaly()/deg2rad, 0, 'g', 16)
						.arg(sat->bStar(), 0, 'g', 16)
						.arg(sat->meanMotion()*xpdotp, 0, 'g', 16)
						.arg(sat->jEpoch(), 0, 'g', 16)
						.arg(sat->name())
						.arg(sat->zrvWidth()/deg2rad, 0, 'g', 16)
						.arg(sat->iconName())
						.arg(sat->isVisibleLabel())
						.arg(sat->isVisibleTrack())
						.arg(sat->isVisibleZrv())
						.arg(sat->isVisibleLines())
						.arg(sat->isAtctiveZone())
						.arg(sat->colorTrack())
						.arg(sat->colorLabel())
						.arg(sat->colorZrv())
						.arg(sat->colorLines())
						.arg(sat->track(), 0, 'g', 16)
						.arg(sat->font().toString())
						.arg(sat->nameX(), 0, 'g', 16)
						.arg(sat->nameY(), 0, 'g', 16)
						.arg(sat->linesWidth(), 0, 'g', 16)
						.arg(sat->modelIndex());
        QSqlQuery q(db);
        q.prepare(query);
        printf("state length %d\n", sat->getStateSize());
        QByteArray bytes(sat->getState(), sat->getStateSize());
        printf("bytes length %d\n", bytes.length());
        puts(bytes.toHex().data());
        q.bindValue(":model_state", bytes);
        q.exec();
        puts(q.executedQuery().toLocal8Bit().data());
//		db.exec(query);
	}
	db.exec("COMMIT;");
}

void SDlgOptions::saveListViewLoc() {
    db.exec("DELETE FROM loctemp;");
    if (satWidget->locList.count() < 1) return;

    Location *loc;
    QString query;
    db.exec("BEGIN;");

	for (int i = 0; i < satWidget->locList.count(); i++) {
		loc = satWidget->locList.at(i);
		query = QString("INSERT INTO loctemp ('lat', 'lon', 'height', 'azimuth', 'sector', "
						"'r', 'name', 'icon', 'show_label', 'show_zrv', 'show_lines', "
						"'active_zone', 'color_label', 'color_zrv', 'color_lines', 'font', "
						"'name_x', 'name_y', 'lines_width') "
						"VALUES(%0, %1, %2, %3, %4, %5, '%6', '%7', %8, %9, %10, %11, %12, "
						"%13, %14, '%15', %16, %17, %18);")
						.arg(loc->latitude(), 0, 'g', 16)
						.arg(loc->longitude(), 0, 'g', 16)
						.arg(loc->height(), 0, 'g', 16)
						.arg(loc->zrlAzimuth(), 0, 'g', 16)
						.arg(loc->zrlWidth(), 0, 'g', 16)
						.arg(loc->zrlRange(), 0, 'g', 16)
						.arg(loc->name())
						.arg(loc->iconName())
						.arg(loc->isVisibleLabel())
						.arg(loc->isVisibleZrv())
						.arg(loc->isVisibleLines())
						.arg(loc->isActiveZone())
						.arg(loc->colorLabel())
						.arg(loc->colorZrv())
						.arg(loc->colorLines())
						.arg(loc->font().toString())
						.arg(loc->nameX(), 0, 'g', 16)
						.arg(loc->nameY(), 0, 'g', 16)
						.arg(loc->linesWidth(), 0, 'g', 16);
		db.exec(query);
	}
	db.exec("COMMIT;");
}

void SDlgOptions::loadListViewSat() {
	QSqlTableModel modelSatTemp;
	modelSatTemp.setTable("sattemp");
	modelSatTemp.setEditStrategy(QSqlTableModel::OnManualSubmit);
	modelSatTemp.select();

	while (modelSatTemp.canFetchMore()) {
		modelSatTemp.fetchMore();
	}

	Satellite *sat;
	int model_index;
	for (int i = 0; i < modelSatTemp.rowCount(); i++) {
		model_index = modelSatTemp.record(i).field("model_index").value().toInt();
		satWidget->setSatModel(model_index);
//		sat = satWidget->satList.add(satWidget->getSatModel());
		sat = satWidget->getSatModel();
		sat->setModelIndex(model_index);
		setSat(sat, modelSatTemp.record(i));
		sat->visibleLabel (modelSatTemp.record(i).field("show_label" ).value().toBool());
		sat->visibleTrack (modelSatTemp.record(i).field("show_track" ).value().toBool());
		sat->visibleZrv   (modelSatTemp.record(i).field("show_zrv"   ).value().toBool());
		sat->visibleLines (modelSatTemp.record(i).field("show_lines" ).value().toBool());
		sat->activeZone   (modelSatTemp.record(i).field("active_zone").value().toBool());
		sat->setColorTrack(modelSatTemp.record(i).field("color_track").value().toUInt());
		sat->setColorLabel(modelSatTemp.record(i).field("color_label").value().toUInt());
		sat->setColorZrv  (modelSatTemp.record(i).field("color_zrv"  ).value().toUInt());
		sat->setColorLines(modelSatTemp.record(i).field("color_lines").value().toUInt());
		sat->setTrack     (modelSatTemp.record(i).field("track"      ).value().toDouble());
		QFont font;
		font.fromString(modelSatTemp.record(i).field("font").value().toString());
		sat->setFont(font);
		sat->setNameX(modelSatTemp.record(i).field("name_x").value().toDouble());
		sat->setNameY(modelSatTemp.record(i).field("name_y").value().toDouble());
		sat->setLinesWidth(modelSatTemp.record(i).field("lines_width").value().toDouble());
        satWidget->addSat(sat);
	}
	modelSatTemp.clear();

	updateListViewSat();
	if (satWidget->satList.count() == 1) satWidget->setIndexSat(0);
	satWidget->refreshAll();
}

void SDlgOptions::loadListViewLoc() {
	QSqlTableModel modelLocTemp;
	modelLocTemp.setTable("loctemp");
	modelLocTemp.setEditStrategy(QSqlTableModel::OnManualSubmit);
	modelLocTemp.select();

	while (modelLocTemp.canFetchMore()) {
		modelLocTemp.fetchMore();
	}

	Location *loc;
	for (int i = 0; i < modelLocTemp.rowCount(); i++) {
		loc = new Location();
		setLoc(loc, modelLocTemp.record(i));
		loc->visibleLabel (modelLocTemp.record(i).field("show_label" ).value().toBool());
		loc->visibleZrv   (modelLocTemp.record(i).field("show_zrv"   ).value().toBool());
		loc->visibleLines (modelLocTemp.record(i).field("show_lines" ).value().toBool());
		loc->activeZone   (modelLocTemp.record(i).field("active_zone").value().toBool());
		loc->setColorLabel(modelLocTemp.record(i).field("color_label").value().toUInt());
		loc->setColorZrv  (modelLocTemp.record(i).field("color_zrv"  ).value().toUInt());
		loc->setColorLines(modelLocTemp.record(i).field("color_lines").value().toUInt());
		QFont font;
		font.fromString   (modelLocTemp.record(i).field("font"       ).value().toString());
		loc->setFont(font);
		loc->setNameX     (modelLocTemp.record(i).field("name_x"     ).value().toDouble());
		loc->setNameY     (modelLocTemp.record(i).field("name_y"     ).value().toDouble());
		loc->setLinesWidth(modelLocTemp.record(i).field("lines_width").value().toDouble());
        satWidget->addLoc(loc);
	}
	modelLocTemp.clear();

	updateListViewLoc();
	if (satWidget->locList.count() == 1) satWidget->setIndexLoc(0);
	satWidget->refreshAll();
}

void SDlgOptions::setDb() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir = QDir::home();
    dir.cd("satviewer");
    db.setDatabaseName(dir.filePath("main.db"));
    if (!db.open()) QMessageBox::information(this, "Error", db.lastError().text() + "\n" + dir.filePath("main.db"), 0);

    db.exec( QString(sqlSat    ) );
    db.exec( QString(sqlSatTemp) );
    db.exec( QString(sqlLoc    ) );
    db.exec( QString(sqlLocTemp) ); // sun model problem

    modelDbSat = new QSqlTableModel(this, db);
    modelDbSat->setTable("sat");
    modelDbSat->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelDbSat->select();

    while (modelDbSat->canFetchMore()) {
        modelDbSat->fetchMore();
    }

    listViewDBSat->setModel(modelDbSat);
    connect(listViewDBSat->selectionModel(), 
            SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
            this, 
            SLOT(selectDbSat(const QModelIndex &, const QModelIndex &))
            );
    listViewDBSat->setModelColumn(modelDbSat->fieldIndex("name"));

    mapperSat.setModel(modelDbSat);
    mapperSat.addMapping(lineEditSatName , modelDbSat->fieldIndex("name")     );
    mapperSat.addMapping(lineEditSatGroup, modelDbSat->fieldIndex("groupname"));
    mapperSat.addMapping(lineEditSatI    , modelDbSat->fieldIndex("i")        );
    mapperSat.addMapping(lineEditSatOmg  , modelDbSat->fieldIndex("omg")      );
    mapperSat.addMapping(lineEditSatE    , modelDbSat->fieldIndex("e")        );
    mapperSat.addMapping(lineEditSatW    , modelDbSat->fieldIndex("w")        );
    mapperSat.addMapping(lineEditSatM0   , modelDbSat->fieldIndex("m0")       );
    mapperSat.addMapping(lineEditSatN    , modelDbSat->fieldIndex("n")        );
    mapperSat.addMapping(lineEditSatBStar, modelDbSat->fieldIndex("bstar")    );
    mapperSat.toFirst();

    modelDbLoc = new QSqlTableModel(this, db);
    modelDbLoc->setTable("loc");
    modelDbLoc->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelDbLoc->select();

    while (modelDbLoc->canFetchMore()) {
        modelDbLoc->fetchMore();
    }

    listViewDBLoc->setModel(modelDbLoc);
    connect(listViewDBLoc->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(selectDbLoc(const QModelIndex &, const QModelIndex &)));
    listViewDBLoc->setModelColumn(modelDbLoc->fieldIndex("name"));

    mapperLoc.setModel(modelDbLoc);
    mapperLoc.addMapping(lineEditLocName   , modelDbLoc->fieldIndex("name")   );
    mapperLoc.addMapping(lineEditLocLat    , modelDbLoc->fieldIndex("lat")    );
    mapperLoc.addMapping(lineEditLocLon    , modelDbLoc->fieldIndex("lon")    );
    mapperLoc.addMapping(lineEditLocHeight , modelDbLoc->fieldIndex("height") );
    mapperLoc.addMapping(lineEditLocAzimuth, modelDbLoc->fieldIndex("azimuth"));
    mapperLoc.addMapping(lineEditLocWidth  , modelDbLoc->fieldIndex("sector") );
    mapperLoc.addMapping(lineEditLocRange  , modelDbLoc->fieldIndex("r")      );
    mapperLoc.toFirst();
}

void SDlgOptions::setSat(Satellite *sat, QSqlRecord record) {
    if (sat == 0 || record.isEmpty()) return;
//    double const deg2rad = M_PI/180.0;
//    double const xpdotp = 1440.0/(2.0*M_PI);
//    double i         = record.field("i"    ).value().toDouble()*deg2rad;
//    double omg       = record.field("omg"  ).value().toDouble()*deg2rad;
//    double e         = record.field("e"    ).value().toDouble();
//    double w         = record.field("w"    ).value().toDouble()*deg2rad;
//    double mo        = record.field("m0"   ).value().toDouble()*deg2rad;
//    double no        = record.field("n"    ).value().toDouble()/xpdotp;
//    double bstar     = record.field("bstar").value().toDouble();
//    double jdsaepoch = record.field("time" ).value().toDouble();
    QByteArray model_state = record.field("model_state").value().toByteArray();
    if (model_state.size() < 1) {
        puts("empty model");
        return;
    }
    
    printf("bytes length %d\n", model_state.length());
    puts(model_state.toHex().data());
    QString icon     = record.field("icon" ).value().toString();
    if (icon.isEmpty() || !QFile::exists(icon)) {
        QDir dir = QDir::home();
        dir.cd("satviewer/icons");
        icon = dir.filePath("sat.png");
    }
    satWidget->setIcon(sat, icon);

    sat->setName(record.field("name").value().toString());
    sat->modelInit(model_state.data(), model_state.size());
//    sat->modelInit(WGS84, jdsaepoch, bstar, i, omg, e, w, mo, no);
}

void SDlgOptions::setLoc(Location *loc, QSqlRecord record) {
    if (loc == 0 || record.isEmpty()) return;
    loc->setLatitude  (record.field("lat"    ).value().toDouble());
    loc->setLongitude (record.field("lon"    ).value().toDouble());
    loc->setHeight    (record.field("height" ).value().toDouble());
    loc->setZrlAzimuth(record.field("azimuth").value().toDouble());
    loc->setZrlRange  (record.field("r"      ).value().toDouble());
    loc->setZrlWidth  (record.field("sector" ).value().toDouble());
    loc->setName      (record.field("name"   ).value().toString());
    QString icon = record.field("icon").value().toString();
    if (icon.isEmpty() || !QFile::exists(icon)) {
        QDir dir = QDir::home();
        dir.cd("satviewer/icons");
        icon = dir.filePath("loc.png");
    }
    satWidget->setIcon(loc, icon);
}

void SDlgOptions::updateListViewSat() {
    if (listViewSat->model() != 0) delete listViewSat->model();
    if (satWidget->satList.count() < 1) return;
    QStandardItemModel *model = new QStandardItemModel(satWidget->satList.count(), 0);
    for (int i = 0; i < satWidget->satList.count(); i++)
            model->setItem(i, new QStandardItem(satWidget->satList.at(i)->name()));
    listViewSat->setModel(model);
    connect(
            listViewSat->selectionModel(), 
            SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
            this, 
            SLOT(selectSat(const QModelIndex &, const QModelIndex &))
            );
}

void SDlgOptions::updateListViewLoc() {
    if (listViewLoc->model() != 0) delete listViewLoc->model();
    if (satWidget->locList.count() < 1) return;
    QStandardItemModel *model = new QStandardItemModel(satWidget->locList.count(), 0);
    for (int i = 0; i < satWidget->locList.count(); i++)
            model->setItem(i, new QStandardItem(satWidget->locList.at(i)->name()));
    listViewLoc->setModel(model);
    connect(
            listViewLoc->selectionModel(), 
            SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
            this, 
            SLOT(selectLoc(const QModelIndex &, const QModelIndex &))
            );
}

void SDlgOptions::setBtnColor(QWidget *widget) {
    bool ok;
    QPalette pal = widget->palette();
    QRgb rgb = QColorDialog::getRgba(pal.color(QPalette::Button).rgba(), &ok, this);
    if (!ok) return;

    pal.setColor(QPalette::Button, QColor::fromRgb(rgb));
    widget->setPalette(pal);
}

uint32_t SDlgOptions::flipRgb(uint32_t rgb) {
    //OpenGL 0xAABBGGRR //Qt 0xAARRGGBB
    uint8_t a, r, g, b;
    b = rgb;
    g = rgb >> 8;
    r = rgb >> 16;
    a = rgb >> 24;
    rgb = (a << 24) | (b << 16) | (g << 8) | (r);
    return rgb;
}

void SDlgOptions::addToSatList() {
    addToSatList(listViewDBSat->currentIndex());
}

void SDlgOptions::deleteSatList() {
    delFromSatList(listViewSat->currentIndex());
}

void SDlgOptions::addToLocList() {
    addToLocList(listViewDBLoc->currentIndex());
}

void SDlgOptions::deleteLocList() {
    delFromLocList(listViewLoc->currentIndex());
}

void SDlgOptions::selectPage(const QModelIndex &current, const QModelIndex &previous) {
    if (!current.isValid()) return;
    this->stackedWidget->setCurrentIndex(current.row());
}

void SDlgOptions::selectSatPage() {
    stackedWidget->setCurrentIndex(0);
}

void SDlgOptions::selectLocPage() {
    stackedWidget->setCurrentIndex(1);
}

void SDlgOptions::selectZrvPage() {
    stackedWidget->setCurrentIndex(2);
}

void SDlgOptions::selectAboutPage() {
    stackedWidget->setCurrentIndex(3);
}

void SDlgOptions::selectParamsPage() {
    stackedWidget->setCurrentIndex(4);
    scriptParameters();
}

void SDlgOptions::selectWidgetsPage() {
    stackedWidget->setCurrentIndex(5);
}

void SDlgOptions::selectTlePage() {
    stackedWidget->setCurrentIndex(6);
}

void SDlgOptions::selectMapPage() {
    stackedWidget->setCurrentIndex(7);
}

void SDlgOptions::selectSettingsPage() {
    stackedWidget->setCurrentIndex(8);
}

void SDlgOptions::selectDbSat(const QModelIndex &current, const QModelIndex &previous) {
    if (!current.isValid()) return;
    mapperSat.setCurrentIndex(current.row());
    Satellite sat;
    setSat(&sat, modelDbSat->record(current.row()));
    double tm = 86400000.0*(modelDbSat->record(current.row()).value("time").toDouble() - 2440587.5);
    lineEditSatTime->setText(QDateTime::fromMSecsSinceEpoch((uint64_t)tm).toUTC().toString("dd.MM.yyyy H:mm:ss.zzz"));
}

void SDlgOptions::selectDbLoc(const QModelIndex &current, const QModelIndex &previous) {
    if (!current.isValid()) return;
    mapperLoc.setCurrentIndex(current.row());
    Location loc;
    setLoc(&loc, modelDbLoc->record(current.row()));
}

void SDlgOptions::selectSat(const QModelIndex &current, const QModelIndex &previous) {
    if (!current.isValid()) return;
    satWidget->setIndexSat(current.row());
}

void SDlgOptions::selectLoc(const QModelIndex &current, const QModelIndex &previous) {
    if (!current.isValid()) return;
    satWidget->setIndexLoc(current.row());
}

void SDlgOptions::setFilterSatName(const QString &line) {
    QString filter = "";
    if (line != "" && line.indexOf('\'') < 0)
            filter = "name LIKE '" + this->lineEditSatNameFilter->text() + "%'";
    modelDbSat->setFilter(filter);
}

void SDlgOptions::setFilterSat() {
    QString line = lineEditSatFilter->text();
    if (btnSatFilter->isChecked())
        modelDbSat->setFilter(line);
    else {
        modelDbSat->setFilter("");
        modelDbSat->select();
    }
}

void SDlgOptions::setFilterLocName(const QString &line) {
    QString filter = "";
    if (line != "" && line.indexOf('\'') < 0)
            filter = "name LIKE '" + this->lineEditLocNameFilter->text() + "%'";
    modelDbLoc->setFilter(filter);
}

void SDlgOptions::setFilterLoc() {
    QString line = lineEditLocFilter->text();
    if (btnLocFilter->isChecked())
        modelDbLoc->setFilter(line);
    else {
        modelDbLoc->setFilter("");
        modelDbLoc->select();
    }
}

void SDlgOptions::loadDbFromTle() {
    double const rad2deg = 180.0/M_PI;
    double const xpdotp = 1440.0/(2.0*M_PI);
    QDir dir = QDir::home();
    dir.cd("satviewer/tle");
    QStringList fileList = QFileDialog::getOpenFileNames(this, 
            "Open TLE File", dir.path(), 
            "Text Files (*.txt);;All Files (*.*)", NULL, 
            QFileDialog::DontUseNativeDialog);
    if (fileList.isEmpty()) return;
    TleReader tle;
    QString filePath;
    QString query;
    db.exec("BEGIN;");
    for (int j = 0; j < fileList.count(); j++) {
        filePath = fileList.at(j);
        if (filePath.isEmpty()) break;
        tle.init(filePath.toLocal8Bit().data());
        for (int i = 0; i < tle.count(); i++) {
            tle.item(i);
            query = QString(
                    "INSERT INTO sat ('groupname', 'name', 'i', 'omg', 'e', "
                    "'w', 'm0', 'n', 'bstar', 'time', 'model_state') "
                    "VALUES('%0', '%1', %2, %3, %4, %5, %6, %7, %8, %9, "
                    ":model_state);")
                .arg(QFileInfo(filePath).baseName())
                .arg(QString(tle.name()).trimmed())
                .arg(tle.inclination()*rad2deg  , 0, 'g', 16)
                .arg(tle.argLatPerigee()*rad2deg, 0, 'g', 16)
                .arg(tle.eccentricity()         , 0, 'g', 16)
                .arg(tle.latAscNode()*rad2deg   , 0, 'g', 16)
                .arg(tle.meanAnomaly()*rad2deg  , 0, 'g', 16)
                .arg(tle.meanMotion()*xpdotp    , 0, 'g', 16)
                .arg(tle.bStar()                , 0, 'g', 16)
                .arg(tle.jEpoch()               , 0, 'g', 16);

        QSqlQuery q(db);
        q.prepare(query);
        printf("tle state length %d\n", tle.sizeState());
        QByteArray bytes(tle.state(), tle.sizeState());
        printf("tle bytes length %d\n", bytes.length());
        puts(bytes.toHex().data());
        q.bindValue(":model_state", bytes);
        q.exec();
        puts(q.executedQuery().toLocal8Bit().data());
//        db.exec(query);
//        puts(db.lastError().text().toLocal8Bit().data());
        }
    }
    db.exec("COMMIT;");
    modelDbSat->submitAll();
}

void SDlgOptions::loadDbLoc() {
	QString query;
	char buf[256];
	QDir dir = QDir::home();
	dir.cd("satviewer/loc");
	QStringList fileList = QFileDialog::getOpenFileNames(this, "Open File", dir.path(), "Text Files (*.txt);;All Files (*.*)");
	if (fileList.isEmpty()) return;
	QString filePath;
	ifstream f;
	db.exec("BEGIN;");
	for (int j = 0; j < fileList.count(); j++) {
		filePath = fileList.at(j);
		if (filePath.isEmpty()) break;
		f.open(filePath.toLocal8Bit().data());
		if (!f.is_open()) return;
		do {
			f.getline(buf, 256);
			if (strlen(buf) > 0) {
				query = QString("INSERT INTO loc (name, lat, lon, height, azimuth, sector, r) VALUES(%0);").arg(buf);
				db.exec(query);
			}
		} while (!f.eof());
		f.close();
		f.clear();
	}
	db.exec("COMMIT;");
	modelDbLoc->submitAll();
}

void SDlgOptions::clearDbSat() {
    if (QMessageBox::warning(this, "Warning", "Remove all records?",
        QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        db.exec("DELETE FROM sat");
        modelDbSat->submitAll();
    }
}
void SDlgOptions::clearDbLoc() {
    if (QMessageBox::warning(this, "Warning", "Remove all records?",
        QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        db.exec("DELETE FROM loc");
        modelDbLoc->submitAll();
    }
}

void SDlgOptions::deleteDbSat() {
    QModelIndexList indexList = listViewDBSat->selectionModel()->selectedIndexes();
    int count = indexList.count();
    if (count < 1) return;
    for (int i = 0; i < count; i++) modelDbSat->removeRow(indexList.at(i).row());
    modelDbSat->submitAll();
}

void SDlgOptions::deleteDbLoc() {
    QModelIndexList indexList = listViewDBLoc->selectionModel()->selectedIndexes();
    int count = indexList.count();
    if (count < 1) return;
    for (int i = 0; i < count; i++) modelDbLoc->removeRow(indexList.at(i).row());
    modelDbLoc->submitAll();
}

void SDlgOptions::addToSatList(const QModelIndex &index) {
    if (!index.isValid()) return;
    int iRow = index.row();
    Satellite *sat;
    QModelIndexList indexList = listViewDBSat->selectionModel()->selectedIndexes();

    for (int i = 0; i < indexList.count(); i++) {
        iRow = indexList.value(i).row();
        sat = satWidget->getSatModel();
        sat->copy(&satDialog->defaultSat);
        setSat(sat, modelDbSat->record(iRow));
        satWidget->addSat(sat);
    }

    updateListViewSat();
    if (listViewDBSat->model() == 0) return;
    QModelIndex mIndex = listViewDBSat->model()->index(iRow + 1, 0);
    if (mIndex.isValid()) listViewDBSat->setCurrentIndex(mIndex);
    if ((satWidget->indexSat() < 0) && (satWidget->satList.count() > 0)) 
        satWidget->setIndexSat(0);
    satWidget->refreshAll();
}

void SDlgOptions::addToLocList(const QModelIndex &index) {
    if (!index.isValid()) return;
    int iRow = index.row();
    Location *loc;
    QModelIndexList indexList = listViewDBLoc->selectionModel()->selectedIndexes();
    for (int i = 0; i < indexList.count(); i++) {
        iRow = indexList.value(i).row();
        loc = new Location();
        loc->copy(&locDialog->defaultLoc);
        setLoc(loc, modelDbLoc->record(iRow));
        satWidget->addLoc(loc);
    }

    updateListViewLoc();
    if (listViewDBLoc->model() == 0) return;
    QModelIndex mIndex = listViewDBLoc->model()->index(iRow + 1, 0);
    if (mIndex.isValid()) listViewDBLoc->setCurrentIndex(mIndex);
    if ((satWidget->indexLoc() < 0) && (satWidget->locList.count() > 0)) 
        satWidget->setIndexLoc(0);
    satWidget->refreshAll();
}

void SDlgOptions::delFromSatList(const QModelIndex &index) {
    int iRow = -1;
    if (index.isValid()) iRow = index.row();
    if (listViewSat->selectionModel() == NULL) return;
    QModelIndexList indexList = listViewSat->selectionModel()->selectedIndexes();
    int count = indexList.count();
    if (count < 1) return;
    Satellite **tmp = new Satellite*[count];

    for (int i = 0; i < count; i++)
        tmp[i] = satWidget->satList.at(indexList.value(i).row());

    for (int i = 0; i < count; i++) satWidget->removeSat(tmp[i]);

    delete [] tmp;
    updateListViewSat();
    if (listViewSat->model() == 0) return;
    QModelIndex mIndex = listViewSat->model()->index(iRow, 0);
    if (mIndex.isValid()) listViewSat->setCurrentIndex(mIndex);
    satWidget->refreshAll();
}

void SDlgOptions::delFromLocList(const QModelIndex &index) {
    int iRow = -1;
    if (index.isValid()) iRow = index.row();
    if (listViewLoc->selectionModel() == NULL) return;
    QModelIndexList indexList = listViewLoc->selectionModel()->selectedIndexes();
    int count = indexList.count();
    if (count < 1) return;
    Location **tmp = new Location*[count];

    for (int i = 0; i < count; i++)
        tmp[i] = satWidget->locList.at(indexList.value(i).row());

    for (int i = 0; i < count; i++)
        satWidget->removeLoc(tmp[i]);

    delete [] tmp;
    updateListViewLoc();
    if (listViewLoc->model() == 0) return;
    QModelIndex mIndex = listViewLoc->model()->index(iRow, 0);
    if (mIndex.isValid()) listViewLoc->setCurrentIndex(mIndex);
    satWidget->refreshAll();
}

void SDlgOptions::scriptParameters() {
//    Satellite *sat = satWidget->currentSat();
//    Location *loc = satWidget->currentLoc();
//    if (sat == 0 || loc == 0) return;
//    scriptFrame->exec(sat, loc, satWidget->time());
}

void SDlgOptions::addDbLoc() {
    modelDbLoc->insertRow(mapperLoc.currentIndex());
    modelDbLoc->submitAll();
}

void SDlgOptions::changeDbSat() {
    satDialog->makeSat(satWidget->currentSat());
    satWidget->refreshAll();
}

void SDlgOptions::changeDbLoc() {
    locDialog->makeLoc(satWidget->currentLoc());
    satWidget->refreshAll();
}

void SDlgOptions::helpSatSql() {
    QMessageBox::information(this, "SQL Table Fields",
                "id\tINTEGER NOT NULL\n"
                "groupname\tTEXT\n"
                "name\tTEXT NOT NULL\n"
                "i\tDOUBLE\n"
                "omg\tDOUBLE\n"
                "e\tDOUBLE\n"
                "w\tDOUBLE\n"
                "m0\tDOUBLE\n"
                "n\tDOUBLE\n"
                "bstar\tDOUBLE\n"
                "time\tDOUBLE\n"
                "zrv\tDOUBLE\n"
                "alpha\tDOUBLE\n"
                "beta\tDOUBLE\n"
                "zrl\tDOUBLE\n\n"
                "Example: i>60 and name LIKE \'cosm%\'");
}

void SDlgOptions::helpLocSql() {
    QMessageBox::information(this, "SQL Table Fields",
                "id\tINTEGER NOT NULL\n"
                "name\tTEXT NOT NULL\n"
                "lat\tDOUBLE\n"
                "lon\tDOUBLE\n"
                "height\tDOUBLE\n"
                "azimuth\tDOUBLE\n"
                "sector\tDOUBLE\n"
                "r\tDOUBLE\n\n"
                "Example: lat>60 and name LIKE \'Rio%\'");
}

void SDlgOptions::setSatWidget(GLSatAbstractWidget *satWidget) {
    this->satWidget = satWidget;
    satWidget->settingsWidget->setParent(tabWidget);
//    jswList->setDesktop(satWidget);
    if (stackedWidget->widget(7) != NULL) stackedWidget->removeWidget(stackedWidget->widget(7));
        stackedWidget->insertWidget(7, satWidget->settingsWidget);
        satDialog->setSatWidget(satWidget);
        locDialog->setSatWidget(satWidget);
}

void SDlgOptions::aboutQt() {
    QMessageBox::aboutQt(this);
}

void SDlgOptions::clearSatList() {
    listViewSat->selectAll();
    delFromSatList(listViewSat->currentIndex());
}

void SDlgOptions::clearLocList() {
    listViewLoc->selectAll();
    delFromLocList(listViewLoc->currentIndex());
}
