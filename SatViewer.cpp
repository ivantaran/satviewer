/* 
 * File:   SatViewer.cpp
 * Author: Ivan Ryazanov
 * 
 * Created on April 13, 2019, 9:45 PM
 */

#include "SatViewer.h"

SatViewer::SatViewer() {
    m_satellites.clear();
    m_locations.clear();
    m_currentSatellite = nullptr;
    m_currentLocation = nullptr;
}

SatViewer::SatViewer(const SatViewer& orig) {
}

SatViewer::~SatViewer() {
    
    for (const auto& sat : m_satellites) {
        if (sat != nullptr) {
            delete sat;
        }
    }
    m_satellites.clear();
    
    for (const auto& loc : m_locations) {
        if (loc != nullptr) {
            delete loc;
        }
    }
    m_locations.clear();
    
}

void SatViewer::appendSatellite(Satellite* sat) {
    m_satellites.push_back(sat);
}

void SatViewer::appendLocation(Location* loc) {
    m_locations.push_back(loc);
}

void SatViewer::removeSatellite(Satellite *sat) {
    m_satellites.remove(sat);
//    int pos = satList.indexOf(sat);
//    if (pos == -1) return;
//    ioList.deleteSat(satList.at(pos));
//    satList.removeAt(pos);
//    delete sat;
//    setIndexSat(pos - 1);
}

void SatViewer::removeLocation(Location *loc) {
    m_locations.remove(loc);
//    int pos = locList.indexOf(loc);
//    if (pos == -1) return;
//    ioList.deleteLoc(locList.at(pos));
//    locList.removeAt(pos);
//    delete loc;
//    setIndexLoc(pos - 1);
}

Satellite *SatViewer::currentSatellite() {
    return m_currentSatellite;
//    if ((m_currentSatellite >= 0) && 
//            ((long unsigned int)m_currentSatellite < m_satellites.size())) {
//        auto item = m_satellites.begin();
//        std::advance(item, m_currentSatellite);
//        return (*item);
//    }
//    else {
//        return nullptr;
//    }
}

Location *SatViewer::currentLocation() {
    return m_currentLocation;
}

void SatViewer::setCurrentSatelliteIndex(long unsigned int index) {
    if (index < m_satellites.size()) {
        auto it = m_satellites.begin();
        std::advance(it, index);
        m_currentSatellite =  (*it);
    }
    else {
        m_currentSatellite = nullptr;
    }
//    emit currentChanged(currentSat(), currentLoc(), &m_time); // TODO
}

void SatViewer::setCurrentLocationIndex(long unsigned int index) {
    if (index < m_locations.size()) {
        auto it = m_locations.begin();
        std::advance(it, index);
        m_currentLocation =  (*it);
    }
    else {
        m_currentLocation = nullptr;
    }
//    refreshAll();
//    emit currentChanged(currentSat(), currentLoc(), &m_time); // TODO
}
