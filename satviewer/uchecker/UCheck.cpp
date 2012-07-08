/*
 * UCheck.cpp
 *
 *  Created on: 02.10.2010
 *      Author: Yan Coduemat
 */

#include "UCheck.h"
#include <QDir>
#include <QSettings>
#include <QMessageBox>

UCheck::UCheck(QWidget * parent, int versionId, QString host, QString request) : QHttp(parent) {
	m_id = versionId;
	m_host = host;			//"satviewer.net"
	m_request = request;	//"/version/current.txt"
	setHost(m_host);
	m_file.setFileName(QDir::temp().filePath("satviewer.ver"));
	connect(this, SIGNAL(done(bool)), this, SLOT(verify(bool)));
}

UCheck::~UCheck() {
	if (m_file.isOpen()) m_file.close();
}

void UCheck::check() {
	if (!m_file.open(QFile::ReadWrite | QFile::Text | QFile::Truncate))
		puts("error: can't create 'satviewer.ver' file in the temp");
//		QMessageBox::information((QWidget *)parent(), "Error", "No access temp", QMessageBox::Ok);
	get(m_request, &m_file);
}

void UCheck::verify(bool error) {
	if ((!error) && (m_file.isOpen()) && (m_file.reset()) && (m_file.isReadable())) {
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
//	else {
//		this->abort();
//		QMessageBox::information((QWidget *)parent(), tr("Update is error"), this->errorString(), QMessageBox::Ok);
//		puts("Error check for update:");
//		puts(this->errorString().toLocal8Bit().data());
//	}
//	m_file.close();
//	m_file.remove();
}
