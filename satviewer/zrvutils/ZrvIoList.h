/*
 * ZRVIOList.h
 *
 *  Created on: 16.07.2009
 *      Author: Yan Coduemat
 */

#ifndef ZRVIOLIST_H_
#define ZRVIOLIST_H_

#include <stdlib.h>
#include "../satutils/Satellite.h"
#include "../locutils/Location.h"
#include <vector>

using namespace std;

class ZrvIoListItem {
public:
	double time;
	Satellite *sat;
	Location *loc;
	ZrvIoListItem() {
		sat = 0;
		loc = 0;
		time = -1;
	}
	virtual ~ZrvIoListItem(){};
};

class ZrvIoList {
public:
	ZrvIoList();
	virtual ~ZrvIoList();
	void add(Satellite *sat, Location *loc, const double time);
	void del(int index);
	void deleteSat(Satellite *sat);
	void deleteLoc(Location *loc);
	void clear();
	//ZrvIoListItem *first();
	//ZrvIoListItem *current();
	//ZrvIoListItem *next();
	inline int count() { return m_count; }
	ZrvIoListItem *item(int index);
	int find(Satellite *sat, Location *loc);
private:
	std::vector<ZrvIoListItem*> *list;
	std::vector<ZrvIoListItem*>::iterator curr;
	int m_count;
};

#endif /* ZRVIOLIST_H_ */
