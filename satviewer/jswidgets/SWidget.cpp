/*
 * SWidget.cpp
 *
 *  Created on: 19.03.2010
 *      Author: Yan Coduemat
 */

#include "SWidget.h"
#include <QMouseEvent>

SWidget::SWidget(QWidget *parent, QString fileName) {
	m_sat = 0;
	m_loc = 0;
	m_time = 0;
	m_maskColor = Qt::magenta;
	m_fillColor = Qt::black;
	this->resize(64, 32);
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly)) {
		puts(QString("Error script file open: %0").arg(file.errorString()).toLocal8Bit().data());
		return;
	}
	QTextStream stream(&file);
	script = stream.readAll();
	file.close();
    QScriptValue scriptCanvas = engine.newQObject(this);
    engine.globalObject().setProperty("canvas", scriptCanvas);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    setCursor(Qt::OpenHandCursor);
    this->setParent(parent);
	pixmap = QPixmap(width(), height());
	pixmap.fill(Qt::black);
	canvas.begin(&pixmap);

	engine.evaluate(script);
    m_title = engine.globalObject().property("title").toString();
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
	timer->setInterval(1000);
	timer->start();
	this->onTimer();
	//this->show();
}
void SWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	setMask(pixmap.createMaskFromColor(m_maskColor));
	painter.drawPixmap(0, 0, pixmap);
	painter.end();
}

SWidget::~SWidget() {

}

void SWidget::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {
		move(event->globalPos() - dragPosition);
		event->accept();
	}
}

void SWidget::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		dragPosition = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void SWidget::onTimer() {
	if ((m_sat == 0) || (m_loc == 0) || (m_time == 0)) {
		hide();
		return;
	}
	if (!isVisible()) show();
	setVars();
	QScriptValue sVal =  engine.evaluate(script);
    if (sVal.isError()) puts(sVal.toString().toAscii().data());
    this->repaint();
}

void SWidget::drawText(int x, int y, QString text) {
	canvas.drawText(x, y, text);
}

void SWidget::fill(int value) {
	m_fillColor = QColor::fromRgb(value);
	pixmap.fill(value);
}

void SWidget::setPen(int value) {
	canvas.setPen(QColor::fromRgb(value));
}

void SWidget::setFont(QString fontName, int pointSize, int weight, bool italic) {
	QFont font(fontName, pointSize, weight, italic);
	if (m_maskColor == m_fillColor) font.setStyleStrategy(QFont::NoAntialias);
	else font.setStyleStrategy(QFont::PreferAntialias);
	canvas.setFont(font);
}

void SWidget::setSize(int w, int h) {
	canvas.end();
	resize(w, h);
	pixmap = pixmap.scaled(w, h);
	canvas.begin(&pixmap);
	if (m_maskColor == m_fillColor) canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, false);
	else canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
}

void SWidget::setPos(int x, int y) {
	move(x, y);
}

void SWidget::setInterval(int value) {
	timer->setInterval(value);
}

void SWidget::setMaskColor(int value) {
	m_maskColor = QColor::fromRgb(value);
	if (m_maskColor == m_fillColor) canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, false);
	else canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
}

void SWidget::setVars() {
	if ((m_sat == 0) || (m_loc == 0) || (m_time == 0)) return;
    engine.globalObject().setProperty("timeNow", *m_time, QScriptValue::ReadOnly);
    engine.globalObject().setProperty("nameSat", m_sat->name(), QScriptValue::ReadOnly);
    engine.globalObject().setProperty("nameLoc", m_loc->name(), QScriptValue::ReadOnly);
    QScriptValue ascSat =  engine.newArray(6);
    QScriptValue ascLoc =  engine.newArray(6);
    for (int i = 0; i < 3; i++) {
    	ascSat.setProperty(i    , m_sat->xyz_g()[i] );
    	ascSat.setProperty(i + 3, m_sat->vxyz_g()[i]);
    	ascLoc.setProperty(i    , m_loc->xyz()[i]   );
    	ascLoc.setProperty(i + 3, 0.0               );
    }
    engine.globalObject().setProperty("ascSat", ascSat, QScriptValue::ReadOnly);
    engine.globalObject().setProperty("ascLoc", ascLoc, QScriptValue::ReadOnly);
    QWidget *p = (QWidget *)parent();
    engine.globalObject().setProperty("parentWidth", p->width(), QScriptValue::ReadOnly);
    engine.globalObject().setProperty("parentHeight", p->height(), QScriptValue::ReadOnly);
}

void SWidget::set(Satellite *sat, Location *loc, double *time) {
	m_sat = sat;
	m_loc = loc;
	m_time = time;
}

void SWidget::activate(bool state) {
	if (state) {
		timer->start();
		show();
	}
	else {
		timer->stop();
		hide();
	}
}
