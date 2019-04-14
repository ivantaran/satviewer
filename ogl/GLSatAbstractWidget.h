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
#include <QSettings>
#include <QOpenGLTexture>

#include "../zrvutils/ZrvIoList.h"
#include "../SatViewer.h"

typedef Satellite * (*CustomSat)(); // TODO remove this

class GLSatAbstractWidget : public QOpenGLWidget, protected QOpenGLFunctions_2_0 { // TODO QOpenGLWidget - to protected
    Q_OBJECT
public:
//    ZrvIoList ioList;
    QWidget *settingsWidget;
    typedef Satellite * (*CustomSat)();
    CustomSat getSatModel, getSunModel;
    GLSatAbstractWidget(SatViewer *satviewer, QWidget *parent = nullptr);
    virtual ~GLSatAbstractWidget();
    virtual void readSettings() {}
    virtual void writeSettings(QSettings *settings) { Q_UNUSED(settings); }
    virtual void retranslateUi() {}
    virtual void setIcon(Satellite *sat, const QString& fileName = "") { Q_UNUSED(sat); Q_UNUSED(fileName); }
    virtual void setIcon(Location *loc, const QString& fileName = "") { Q_UNUSED(loc); Q_UNUSED(fileName); }
    void setSatModel(int index = -1);
    void setSunModel(QString fileName = "");
    void refreshAll();
    void setFontNames(QFont font);
    void setFontNet(QFont font);
    void loadTexture(QString filePath = "");

    void setColorNet(uint32_t color);
    void setColorLocA(uint32_t color);
    void setColorNetFont (uint32_t color);
    void setColorNight(uint32_t color);

    uint32_t colorNet() const {return m_colorNet;}
    uint32_t colorNetFont() const {return clrNetFont;}
    uint32_t colorNight() const {return clrNight;}

    QFont fontNet() const {return fntNet;}

    void showZRV(bool value);
    void showZRVLines(bool value);
    void showZRL(bool value);
    void showSatNames(bool value);
    void showLocNames(bool value);
    void showSun(bool value);
    void showNight(bool value);
    
    SatViewer *satviewer() { return m_satviewer; }

public slots:
    void refresh(); //TODO private this
    
signals:
    void statusZRVChanged(QString text);
    void doubleClickedSat();
    void doubleClickedLoc();
    void zoomed(float value);
    void movedX(float value);
    void movedY(float value);
    void initialized();
    
protected:
    SatViewer *m_satviewer;
    GLuint m_colorNet, clrNetFont, clrNight;
    GLuint list_map, list_net, list_events, list_sun, list_loc, list_sat;
    bool list_map_ready, list_net_ready, list_events_ready, list_sun_ready, list_loc_ready, list_sat_ready, list_labels_ready;
    QOpenGLTexture *textureID;
    QFont fntNet;
    bool shwSun, shwNight;
    float m_zoom, m_dx, m_dy, m_dz;
    QPoint pointMoveMap;
    bool m_cursorOnSatellite, m_cursorOnLocation;
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);
    virtual void compileMapList();
    virtual void compileSatList();
    virtual void compileLocList();
    virtual void compileSunList();
    virtual void compileEventsList();
    virtual float zoom(float value = 0.0);
    virtual float moveX(float value = 0.0);
    virtual float moveY(float value = 0.0);
//        virtual void compileSatIcon(Satellite *sat) {}
//        virtual void compileLocIcon(Location *loc) {}
private:
    TleReader *tle;
};

#endif /* GLSATABSTRACTWIDGET_H_ */
