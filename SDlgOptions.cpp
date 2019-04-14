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

SDlgOptions::SDlgOptions(SatViewer *satviewer, GLSatAbstractWidget *w) {
    widget.setupUi(this);
    
    m_satviewer = satviewer;
    
    satDialog = new Sgp4Dialog(w);
    satDialog->setParent(this, Qt::Dialog | Qt::WindowTitleHint);
    satDialog->setWindowModality(Qt::WindowModal);

    locDialog = new SLocDialog(w);
    locDialog->setParent(this, Qt::Dialog | Qt::WindowTitleHint);
    locDialog->setWindowModality(Qt::WindowModal);

    QDir dir = QDir::home();
    dir.cd("satviewer/tle");
    tleFrame = new SUpdater(dir.filePath("tle_list.lst"));
    tleFrame->setParent(widget.tabWidgetSettings);
    widget.tabWidgetSettings->insertTab(0, tleFrame, tr("TLE"));

    jswList = new SWidgetList();
    jswList->setParent(widget.tabWidgetSettings);
    widget.tabWidgetSettings->insertTab(1, jswList, tr("Widgets"));

    dir = QDir::home();
    dir.cd("satviewer/jsprm");
    scriptFrame = new SScriptFrame(dir.filePath("prmlist.js"));
    scriptFrame->setParent(widget.tabWidgetData);
    widget.tabWidgetData-> insertTab(1, scriptFrame, tr("Parameters"));


    widget.listViewSat->setModel(new QStandardItemModel(this));
    widget.listViewLoc->setModel(new QStandardItemModel(this));
    
    setSatWidget(w);
    setDb();
    
    connect(widget.lineEditSatNameFilter, SIGNAL(textChanged(const QString &)), 
            this, SLOT(setFilterSatName(const QString &)));
    connect(widget.lineEditLocNameFilter, SIGNAL(textChanged(const QString &)), 
            this, SLOT(setFilterLocName(const QString &)));
    connect(widget.btnSatSqlHelp, SIGNAL(clicked()), this, SLOT(helpSatSql  ()));
    connect(widget.btnLocSqlHelp, SIGNAL(clicked()), this, SLOT(helpLocSql  ()));
    connect(widget.btnSatFilter , SIGNAL(clicked()), this, SLOT(setFilterSat()));
    connect(widget.btnLocFilter , SIGNAL(clicked()), this, SLOT(setFilterLoc()));

    connect(widget.btnOpenTle    , SIGNAL(clicked()), this, SLOT(loadDbFromTle()));
    connect(widget.btnOpenLoc    , SIGNAL(clicked()), this, SLOT(loadDbLoc    ()));
    connect(widget.btnAddDbLoc   , SIGNAL(clicked()), this, SLOT(addDbLoc     ()));
    connect(widget.btnDeleteDbSat, SIGNAL(clicked()), this, SLOT(deleteDbSat  ()));
    connect(widget.btnDeleteDbLoc, SIGNAL(clicked()), this, SLOT(deleteDbLoc  ()));
    connect(widget.btnClearDbSat , SIGNAL(clicked()), this, SLOT(clearDbSat   ()));
    connect(widget.btnClearDbLoc , SIGNAL(clicked()), this, SLOT(clearDbLoc   ()));


    connect(widget.listViewDBSat, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addToSatList(const QModelIndex &)));
    connect(widget.listViewDBLoc, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(addToLocList(const QModelIndex &)));
    connect(widget.listViewSat, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(changeDbSat()));
    connect(widget.listViewLoc, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(changeDbLoc()));
    connect(scriptFrame->getWidget()->btnRefresh, SIGNAL(clicked()), this, SLOT(scriptParameters()));
    connect(widget.btnDeleteSatList, SIGNAL(clicked()), this, SLOT(deleteSatList()));
    connect(widget.btnDeleteLocList, SIGNAL(clicked()), this, SLOT(deleteLocList()));
    connect(widget.btnAddToSatList , SIGNAL(clicked()), this, SLOT(addToSatList ()));
    connect(widget.btnAddToLocList , SIGNAL(clicked()), this, SLOT(addToLocList ()));
    connect(widget.btnClearSatList , SIGNAL(clicked()), this, SLOT(clearSatList ()));
    connect(widget.btnClearLocList , SIGNAL(clicked()), this, SLOT(clearLocList ()));
    connect(widget.btnChangeDbSat  , SIGNAL(clicked()), this, SLOT(changeDbSat  ()));
    connect(widget.btnChangeDbLoc  , SIGNAL(clicked()), this, SLOT(changeDbLoc  ()));

    connect(
        widget.listViewSat->selectionModel(), 
        SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
        this, 
        SLOT(selectSat(const QModelIndex &, const QModelIndex &))
    );

    connect(
        widget.listViewLoc->selectionModel(), 
        SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
        this, 
        SLOT(selectLoc(const QModelIndex &, const QModelIndex &))
    );
}

