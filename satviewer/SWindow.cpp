/*
 * SWindow.cpp
 *
 *  Created on: 22.12.2009
 *      Author: Yan Coduemat
 */

#include "SWindow.h"
#include <QStyleFactory>

SWindow::SWindow() {
    satWidget = 0;
    dlgOptions = 0;
    language = tr("English");

    this->setupUi(this);
    originalPalette = qApp->palette();

    labelLoc.setMinimumWidth(32);
    labelSat.setMinimumWidth(32);
    labelLoc.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    labelSat.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    statusBar()->addWidget(&labelLoc, 0);
    statusBar()->addWidget(&labelSat, 0);

    satWidget = new GLSatWidget(this);

    QHBoxLayout *mapLayout = new QHBoxLayout;
    mapLayout->setSpacing(0);
    mapLayout->setMargin(0);
    //selectGlWidget(0);

    dlgOptions = new SDlgOptions(satWidget);
    dlgOptions->setParent(this, Qt::Window);
    move((qApp->desktop()->width() - width())/2, (qApp->desktop()->height() - height())/2);
    dlgOptions->move((qApp->desktop()->width() - dlgOptions->width())/2, (qApp->desktop()->height() - dlgOptions->height())/2);
    connect(tlBtnOptions, SIGNAL(clicked()), dlgOptions, SLOT(show()));

    uiSettings.setupUi(&settingsWidget);
    dlgOptions->stackedWidget->insertWidget(8, &settingsWidget);
    uiSettings.comboStyle->addItem(tr("system (need restart)"));
    uiSettings.comboStyle->addItems(QStyleFactory::keys());
    //	uiSettings.comboSatModel->addItems(satWidget->satModelList());

    mapLayout->addWidget(satWidget);
    frameMap->setLayout(mapLayout);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timeX    = 50;
    timer->start((int)timeX);
    time     =  0;
    timeType =  0;
    QDir path = QDir::home();
    path.cd("satviewer/widgets");
    shcFullScreen = new QShortcut(QKeySequence("Ctrl+F"), this);
    shcEscFullScreen = new QShortcut(QKeySequence("Esc"), this);
    dlgOptions->jswList->init(this->frameMap, path.path());

    uCheck = new UCheck(this, 20112, "satviewer.net", "/version/current.txt");

    connect(uiSettings.comboStyle   , SIGNAL(currentIndexChanged(int)), this, SLOT(selectStyle   (int)));
    connect(uiSettings.comboGlWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(selectGlWidget(int)));
    connect(uiSettings.btnPrintScr,  SIGNAL(clicked()), this, SLOT(onBtnPrintScrClicked()));
    //	connect(uiSettings.comboSatModel, SIGNAL(currentIndexChanged(int)), this, SLOT(onSatModelChanged(int)));
    connect(uiSettings.checkPalette, SIGNAL(clicked(bool)), this, SLOT(selectPalette(bool)));
    connect(uiSettings.checkUpdates, SIGNAL(clicked(bool)), this, SLOT(checkVersion (bool)));
    connect(shcFullScreen, SIGNAL(activated()), this, SLOT(fullScreen()));
    connect(shcEscFullScreen, SIGNAL(activated()), this, SLOT(escFullScreen()));
    connect(btnFullScreen, SIGNAL(clicked()), this, SLOT(fullScreen()));
    connect(tlBtnTime, SIGNAL(clicked()), this, SLOT(onTimeClick()));
    connect(tlBtnPlay, SIGNAL(clicked()), this, SLOT(onPlayClick()));
    connect(tlBtnBackward, SIGNAL(clicked()), this, SLOT(onBackwardClick()));
    connect(tlBtnForward , SIGNAL(clicked()), this, SLOT(onForwardClick ()));
    connect(uiSettings.btnReset, SIGNAL(clicked()), this, SLOT(resetSettings()));
    connect(spinBoxTimeX    , SIGNAL(valueChanged       (int)), this, SLOT(onTimeXChanged   (int)));
    connect(spinBoxStep     , SIGNAL(valueChanged       (int)), this, SLOT(onStepChanged    (int)));
    connect(comboBoxStep    , SIGNAL(currentIndexChanged(int)), this, SLOT(onStepChanged    (int)));
    connect(comboBoxTimeType, SIGNAL(currentIndexChanged(int)), this, SLOT(onTimeTypeChanged(int)));
    connect(uiSettings.comboLanguage, SIGNAL(currentIndexChanged(int)), this, SLOT(selectLanguage(int)));
    connect(satWidget, SIGNAL(statusZRVChanged(QString)), this, SLOT(addZRVMessage(QString)));
    connect(satWidget, SIGNAL(doubleClickedSat()), dlgOptions, SLOT(changeDbSat()));
    connect(satWidget, SIGNAL(doubleClickedLoc()), dlgOptions, SLOT(changeDbLoc()));
    connect(satWidget, SIGNAL(currentChanged(Satellite*, Location*, double*)), this, SLOT(setSwlVars(Satellite*, Location*, double*)));
    readSettings();
    //	enumSatModelList();
}

