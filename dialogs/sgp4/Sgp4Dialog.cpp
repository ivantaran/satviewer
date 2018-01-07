/*
 * Sgp4Dialog.cpp
 *
 *  Created on: 28.12.2009
 *      Author: Yan Coduemat
 */

#include "Sgp4Dialog.h"
#include "../../models/sgp4/sgp_struct.h"
#include "math.h"

Sgp4Dialog::Sgp4Dialog(GLSatAbstractWidget *satWidget) : SAbstractObjDialog(satWidget) {
	this->setupUi(this);
	lineEditBStar->setValidator(new QDoubleValidator());
	lineEditE->setValidator    (new QDoubleValidator());
	lineEditI->setValidator    (new QDoubleValidator());
	lineEditM0->setValidator   (new QDoubleValidator());
	lineEditN->setValidator    (new QDoubleValidator());
	lineEditOmg->setValidator  (new QDoubleValidator());
	lineEditTime->setValidator (new QDoubleValidator());
	lineEditW->setValidator    (new QDoubleValidator());
	m_sat = 0;
	m_fromlist = true;
        setSatWidget(satWidget);
	comboModel->addItems(satWidget->satModelList());
	//connect(btnIcon, SIGNAL(clicked()), this, SLOT(setIcon()));
	connect(btnColorName , SIGNAL(clicked()), this, SLOT(setColorSatName ()));
	connect(btnColorZrv  , SIGNAL(clicked()), this, SLOT(setColorSatZrv  ()));
	connect(btnColorLines, SIGNAL(clicked()), this, SLOT(setColorSatLines()));
	connect(btnColorTrack, SIGNAL(clicked()), this, SLOT(setColorSatTrack()));
	connect(btnFont      , SIGNAL(clicked()), this, SLOT(setSatFont      ()));
	connect(btnDefault   , SIGNAL(clicked()), this, SLOT(setDefault      ()));
	connect(btnIcon      , SIGNAL(clicked()), this, SLOT(setIcon         ()));
	connect(comboModel, SIGNAL(currentIndexChanged(int)), this, SLOT(selectModel(int)));
}

Sgp4Dialog::~Sgp4Dialog() {

}

uint32_t Sgp4Dialog::flipRgb(uint32_t rgb) {
	//OpenGL 0xAABBGGRR //Qt 0xAARRGGBB
	uint8_t a, r, g, b;
	b = rgb;
	g = rgb >> 8;
	r = rgb >> 16;
	a = rgb >> 24;
	rgb = (a << 24) | (b << 16) | (g << 8) | (r);
	return rgb;
}

void Sgp4Dialog::showEvent(QShowEvent * event) {
	if (m_sat == 0) return;

	double const rad2deg = 180.0/M_PI;
	double const xpdotp  = 1440.0/(2.0*M_PI);
	QPalette pal;
	QRgb rgb;

	QPixmap pixmap(m_sat->iconName());
        btnIcon->setIcon(pixmap);

	spinTrack->setValue(m_sat->track());
	btnFont->setFont(m_sat->font());

	lineEditName->setText ( m_sat->name() );
	lineEditI->setText    ( QString::number( m_sat->inclination()*rad2deg,   'g', 16) );
	lineEditOmg->setText  ( QString::number( m_sat->argLatPerigee()*rad2deg, 'g', 16) );
	lineEditE->setText    ( QString::number( m_sat->eccentricity(),          'g', 16) );
	lineEditW->setText    ( QString::number( m_sat->latAscNode()*rad2deg,    'g', 16) );
	lineEditM0->setText   ( QString::number( m_sat->meanAnomaly()*rad2deg,   'g', 16) );
	lineEditN->setText    ( QString::number( m_sat->meanMotion()*xpdotp,     'g', 16) );
	lineEditBStar->setText( QString::number( m_sat->bStar(),                 'g', 16) );
	spinZRV->setValue     ( m_sat->zrvWidth()*rad2deg );

	spinNameX->setValue( (int)m_sat->nameX() );
	spinNameY->setValue( (int)m_sat->nameY() );
	spinLines->setValue( m_sat->linesWidth() );

	//		double tm = 86400.0*(m_sat->jEpoch() - 2440587.5);
	//		lineEditSatTime->setText(QDateTime::fromTime_t((int)tm).toString("dd.MM.yyyy H:mm:ss"));

	uint64_t tm = (uint64_t)(86400000.0*(m_sat->jEpoch() - 2440587.5));
	dateTimeEdit->setDateTime(QDateTime::fromMSecsSinceEpoch(tm).toUTC());
	lineEditTime->setText ( QString::number(m_sat->jEpoch(), 'g', 16) );

	checkName->setChecked     ( m_sat->isVisibleLabel() );
	checkTrack->setChecked    ( m_sat->isVisibleTrack() );
	checkZrv->setChecked      ( m_sat->isVisibleZrv  () );
	checkZrvLines->setChecked ( m_sat->isVisibleLines() );
	checkZrvEnable->setChecked( m_sat->isAtctiveZone () );

	rgb = m_sat->colorLabel();
	pal = btnColorName->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorName->setPalette(pal);

	rgb = m_sat->colorZrv();
	pal = btnColorZrv->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorZrv->setPalette(pal);

	rgb = m_sat->colorLines();
	pal = btnColorLines->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorLines->setPalette(pal);

	rgb = m_sat->colorTrack();
	pal = btnColorTrack->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));

	btnColorTrack->setPalette(pal);
	comboModel->blockSignals(true);
	comboModel->setCurrentIndex(m_sat->modelIndex());
	comboModel->blockSignals(false);
}

