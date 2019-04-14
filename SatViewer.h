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
#include "zrvutils/ZrvIoList.h"

class SatViewer : public QObject {
    Q_OBJECT
public:
    SatViewer();
    SatViewer(const SatViewer& orig);
    virtual ~SatViewer();
    static void aerv(const double loc_rg[], const double sat_rg[], double aerv[]);
    void appendSatellite(Satellite* sat);
    void appendLocation(Location* loc);
    void removeSatellite(Satellite *sat);
    void removeLocation(Location *loc);
    void setCurrentSatelliteIndex(long unsigned int index);
    void setCurrentLocationIndex(long unsigned int index);
    void setCurrentSatellite(Satellite* sat);
    void setCurrentLocation(Location* loc);
    void setTime(double value);
    std::list<Satellite *> satellites() { return m_satellites; }
    std::list<Location *> locations() { return m_locations; }
    Satellite *currentSatellite();
    Location *currentLocation();
    ZrvIoList *ioList() { return &m_ioList; }
    double time() { return m_time; }
    
signals:
    void currentChanged(Satellite *sat, Location *loc, double *time);
    void timeChanged();
    
private:
    std::list<Satellite *> m_satellites;
    std::list<Location *> m_locations;
    Satellite *m_currentSatellite;
    Location *m_currentLocation;
    double m_time;
    ZrvIoList m_ioList;
    
};

#endif /* SATVIEWER_H */