SWindow::~SWindow() {

}

void SWindow::readStrings() {
    QDir dir = QDir::home();
    dir.cd(QString("satviewer").append(QDir::separator()).append("translations"));

    //	QString lang;
    uiSettings.comboLanguage->clear();
    uiSettings.comboLanguage->addItem("English");
    listLang = dir.entryList(QStringList("*.qm"), QDir::Files, QDir::Name);

    QTranslator translator;
    QMutableStringListIterator i(listLang);
    while (i.hasNext()) {
        i.next();
        i.setValue(dir.filePath(i.value()));
        if (translator.load(i.value())) uiSettings.comboLanguage->addItem(translator.translate("SWindow", "English"));
        else i.remove();
    }
}

void SWindow::readSettings() {
	QDir dir = QDir::home();
	QSettings::setUserIniPath(dir.path());
	QSettings settings(QSettings::IniFormat, QSettings::UserScope, "satviewer", "satviewer");
	settings.setIniCodec("UTF-8");
//	GLSatAbstractWidget *satWidget = dlgOptions->getSatWidget();
	dateTimeEdit->setDateTime(QDateTime::fromTime_t(settings.value("time", QDateTime::currentDateTime().toTime_t()).toUInt()));
	//time = settings.value("time", QDateTime::currentDateTime().toTime_t()).toDouble();

	uiSettings.comboStyle->setCurrentIndex( settings.value("style", 0).toInt() );
	uiSettings.checkPalette->setChecked(false);
	if (settings.value("checkPalette", false).toBool()) uiSettings.checkPalette->click();

	spinBoxStep->setValue            ( settings.value("timeStep",  1 ).toInt() );
	comboBoxStep->setCurrentIndex    ( settings.value("timeStepX", 0 ).toInt() );
	spinBoxTimeX->setValue           ( settings.value("timeX",     25).toInt() );
	comboBoxTimeType->setCurrentIndex( settings.value("timeType",  0 ).toInt() );

	satWidget->readSettings(&settings);

	uiSettings.checkSave->setChecked   (settings.value("checkSave"   , true ).toBool());
	uiSettings.checkUpdates->setChecked(false);
	if (settings.value("checkUpdates", true).toBool()) uiSettings.checkUpdates->click();

	tlBtnTime->setChecked(settings.value("tlBtnTime", false).toBool());
	tlBtnPlay->setChecked(settings.value("tlBtnPlay", true ).toBool());

	dlgOptions->satDialog->defaultSat.visibleLabel( settings.value("defaultSat/isVisibleLabel", true).toBool() );
	dlgOptions->satDialog->defaultSat.visibleLines( settings.value("defaultSat/isVisibleLines", true).toBool() );
	dlgOptions->satDialog->defaultSat.visibleTrack( settings.value("defaultSat/isVisibleTrack", true).toBool() );
	dlgOptions->satDialog->defaultSat.visibleZrv  ( settings.value("defaultSat/isVisibleZrv"  , true).toBool() );

	dlgOptions->satDialog->defaultSat.setColorLabel( settings.value("defaultSat/colorLabel", 0x0000FFFF).toUInt() );
	dlgOptions->satDialog->defaultSat.setColorLines( settings.value("defaultSat/colorLines", 0xFF45772D).toUInt() );
	dlgOptions->satDialog->defaultSat.setColorTrack( settings.value("defaultSat/colorTrack", 0xFF00FF55).toUInt() );
	dlgOptions->satDialog->defaultSat.setColorZrv  ( settings.value("defaultSat/colorZrv"  , 0x1000AA00).toUInt() );

	QFont font;
	font.fromString(settings.value( "defaultSat/font", QFont().toString()).toString() );
	dlgOptions->satDialog->defaultSat.setFont(font);
	dlgOptions->satDialog->defaultSat.setTrack( settings.value("defaultSat/track"   , 0.5).toDouble() );
	dlgOptions->satDialog->defaultSat.setZRV  ( settings.value("defaultSat/zrvWidth", 0.0).toDouble() );
	dlgOptions->satDialog->defaultSat.setNameX( settings.value("defaultSat/nameX"   , 0.0).toDouble() );
	dlgOptions->satDialog->defaultSat.setNameY( settings.value("defaultSat/nameY"   , 0.0).toDouble() );
	dlgOptions->satDialog->defaultSat.setLinesWidth( settings.value("defaultSat/linesWidth"   , 1.0).toDouble() );
	dlgOptions->satDialog->defaultSat.setModelIndex(settings.value("defaultSat/modelIndex"  , 0).toInt());

	dlgOptions->locDialog->defaultLoc.visibleLabel( settings.value("defaultLoc/isVisibleLabel", true ).toBool() );
	dlgOptions->locDialog->defaultLoc.visibleLines( settings.value("defaultLoc/isVisibleLines", false ).toBool() );
	dlgOptions->locDialog->defaultLoc.visibleZrv  ( settings.value("defaultLoc/isVisibleZrv"  , false).toBool() );

	dlgOptions->locDialog->defaultLoc.setColorLabel( settings.value("defaultLoc/colorLabel", 0x0000FFFF).toUInt() );
	dlgOptions->locDialog->defaultLoc.setColorLines( settings.value("defaultLoc/colorLines", 0xFF00FFFF).toUInt() );
	dlgOptions->locDialog->defaultLoc.setColorZrv  ( settings.value("defaultLoc/colorZrv"  , 0x2000FFFF).toUInt() );


	font.fromString(settings.value( "defaultLoc/font", QFont().toString()).toString() );
	dlgOptions->locDialog->defaultLoc.setFont(font);

	dlgOptions->locDialog->defaultLoc.setZrlAzimuth( settings.value("defaultLoc/zrlAzimuth", 0).toDouble() );
	dlgOptions->locDialog->defaultLoc.setZrlRange  ( settings.value("defaultLoc/zrlRange"  , 0).toDouble() );
	dlgOptions->locDialog->defaultLoc.setZrlWidth  ( settings.value("defaultLoc/zrlWidth"  , 0).toDouble() );
	dlgOptions->locDialog->defaultLoc.setNameX     ( settings.value("defaultLoc/nameX"   , 0.0).toDouble() );
	dlgOptions->locDialog->defaultLoc.setNameY     ( settings.value("defaultLoc/nameY"   , 0.0).toDouble() );
	dlgOptions->locDialog->defaultLoc.setLinesWidth( settings.value("defaultLoc/linesWidth"   , 1.0).toDouble() );

	readStrings();
	uiSettings.comboLanguage->setCurrentIndex(settings.value("language", 0).toInt());

	dlgOptions->loadListViewSat();
	dlgOptions->loadListViewLoc();
	if (satWidget->satList.count() > 0) satWidget->setIndexSat(0);
	if (satWidget->locList.count() > 0) satWidget->setIndexLoc(0);
	onStepChanged(0);
	onTimeClick();
	onTimer();
}