SDlgOptions::~SDlgOptions() {
    db.close();
}

void SDlgOptions::saveListViewSat() {
    db.exec("DELETE FROM sattemp;");
    db.exec("BEGIN;");

    for (const auto& sat : m_satviewer->satellites()) {
        QString query = QString(
            "INSERT INTO sattemp ('name', 'zrv', 'icon', 'show_label', "
            "'show_track', 'show_zrv', 'show_lines', 'active_zone', "
            "'color_track', 'color_label', 'color_zrv', 'color_lines', "
            "'track', 'font', 'name_x', 'name_y', 'lines_width', "
            "'model_state') "
            "VALUES('%0', %1, '%2', %3, %4, %5, %6, %7, %8, %9, %10, %11, "
            "%12, '%13', %14, %15, %16, :model_state);")
            .arg(sat->name())
            .arg(qRadiansToDegrees(sat->zrvWidth()), 0, 'g', 16)
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
            .arg(sat->linesWidth(), 0, 'g', 16);
        QSqlQuery q(db);
        q.prepare(query);
        QByteArray bytes(sat->getState(), sat->getStateSize());
        q.bindValue(":model_state", bytes);
        q.exec();
    }
    db.exec("COMMIT;");
}

void SDlgOptions::saveListViewLoc() {
    db.exec("DELETE FROM loctemp;");
    db.exec("BEGIN;");

    for (const auto &loc : m_satviewer->locations()) {
        QString query = QString(
            "INSERT INTO loctemp ('lat', 'lon', 'height', 'azimuth', 'sector', "
            "'r', 'name', 'icon', 'show_label', 'show_zrv', 'show_lines', "
            "'active_zone', 'color_label', 'color_zrv', 'color_lines', 'font', "
            "'name_x', 'name_y', 'lines_width') "
            "VALUES(%0, %1, %2, %3, %4, %5, '%6', '%7', %8, %9, %10, %11, %12, "
            "%13, %14, '%15', %16, %17, %18);")
            .arg(loc->latitude(), 0, 'g', 16)
            .arg(loc->longitude(), 0, 'g', 16)
            .arg(loc->height(), 0, 'g', 16)
            .arg(loc->zrlAzimuth(), 0, 'g', 16)
            .arg(loc->zrlWidth(), 0, 'g', 16) //TODO rad2deg
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

    for (int i = 0; i < modelSatTemp.rowCount(); i++) {
        satWidget->setSatModel(0);
        Satellite *sat = satWidget->getSatModel();
        setSat(sat, modelSatTemp.record(i));
        sat->setZrv(qDegreesToRadians(modelSatTemp.record(i).field("zrv" ).value().toDouble()));
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
        satWidget->satviewer()->appendSatellite(sat);
    }
    modelSatTemp.clear();

    updateListViewSat();
//    if (satWidget->satList.count() == 1) { //TODO
//        satWidget->setIndexSat(0);
//    }
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
        satWidget->satviewer()->appendLocation(loc);
    }
    modelLocTemp.clear();

    updateListViewLoc();
//    if (satWidget->locList.count() == 1) { // TODO
//        satWidget->setIndexLoc(0);
//    }
    satWidget->refreshAll();
}

