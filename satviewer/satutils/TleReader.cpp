/*
 * SatList.h
 *
 *  Created on: 21.05.2009
 *      Author: Yan Coduemat
 */

#include "TleReader.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <fstream>

using namespace std;

#define PI 3.14159265358979323846
#define deg2rad PI/180.0
#define xpdotp 1440.0/(2.0*PI)

TleReader::TleReader(void)
{
}

TleReader::TleReader(const char *fileName)
{
	init(fileName);
}


TleReader::~TleReader(void)
{
	delete fName;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < m_count; j++)
			delete lines[i][j];
		delete lines[i];
	}
}

void TleReader::init(const char *fileName) {

	m_count = -1;
	fName = new char[strlen(fileName) + 1];
	strcpy(fName, fileName);
	ifstream f(fName);
	if (!f.is_open()) return;
	char line1[TLE_LINE_LEN], line2[TLE_LINE_LEN];
	do {
		line1[0] = 0;
		line2[0] = 0;
		f.getline(line1, TLE_LINE_LEN);
		f.getline(line1, TLE_LINE_LEN);
		f.getline(line2, TLE_LINE_LEN);
		m_count++;
	} while (!f.eof() && line1[0] == '1' && line2[0] == '2');
	if (m_count < 1) {
		f.close();
		return;
	}
	//f.clear();
	//f.seekg(0);
	f.close();
	fstream fa(fName);
	for (int i = 0; i < 3; i++) {
		lines[i] = new char*[m_count];
		for (int j = 0; j < m_count; j++)
			lines[i][j] = new char[TLE_LINE_LEN];
	}

	for (int i = 0; i < m_count; i++) {
		fa.getline(lines[0][i], TLE_LINE_LEN);
		fa.getline(lines[1][i], TLE_LINE_LEN);
		fa.getline(lines[2][i], TLE_LINE_LEN);
	}

	fa.close();
}

void TleReader::item(int index) {
	if (index >= m_count) return;
	int bexp;
	char tmp[TLE_LINE_LEN];
	setlocale(LC_NUMERIC, "C");
	sscanf(lines[0][index],"%[^\r\n]", m_name);
	sscanf(lines[1][index], "%s %s %s %lf %s %s %7lf %2d", tmp, tmp, tmp, &epochdays, tmp, tmp, &bstar, &bexp);
	sscanf(lines[2][index], "%s %s %lf %lf %lf %lf %lf %11lf", tmp, tmp, &inclo, &nodeo, &ecco, &argpo, &mo, &no);
	bstar *= pow(10.0, bexp - 5);
	ecco *= 1e-7;
	inclo *= deg2rad;
	nodeo *= deg2rad;
	argpo *= deg2rad;
	mo *= deg2rad;
	no	/= xpdotp;

	epochyr = (int)(epochdays/1000);
	epochdays -= epochyr*1000;
	jdsatepoch = jday(epochyr, epochdays);
}

void TleReader::days2mdhms(int xyear, double xdays) {
	int i, inttemp, dayofyr;
	double    temp;
	int lmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (xyear < 50) year = xyear + 2000;
	else year = xyear + 1900;
	days = xdays;

	dayofyr = (int)floor(days);
	/* ----------------- find month and day of month ---------------- */
	if ( (year % 4) == 0 ) lmonth[1] = 29;

	i = 1;
	inttemp = 0;
	while ((dayofyr > inttemp + lmonth[i-1]) && (i < 12)) {
		inttemp = inttemp + lmonth[i-1];
		i++;
	}
	mon = i;
	day = dayofyr - inttemp;

	/* ----------------- find hours minutes and seconds ------------- */
	temp = (days - dayofyr) * 24.0;
	hr   = (int)floor(temp);
	temp = (temp - hr) * 60.0;
	minute  = (int)floor(temp);
	sec  = (temp - minute) * 60.0;
}

double TleReader::jday(int xyear, double xdays) {
    days2mdhms(xyear, xdays);
    return 367.0 * year -
        floor((7 * (year + floor((mon + 9) / 12.0))) * 0.25) +
        floor( 275 * mon / 9.0 ) + day + 1721013.5 +
        ((sec / 60.0 + minute) / 60.0 + hr) / 24.0;
}

