/*
 * SUpdater.cpp
 *
 *  Created on: 14.03.2010
 *      Author: Yan Coduemat
 */

#include "SUpdater.h"
#include <QStandardItemModel>
#include <QFileInfo>

SUpdater::SUpdater(QString fileName) {
	// TODO Auto-generated constructor stub
	this->setupUi(this);
	http = new QHttp(this);
	file = 0;
	listFile = 0;
	httpGetId = -1;
    urlIndex = -1;
    httpRequestAborted = false;
	urlIndex = 0;

    connect(http, SIGNAL(dataReadProgress(int, int)), this, SLOT(updateDataReadProgress(int, int)));
    connect(http, SIGNAL(responseHeaderReceived(QHttpResponseHeader)), this, SLOT(readResponseHeader(QHttpResponseHeader)));
    connect(http, SIGNAL(done(bool)), this, SLOT(doneGet(bool)));
	connect(btnUpdate, SIGNAL(clicked()), this, SLOT(updateTle()));
    connect(btnSave, SIGNAL(clicked()), this, SLOT(save()));
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(addLine()));
    connect(btnRemove, SIGNAL(clicked()), this, SLOT(removeLine()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(btnAbort, SIGNAL(clicked()), this, SLOT(abort()));
    load(fileName);

}

SUpdater::~SUpdater() {
	// TODO Auto-generated destructor stub
}

void SUpdater::updateTle() {
    QStandardItemModel *model = (QStandardItemModel *)listView->model();
    while ( (urlIndex < model->rowCount()) &&
    		(model->item(urlIndex)->checkState() == Qt::Unchecked) )
        urlIndex++;
	if (urlIndex >= model->rowCount()) {
		urlIndex = 0;
		return;
	}
	progressBar->setValue(0);

	if (file) {
    	file->close();
    	delete file;
    	file = 0;
    }

    QUrl url(model->item(urlIndex)->text());
    model->item(urlIndex)->setIcon(QIcon(":/status/task.png"));

    QFileInfo fileInfo(url.path());
    QString fileName = fileInfo.fileName();
    if (fileName.isEmpty())
        fileName = "index.html";

    if (QFile::exists(fileName)) QFile::remove(fileName);

    fileInfo.setFile(listFile->fileName());
    file = new QFile(fileInfo.path() + "/" + fileName);

    if (!file->open(QFile::WriteOnly)) {
    	textStatus->appendPlainText(QString("[%0]: %1").arg(fileName).arg(file->errorString()));
        delete file;
        file = 0;
        return;
    }

    QHttp::ConnectionMode mode = url.scheme().toLower() == "https" ? QHttp::ConnectionModeHttps : QHttp::ConnectionModeHttp;
    http->setHost(url.host(), mode, url.port() == -1 ? 0 : url.port());

    if (!url.userName().isEmpty()) http->setUser(url.userName(), url.password());

    httpRequestAborted = false;
    QByteArray path = QUrl::toPercentEncoding(url.path(), "!$&'()*+,;=:@/");
    if (path.isEmpty()) path = "/";
    httpGetId = http->get(path, file);
}

void SUpdater::updateDataReadProgress(int bytesRead, int totalBytes)
{
	if (httpRequestAborted) return;

	progressBar->setMaximum(totalBytes);
	progressBar->setValue(bytesRead);
}

void SUpdater::readResponseHeader(const QHttpResponseHeader &responseHeader)
{
    switch (responseHeader.statusCode()) {
    case 200:                   // Ok
    case 301:                   // Moved Permanently
    case 302:                   // Found
    case 303:                   // See Other
    case 307:                   // Temporary Redirect
        // these are not error conditions
        break;

    default:
    	textStatus->appendPlainText(QString("[%0]: %1").arg(file->fileName()).arg(responseHeader.reasonPhrase()));
        http->abort();
    }
}

void SUpdater::doneGet(bool error) {
	QStandardItemModel *model = (QStandardItemModel *)listView->model();
	file->close();
	if (error) {
		http->abort();
		file->remove();
		model->item(urlIndex)->setIcon(QIcon(":/status/no.png"));
		textStatus->appendPlainText(QString("[%0]: %1").arg(file->fileName()).arg(http->errorString()));
	}
	else {
		model->item(urlIndex)->setIcon(QIcon(":/status/ok.png"));
	}
	if (httpRequestAborted) return;
	urlIndex++;
	updateTle();
}

void SUpdater::load(QString fileName) {
	QString line, url;
	bool state;
	int i = 0;
	QStandardItemModel *model = new QStandardItemModel();
	if (listFile != 0) {
		listFile->close();
		delete listFile;
		listFile = 0;
	}
	listFile = new QFile(fileName);

	if (!listFile->exists()) {
		textStatus->appendPlainText(QString("Error access to file [%0].").arg(fileName));
		return;
	}

	listFile->open(QFile::ReadOnly | QFile::Text);

	if (!listFile->isOpen()) {
    	textStatus->appendPlainText(QString("[%0]: %1").arg(fileName).arg(file->errorString()));
		return;
	};

	while (!listFile->atEnd()) {
		line = QString(listFile->readLine());
		state = line.section(',', 0, 0).toInt();
		url = line.section(',', 1).trimmed();
		model->appendRow(new QStandardItem(url));
		model->item(i)->setCheckable(true);
		if (state) model->item(i)->setCheckState(Qt::Checked);
		i++;
	}

	listView->setModel(model);
	listFile->close();
}

void SUpdater::save() {
	QString url, line;
	bool state;
	QStandardItemModel *model = (QStandardItemModel *)listView->model();

	if (!listFile->exists()) {
		textStatus->appendPlainText(QString("Error access to file [%0].").arg(listFile->fileName()));
		return;
	}

	listFile->open(QFile::WriteOnly | QFile::Text);

	if (!listFile->isOpen()) {
    	textStatus->appendPlainText(QString("[%0]: %1").arg(listFile->fileName()).arg(file->errorString()));
		return;
	}

	for (int i = 0; i < model->rowCount(); i++) {
		url = model->item(i)->text();
		state = (model->item(i)->checkState() == Qt::Checked);
		line = QString("%0,%1\n").arg((int)state).arg(url);
		listFile->write(line.toLocal8Bit());
	}
	listFile->close();
}

void SUpdater::addLine() {
	QStandardItemModel *model = (QStandardItemModel *)listView->model();
	QStandardItem *item = new QStandardItem("http://");
	item->setCheckable(true);
	model->insertRow(listView->currentIndex().row(), item);
}

void SUpdater::removeLine() {
	//QStandardItemModel *model = (QStandardItemModel *)listView->model();
	listView->model()->removeRow(listView->currentIndex().row());
}

void SUpdater::clear() {
	QStandardItemModel *model = (QStandardItemModel *)listView->model();
	model->clear();
}

void SUpdater::abort() {
	httpRequestAborted = true;
	http->abort();
}