void SDlgOptions::setDb() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir = QDir::home();
    dir.cd("satviewer");
    db.setDatabaseName(dir.filePath("main.db"));
    
    if (!db.open()) {
        QMessageBox::information(this, "Error", 
        db.lastError().text() + "\n" + dir.filePath("main.db"), 0);
    }

    db.exec( QString(sqlSat    ) );
    db.exec( QString(sqlSatTemp) );
    db.exec( QString(sqlLoc    ) );
    db.exec( QString(sqlLocTemp) ); // TODO sun model problem

    modelDbSat = new QSqlTableModel(this, db);
    modelDbSat->setTable("sat");
    modelDbSat->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelDbSat->select();

    while (modelDbSat->canFetchMore()) {
        modelDbSat->fetchMore();
    }

    widget.listViewDBSat->setModel(modelDbSat);
    connect(widget.listViewDBSat->selectionModel(), 
        SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
        this, 
        SLOT(selectDbSat(const QModelIndex &, const QModelIndex &))
    );
    widget.listViewDBSat->setModelColumn(modelDbSat->fieldIndex("name"));

    mapperSat.setModel(modelDbSat);
    mapperSat.addMapping(widget.lineEditSatName , modelDbSat->fieldIndex("name")     );
    mapperSat.addMapping(widget.lineEditSatGroup, modelDbSat->fieldIndex("groupname"));
    mapperSat.addMapping(widget.lineEditSatI    , modelDbSat->fieldIndex("i")        );
    mapperSat.addMapping(widget.lineEditSatOmg  , modelDbSat->fieldIndex("omg")      );
    mapperSat.addMapping(widget.lineEditSatE    , modelDbSat->fieldIndex("e")        );
    mapperSat.addMapping(widget.lineEditSatW    , modelDbSat->fieldIndex("w")        );
    mapperSat.addMapping(widget.lineEditSatM0   , modelDbSat->fieldIndex("m0")       );
    mapperSat.addMapping(widget.lineEditSatN    , modelDbSat->fieldIndex("n")        );
    mapperSat.addMapping(widget.lineEditSatBStar, modelDbSat->fieldIndex("bstar")    );
    mapperSat.toFirst();

    modelDbLoc = new QSqlTableModel(this, db);
    modelDbLoc->setTable("loc");
    modelDbLoc->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelDbLoc->select();

    while (modelDbLoc->canFetchMore()) {
        modelDbLoc->fetchMore();
    }

    widget.listViewDBLoc->setModel(modelDbLoc);
    
    connect(
        widget.listViewDBLoc->selectionModel(), 
        SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), 
        this, 
        SLOT(selectDbLoc(const QModelIndex &, const QModelIndex &))
    );
    
    widget.listViewDBLoc->setModelColumn(modelDbLoc->fieldIndex("name"));

    mapperLoc.setModel(modelDbLoc);
    mapperLoc.addMapping(widget.lineEditLocName   , modelDbLoc->fieldIndex("name")   );
    mapperLoc.addMapping(widget.lineEditLocLat    , modelDbLoc->fieldIndex("lat")    );
    mapperLoc.addMapping(widget.lineEditLocLon    , modelDbLoc->fieldIndex("lon")    );
    mapperLoc.addMapping(widget.lineEditLocHeight , modelDbLoc->fieldIndex("height") );
    mapperLoc.addMapping(widget.lineEditLocAzimuth, modelDbLoc->fieldIndex("azimuth"));
    mapperLoc.addMapping(widget.lineEditLocWidth  , modelDbLoc->fieldIndex("sector") );
    mapperLoc.addMapping(widget.lineEditLocRange  , modelDbLoc->fieldIndex("r")      );
    mapperLoc.toFirst();
}

void SDlgOptions::setSat(Satellite *sat, QSqlRecord record) {
    if (sat == NULL || record.isEmpty()) {
        return;
    }
    QByteArray model_state = record.field("model_state").value().toByteArray();
    if (model_state.size() <= 0) {
        qWarning("empty model");
        return;
    }
    
    QString icon     = record.field("icon" ).value().toString();
    if (icon.isEmpty() || !QFile::exists(icon)) {
        QDir dir = QDir::home();
        dir.cd("satviewer/icons");
        icon = dir.filePath("sat.png");
    }
    satWidget->setIcon(sat, icon);

    sat->setName(record.field("name").value().toString());
    qWarning() << model_state.size();
    sat->modelInit(model_state.data(), model_state.size());
}

