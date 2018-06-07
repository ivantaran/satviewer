// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * SLocDialog.cpp
 *
 *  Created on: 03.01.2010
 *      Author: Ivan Ryazanov
 */

#include "SLocDialog.h"
#include <QtMath>

SLocDialog::SLocDialog(GLSatAbstractWidget *satWidget) {
    m_loc = NULL;
    widget.setupUi(this);
    setSatWidget(satWidget);

    widget.lineEditAzimuth->setValidator(new QDoubleValidator());
    widget.lineEditHeight->setValidator (new QDoubleValidator());
    widget.lineEditLat->setValidator    (new QDoubleValidator());
    widget.lineEditLon->setValidator    (new QDoubleValidator());
    widget.lineEditRange->setValidator  (new QDoubleValidator());
    widget.lineEditWidth->setValidator  (new QDoubleValidator());

    connect(widget.btnColorName , SIGNAL(clicked()), this, SLOT(setColorLocName ()));
    connect(widget.btnColorZrv  , SIGNAL(clicked()), this, SLOT(setColorLocZrv  ()));
    connect(widget.btnColorLines, SIGNAL(clicked()), this, SLOT(setColorLocLines()));
    connect(widget.btnFont      , SIGNAL(clicked()), this, SLOT(setLocFont      ()));
    connect(widget.btnDefault   , SIGNAL(clicked()), this, SLOT(setDefault      ()));
    connect(widget.btnIcon      , SIGNAL(clicked()), this, SLOT(setIcon         ()));
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
    if (m_loc == NULL) {
        return;
    }

//    double const rad2deg = 180.0/M_PI;
    QPalette pal;
    QRgb rgb;

    QPixmap pixmap(m_loc->iconName());
        widget.btnIcon->setIcon(pixmap);

    widget.btnFont->setFont(m_loc->font());

    widget.lineEditName->setText   ( m_loc->name() );
    widget.lineEditLat->setText    ( QString::number( m_loc->latitude(),   'g', 16) );
    widget.lineEditLon->setText    ( QString::number( m_loc->longitude(),  'g', 16) );
    widget.lineEditHeight->setText ( QString::number( m_loc->height(),     'g', 16) );
    widget.lineEditAzimuth->setText( QString::number( m_loc->zrlAzimuth(), 'g', 16) );
    widget.lineEditRange->setText  ( QString::number( m_loc->zrlRange(),   'g', 16) );
    widget.lineEditWidth->setText  ( QString::number( m_loc->zrlWidth(),   'g', 16) );

    widget.spinNameX->setValue( m_loc->nameX() );
    widget.spinNameY->setValue( m_loc->nameY() );

    widget.spinLines->setValue( m_loc->linesWidth() );

    widget.checkName->setChecked     ( m_loc->isVisibleLabel() );
    widget.checkZrv->setChecked      ( m_loc->isVisibleZrv  () );
    widget.checkZrvLines->setChecked ( m_loc->isVisibleLines() );
    widget.checkZrvEnable->setChecked( m_loc->isActiveZone  () );

    rgb = m_loc->colorLabel();
    pal = widget.btnColorName->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(rgb));
    widget.btnColorName->setPalette(pal);

    rgb = m_loc->colorZrv();
    pal = widget.btnColorZrv->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
    widget.btnColorZrv->setPalette(pal);

    rgb = m_loc->colorLines();
    pal = widget.btnColorLines->palette();
    pal.setColor(QPalette::Button, QColor::fromRgba(flipRgb(rgb)));
    widget.btnColorLines->setPalette(pal);
}

void SLocDialog::makeLoc(Location *loc) {
    if (loc == NULL) return;

    QPalette pal;
    QRgb rgb;

    QPixmap pixmap;
    setLoc(loc);
    if (exec() == QDialog::Rejected) return;

    double lat     = widget.lineEditLat->text().toDouble();
    double lon     = widget.lineEditLon->text().toDouble();
    double height  = widget.lineEditHeight->text().toDouble();
    double azimuth = widget.lineEditAzimuth->text().toDouble();
    double range   = widget.lineEditRange->text().toDouble();
    double width   = widget.lineEditWidth->text().toDouble();

    loc->setName( widget.lineEditName->text() );
    loc->setLatitude  ( lat     );
    loc->setLongitude ( lon     );
    loc->setHeight    ( height  );
    loc->setZrlAzimuth( azimuth );
    loc->setZrlRange  ( range   );
    loc->setZrlWidth  ( width   );

    loc->setNameX( widget.spinNameX->value() );
    loc->setNameY( widget.spinNameY->value() );

    loc->setLinesWidth( widget.spinLines->value() );

    loc->setFont     ( widget.btnFont->font()             );
    loc->visibleLabel( widget.checkName->isChecked()      );
    loc->visibleZrv  ( widget.checkZrv->isChecked()       );
    loc->visibleLines( widget.checkZrvLines->isChecked()  );
    loc->activeZone  ( widget.checkZrvEnable->isChecked() );

    pal = widget.btnColorName->palette();
    rgb = pal.color(QPalette::Button).rgba();
    loc->setColorLabel(rgb);

    pal = widget.btnColorZrv->palette();
    rgb = pal.color(QPalette::Button).rgba();
    loc->setColorZrv(flipRgb(rgb));

    pal = widget.btnColorLines->palette();
    rgb = pal.color(QPalette::Button).rgba();
    loc->setColorLines(flipRgb(rgb));

}

void SLocDialog::setBtnColor(QWidget *widget) {
    QPalette pal = widget->palette();
    QColor color = QColorDialog::getColor(
            pal.color(QPalette::Button), 
            this, "", 
            QColorDialog::ShowAlphaChannel | QColorDialog::DontUseNativeDialog);
    if (color.isValid()) {
        pal.setColor(QPalette::Button, color);
        widget->setPalette(pal);
    }
}

void SLocDialog::setColorLocName() {
    setBtnColor(widget.btnColorName);
//        Satellite *sat = satList.getItem(satWidget->indexSat);
//        sat->setColorLabel(rgb);
}

void SLocDialog::setColorLocZrv() {
    setBtnColor(widget.btnColorZrv);
}

void SLocDialog::setColorLocLines() {
    setBtnColor(widget.btnColorLines);
}

void SLocDialog::setLocFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, widget.btnFont->font(), this);
    if (ok) widget.btnFont->setFont(font);
}

void SLocDialog::setDefault() {
    Location *loc = m_loc;
    makeLoc(&defaultLoc);
    m_loc = loc;
}

void SLocDialog::setIcon() {
    QDir dir = QDir::home();
    dir.cd("satviewer/icons");
    QString filePath = QFileDialog::getOpenFileName(
            this, 
            "Open PNG Image", 
            dir.path(), 
            "PNG Images (*.png)", NULL, 
            QFileDialog::DontUseNativeDialog);
    if (!filePath.isEmpty()) {
        widget.btnIcon->setIcon(QPixmap(filePath));
        satWidget->setIcon(m_loc, filePath);
    }
}

void SLocDialog::setSatWidget(GLSatAbstractWidget *satWidget) {
    this->satWidget = satWidget;
}
