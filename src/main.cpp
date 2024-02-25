/*
 * File:   main.cpp
 * Author: Ivan Ryazanov
 *
 * Created on April 13, 2019, 9:41 PM
 */

#include "gui/SWindow.h"
#include "satviewer.h"
#include <QApplication>
#include <QtDebug>

void copyDefault() {
    QString home = QDir::home().path() + QDir::separator() + "satviewer" + QDir::separator();
    if (QDir(home).exists()) {
        qWarning("profile is exists");
        return;
    }
    QDir().mkpath(home);
    QString profile = QDir(qApp->applicationDirPath() + QDir::separator() + "profile").path();
    QDirIterator it(profile, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        if (it.fileInfo().isDir()) {
            if (!it.fileInfo().dir().mkdir(
                    home + QDir(profile).relativeFilePath(it.fileInfo().filePath()))) {
                qWarning("Error mkdir:");
                qWarning() << it.fileInfo().filePath();
            } else {
                qWarning("mkdir:");
                qWarning() << it.fileInfo().filePath();
            }
        }

        if (it.fileInfo().isFile()) {
            if (!QFile(it.filePath())
                     .copy(QString(home +
                                   QDir(profile).relativeFilePath(it.fileInfo().filePath())))) {
                qWarning("Error copy:");
                qWarning() << it.fileInfo().filePath();
            } else {
                qWarning("copy:");
                qWarning() << it.fileInfo().filePath();
            }
        }
    }
}

int main(int argc, char *argv[]) {
    //    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication app(argc, argv);

    //    QSurfaceFormat format;
    //    format.setDepthBufferSize(24);
    //    format.setVersion(3, 3);
    //    qWarning("%d.%d", format.majorVersion(), format.minorVersion());
    //    QSurfaceFormat::setDefaultFormat(format);

    copyDefault();
    SatViewer satviewer;
    SWindow wndMain(&satviewer);
    wndMain.show();
    return app.exec();
}
