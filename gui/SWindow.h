/*
 * SWindow.h
 *
 *  Created on: 05.05.2009
 *      Author: Ivan Ryazanov
 */

#ifndef SWINDOW_H_
#define SWINDOW_H_

#include "../utils/ogl/GLSatWidget.h"
#include "../utils/ogl/GLSatWidget3d.h"
#include "../utils/ogl/RadarWidget.h"
#include "RotatorWidget.h"
#include "SDlgOptions.h"
#include "SatViewer.h"
#include "UCheck.h"
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
    Ui::MainWindow widget;
    Ui::SettingsWidget uiSettings;

    GLSatAbstractWidget *m_radarWidget;
    GLSatAbstractWidget *satWidget;
    QComboBox m_comboBoxTimeStepUnit;
    QComboBox m_comboBoxTimeZone;
    QDateTimeEdit m_dateTimeEdit;
    QPalette originalPalette;
    QSpinBox m_spinBoxTimeStep;
    QTranslator m_translator;
    QWidget m_spacer1;
    QWidget m_spacer2;
    QWidget settingsWidget;
    RotatorSettings m_rotatorSettingsWidget;
    SatViewer *m_satviewer;
    UCheck *uCheck;

    time_t time, timeStep;
    time_t timeX; // default 25 or 50, setting timeX, min 1, max 100, step 5
    int timeType;
    QLabel labelLoc, labelSat;
    QStringList listLang;
    QString language;
    void closeEvent(QCloseEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void fullScreen();
    void exitFullScreen();
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
    void onTimeXChanged(int value); // TODO remove this
    void selectLanguage(int value);
    void setSwlVars(Satellite *sat, Location *loc, double *time);
    void selectStyle(int value);
    void selectPalette(bool value);
    void onBtnPrintScrClicked();
    void resetSettings();
    void readSettings();
};

#endif /* SWINDOW_H_ */
