/*
 * dbsql.h
 *
 *  Created on: 14.02.2010
 *      Author: Yan Coduemat
 */

#ifndef DBSQL_H_
#define DBSQL_H_

char sqlSat[] =
		"CREATE TABLE 'sat' ("
		     "'id' INTEGER NOT NULL,"
		     "'groupname' TEXT,"
		     "'name' TEXT NOT NULL,"
		     "'i' DOUBLE,"
		     "'omg' DOUBLE,"
		     "'e' DOUBLE,"
		     "'w' DOUBLE,"
		     "'m0' DOUBLE,"
		     "'n' DOUBLE,"
		     "'bstar' DOUBLE,"
		     "'time' DOUBLE,"
		     "PRIMARY KEY ('id')"
		 ");";

char sqlLoc[] =
		"CREATE TABLE 'loc' ("
		     "'id' INTEGER NOT NULL,"
		     "'name' TEXT NOT NULL,"
		     "'lat' DOUBLE,"
		     "'lon' DOUBLE,"
		     "'height' DOUBLE,"
		     "'azimuth' DOUBLE,"
		     "'sector' DOUBLE,"
		     "'r' DOUBLE,"
		     "PRIMARY KEY ('id')"
		 ");";

char sqlSatTemp[] =
		"CREATE TABLE 'sattemp' ("
		     "'id' INTEGER NOT NULL,"
		     "'group' TEXT,"
		     "'name' TEXT NOT NULL,"
		     "'i' DOUBLE,"
		     "'omg' DOUBLE,"
		     "'e' DOUBLE,"
		     "'w' DOUBLE,"
		     "'m0' DOUBLE,"
		     "'n' DOUBLE,"
		     "'bstar' DOUBLE,"
		     "'time' DOUBLE,"
		     "'zrv' DOUBLE,"
		     "'alpha' DOUBLE,"
		     "'beta' DOUBLE,"
		     "'zrl' DOUBLE,"
		     "'icon' TEXT,"
		     "'show_label' INTEGER,"
		     "'show_track' INTEGER,"
		     "'show_zrv' INTEGER,"
		     "'show_lines' INTEGER,"
			 "'active_zone' INTEGER,"
		     "'color_track' INTEGER,"
		     "'color_label' INTEGER,"
		     "'color_zrv' INTEGER,"
		     "'color_lines' INTEGER,"
		     "'track' DOUBLE,"
		     "'font' TEXT,"
			 "'name_x' DOUBLE,"
			 "'name_y' DOUBLE,"
			 "'lines_width' DOUBLE,"
		     "'model_index' INTEGER,"
		     "PRIMARY KEY ('id')"
		 ");";

char sqlLocTemp[] =
		"CREATE TABLE 'loctemp' ("
		     "'id' INTEGER NOT NULL,"
		     "'name' TEXT NOT NULL,"
		     "'lat' DOUBLE,"
		     "'lon' DOUBLE,"
		     "'height' DOUBLE,"
		     "'azimuth' DOUBLE,"
		     "'sector' DOUBLE,"
		     "'r' DOUBLE,"
		     "'icon' TEXT,"
		     "'show_label' INTEGER,"
		     "'show_zrv' INTEGER,"
		     "'show_lines' INTEGER,"
			 "'active_zone' INTEGER,"
		     "'color_label' INTEGER,"
		     "'color_zrv' INTEGER,"
		     "'color_lines' INTEGER,"
		     "'font' TEXT,"
			 "'name_x' DOUBLE,"
			 "'name_y' DOUBLE,"
			 "'lines_width' DOUBLE,"
		     "PRIMARY KEY ('id')"
		 ");";

#endif /* DBSQL_H_ */
