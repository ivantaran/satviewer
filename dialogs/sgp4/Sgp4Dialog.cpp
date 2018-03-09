// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * Sgp4Dialog.cpp
 *
 *  Created on: 28.12.2009
 *      Author: Ivan Ryazanov
 */

#include "Sgp4Dialog.h"
#include "../../models/sgp4/sgp_struct.h"
#include "math.h"

Sgp4Dialog::Sgp4Dialog(GLSatAbstractWidget *satWidget) : SAbstractObjDialog(satWidget) {
    widget.setupUi(this);
    widget.lineEditBStar->setValidator(new QDoubleValidator());
    widget.lineEditE->setValidator    (new QDoubleValidator());
    widget.lineEditI->setValidator    (new QDoubleValidator());
    widget.lineEditM0->setValidator   (new QDoubleValidator());
    widget.lineEditN->setValidator    (new QDoubleValidator());
    widget.lineEditOmg->setValidator  (new QDoubleValidator());
    widget.lineEditTime->setValidator (new QDoubleValidator());
    widget.lineEditW->setValidator    (new QDoubleValidator());
    m_sat = 0;
    m_fromlist = true;
    setSatWidget(satWidget);
    widget.comboModel->addItems(satWidget->satModelList());
    //connect(btnIcon, SIGNAL(clicked()), this, SLOT(setIcon()));
    connect(widget.btnColorName , SIGNAL(clicked()), this, SLOT(setColorSatName ()));
    connect(widget.btnColorZrv  , SIGNAL(clicked()), this, SLOT(setColorSatZrv  ()));
    connect(widget.btnColorLines, SIGNAL(clicked()), this, SLOT(setColorSatLines()));
    connect(widget.btnColorTrack, SIGNAL(clicked()), this, SLOT(setColorSatTrack()));
    connect(widget.btnFont      , SIGNAL(clicked()), this, SLOT(setSatFont      ()));
    connect(widget.btnDefault   , SIGNAL(clicked()), this, SLOT(setDefault      ()));
    connect(widget.btnIcon      , SIGNAL(clicked()), this, SLOT(setIcon         ()));
    connect(widget.comboModel, SIGNAL(currentIndexChanged(int)), this, SLOT(selectModel(int)));
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
    widget.btnIcon->setIcon(pixmap);

    widget.spinTrack->setValue(m_sat->track());
    widget.btnFont->setFont(m_sat->font());

    widget.lineEditName->setText ( m_sat->name() );
    widget.lineEditI->setText    ( QString::number( m_sat->inclination()*rad2deg,   'g', 16) );
    widget.lineEditOmg->setText  ( QString::number( m_sat->argLatPerigee()*rad2deg, 'g', 16) );
    widget.lineEditE->setText    ( QString::number( m_sat->eccentricity(),          'g', 16) );
    widget.lineEditW->setText    ( QString::number( m_sat->latAscNode()*rad2deg,    'g', 16) );
    widget.lineEditM0->setText   ( QString::number( m_sat->meanAnomaly()*rad2deg,   'g', 16) );
    widget.lineEditN->setText    ( QString::number( m_sat->meanMotion()*xpdotp,     'g', 16) );
    widget.lineEditBStar->setText( QString::number( m_sat->bStar(),                 'g', 16) );
    widget.spinZRV->setValue     ( m_sat->zrvWidth()*rad2deg );

    widget.spinNameX->setValue( (int)m_sat->nameX() );
    widget.spinNameY->setValue( (int)m_sat->nameY() );
    widget.spinLines->setValue( m_sat->linesWidth() );

    //		double tm = 86400.0*(m_sat->jEpoch() - 2440587.5);
    //		lineEditSatTime->setText(QDateTime::fromTime_t((int)tm).toString("dd.MM.yyyy H:mm:ss"));

    uint64_t tm = (uint64_t)(86400000.0*(m_sat->jEpoch() - 2440587.5));
    widget.dateTimeEdit->setDateTime(QDateTime::fromMSecsSinceEpoch(tm).toUTC());
    widget.lineEditTime->setText ( QString::number(m_sat->jEpoch(), 'g', 16) );

    widget.checkName->setChecked     ( m_sat->isVisibleLabel() );
    widget.checkTrack->setChecked    ( m_sat->isVisibleTrack() );
    widget.checkZrv->setChecked      ( m_sat->isVisibleZrv  () );
    widget.checkZrvLines->setChecked ( m_sat->isVisibleLines() );
    widget.checkZrvEnable->setChecked( m_sat->isAtctiveZone () );

    rgb = m_sat->colorLabel();
    pal = widget.btnColorName->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
    widget.btnColorName->setPalette(pal);

    rgb = m_sat->colorZrv();
    pal = widget.btnColorZrv->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
    widget.btnColorZrv->setPalette(pal);

    rgb = m_sat->colorLines();
    pal = widget.btnColorLines->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
    widget.btnColorLines->setPalette(pal);

    rgb = m_sat->colorTrack();
    pal = widget.btnColorTrack->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));

    widget.btnColorTrack->setPalette(pal);
    widget.comboModel->blockSignals(true);
    widget.comboModel->setCurrentIndex(m_sat->modelIndex());
    widget.comboModel->blockSignals(false);
}