void SDlgOptions::setLoc(Location *loc, QSqlRecord record) {
    if (loc == NULL || record.isEmpty()) {
        return;
    }
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
    QStandardItemModel *model = (QStandardItemModel *)widget.listViewSat->model();
    if (model != nullptr) {
        model->clear();
        for (const auto& sat : m_satviewer->satellites()) {
            model->appendRow(new QStandardItem(sat->name()));
        }
    }
}

void SDlgOptions::updateListViewLoc() {
    QStandardItemModel *model = (QStandardItemModel *)widget.listViewLoc->model();
    if (model != nullptr) {
        model->clear();
        for (const auto& loc : m_satviewer->locations()) {
            model->appendRow(new QStandardItem(loc->name()));
        }
    }
}

void SDlgOptions::setBtnColor(QWidget *widget) {
    bool ok;
    QPalette pal = widget->palette();
    QRgb rgb = QColorDialog::getRgba(pal.color(QPalette::Button).rgba(), &ok, this);
    if (ok) {
        pal.setColor(QPalette::Button, QColor::fromRgb(rgb));
        widget->setPalette(pal);
    }
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
    addToSatList(widget.listViewDBSat->currentIndex());
}

void SDlgOptions::deleteSatList() {
    delFromSatList(widget.listViewSat->currentIndex());
}

void SDlgOptions::addToLocList() {
    addToLocList(widget.listViewDBLoc->currentIndex());
}

void SDlgOptions::deleteLocList() {
    delFromLocList(widget.listViewLoc->currentIndex());
}

void SDlgOptions::selectDbSat(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous)
    if (current.isValid()) {
        mapperSat.setCurrentIndex(current.row());
        Satellite sat;
        setSat(&sat, modelDbSat->record(current.row()));
        double tm = 86400000.0 * (modelDbSat->record(current.row())
            .value("time").toDouble() - 2440587.5);
        widget.lineEditSatTime->setText(
            QDateTime::fromMSecsSinceEpoch((uint64_t)tm)
                .toUTC().toString("dd.MM.yyyy H:mm:ss.zzz")
        );
    }
}

void SDlgOptions::selectDbLoc(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous)
    if (current.isValid()) {
        mapperLoc.setCurrentIndex(current.row());
        Location loc;
        setLoc(&loc, modelDbLoc->record(current.row()));
    }
}

void SDlgOptions::selectSat(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous)
    if (current.isValid()) {
        m_satviewer->setCurrentSatelliteIndex(current.row());
    }
}

void SDlgOptions::selectLoc(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous)
    if (current.isValid()) {
        m_satviewer->setCurrentLocationIndex(current.row());
    }
}

void SDlgOptions::setFilterSatName(const QString &line) {
    QString filter = "";
    if (line != "" && line.indexOf('\'') < 0)
            filter = "name LIKE '" + widget.lineEditSatNameFilter->text() + "%'";
    modelDbSat->setFilter(filter);
}

void SDlgOptions::setFilterSat() {
    QString line = widget.lineEditSatFilter->text();
    if (widget.btnSatFilter->isChecked())
        modelDbSat->setFilter(line);
    else {
        modelDbSat->setFilter("");
        modelDbSat->select();
    }
}

void SDlgOptions::setFilterLocName(const QString &line) {
    QString filter = "";
    if (line != "" && line.indexOf('\'') < 0)
            filter = "name LIKE '" + widget.lineEditLocNameFilter->text() + "%'";
    modelDbLoc->setFilter(filter);
}

void SDlgOptions::setFilterLoc() {
    QString line = widget.lineEditLocFilter->text();
    if (widget.btnLocFilter->isChecked())
        modelDbLoc->setFilter(line);
    else {
        modelDbLoc->setFilter("");
        modelDbLoc->select();
    }
}

