/*
 * SatViewer.cpp
 *
 *  Created on: 05.05.2009
 *      Author: Yan Coduemat
 */

#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include <qt4/QtCore/qglobal.h>
#include "SWindow.h"

void copyDefault() {
	QString home = QDir::home().path() + QDir::separator() + "satviewer" + QDir::separator();
	if (QDir(home).exists()) {
		puts("profile is exists");
		return;
	}
	QDir().mkpath(home);
	QString profile = QDir(qApp->applicationDirPath() + QDir::separator() + "profile").path();
	QDirIterator it(profile, QDirIterator::Subdirectories);
	while (it.hasNext()) {
		it.next();
		if (it.fileInfo().isDir()) {
			if (!it.fileInfo().dir().mkdir(home + QDir(profile).relativeFilePath(it.fileInfo().filePath()))) {
				puts("Error mkdir:");
				puts(it.fileInfo().filePath().toLocal8Bit().data());
			} else {
				puts("mkdir:");
				puts(it.fileInfo().filePath().toLocal8Bit().data());
			}
		}

		if (it.fileInfo().isFile()) {
			if (!QFile(it.filePath()).copy(QString(home + QDir(profile).relativeFilePath(it.fileInfo().filePath())))) {
				puts("Error copy:");
				puts(it.fileInfo().filePath().toLocal8Bit().data());
			} else {
				puts("copy:");
				puts(it.fileInfo().filePath().toLocal8Bit().data());
			}
		}
	}
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setVersion(1, 2);
//    qWarning("%d.%d", format.majorVersion(), format.minorVersion());
//    QSurfaceFormat::setDefaultFormat(format);

    copyDefault();
    SWindow wndMain;
    wndMain.show();
    return app.exec();
}
