/*
 * SWidget.h
 *
 *  Created on: 19.03.2010
 *      Author: Ivan Ryazanov
 */

#ifndef SWIDGET_H_
#define SWIDGET_H_

#include "../Location.h"
#include "../Satellite.h"
#include <QFontMetrics>
#include <QJSEngine>
#include <QPainter>
#include <QWidget>

class SWidget : public QWidget {
    Q_OBJECT
public:
    SWidget(QWidget *parent = nullptr, const QString &fileName = "");
    virtual ~SWidget();
    void set(Satellite *sat, Location *loc, double *time);
    inline QString title() {
        return m_title;
    }
    void activate(bool state = true);

public slots:
    void drawText(int x, int y, const QString &text);
    void fill(int value);
    void setPen(int value);
    void setFont(QString name, int pointSize, int weight, bool italic);
    void setSize(int w, int h);
    void setPos(int x, int y);
    void setInterval(int value);
    void setMaskColor(int value);
    int textWidth(const QString &text);
    int fontHeight();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QPoint dragPosition;
    QPixmap pixmap;
    QPainter canvas;
    QColor m_maskColor, m_fillColor;
    int m_timer;
    int m_interval;
    QString script;
    QString m_title;
    QJSEngine engine;
    Satellite *m_sat;
    Location *m_loc;
    double *m_time;
    void setVars();
    void timerEvent(QTimerEvent *event);

private slots:
    void onTimer();
};

#endif /* SWIDGET_H_ */