void Sgp4Dialog::makeSat(Satellite *sat, bool fromlist) {

	double const deg2rad = M_PI/180.0;
	double const xpdotp  = 1440.0/(2.0*M_PI);
	QPalette pal;
	QRgb rgb;

	QPixmap pixmap;
	m_fromlist = fromlist;
	m_sat = sat;
	if (exec() == QDialog::Rejected ) return;

	if (m_sat == 0) return;

	QString name = lineEditName->text();
    struct ms state;
//	double i     = lineEditI->text().toDouble()*deg2rad;
//	double omg   = lineEditOmg->text().toDouble()*deg2rad;
//	double e     = lineEditE->text().toDouble();
//	double w     = lineEditW->text().toDouble()*deg2rad;
//	double m0    = lineEditM0->text().toDouble()*deg2rad;
//	double n     = lineEditN->text().toDouble()/xpdotp;
//	double bstar = lineEditBStar->text().toDouble();
//	double epoch = lineEditTime->text().toDouble();

    state.inclo     = lineEditI->text().toDouble()*deg2rad;
    state.argpo   = lineEditOmg->text().toDouble()*deg2rad;
    state.ecco     = lineEditE->text().toDouble();
    state.nodeo     = lineEditW->text().toDouble()*deg2rad;
    state.mo    = lineEditM0->text().toDouble()*deg2rad;
    state.no     = lineEditN->text().toDouble()/xpdotp;
    state.bstar = lineEditBStar->text().toDouble();
    state.jdsatepoch = lineEditTime->text().toDouble();
    state.consttype = WGS84;
    
//		double epoch = 	QDateTime::fromString(lineEditSatTime->text(), "dd.MM.yyyy H:mm:ss").toTime_t();
//		epoch = epoch/86400.0 + 2440587.5;
	double zrv = spinZRV->value()*deg2rad;

//	return;
	m_sat->modelInit((char *)&state, sizeof(state));
	m_sat->setName(name);
	m_sat->setZrv(zrv);
	m_sat->setTrack(spinTrack->value());
	m_sat->setFont(btnFont->font());

	m_sat->setNameX( spinNameX->value() );
	m_sat->setNameY( spinNameY->value() );

	m_sat->setLinesWidth( spinLines->value() );

	m_sat->visibleLabel( checkName->isChecked()      );
	m_sat->visibleTrack( checkTrack->isChecked()     );
	m_sat->visibleZrv  ( checkZrv->isChecked()       );
	m_sat->visibleLines( checkZrvLines->isChecked()  );
	m_sat->activeZone  ( checkZrvEnable->isChecked() );

	pal = btnColorName->palette();
	rgb = pal.color(QPalette::Button).rgba();
	m_sat->setColorLabel(flipRgb(rgb));

	pal = btnColorZrv->palette();
	rgb = pal.color(QPalette::Button).rgba();
	m_sat->setColorZrv(flipRgb(rgb));

	pal = btnColorLines->palette();
	rgb = pal.color(QPalette::Button).rgba();
	m_sat->setColorLines(flipRgb(rgb));

	pal = btnColorTrack->palette();
	rgb = pal.color(QPalette::Button).rgba();
	m_sat->setColorTrack(flipRgb(rgb));

	m_sat->setModelIndex(comboModel->currentIndex());
}

void Sgp4Dialog::setBtnColor(QWidget *widget) {
    QPalette pal = widget->palette();
    QColor color = QColorDialog::getColor(pal.color(QPalette::Button), this, "",
            QColorDialog::ShowAlphaChannel | QColorDialog::DontUseNativeDialog);
    if (color.isValid()) {
        pal.setColor(QPalette::Button, color);
        widget->setPalette(pal);
    }
}

void Sgp4Dialog::setColorSatName() {
	setBtnColor(btnColorName);
}

void Sgp4Dialog::setColorSatZrv() {
	setBtnColor(btnColorZrv);
}

void Sgp4Dialog::setColorSatLines() {
	setBtnColor(btnColorLines);
}

void Sgp4Dialog::setColorSatTrack() {
	setBtnColor(btnColorTrack);
}

void Sgp4Dialog::setSatFont() {
	bool ok;
	QFont font = QFontDialog::getFont(&ok, btnFont->font(), this);
	if (ok) btnFont->setFont(font);
}

void Sgp4Dialog::setDefault() {
	Satellite *sat = m_sat;
	makeSat(&defaultSat, 0);
	m_sat = sat;
}

void Sgp4Dialog::selectModel(int index) {
    if (index < 0) return;
    puts("selectModel");
    if (satWidget->satList.count() < 1) return;
    if (m_fromlist) {
            int pos = satWidget->satList.indexOf(m_sat);
            if (pos == -1) {
                puts("sat not found");
                return;
            }
            satWidget->selectSatModel(index, pos);
            m_sat = satWidget->satList.at(pos);
    }
    else m_sat->setModelIndex(index);
}

void Sgp4Dialog::setIcon() {
    QDir dir = QDir::home();
    dir.cd("satviewer/icons");
    QString filePath = QFileDialog::getOpenFileName(this, "Open PNG Image", dir.path(), "PNG Images (*.png)");
    if (filePath.isEmpty()) return;
    btnIcon->setIcon(QPixmap(filePath));
    satWidget->setIcon(m_sat, filePath);
}

void Sgp4Dialog::setSatWidget(GLSatAbstractWidget *satWidget) { 
    this->satWidget = satWidget; 
    comboModel->clear();
    comboModel->addItems(satWidget->satModelList());
}
