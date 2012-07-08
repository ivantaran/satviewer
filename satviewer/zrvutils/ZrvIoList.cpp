/*
 * ZRVIOList.cpp
 *
 *  Created on: 16.07.2009
 *      Author: Yan Coduemat
 */

#include "ZrvIoList.h"


ZrvIoList::ZrvIoList() {
	list = new std::vector<ZrvIoListItem*>;
	m_count = 0;
}

ZrvIoList::~ZrvIoList() {
	list->clear();
	delete list;
}

void ZrvIoList::add(Satellite *sat, Location *loc, const double time) {
	ZrvIoListItem *item =  new ZrvIoListItem();
	item->sat = sat;
	item->loc = loc;
	item->time = time;
	list->push_back(item);
	m_count++;
}

ZrvIoListItem *ZrvIoList::item(int index) {
	if (index < 0 || index >= m_count) return NULL;
	return list->at(index);
}

int ZrvIoList::find(Satellite *sat, Location *loc) {
	int i = 0;
	for (curr = list->begin(); curr != list->end(); curr++) {
		if (((*curr)->sat == sat) && ((*curr)->loc == loc)) return i;
		i++;
	}
	return -1;
}

void ZrvIoList::clear() {
	for (curr = list->begin(); curr != list->end(); curr++)
		delete (*curr);
	list->clear();
	m_count = 0;
}

void ZrvIoList::del(int _index) {
	if (_index >= m_count) return;
	curr = list->begin() + _index;
	delete (*curr);
	list->erase(curr);
	m_count--;
}

void ZrvIoList::deleteSat(Satellite *sat) {
	for (curr = list->begin(); curr != list->end(); curr++)
		if ((*curr)->sat == sat) {
			delete (*curr);
			curr = list->erase(curr);
			curr--;
			m_count--;
		}
}

void ZrvIoList::deleteLoc(Location *loc) {
	for (curr = list->begin(); curr != list->end(); curr++)
		if ((*curr)->loc == loc) {
			delete (*curr);
			curr = list->erase(curr);
			curr--;
			m_count--;
		}
}
