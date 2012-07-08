/*
 * SLocDialog.cpp
 *
 *  Created on: 03.01.2010
 *      Author: Yan Coduemat
 */

#include "SLocDialog.h"
#include "math.h"

SLocDialog::SLocDialog(GLSatAbstractWidget *satWidget) {
    m_loc = 0;
    this->setupUi(this);
    setSatWidget(satWidget);

    lineEditAzimuth->setValidator(new QDoubleValidator());
    lineEditHeight->setValidator (new QDoubleValidator());
    lineEditLat->setValidator    (new QDoubleValidator());
    lineEditLon->setValidator    (new QDoubleValidator());
    lineEditRange->setValidator  (new QDoubleValidator());
    lineEditWidth->setValidator  (new QDoubleValidator());

    connect(btnColorName , SIGNAL(clicked()), this, SLOT(setColorLocName ()));
    connect(btnColorZrv  , SIGNAL(clicked()), this, SLOT(setColorLocZrv  ()));
    connect(btnColorLines, SIGNAL(clicked()), this, SLOT(setColorLocLines()));
    connect(btnFont      , SIGNAL(clicked()), this, SLOT(setLocFont      ()));
    connect(btnDefault   , SIGNAL(clicked()), this, SLOT(setDefault      ()));
    connect(btnIcon      , SIGNAL(clicked()), this, SLOT(setIcon         ()));
}

SLocDialog::~SLocDialog() {

}

uint32_t SLocDialog::flipRgb(uint32_t rgb) {
    //OpenGL 0xAABBGGRR //Qt 0xAARRGGBB
    uint8_t a, r, g, b;
    b = rgb;
    g = rgb >> 8;
    r = rgb >> 16;
    a = rgb >> 24;
    rgb = (a << 24) | (b << 16) | (g << 8) | (r);
    return rgb;
}

void SLocDialog::showEvent(QShowEvent * event) {
	if (m_loc == 0) return;

//	double const rad2deg = 180.0/M_PI;
	QPalette pal;
	QRgb rgb;

	QPixmap pixmap(m_loc->iconName());
        btnIcon->setIcon(pixmap);

	btnFont->setFont(m_loc->font());

	lineEditName->setText   ( m_loc->name() );
	lineEditLat->setText    ( QString::number( m_loc->latitude(),   'g', 16) );
	lineEditLon->setText    ( QString::number( m_loc->longitude(),  'g', 16) );
	lineEditHeight->setText ( QString::number( m_loc->height(),     'g', 16) );
	lineEditAzimuth->setText( QString::number( m_loc->zrlAzimuth(), 'g', 16) );
	lineEditRange->setText  ( QString::number( m_loc->zrlRange(),   'g', 16) );
	lineEditWidth->setText  ( QString::number( m_loc->zrlWidth(),   'g', 16) );

	spinNameX->setValue( m_loc->nameX() );
	spinNameY->setValue( m_loc->nameY() );

	spinLines->setValue( m_loc->linesWidth() );

	checkName->setChecked     ( m_loc->isVisibleLabel() );
	checkZrv->setChecked      ( m_loc->isVisibleZrv  () );
	checkZrvLines->setChecked ( m_loc->isVisibleLines() );
	checkZrvEnable->setChecked( m_loc->isActiveZone  () );

	rgb = m_loc->colorLabel();
	pal = btnColorName->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorName->setPalette(pal);

	rgb = m_loc->colorZrv();
	pal = btnColorZrv->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorZrv->setPalette(pal);

	rgb = m_loc->colorLines();
	pal = btnColorLines->palette();
	pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
	btnColorLines->setPalette(pal);
}

void SLocDialog::makeLoc(Location *loc) {
	if (loc == 0) return;

//	double const deg2rad = M_PI/180.0;
	QPalette pal;
	QRgb rgb;

	QPixmap pixmap;
	setLoc(loc);
	if (exec() == QDialog::Rejected ) return;

	double lat     = lineEditLat->text().toDouble();
	double lon     = lineEditLon->text().toDouble();
	double height  = lineEditHeight->text().toDouble();
	double azimuth = lineEditAzimuth->text().toDouble();
	double range   = lineEditRange->text().toDouble();
	double width   = lineEditWidth->text().toDouble();

	loc->setName( lineEditName->text() );
	loc->setLatitude  ( lat     );
	loc->setLongitude ( lon     );
	loc->setHeight    ( height  );
	loc->setZrlAzimuth( azimuth );
	loc->setZrlRange  ( range   );
	loc->setZrlWidth  ( width   );

	loc->setNameX( spinNameX->value() );
	loc->setNameY( spinNameY->value() );

	loc->setLinesWidth( spinLines->value() );

	loc->setFont     ( btnFont->font()             );
	loc->visibleLabel( checkName->isChecked()      );
	loc->visibleZrv  ( checkZrv->isChecked()       );
	loc->visibleLines( checkZrvLines->isChecked()  );
	loc->activeZone  ( checkZrvEnable->isChecked() );

	pal = btnColorName->palette();
	rgb = pal.color(QPalette::Button).rgba();
	loc->setColorLabel(flipRgb(rgb));

	pal = btnColorZrv->palette();
	rgb = pal.color(QPalette::Button).rgba();
	loc->setColorZrv(flipRgb(rgb));

	pal = btnColorLines->palette();
	rgb = pal.color(QPalette::Button).rgba();
	loc->setColorLines(flipRgb(rgb));

}

void SLocDialog::setBtnColor(QWidget *widget) {
	QPalette pal = widget->palette();
	QColor color = QColorDialog::getColor(pal.color(QPalette::Button), this, 0, QColorDialog::ShowAlphaChannel);
	if (!color.isValid()) return;
	pal.setColor(QPalette::Button, color);
	widget->setPalette(pal);
}

void SLocDialog::setColorLocName() {
	setBtnColor(btnColorName);
//		Satellite *sat = satList.getItem(satWidget->indexSat);
//		sat->setColorLabel(rgb);
}

void SLocDialog::setColorLocZrv() {
	setBtnColor(btnColorZrv);
}

void SLocDialog::setColorLocLines() {
	setBtnColor(btnColorLines);
}

void SLocDialog::setLocFont() {
	bool ok;
	QFont font = QFontDialog::getFont(&ok, btnFont->font(), this);
	if (ok) btnFont->setFont(font);
}

void SLocDialog::setDefault() {
	Location *loc = m_loc;
	makeLoc(&defaultLoc);
	m_loc = loc;
}

void SLocDialog::setIcon() {
    QDir dir = QDir::home();
    dir.cd("satviewer/icons");
    QString filePath = QFileDialog::getOpenFileName(this, "Open PNG Image", dir.path(), "PNG Images (*.png)");
    if (filePath.isEmpty()) return;
    btnIcon->setIcon(QPixmap(filePath));
    satWidget->setIcon(m_loc, filePath);
}

void SLocDialog::setSatWidget(GLSatAbstractWidget *satWidget) {
    this->satWidget = satWidget;
}
