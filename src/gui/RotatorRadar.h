#ifndef ROTATORRADAR_H
#define ROTATORRADAR_H

#include <QWidget>
#include <QPainter>
#include <QtMath>

class RotatorRadar : public QWidget {
    Q_OBJECT
    
public:
    RotatorRadar();
    virtual ~RotatorRadar();
    void setSensor(qreal azm, qreal elv, bool visible);    
protected:    
    virtual void paintEvent(QPaintEvent*);
    virtual void resizeEvent(QResizeEvent *event);    

private:
    QColor m_colorBackground;
    QColor m_colorGrid;
    QColor m_colorItem;
    QColor m_colorItemBorder;

    class RadarItem{
    public:
        RadarItem() {    
            azm     = 0.0;//(qreal)(qrand() % 628) * 0.01;
            elv     = 0.0;//-M_PI_2;//(qreal)(qrand() % 157) * 0.01;
            visible = true;
        }
        qreal azm;
        qreal elv;
        bool visible;
    };
    
    RadarItem m_sensor;
    void drawSensor(QPainter *p);
};

#endif	/* ROTATORRADAR_H */
