/*
 * SWindow.h
 *
 *  Created on: 05.05.2009
 *      Author: Yan Coduemat
 */

#ifndef SWINDOW_H_
#define SWINDOW_H_

#include <inttypes.h>
#include <QSettings>
#include <QShortcut>
#include <QDesktopWidget>
#include "SDlgOptions.h"
#include "ui_SatViewer.h"
#include "ui_settings.h"
#include "uchecker/UCheck.h"
#include "ogl/GLSatWidget3d.h"
#include "ogl/GLSatWidget.h"
#include "ogl/GLSatAbstractWidget.h"

class SWindow: public QMainWindow, public Ui::MainWindow {
    Q_OBJECT
public:
    SDlgOptions *dlgOptions;
    QTimer *timer;
    SWindow();
    virtual ~SWindow();
    void readStrings();
    void readSettings();
    void writeSettings();

private:
    QWidget settingsWidget;
    Ui::SettingsWidget uiSettings;
    QPalette originalPalette;
    GLSatAbstractWidget *satWidget;
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
    void onTimer();
    void onPlayClick();
    void onTimeClick();
    void onBackwardClick();
    void onForwardClick();
    void onStepChanged(int value);
    void onTimeXChanged(int value);
    void selectLanguage(int value);
    void setSwlVars(Satellite *sat, Location *loc, double *time);
    void selectStyle(int value);
    void selectGlWidget(int value);
    void selectPalette(bool value);
    //	void onSatModelChanged(int index);
    void onBtnPrintScrClicked();
    void resetSettings();
};

#endif /* SWINDOW_H_ */
