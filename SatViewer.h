/* 
 * File:   SatViewer.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 9:45 PM
 */

#ifndef SATVIEWER_H
#define SATVIEWER_H

#include <QList>

#include "locutils/Location.h"
#include "satutils/Satellite.h"

class SatViewer {
public:
    SatViewer();
    SatViewer(const SatViewer& orig);
    virtual ~SatViewer();
    QList<Satellite *> *satellites() { return &m_satellites; }
    QList<Location *> *locations() { return &m_locations; }
private:
    QList<Satellite *> m_satellites;
    QList<Location *> m_locations;

};

#endif /* SATVIEWER_H */