void SDlgOptions::loadDbFromTle() {
    QDir dir = QDir::home();
    dir.cd("satviewer/tle");
    QStringList fileList = QFileDialog::getOpenFileNames(this, 
            "Open TLE File", dir.path(), 
            "Text Files (*.txt);;All Files (*.*)", NULL, 
            QFileDialog::DontUseNativeDialog);
    if (fileList.isEmpty()) {
        return;
    }
    TleReader tle;
    db.exec("BEGIN;");
    for (const auto& filePath : fileList) {
        if (filePath.isEmpty()) {
            continue;
        }
        tle.init(filePath.toLocal8Bit().data());
        for (int i = 0; i < tle.count(); i++) {
            tle.item(i);
            QString query = QString(
                    "INSERT INTO sat ('groupname', 'name', 'i', 'omg', 'e', "
                    "'w', 'm0', 'n', 'bstar', 'time', 'model_state') "
                    "VALUES('%0', '%1', %2, %3, %4, %5, %6, %7, %8, %9, "
                    ":model_state);")
                    .arg(QFileInfo(filePath).baseName())
                    .arg(QString(tle.name()).trimmed())
                    .arg(qRadiansToDegrees(tle.inclination()), 0, 'g', 16)
                    .arg(qRadiansToDegrees(tle.argLatPerigee()), 0, 'g', 16)
                    .arg(tle.eccentricity(), 0, 'g', 16)
                    .arg(qRadiansToDegrees(tle.latAscNode()), 0, 'g', 16)
                    .arg(qRadiansToDegrees(tle.meanAnomaly()), 0, 'g', 16)
                    .arg(tle.meanMotion() * 1440.0 / (2.0 * M_PI), 0, 'g', 16)
                    .arg(tle.bStar(), 0, 'g', 16)
                    .arg(tle.jEpoch(), 0, 'g', 16);

            QSqlQuery q(db);
            q.prepare(query);
            QByteArray bytes(tle.state(), tle.sizeState());
            q.bindValue(":model_state", bytes);
            q.exec();
        }
    }
    db.exec("COMMIT;");
    modelDbSat->submitAll();
}