void SWindow::writeSettings() {
	if (!uiSettings.checkSave->isChecked()) return;

	QSettings::setUserIniPath(QDir::home().path());
	QSettings settings(QSettings::IniFormat, QSettings::UserScope, "satviewer", "satviewer");
//	GLSatAbstractWidget *satWidget = dlgOptions->getSatWidget();

	settings.setValue( "time"     , dateTimeEdit->dateTime().toTime_t() );
	settings.setValue( "timeStep" , spinBoxStep->value()                );
	settings.setValue( "timeStepX", comboBoxStep->currentIndex()        );
	settings.setValue( "timeX"    , spinBoxTimeX->value()               );
	settings.setValue( "timeType" , comboBoxTimeType->currentIndex()    );

	settings.setValue( "checkSave"   , uiSettings.checkSave->isChecked   () );
	settings.setValue( "checkUpdates", uiSettings.checkUpdates->isChecked() );

	settings.setValue( "tlBtnTime", tlBtnTime->isChecked() );
	settings.setValue( "tlBtnPlay", tlBtnPlay->isChecked() );

	settings.setValue( "language"    , uiSettings.comboLanguage->currentIndex() );
	settings.setValue( "style"       , uiSettings.comboStyle->currentIndex()    );
	settings.setValue( "checkPalette", uiSettings.checkPalette->isChecked()     );

	settings.setValue( "defaultSat/isVisibleLabel", dlgOptions->satDialog->defaultSat.isVisibleLabel() );
	settings.setValue( "defaultSat/isVisibleLines", dlgOptions->satDialog->defaultSat.isVisibleLines() );
	settings.setValue( "defaultSat/isVisibleTrack", dlgOptions->satDialog->defaultSat.isVisibleTrack() );
	settings.setValue( "defaultSat/isVisibleZrv"  , dlgOptions->satDialog->defaultSat.isVisibleZrv()   );

	settings.setValue( "defaultSat/colorLabel", dlgOptions->satDialog->defaultSat.colorLabel() );
	settings.setValue( "defaultSat/colorLines", dlgOptions->satDialog->defaultSat.colorLines() );
	settings.setValue( "defaultSat/colorTrack", dlgOptions->satDialog->defaultSat.colorTrack() );
	settings.setValue( "defaultSat/colorZrv"  , dlgOptions->satDialog->defaultSat.colorZrv()   );

	settings.setValue( "defaultSat/font"    , dlgOptions->satDialog->defaultSat.font().toString() );
	settings.setValue( "defaultSat/track"   , dlgOptions->satDialog->defaultSat.track()           );
	settings.setValue( "defaultSat/zrvWidth", dlgOptions->satDialog->defaultSat.zrvWidth()        );
	settings.setValue( "defaultSat/nameX"   , dlgOptions->satDialog->defaultSat.nameX()           );
	settings.setValue( "defaultSat/nameY"   , dlgOptions->satDialog->defaultSat.nameY()           );
	settings.setValue( "defaultSat/linesWidth", dlgOptions->satDialog->defaultSat.linesWidth()    );
	settings.setValue( "defaultSat/modelIndex", dlgOptions->satDialog->defaultSat.modelIndex()    );

	settings.setValue( "defaultLoc/isVisibleLabel", dlgOptions->locDialog->defaultLoc.isVisibleLabel() );
	settings.setValue( "defaultLoc/isVisibleLines", dlgOptions->locDialog->defaultLoc.isVisibleLines() );
	settings.setValue( "defaultLoc/isVisibleZrv"  , dlgOptions->locDialog->defaultLoc.isVisibleZrv()   );

	settings.setValue( "defaultLoc/colorLabel", dlgOptions->locDialog->defaultLoc.colorLabel() );
	settings.setValue( "defaultLoc/colorLines", dlgOptions->locDialog->defaultLoc.colorLines() );
	settings.setValue( "defaultLoc/colorZrv"  , dlgOptions->locDialog->defaultLoc.colorZrv()   );

	settings.setValue( "defaultLoc/font", dlgOptions->locDialog->defaultLoc.font().toString() );

	settings.setValue( "defaultLoc/zrlAzimuth", dlgOptions->locDialog->defaultLoc.zrlAzimuth() );
	settings.setValue( "defaultLoc/zrlRange"  , dlgOptions->locDialog->defaultLoc.zrlRange()   );
	settings.setValue( "defaultLoc/zrlWidth"  , dlgOptions->locDialog->defaultLoc.zrlWidth()   );
	settings.setValue( "defaultLoc/nameX"     , dlgOptions->locDialog->defaultLoc.nameX()      );
	settings.setValue( "defaultLoc/nameY"     , dlgOptions->locDialog->defaultLoc.nameY()      );
	settings.setValue( "defaultLoc/linesWidth", dlgOptions->locDialog->defaultLoc.linesWidth() );

	satWidget->writeSettings(&settings);

	dlgOptions->saveListViewSat();
	dlgOptions->saveListViewLoc();
}

