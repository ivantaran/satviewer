
#include "supdater.h"
#include <QFileInfo>
#include <QStandardItemModel>

SUpdater::SUpdater(const QString &fileName) {
    widget.setupUi(this);
    listFile = nullptr;
    httpGetId = -1;
    httpRequestAborted = false;
    urlIndex = 0;
    m_reply = nullptr;
    m_path = "";
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

    QUrl url(model->item(urlIndex)->text());
    model->item(urlIndex)->setIcon(QIcon(":/status/right-arrow-1.svg"));

    QFileInfo fileInfo(listFile->fileName());
    m_path = fileInfo.path() + QDir::separator();

    httpRequestAborted = false;
    m_reply = m_manager.get(QNetworkRequest(url));

    connect(m_reply, SIGNAL(finished()), this, SLOT(httpFinished())); // TODO disconnect
    connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)), this,
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

    if (m_reply->error()) {
        model->item(urlIndex)->setIcon(QIcon(":/status/prohibition.svg"));
        QString err = QString("Download of [%0] failed: %1.")
                          .arg(m_reply->url().toString(), m_reply->errorString());
        widget.textStatus->appendPlainText(err);
    } else {
        QVariant content = m_reply->header(QNetworkRequest::ContentDispositionHeader);
        if (content.isValid()) {
            QString disposition = content.toString();
            QRegularExpression regex("filename\\*?=\"?([^\";]+)\"?");
            QRegularExpressionMatch match = regex.match(disposition);
            if (match.hasMatch()) {
                QString fileName = match.captured(1).trimmed();
                if (fileName.contains('%')) {
                    fileName = QUrl::fromPercentEncoding(fileName.toUtf8());
                }

                QFile file(m_path + fileName);
                if (file.open(QFile::WriteOnly)) {
                    file.write(m_reply->readAll());
                    file.close();
                    model->item(urlIndex)->setIcon(QIcon(":/status/correct.svg"));
                } else {
                    qWarning("Error: SUpdater file write");
                }
            }
        }
    }

    m_reply->deleteLater();
    m_reply = nullptr;

    if (httpRequestAborted) {
        return;
    }

    urlIndex++;
    updateTle();
}

void SUpdater::load(const QString &fileName) {
    QString line, url;
    bool state;
    int i = 0;
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
            QString("[%0]: %1").arg(fileName).arg(listFile->errorString()));
        return;
    };

    QStandardItemModel *model = new QStandardItemModel(this);
    while (!listFile->atEnd()) {
        line = QString(listFile->readLine());
        state = line.section(',', 0, 0).toInt();
        url = line.section(',', 1).trimmed();
        model->appendRow(new QStandardItem(url));
        model->item(i)->setCheckable(true);
        if (state) {
            model->item(i)->setCheckState(Qt::Checked);
        }
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
            QString("[%0]: %1").arg(listFile->fileName()).arg(listFile->errorString()));
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
    if (m_reply) {
        m_reply->deleteLater(); // TODO assign to NULL
    }
}
