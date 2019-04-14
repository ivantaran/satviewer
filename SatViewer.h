/* 
 * File:   SatViewer.h
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 9:45 PM
 */

#ifndef SATVIEWER_H
#define SATVIEWER_H

#include "locutils/Location.h"
#include "satutils/Satellite.h"

class SatViewer {
public:
    SatViewer();
    SatViewer(const SatViewer& orig);
    virtual ~SatViewer();
    void appendSatellite(Satellite* sat);
    void appendLocation(Location* loc);
    void removeSatellite(Satellite *sat);
    void removeLocation(Location *loc);
    void setCurrentSatelliteIndex(long unsigned int index);
    void setCurrentLocationIndex(long unsigned int index);
    std::list<Satellite *> satellites() { return m_satellites; }
    std::list<Location *> locations() { return m_locations; }
    Satellite *currentSatellite();
    Location *currentLocation();
private:
    std::list<Satellite *> m_satellites;
    std::list<Location *> m_locations;
    Satellite *m_currentSatellite;
    Location *m_currentLocation;
};

#endif /* SATVIEWER_H */