void SWindow::closeEvent(QCloseEvent *event) {
	writeSettings();
	event->accept();
}

void SWindow::wheelEvent(QWheelEvent *event) {
	if (tlBtnTime->isChecked() && !tlBtnPlay->isChecked()) {
		if (event->delta() > 0) {
			spinBoxStep->setValue(+abs(spinBoxStep->value()));
		}
		if (event->delta() < 0) {
			spinBoxStep->setValue(-abs(spinBoxStep->value()));
		}
		onTimer();
	}
	event->accept();
}


void SWindow::onTimeTypeChanged(int index) {
	timeType = comboBoxTimeType->currentIndex();
}

void SWindow::addZRVMessage(QString text) {
	QStringList list = text.split("|");
	if (list.count() < 4) return;
	QString color;
	if (list.at(1) == "in") color ="#DDDDFF";
	else color ="#EEEEFF";
	QString msg = 	"<table border=0 valign=middle cellpadding=2 cellspacing=1 width=100%>"
					"<tr bgcolor=" + color + ">"
						"<td width=29%>" + list.at(0) + "</td>"
						"<td width=12%>sign " + list.at(1) + "</td>"
						"<td width=29%>" + list.at(2) + "</td>"
						"<td width=12%>" + list.at(3) + "</td>"
						"<td width=18%>" + list.at(4) + " sec.</td>"
					"</tr></table>";
	dlgOptions->textZRVList->append(msg);
}

