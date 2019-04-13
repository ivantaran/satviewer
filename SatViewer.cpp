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

