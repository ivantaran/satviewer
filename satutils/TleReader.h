/*
 * SatList.h
 *
 *  Created on: 21.05.2009
 *      Author: Ivan Ryazanov
 */

#ifndef TLEREADER_H_
#define TLEREADER_H_

#define TLE_LINE_LEN 128


struct tle {
        int consttype;
        double jdsatepoch; 
        double bstar; 
        double inclo; 
        double argpo; 
        double ecco; 
        double nodeo; 
        double mo; 
        double no;    
};

class TleReader {
    
public:
    TleReader(void);
    TleReader(const char *fileName);
    ~TleReader(void);
    void init(const char *fileName);
    void item(int index);
    const char * name         () const { return m_name;     }
    int    count        () const { return m_count;    }
    char * state        () const { return (char *)&m_state;    }
    double eccentricity () const { return m_state.ecco;       }
    double inclination  () const { return m_state.inclo;      }
    double meanAnomaly  () const { return m_state.mo;         }
    double meanMotion   () const { return m_state.no;         }
    double argLatPerigee() const { return m_state.argpo;      }
    double latAscNode   () const { return m_state.nodeo;      }
    double bStar        () const { return m_state.bstar;      }
    double jEpoch       () const { return m_state.jdsatepoch; }
    int sizeState() { return sizeof(struct tle); }

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
    struct tle m_state;
};

#endif /* TLEREADER_H_ */