void SWindow::onTimer() {
	if (!tlBtnTime->isChecked()) time = QDateTime::currentDateTime().toTime_t();
	else {
		time = dateTimeEdit->dateTime().toTime_t();
		time += timeStep;
	}
	switch (timeType) {
		case 1:
			dateTimeEdit->setTimeSpec(Qt::UTC);
			dateTimeEdit->setDateTime(QDateTime::fromTime_t((int)time).toUTC());
		break;
		case 0:
			dateTimeEdit->setTimeSpec(Qt::LocalTime);
			dateTimeEdit->setDateTime(QDateTime::fromTime_t((int)time));
		break;
	}
	satWidget->setTime(time);
}

void SWindow::onPlayClick() {
	//onStepChanged(spinBoxStep->value());
	if ((tlBtnPlay->isChecked() && tlBtnTime->isChecked()) || !tlBtnTime->isChecked()) timer->start((int)timeX);
	else timer->stop();
}

void SWindow::onTimeClick() {
	tlBtnPlay->setEnabled(tlBtnTime->isChecked());
	tlBtnBackward->setEnabled(tlBtnTime->isChecked());
	tlBtnForward->setEnabled(tlBtnTime->isChecked());
	//if (!tlBtnTime->isChecked()) timer->start((int)timeX);
	onPlayClick();
}

void SWindow::onBackwardClick() {
	tlBtnForward->setChecked(!tlBtnBackward->isChecked());
	if (tlBtnBackward->isChecked()) spinBoxStep->setValue(-abs(spinBoxStep->value()));
	else spinBoxStep->setValue(+abs(spinBoxStep->value()));
	tlBtnPlay->setChecked(true);
	onPlayClick();
}

void SWindow::onForwardClick() {
	tlBtnBackward->setChecked(!tlBtnForward->isChecked());
	if (tlBtnForward->isChecked()) spinBoxStep->setValue(+abs(spinBoxStep->value()));
	else spinBoxStep->setValue(-abs(spinBoxStep->value()));
	tlBtnPlay->setChecked(true);
	onPlayClick();
}

void SWindow::onStepChanged(int value) {
	switch (comboBoxStep->currentIndex()) {
		case 0:
			timeStep = 1;
		break;
		case 1:
			timeStep = 60;
		break;
		case 2:
			timeStep = 3600;
		break;
		case 3:
			timeStep = 86400;
		break;
	}

	timeStep *= spinBoxStep->value();
	tlBtnBackward->setChecked((timeStep < 0));
	tlBtnForward->setChecked(!tlBtnBackward->isChecked());
	onPlayClick();
}

void SWindow::onTimeXChanged(int value) {
	if (value < 1) value = 1;
	timeX = 1000/value;
	onPlayClick();
}