void Sgp4Dialog::makeSat(Satellite *sat, bool fromlist) {

    double const deg2rad = M_PI/180.0;
    double const xpdotp  = 1440.0/(2.0*M_PI);
    QPalette pal;
    QRgb rgb;

    QPixmap pixmap;
    m_fromlist = fromlist;
    m_sat = sat;
    if (exec() == QDialog::Rejected) return;

    if (m_sat == 0) return;

    QString name = widget.lineEditName->text();
    struct ms state;
//	double i     = lineEditI->text().toDouble()*deg2rad;
//	double omg   = lineEditOmg->text().toDouble()*deg2rad;
//	double e     = lineEditE->text().toDouble();
//	double w     = lineEditW->text().toDouble()*deg2rad;
//	double m0    = lineEditM0->text().toDouble()*deg2rad;
//	double n     = lineEditN->text().toDouble()/xpdotp;
//	double bstar = lineEditBStar->text().toDouble();
//	double epoch = lineEditTime->text().toDouble();

    state.inclo     = widget.lineEditI->text().toDouble()*deg2rad;
    state.argpo   = widget.lineEditOmg->text().toDouble()*deg2rad;
    state.ecco     = widget.lineEditE->text().toDouble();
    state.nodeo     = widget.lineEditW->text().toDouble()*deg2rad;
    state.mo    = widget.lineEditM0->text().toDouble()*deg2rad;
    state.no     = widget.lineEditN->text().toDouble()/xpdotp;
    state.bstar = widget.lineEditBStar->text().toDouble();
    state.jdsatepoch = widget.lineEditTime->text().toDouble();
    state.consttype = WGS84;
    
//		double epoch = 	QDateTime::fromString(lineEditSatTime->text(), "dd.MM.yyyy H:mm:ss").toTime_t();
//		epoch = epoch/86400.0 + 2440587.5;
    double zrv = widget.spinZRV->value() * deg2rad;

    m_sat->modelInit((char *)&state, sizeof(state));
    m_sat->setName(name);
    m_sat->setZrv(zrv);
    m_sat->setTrack(widget.spinTrack->value());
    m_sat->setFont(widget.btnFont->font());

    m_sat->setNameX( widget.spinNameX->value() );
    m_sat->setNameY( widget.spinNameY->value() );

    m_sat->setLinesWidth( widget.spinLines->value() );

    m_sat->visibleLabel( widget.checkName->isChecked()      );
    m_sat->visibleTrack( widget.checkTrack->isChecked()     );
    m_sat->visibleZrv  ( widget.checkZrv->isChecked()       );
    m_sat->visibleLines( widget.checkZrvLines->isChecked()  );
    m_sat->activeZone  ( widget.checkZrvEnable->isChecked() );

    pal = widget.btnColorName->palette();
    rgb = pal.color(QPalette::Button).rgba();
    m_sat->setColorLabel(flipRgb(rgb));

    pal = widget.btnColorZrv->palette();
    rgb = pal.color(QPalette::Button).rgba();
    m_sat->setColorZrv(flipRgb(rgb));

    pal = widget.btnColorLines->palette();
    rgb = pal.color(QPalette::Button).rgba();
    m_sat->setColorLines(flipRgb(rgb));

    pal = widget.btnColorTrack->palette();
    rgb = pal.color(QPalette::Button).rgba();
    m_sat->setColorTrack(flipRgb(rgb));

    m_sat->setModelIndex(widget.comboModel->currentIndex());
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
    setBtnColor(widget.btnColorName);
}

void Sgp4Dialog::setColorSatZrv() {
    setBtnColor(widget.btnColorZrv);
}

void Sgp4Dialog::setColorSatLines() {
    setBtnColor(widget.btnColorLines);
}

void Sgp4Dialog::setColorSatTrack() {
    setBtnColor(widget.btnColorTrack);
}

void Sgp4Dialog::setSatFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, widget.btnFont->font(), this);
    if (ok) widget.btnFont->setFont(font);
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
    widget.btnIcon->setIcon(QPixmap(filePath));
    satWidget->setIcon(m_sat, filePath);
}

void Sgp4Dialog::setSatWidget(GLSatAbstractWidget *satWidget) { 
    this->satWidget = satWidget; 
    widget.comboModel->clear();
    widget.comboModel->addItems(satWidget->satModelList());
}
