#include "RotatorRadar.h"
#include <QPainterPath>

RotatorRadar::RotatorRadar() {
}

RotatorRadar::~RotatorRadar() {
}

void RotatorRadar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)

    m_colorBackground = Qt::black;
    m_colorGrid = Qt::lightGray;
    m_colorItem = Qt::yellow;
    m_colorItemBorder = Qt::white;

    const qreal scale0 = 0.14644660940672623779957781894758;
    const qreal scale1 = (1.0 - scale0);

    QPainter p;
    p.begin(this);
    // this->setMargins(&p);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::TextAntialiasing, true);

    QPen pen = p.pen();
    pen.setWidth(1);
    p.setPen(m_colorGrid);

    QPainterPath path;
    qreal rx = p.device()->width();
    qreal ry = p.device()->height();

    QPointF point(0.5 * rx, 0.5 * ry);

    path.addEllipse(point, 0.50 * rx, 0.50 * ry);
    p.fillPath(path, m_colorBackground);
    path.addEllipse(point, 0.25 * rx, 0.25 * ry);
    p.drawPath(path);

    p.drawLine(0, 0.5 * ry, rx, 0.5 * ry);
    p.drawLine(0.5 * rx, 0, 0.5 * rx, ry);
    p.drawLine(rx * scale0 + 1, ry * scale0 + 1, rx * scale1 - 1, ry * scale1 - 1);
    p.drawLine(rx * scale0 + 1, ry * scale1 - 1, rx * scale1 - 1, ry * scale0 + 1);

    // drawItems(&p);
    drawSensor(&p);

    p.end();
}

// void RotatorRadar::drawItems(QPainter *p) {

//     QString label;
//     bool visible;
//     qreal xx, yy, rr;

//     qreal w = (qreal)p->device()->width();
//     qreal h = (qreal)p->device()->height();
//     qreal r = qMin(w, h) * 0.075;

//     QFont font = p->font();
//     font.setPointSizeF(r);
//     font.setFamily("Consolas");
//     p->setFont(font);

//     for (int i = 0; i < ItemsCount; i++) {
//         rr = 0.5 - items[i].elv / M_PI;
//         if (rr >= 0.0 && rr <= 0.5) {
//             xx = rr * qCos(items[i].azm - M_PI_2);
//             yy = rr * qSin(items[i].azm - M_PI_2);
//             label = QString("%1").arg(i + 1, 2, 10, QChar('0'));
//             visible = true;
//         }
//         else {
//             xx = 0.0;
//             yy = 0.0;
//             label = "00";
//             visible = false;
//         }

//         if (visible) {
//             qreal x = w * 0.5 + xx * w;
//             qreal y = h * 0.5 + yy * h;

//             QPainterPath path;
//             path.addEllipse(QPointF(x, y), r, r);
//             switch (items[i].state) {
//                 case StateDllLocked:
//                     p->fillPath(path, ColorDllLocked);
//                     p->setPen(ColorPenDllLocked);
//                     break;
//                 case StatePllLocked:
//                     p->fillPath(path, ColorPllLocked);
//                     p->setPen(ColorPenPllLocked);
//                     break;
//                 case StateInfLocked:
//                     p->fillPath(path, ColorInfLocked);
//                     p->setPen(ColorPenInfLocked);
//                     break;
//                 default:
//                     p->fillPath(path, ColorNotLocked);
//                     p->setPen(ColorPenNotLocked);
//                     break;
//             }
//             p->drawPath(path);
//             p->setPen(QColor("black"));
//             p->drawText(QRectF(x - r, y - r, 2 * r, 2 * r), Qt::AlignCenter, label);
//         }
//     }
// }

void RotatorRadar::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event)

    int size = qMin(this->width(), this->height());
    this->resize(size, size);
}

void RotatorRadar::drawSensor(QPainter *p) {

    bool visible;
    qreal xx, yy, rr;

    qreal w = (qreal)p->device()->width();
    qreal h = (qreal)p->device()->height();
    qreal r = qMin(w, h) * 0.033;

    QFont font = p->font();
    font.setPointSizeF(r);
    font.setFamily("Consolas");
    p->setFont(font);

    rr = (0.5 - m_sensor.elv / M_PI);
    if (m_sensor.visible) {
        xx = rr * qCos(m_sensor.azm - M_PI_2);
        yy = rr * qSin(m_sensor.azm - M_PI_2);
        visible = true;
    } else {
        xx = 0.0;
        yy = 0.0;
        visible = false;
    }

    if (visible) {
        qreal x = w * 0.5 + xx * w;
        qreal y = h * 0.5 + yy * h;

        QPainterPath path;
        path.addEllipse(QPointF(x, y), r, r);

        switch (visible) {
        case true:
            p->setPen(m_colorItemBorder);
            p->fillPath(path, m_colorItem);
            break;
        case false:
            p->fillPath(path, QColor("lightred"));
            p->setPen(QColor("gray"));
            break;
        default:
            p->fillPath(path, QColor("lightyellow"));
            p->setPen(QColor("gray"));
            break;
        }
    }
}

void RotatorRadar::setSensor(qreal azm, qreal elv, bool visible) {
    m_sensor.azm = azm;
    m_sensor.elv = elv;
    m_sensor.visible = visible;
    repaint();
}