void SWindow::selectLanguage(int value) {
	if ((value > listLang.count()) || (value < 0)) return;
	if (value == 0) qApp->removeTranslator(&m_translator);
	else {
		value--;
		m_translator.load(listLang.at(value));
		qApp->installTranslator(&m_translator);
	}
	retranslateUi(this);
	dlgOptions->retranslateUi(dlgOptions);
	dlgOptions->satDialog->retranslateUi(dlgOptions->satDialog);
	dlgOptions->locDialog->retranslateUi(dlgOptions->locDialog);
	dlgOptions->scriptFrame->retranslateUi(dlgOptions->scriptFrame);
	dlgOptions->tleFrame->retranslateUi(dlgOptions->tleFrame);
	dlgOptions->jswList->retranslateUi();
	satWidget->retranslateUi();
	uiSettings.comboLanguage->blockSignals(true);
	uiSettings.comboGlWidget->blockSignals(true);
	satWidget->blockSignals(true);
	int tmp = uiSettings.comboGlWidget->currentIndex();
	uiSettings.retranslateUi(&settingsWidget);
	uiSettings.comboGlWidget->setCurrentIndex(tmp);
	uiSettings.comboGlWidget->blockSignals(false);
	uiSettings.comboLanguage->blockSignals(false);
	satWidget->blockSignals(false);
}

void SWindow::setSwlVars(Satellite *sat, Location *loc, double *secs) {
	dlgOptions->jswList->setVars(sat, loc, secs);
	if (loc != 0) labelLoc.setText(loc->name());
	else labelLoc.setText("");
	if (sat != 0) labelSat.setText(sat->name());
	else labelSat.setText("");
}

void SWindow::fullScreen() {
	if (isFullScreen()) {
		showNormal();
		frameTime->show();
		statusBar()->show();
	}
	else {
		showFullScreen();
		frameTime->hide();
		statusBar()->hide();
	}

}

void SWindow::escFullScreen() {
	if (isFullScreen()) {
		fullScreen();
	}
}

void SWindow::selectStyle(int value) {
	if (uiSettings.comboStyle->itemText(value).isEmpty() || value == 0) return;
	qApp->setStyle(uiSettings.comboStyle->itemText(value));
	selectPalette(uiSettings.checkPalette->isChecked());
}

void SWindow::checkVersion(bool checked) {
	if (checked) {
		uCheck->check();
	}
}

void SWindow::selectPalette(bool value) {
	if (value) qApp->setPalette(qApp->style()->standardPalette());
	else qApp->setPalette(originalPalette);
}

void SWindow::selectGlWidget(int value) {
	GLSatAbstractWidget *tmp = satWidget;
	if (satWidget != 0) frameMap->layout()->removeWidget(satWidget);
	if (value == 0) satWidget = new GLSatWidget();
	else satWidget = new GLSatWidget3d();
	frameMap->layout()->addWidget(satWidget);

	if (dlgOptions != 0) dlgOptions->setSatWidget(satWidget);
	connect(satWidget, SIGNAL(statusZRVChanged(QString)), this, SLOT(addZRVMessage(QString)));
	connect(satWidget, SIGNAL(doubleClickedSat()), dlgOptions, SLOT(changeDbSat()));
	connect(satWidget, SIGNAL(doubleClickedLoc()), dlgOptions, SLOT(changeDbLoc()));
	connect(satWidget, SIGNAL(currentChanged(Satellite*, Location*, double*)), this, SLOT(setSwlVars(Satellite*, Location*, double*)));
	readSettings();
	uiSettings.comboGlWidget->blockSignals(true);
	uiSettings.comboGlWidget->setCurrentIndex(value);
	uiSettings.comboGlWidget->blockSignals(false);
	if (tmp != 0) delete tmp;
}

void SWindow::onBtnPrintScrClicked() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PNG File"), "", tr("PNG Files (*.png)"), 0);
    if (filePath.isEmpty()) return;
    QImage img = satWidget->grabFrameBuffer();
    if (!img.save(filePath, "PNG")) QMessageBox::critical(this, tr("Error saving"), tr("File not saved - ") + filePath);
}

void SWindow::resetSettings() {
    uiSettings.checkSave->setChecked(false);
//    dlgOptions->db.close();
    QDir path = QDir::home();
    path.cd("satviewer");
    QFile file;
    file.remove(path.filePath("satviewer.ini"));
//    file.remove(path.filePath("main.db"));
//    QMessageBox::information(this, tr("Settings reset to default"), tr("SatViewer will be closed."), QMessageBox::Ok);
    QProcess::startDetached(qAppName());
    qApp->quit();
}