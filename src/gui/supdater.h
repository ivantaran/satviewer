#ifndef SUPDATER_H_
#define SUPDATER_H_

#include "ui_tleupd.h"
#include <QDialog>
#include <QtNetwork>

class SUpdater : public QWidget {
    Q_OBJECT

public:
    SUpdater(const QString &fileName = "");
    virtual ~SUpdater();
    void load(const QString &fileName);
    inline Ui::Updater *getWidget() {
        return &widget;
    }

private:
    Ui::Updater widget;
    QNetworkAccessManager m_manager;
    QNetworkReply *m_reply;
    QFile *listFile;
    QString m_path;
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
