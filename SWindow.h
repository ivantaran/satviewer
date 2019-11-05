/*
 * SWindow.h
 *
 *  Created on: 05.05.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SWINDOW_H_
#define SWINDOW_H_

#include "SDlgOptions.h"
#include "SatViewer.h"
#include "ogl/GLSatWidget.h"
#include "ogl/GLSatWidget3d.h"
#include "ogl/RadarWidget.h"
#include "uchecker/UCheck.h"
#include "ui_SatViewer.h"
#include "ui_settings.h"
#include <QDesktopWidget>
#include <QSettings>
#include <QShortcut>
#include <inttypes.h>

class SWindow : public QMainWindow {
    Q_OBJECT
public:
    SDlgOptions *dlgOptions;
    QTimer *timer;
    SWindow(SatViewer *satviewer);
    virtual ~SWindow();
    void readStrings();
    void writeSettings();

private:
    SatViewer *m_satviewer;
    QWidget settingsWidget;
    Ui::SettingsWidget uiSettings;
    Ui::MainWindow widget;
    QPalette originalPalette;
    GLSatAbstractWidget *satWidget;
    RadarWidget *radarWidget;
    double time, timeStep, timeX;
    int timeType;
    QShortcut *shcFullScreen, *shcEscFullScreen;
    QLabel labelLoc, labelSat;
    QStringList listLang;
    QString language;
    QTranslator m_translator;
    UCheck *uCheck;
    void closeEvent(QCloseEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void fullScreen();
    void escFullScreen();
    void onTimeTypeChanged(int index);
    void addZRVMessage(QString text);
    void checkVersion(bool checked);
    void onStart();
    void onTimer();
    void onPlayClick();
    void onTimeClick();
    void onBackwardClick();
    void onForwardClick();
    void onStepChanged(int value = 0);
    void onTimeXChanged(int value);
    void selectLanguage(int value);
    void setSwlVars(Satellite *sat, Location *loc, double *time);
    void selectStyle(int value);
    //    void selectGlWidget(int value);
    void selectPalette(bool value);
    //	void onSatModelChanged(int index);
    void onBtnPrintScrClicked();
    void resetSettings();
    void readSettings();
};

#endif /* SWINDOW_H_ */
