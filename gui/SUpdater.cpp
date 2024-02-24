
/*
 * SUpdater.cpp
 *
 *  Created on: 14.03.2010
 *      Author: Ivan Ryazanov
 */

#include "SUpdater.h"
#include <QFileInfo>
#include <QStandardItemModel>

SUpdater::SUpdater(QString fileName) {
    widget.setupUi(this);
    file = 0;
    listFile = 0;
    httpGetId = -1;
    httpRequestAborted = false;
    urlIndex = 0;

    connect(widget.btnUpdate, SIGNAL(clicked()), this, SLOT(updateTle()));
    connect(widget.btnSave, SIGNAL(clicked()), this, SLOT(save()));
    connect(widget.btnAdd, SIGNAL(clicked()), this, SLOT(addLine()));
    connect(widget.btnRemove, SIGNAL(clicked()), this, SLOT(removeLine()));
    connect(widget.btnClear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(widget.btnAbort, SIGNAL(clicked()), this, SLOT(abort()));

    load(fileName);
}

SUpdater::~SUpdater() {
}

void SUpdater::updateTle() {
    QStandardItemModel *model = (QStandardItemModel *)widget.listView->model();

    while ((urlIndex < model->rowCount()) && (model->item(urlIndex)->checkState() == Qt::Unchecked))
        urlIndex++;

    if (urlIndex >= model->rowCount()) {
        urlIndex = 0;
        return;
    }

    widget.progressBar->setValue(0);

    if (file) {
        file->close();
        delete file;
        file = NULL;
    }

    QUrl url(model->item(urlIndex)->text());
    model->item(urlIndex)->setIcon(QIcon(":/status/right-arrow-1.svg"));

    QFileInfo fileInfo(url.url());
    QString fileName = fileInfo.fileName();

    if (fileName.isEmpty()) {
        fileName = "index.html";
    }

    if (QFile::exists(fileName)) {
        QFile::remove(fileName);
    }

    fileInfo.setFile(listFile->fileName());
    file = new QFile(fileInfo.path() + "/" + fileName);

    if (!file->open(QFile::WriteOnly)) {
        widget.textStatus->appendPlainText(
            QString("[%0]: %1").arg(fileName).arg(file->errorString()));
        delete file;
        file = NULL;
        return;
    }

    httpRequestAborted = false;
    reply = manager.get(QNetworkRequest(url));

    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished())); // TODO disconnect
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this,
            SLOT(updateDataReadProgress(qint64, qint64)));
}

void SUpdater::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes) {
    if (httpRequestAborted) {
        return;
    }

    widget.progressBar->setMaximum(totalBytes);
    widget.progressBar->setValue(bytesRead);
}

void SUpdater::httpFinished() {
    QStandardItemModel *model = (QStandardItemModel *)widget.listView->model();

    if (reply->error()) {
        file->remove();
        model->item(urlIndex)->setIcon(QIcon(":/status/prohibition.svg"));
        widget.textStatus->appendPlainText(
            QString("[%0]: %1").arg(file->fileName()).arg(reply->errorString()));
    } else {
        model->item(urlIndex)->setIcon(QIcon(":/status/correct.svg"));
        if (file->isWritable()) {
            file->write(reply->readAll());
        } else {
            qWarning("Error: SUpdater file write");
        }
    }

    file->close();
    reply->deleteLater();
    reply = 0;

    if (httpRequestAborted) {
        return;
    }

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
        widget.textStatus->appendPlainText(QString("Error access to file [%0].").arg(fileName));
        return;
    }

    listFile->open(QFile::ReadOnly | QFile::Text);

    if (!listFile->isOpen()) {
        widget.textStatus->appendPlainText(
            QString("[%0]: %1").arg(fileName).arg(file->errorString()));
        return;
    };

    while (!listFile->atEnd()) {
        line = QString(listFile->readLine());
        state = line.section(',', 0, 0).toInt();
        url = line.section(',', 1).trimmed();
        model->appendRow(new QStandardItem(url));
        model->item(i)->setCheckable(true);
        if (state)
            model->item(i)->setCheckState(Qt::Checked);
        i++;
    }

    widget.listView->setModel(model);
    listFile->close();
}

void SUpdater::save() {
    QString url, line;
    bool state;
    QStandardItemModel *model = (QStandardItemModel *)widget.listView->model();

    if (!listFile->exists()) {
        widget.textStatus->appendPlainText(
            QString("Error access to file [%0].").arg(listFile->fileName()));
        return;
    }

    listFile->open(QFile::WriteOnly | QFile::Text);

    if (!listFile->isOpen()) {
        widget.textStatus->appendPlainText(
            QString("[%0]: %1").arg(listFile->fileName()).arg(file->errorString()));
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
    QStandardItemModel *model = (QStandardItemModel *)widget.listView->model();
    QStandardItem *item = new QStandardItem("http://");
    item->setCheckable(true);
    model->insertRow(widget.listView->currentIndex().row(), item);
}

void SUpdater::removeLine() {
    widget.listView->model()->removeRow(widget.listView->currentIndex().row());
}

void SUpdater::clear() {
    QStandardItemModel *model = (QStandardItemModel *)widget.listView->model();
    model->clear();
}

void SUpdater::abort() {
    httpRequestAborted = true;
    if (reply) {
        reply->deleteLater(); // TODO assign to NULL
    }
}
