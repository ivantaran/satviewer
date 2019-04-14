// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * SWidget.cpp
 *
 *  Created on: 19.03.2010
 *      Author: Ivan Ryazanov
 */

#include "SWidget.h"
#include <QMouseEvent>
#include <QBitmap>
#include <QTimer>
#include <QDebug>

SWidget::SWidget(QWidget *parent, QString fileName) {
    m_sat = 0; //TODO nullptr, fileName - const
    m_loc = 0;
    m_time = 0;
    m_maskColor = Qt::magenta;
    m_fillColor = Qt::black;
    this->resize(64, 32);
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Error script file open: " << file.errorString();
        return;
    }
    QTextStream stream(&file);
    script = stream.readAll();
    file.close();
    QJSValue scriptCanvas = engine.newQObject(this);
    engine.globalObject().setProperty("canvas", scriptCanvas);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    setCursor(Qt::OpenHandCursor);
    this->setParent(parent);
    pixmap = QPixmap(width(), height());
    pixmap.fill(Qt::black);
    if (!canvas.begin(&pixmap)) {
        qWarning("%s: canvas.begin", __func__);
    }

    engine.evaluate(script);
    m_title = engine.globalObject().property("title").toString();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->setInterval(1000);
    timer->start();
    this->onTimer();
}

void SWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    setMask(pixmap.createMaskFromColor(m_maskColor));
    painter.drawPixmap(0, 0, pixmap);
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
    if (!m_sat || !m_loc || !m_time) {
        hide();
        return;
    }
    if (!isVisible()) show();
    setVars();
    QJSValue value =  engine.evaluate(script);
    if (value.isError()) {
        qWarning() << value.toString();
        qWarning() << value.property("lineNumber").toInt();
    }
    repaint();
}

void SWidget::drawText(int x, int y, QString text) {
    canvas.drawText(x, y, text);
}

int SWidget::textWidth(QString text) {
    return canvas.fontMetrics().width(text);
}

int SWidget::fontHeight() {
    return canvas.fontMetrics().height();
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
    if (m_maskColor == m_fillColor) {
        font.setStyleStrategy(QFont::NoAntialias);
    }
    else {
        font.setStyleStrategy(QFont::PreferAntialias);
    }
    canvas.setFont(font);
}

void SWidget::setSize(int w, int h) {
    if (width() == w && height() == h) {
        return;
    }
    resize(w, h);
    QFont font = canvas.font();
    if (!canvas.end()) {
        qWarning("%s: canvas.begin", __func__);
    }
    pixmap = pixmap.scaled(w, h);
    if (!canvas.begin(&pixmap)) {
        qWarning("%s: canvas.begin", __func__);
    }
    if (m_maskColor == m_fillColor) {
        canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, false);
        font.setStyleStrategy(QFont::NoAntialias);
    }
    else {
        canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        font.setStyleStrategy(QFont::PreferAntialias);
    }
    canvas.setFont(font);
}

void SWidget::setPos(int x, int y) {
    move(x, y);
}

void SWidget::setInterval(int value) {
    timer->setInterval(value);
}

void SWidget::setMaskColor(int value) {
    m_maskColor = QColor::fromRgb(value);
    if (m_maskColor == m_fillColor) {
        canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, false);
    }
    else { 
        canvas.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    }
}

void SWidget::setVars() {
    if (!m_sat || !m_loc || !m_time) {
        return;
    }
    engine.globalObject().setProperty("timeNow", *m_time);
    engine.globalObject().setProperty("nameSat", m_sat->name());
    engine.globalObject().setProperty("nameLoc", m_loc->name());
    QJSValue ascSat =  engine.newArray(6);
    QJSValue ascLoc =  engine.newArray(6);
    for (int i = 0; i < 6; i++) {
        ascSat.setProperty(i, m_sat->rg()[i]);
        ascLoc.setProperty(i, m_loc->rg()[i]);
    }
    engine.globalObject().setProperty("ascSat", ascSat);
    engine.globalObject().setProperty("ascLoc", ascLoc);
    QWidget *p = (QWidget *)parent();
    engine.globalObject().setProperty("parentWidth", p->width());
    engine.globalObject().setProperty("parentHeight", p->height());
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
