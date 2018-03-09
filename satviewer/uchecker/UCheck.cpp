// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
 * UCheck.cpp
 *
 *  Created on: 02.10.2010
 *      Author: Ivan Ryazanov
 */

#include "UCheck.h"
#include <QDir>
#include <QSettings>
#include <QMessageBox>

UCheck::UCheck(QWidget * parent, int versionId, QString request) : QNetworkAccessManager(parent) {
	m_id = versionId;
	m_request = request;	//"/version/current.txt"
	m_file.setFileName(QDir::temp().filePath("satviewer.ver"));
}

UCheck::~UCheck() {
	if (m_file.isOpen()) m_file.close();
}

void UCheck::check() {
	if (!m_file.open(QFile::ReadWrite | QFile::Text | QFile::Truncate))
		puts("error: can't create 'satviewer.ver' file in the temp");
        reply = get(QNetworkRequest(m_request));
        
        connect(reply, SIGNAL(finished()) , this, SLOT(httpFinished ()));
        connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
        
}

void UCheck::httpFinished() {
	if ((!reply->error()) && (m_file.isOpen()) && (m_file.reset()) && (m_file.isReadable())) {
		QSettings settings(m_file.fileName(), QSettings::IniFormat);
		int id = settings.value("id", -1).toInt();
		QString name = settings.value("name", "").toString();
		QString url = settings.value("url", "").toString();
		if ((id > m_id) && (!name.isEmpty()) && (!url.isEmpty())) {
			QMessageBox::information((QWidget *)parent(), tr("Update is avaible"),
					tr("Latest version %1 here:<br><a href=\"%2\">%2</a>").arg(name).arg(url), QMessageBox::Ok);
		}
		m_file.close();
		m_file.remove();
	}
        reply->deleteLater();
        reply = 0;
}

void UCheck::httpReadyRead() {
    if (m_file.isOpen() && m_file.isWritable())
        m_file.write(reply->readAll());
    else 
        puts("error: can't write 'satviewer.ver' file in the temp");
}