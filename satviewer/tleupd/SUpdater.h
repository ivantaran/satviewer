/*
 * SUpdater.h
 *
 *  Created on: 14.03.2010
 *      Author: Yan Coduemat
 */

#ifndef SUPDATER_H_
#define SUPDATER_H_

#include "ui_tleupd.h"
#include <QDialog>
#include <QtNetwork>

class SUpdater: public QWidget, public Ui::Updater
{
	Q_OBJECT

public:
	SUpdater(QString fileName = "");
	virtual ~SUpdater();
	void load(QString fileName);
private:
//	QHttp *http;
        QNetworkAccessManager nam;
        QNetworkReply *reply;
	QFile *file, *listFile;
	int httpGetId;
    bool httpRequestAborted;
    int urlIndex;
private slots:
	void updateTle();
	void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);
	void httpFinished();
	void save();
	void addLine();
	void removeLine();
	void clear();
	void abort();
};

#endif /* SUPDATER_H_ */
