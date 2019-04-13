/*
 * GLSatAbstractWidget.h
 *
 *  Created on: 24.03.2010
 *      Author: Ivan Ryazanov
 */

#ifndef GLSATABSTRACTWIDGET_H_
#define GLSATABSTRACTWIDGET_H_

#include <inttypes.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_2_0>
#include <QLibrary>
#include <QSettings>
#include <QOpenGLTexture>

#include "../zrvutils/ZrvIoList.h"

typedef Satellite * (*CustomSat)(); // TODO remove this

class GLSatAbstractWidget : public QOpenGLWidget, protected QOpenGLFunctions_2_0 { // TODO QOpenGLWidget - to protected
	Q_OBJECT
public:
    QList<Satellite *> satList;
    QList<Location *> locList;
    ZrvIoList ioList;
    QWidget *settingsWidget;
    typedef Satellite * (*CustomSat)();
    CustomSat getSatModel, getSunModel;
    GLSatAbstractWidget(QWidget *parent = nullptr);
    virtual ~GLSatAbstractWidget();
    virtual void readSettings() {}
    virtual void writeSettings(QSettings *settings) { Q_UNUSED(settings); }
    virtual void retranslateUi() {}
    virtual void setIcon(Satellite *sat, const QString& fileName = "") { Q_UNUSED(sat); Q_UNUSED(fileName); }
    virtual void setIcon(Location *loc, const QString& fileName = "") { Q_UNUSED(loc); Q_UNUSED(fileName); }
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

    uint32_t colorNet() const {return clrNet;}
    uint32_t colorNetFont() const {return clrNetFont;}
    uint32_t colorNight() const {return clrNight;}

    QFont fontNet() const {return fntNet;}
    double time() const {return m_time;}

    QStringList satModelList() const {return m_satModelList;}

    void showZRV(bool value);
    void showZRVLines(bool value);
    void showZRL(bool value);
    void showSatNames(bool value);
    void showLocNames(bool value);
    void showSun(bool value);
    void showNight(bool value);

    int indexSat() const {return m_indexSat;}
    int indexLoc() const {return m_indexLoc;}

    Satellite * currentSat() {
        if ((m_indexSat < 0) || (m_indexSat >= satList.count())) return nullptr; // TODO move to cpp
        return satList.at(m_indexSat);
    }

    Location * currentLoc() {
        if ((m_indexLoc < 0) || (m_indexLoc >= locList.count())) return nullptr; // TODO move to cpp
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
    void initialized();
    
protected:
    GLuint clrNet, clrNetFont, clrNight;
    GLuint list_map, list_net, list_events, list_sun, list_loc, list_sat, list_labels;
    bool list_map_ready, list_net_ready, list_events_ready, list_sun_ready, list_loc_ready, list_sat_ready, list_labels_ready;
    double m_time;
    QOpenGLTexture *textureID;
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
    virtual float zoom(float value = 0.0);
    virtual float moveX(float value = 0.0);
    virtual float moveY(float value = 0.0);
//        virtual void compileSatIcon(Satellite *sat) {}
//        virtual void compileLocIcon(Location *loc) {}
private:
    QStringList m_satModelList;
    TleReader *tle;
    QLibrary lib;
    void enumSatModelList();
};

#endif /* GLSATABSTRACTWIDGET_H_ */
