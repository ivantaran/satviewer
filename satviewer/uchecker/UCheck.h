/*
 * UCheck.h
 *
 *  Created on: 02.10.2010
 *      Author: Yan Coduemat
 */

#ifndef UCHECK_H_
#define UCHECK_H_
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QString>
#include <QWidget>

class UCheck : private QNetworkAccessManager {
	Q_OBJECT
public:
	UCheck(QWidget * parent = 0, int versionId = -1, QString request = "");
	virtual ~UCheck();
	void check();
private:
	QFile m_file;
	int m_id;
	QString m_host;
	QString m_request;
        QNetworkReply *reply;
private slots:
	void httpFinished();
        void httpReadyRead();
};

#endif /* UCHECK_H_ */
