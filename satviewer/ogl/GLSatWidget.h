/*
 * GLSatWidget.h
 *
 *  Created on: 15.05.2009
 *      Author: Yan Coduemat
 */

#ifndef GLSATWIDGET_H_
#define GLSATWIDGET_H_

#include "GLSatAbstractWidget.h"
#include "ui_mapsettings.h"
#include <QSettings>
#include "glsprite/GLSprite.h"

class GLSatWidget : public GLSatAbstractWidget {
	Q_OBJECT
public:
	GLSatWidget(QWidget *parent = 0);
	virtual ~GLSatWidget();

	void readSettings(QSettings *settings);
	void writeSettings(QSettings *settings);
	inline void retranslateUi() { ui.retranslateUi(this); }
        void addSat(Satellite *sat);
        void addLoc(Location *loc);
        void setIcon(Satellite *sat, QString  fileName = QString());
        void setIcon(Location *loc, QString  fileName = QString());
private:
	Ui::MapWidgetSettings ui;
	GLSprite sprite_current, sprite_active;
        
	void compileMapList();
	void compileSatList();
	void compileLocList();
	void compileSunList();
	void compileEventsList();
	void renderText(float x, float y, const QString& text, int color = 0, const QFont &font = QFont());
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
	float zoom(float value = 0);
	float moveX(float value = 0);
	float moveY(float value = 0);

private slots:
	void btnColorClicked();
	void onBtnMapFileClicked();
	void btnFontNetClicked();
	void onColorTypeChanged(int index);
	void onCheckSun(bool value);
	void onCheckNight(bool value);
	void changeZoom(double value);
	void changeX(double value);
	void changeY(double value);
};

#endif /* GLSATWIDGET_H_ */
