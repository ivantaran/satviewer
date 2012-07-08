/*
 * GLSatAbstractWidget.h
 *
 *  Created on: 24.03.2010
 *      Author: Yan Coduemat
 */

#ifndef GLSATABSTRACTWIDGET_H_
#define GLSATABSTRACTWIDGET_H_

#include <inttypes.h>
#include <QGLWidget>
#include <QLibrary>
#include <QSettings>
#include <QtOpenGL>

#include "../zrvutils/ZrvIoList.h"

typedef Satellite * (*CustomSat)();

class GLSatAbstractWidget : public QGLWidget {
	Q_OBJECT
public:
    QList<Satellite *> satList;
    QList<Location *> locList;
    ZrvIoList ioList;
    QWidget *settingsWidget;
	typedef Satellite * (*CustomSat)();
	CustomSat getSatModel, getSunModel;
	GLSatAbstractWidget(QWidget *parent = 0);
	virtual ~GLSatAbstractWidget();
	virtual void readSettings(QSettings *settings) {}
	virtual void writeSettings(QSettings *settings) {}
	virtual void retranslateUi() {}
        virtual void setIcon(Satellite *sat, QString fileName = QString()) {}
        virtual void setIcon(Location *loc, QString fileName = QString()) {}
	void setTime(double secs);
	void setSatModel(int index = -1);
	void setSunModel(QString fileName = "");
	void refresh();
	void refreshAll();
	void setFontNames(QFont font);
	void setFontNet(QFont font);
	void loadTexture(QString filePath = "");
	void selectSatModel(int index, int pos);

	void setColorNet(uint32_t color);
	void setColorLocA(uint32_t color);
	void setColorNetFont (uint32_t color);
	void setColorNight(uint32_t color);

	inline uint32_t colorNet() {return clrNet;}
	inline uint32_t colorNetFont() {return clrNetFont;}
	inline uint32_t colorNight() {return clrNight;}

	inline QFont fontNet() {return fntNet;}
	inline double time() {return m_time;}

	inline QStringList satModelList() {return m_satModelList;}

	void showZRV(bool value);
	void showZRVLines(bool value);
	void showZRL(bool value);
	void showSatNames(bool value);
	void showLocNames(bool value);
	void showSun(bool value);
	void showNight(bool value);

	inline int indexSat() {return m_indexSat;}
	inline int indexLoc() {return m_indexLoc;}

	Satellite * currentSat() {
            if ((m_indexSat < 0) || (m_indexSat >= satList.count())) return 0;
            return satList.at(m_indexSat);
        }

        Location * currentLoc() {
            if ((m_indexLoc < 0) || (m_indexLoc >= locList.count())) return 0;
            return locList.at(m_indexLoc);
        }

	void setIndexSat(int index);
	void setIndexLoc(int index);

        virtual void addSat(Satellite *sat);
        virtual void addLoc(Location *loc);
	void removeSat(Satellite *sat);
	void removeLoc(Location *loc);

signals:
	void statusZRVChanged(QString text);
	void doubleClickedSat();
	void doubleClickedLoc();
	void currentChanged(Satellite *sat, Location *loc, double *time);
	void zoomed(float value);
	void movedX(float value);
	void movedY(float value);
protected:
	Satellite *sun;
	uint32_t clrNet, clrNetFont, clrNight;
        uint32_t list_map, list_net, list_events, list_sun, list_loc, list_sat, list_labels;
	double m_time;
	uint32_t textureID;
	QFont fntNet;
	bool shwSun, shwNight;
    float m_zoom, m_dx, m_dy, m_dz;
    int m_indexLoc, m_indexSat;
    QPoint pointMoveMap;
	virtual void initializeGL();
	virtual void paintGL();
	virtual void resizeGL(int width, int height);
	virtual void compileMapList() {}
	virtual void compileSatList() {}
	virtual void compileLocList() {}
	virtual void compileSunList() {}
	virtual void compileEventsList() {}
	virtual void renderText(float x, float y, QString text, int color, QFont font = QFont()) {}
	virtual float zoom(float value = 0);
	virtual float moveX(float value = 0);
	virtual float moveY(float value = 0);
//        virtual void compileSatIcon(Satellite *sat) {}
//        virtual void compileLocIcon(Location *loc) {}
private:
	QStringList m_satModelList;
	TleReader *tle;
	QLibrary lib;
	void enumSatModelList();
};

#endif /* GLSATABSTRACTWIDGET_H_ */
