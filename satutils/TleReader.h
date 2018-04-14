/*
 * SatList.h
 *
 *  Created on: 21.05.2009
 *      Author: Ivan Ryazanov
 */

#ifndef TLEREADER_H_
#define TLEREADER_H_

#define TLE_LINE_LEN 128

class TleReader {
    
public:

    typedef struct {
        double jdsatepoch; 
        double bstar; 
        double incl; 
        double argp; 
        double ecc; 
        double node; 
        double m; 
        double n;    
    } sgp4_t;
    
    TleReader(void);
    TleReader(const char *fileName);
    ~TleReader(void);
    void init(const char *fileName);
    void item(int index);
    const char * name         () const { return m_name;     }
    int    count        () const { return m_count;    }
    char * state        () const { return (char *)&m_state;    }
    double eccentricity () const { return m_state.ecc;       }
    double inclination  () const { return m_state.incl;      }
    double meanAnomaly  () const { return m_state.m;         }
    double meanMotion   () const { return m_state.n;         }
    double argLatPerigee() const { return m_state.argp;      }
    double latAscNode   () const { return m_state.node;      }
    double bStar        () const { return m_state.bstar;      }
    double jEpoch       () const { return m_state.jdsatepoch; }
    int sizeState() { return sizeof(m_state); }

private:
    char *fName;
    double epochdays;
    int epochyr;
    int m_count;
    char m_name[TLE_LINE_LEN];
    char **lines[3];
    int year, mon, day, hr, minute;
    double days, sec;
    void days2mdhms(int xyear, double xdays);
    double jday(int xyear, double xdays);
    sgp4_t m_state;
};

#endif /* TLEREADER_H_ */