void SDlgOptions::loadDbLoc() {
    QString query;
    char buf[256];
    QString filePath;
    ifstream f;
    QDir dir = QDir::home();
    dir.cd("satviewer/loc");
    QStringList fileList = QFileDialog::getOpenFileNames(
            this, "Open File", dir.path(), 
            "Text Files (*.txt);;All Files (*.*)", NULL, 
            QFileDialog::DontUseNativeDialog);
    if (fileList.isEmpty()) {
        return;
    }
    db.exec("BEGIN;");
    for (const auto& filePath : fileList) {
        if (filePath.isEmpty()) {
            continue;
        }
        f.open(filePath.toLocal8Bit().constData());
        if (!f.is_open()) {
            continue;
        }
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
    QModelIndexList indexList = widget.listViewDBSat->selectionModel()->selectedIndexes();
    for (const auto& index : indexList) {
        modelDbSat->removeRow(index.row());
    }
    modelDbSat->submitAll();
}

void SDlgOptions::deleteDbLoc() {
    QModelIndexList indexList = widget.listViewDBLoc->selectionModel()->selectedIndexes();
    for (const auto& index : indexList) {
        modelDbLoc->removeRow(index.row());
    }
    modelDbLoc->submitAll();
}

void SDlgOptions::addToSatList(const QModelIndex &index) {
    if (!index.isValid()) {
        return;
    }
    
    QModelIndexList indexList = widget.listViewDBSat->selectionModel()->selectedIndexes();
    for (const auto& i : indexList) {
        if (i.column() == widget.listViewDBSat->modelColumn()) {
            Satellite *sat = satWidget->getSatModel();
            sat->copy(&satDialog->defaultSat);
            setSat(sat, modelDbSat->record(i.row()));
            satWidget->satviewer()->appendSatellite(sat);
        }
    }
    updateListViewSat();
    
    int position = index.row() + indexList.count() + 1;
    QModelIndex mIndex = widget.listViewDBSat->model()->index(position, 0);
    
    if (mIndex.isValid()) {
        widget.listViewDBSat->setCurrentIndex(mIndex);
    }
    
    if (m_satviewer->currentSatellite() == nullptr) {
        m_satviewer->setCurrentSatelliteIndex(0);
    }

    satWidget->refreshAll();
}

void SDlgOptions::addToLocList(const QModelIndex &index) {
    if (!index.isValid()) {
        return;
    }
    
    QModelIndexList indexList = widget.listViewDBLoc->selectionModel()->selectedIndexes();
    
    for (const auto& i : indexList) {
        if (i.column() == widget.listViewDBLoc->modelColumn()) {
            Location *loc = new Location();
            loc->copy(&locDialog->defaultLoc);
            setLoc(loc, modelDbLoc->record(i.row()));
            satWidget->satviewer()->appendLocation(loc);
        }
    }

    updateListViewLoc();

    int position = index.row() + indexList.count() + 1;
    QModelIndex mIndex = widget.listViewDBLoc->model()->index(position, 0);
    
    if (mIndex.isValid()) {
        widget.listViewDBLoc->setCurrentIndex(mIndex);
    }
    
    if (m_satviewer->currentLocation() == nullptr) {
        m_satviewer->setCurrentLocationIndex(0);
    }
    
    satWidget->refreshAll();
}

void SDlgOptions::delFromSatList(const QModelIndex &index) {
    QModelIndexList indexList = widget.listViewSat->selectionModel()->selectedIndexes();
    
    std::vector<Satellite *> v ( 
        m_satviewer->satellites().begin(), 
        m_satviewer->satellites().end() 
    );

    for (const auto& i : indexList) {
        m_satviewer->removeSatellite(v.at(i.row()));
    }

    updateListViewSat();

    int position = index.isValid() ? index.row() : -1;
    QModelIndex mIndex = widget.listViewSat->model()->index(position, 0);
    if (mIndex.isValid()) {
        widget.listViewSat->setCurrentIndex(mIndex);
    }
}

void SDlgOptions::delFromLocList(const QModelIndex &index) {
    QModelIndexList indexList = widget.listViewLoc->selectionModel()->selectedIndexes();
    
    std::vector<Location *> v { 
        m_satviewer->locations().begin(), 
        m_satviewer->locations().end() 
    };
    
    for (const auto& i : indexList) {
        m_satviewer->removeLocation(v.at(i.row()));
    }

    updateListViewLoc();
    int position = index.isValid() ? index.row() : -1;
    QModelIndex mIndex = widget.listViewLoc->model()->index(position, 0);
    if (mIndex.isValid()) {
        widget.listViewLoc->setCurrentIndex(mIndex);
    }
}

void SDlgOptions::scriptParameters() {
    Satellite *sat = m_satviewer->currentSatellite();
    Location *loc = m_satviewer->currentLocation();
    if ((sat == nullptr) || (loc == nullptr)) {
        return;
    }
    scriptFrame->exec(sat, loc, m_satviewer->time());
}

void SDlgOptions::addDbLoc() {
    modelDbLoc->insertRow(mapperLoc.currentIndex());
    modelDbLoc->submitAll();
}

void SDlgOptions::changeDbSat() {
    satDialog->makeSat(m_satviewer->currentSatellite());
    satWidget->refreshAll();
}

void SDlgOptions::changeDbLoc() {
    locDialog->makeLoc(m_satviewer->currentLocation());
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

void SDlgOptions::setSatWidget(GLSatAbstractWidget *w) {
    this->satWidget = w;
    satWidget->settingsWidget->setParent(widget.tabWidgetSettings);
    jswList->setDesktop(satWidget);
//    if (widget.stackedWidget->widget(7) != NULL) {
//        widget.stackedWidget->removeWidget(widget.stackedWidget->widget(7));
//    }
    widget.tabWidgetSettings->insertTab(4, satWidget->settingsWidget, tr("Map"));
    satDialog->setSatWidget(satWidget);
    locDialog->setSatWidget(satWidget);
}

void SDlgOptions::aboutQt() {
    QMessageBox::aboutQt(this);
}

void SDlgOptions::clearSatList() {
//    widget.listViewSat->selectAll();
//    delFromSatList(widget.listViewSat->currentIndex());
    m_satviewer->clearSatellites();
    updateListViewSat();
}

void SDlgOptions::clearLocList() {
//    widget.listViewLoc->selectAll();
//    delFromLocList(widget.listViewLoc->currentIndex());
    m_satviewer->clearLocations();
    updateListViewLoc();
}
