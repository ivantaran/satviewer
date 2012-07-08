/*
 * SatList.h
 *
 *  Created on: 21.05.2009
 *      Author: Yan Coduemat
 */

#ifndef TLEREADER_H_
#define TLEREADER_H_

#define TLE_LINE_LEN 128

class TleReader
{
public:
	TleReader(void);
	TleReader(const char *fileName);
	~TleReader(void);
	void init(const char *fileName);
	void item(int index);
	inline char * name         () { return m_name;     }
	inline int    count        () { return m_count;    }
	inline double eccentricity () { return ecco;       }
	inline double inclination  () { return inclo;      }
	inline double meanAnomaly  () { return mo;         }
	inline double meanMotion   () { return no;         }
	inline double argLatPerigee() { return argpo;      }
	inline double latAscNode   () { return nodeo;      }
	inline double bStar        () { return bstar;      }
	inline double jEpoch       () { return jdsatepoch; }

private:
	char *fName;
	double no, nddot, ndot, bstar, inclo, nodeo, ecco, argpo, mo, epochdays, jdsatepoch;
	int epochyr;
	int m_count;
	char m_name[TLE_LINE_LEN];
	char **lines[3];
	int year, mon, day, hr, minute;
    double days, sec;
	void days2mdhms(int xyear, double xdays);
	double jday(int xyear, double xdays);
};

#endif /* TLEREADER_H_ */
