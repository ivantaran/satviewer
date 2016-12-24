
INCLUDEPATH += .
TARGET = SatViewer
DESTDIR = ../bin
LIBS += -lGLU

MOC_DIR = build
OBJECTS_DIR = build

CONFIG += console debug

#CONFIG +=   warn_on \
#            opengl \
#            thread \
#            rtti \
#            console \
#            qt \
#            debug

QT      +=  gui \
            core \
#            script \
            sql \
            opengl \
            network

TEMPLATE = app

HEADERS    +=	\
                SWindow.h \
                SDlgOptions.h \
                SLocDialog.h \
                ../dialogs/sgp4/Sgp4Dialog.h \
                ../models/sgp4/Sgp4Model.h \
#                jscalc/SScriptFrame.h \
                ogl/GLSatWidget.h \
                ogl/GLSatAbstractWidget.h \
                ogl/GLSatWidget3d.h \
                ogl/satogl.h \
                satutils/Satellite.h \
                satutils/TleReader.h \
                locutils/Location.h \
                zrvutils/ZrvIoList.h \
                crd/crd.h \
                tleupd/SUpdater.h \
                sql/dbsql.h \
#                jswidgets/SWidget.h \
#                jswidgets/SWidgetList.h \
                uchecker/UCheck.h \
                ogl/globj/GLObjMaterial.h \
                ogl/globj/GLObjecter.h \
                ogl/glsprite/GLSprite.h \
                ogl/SatWidgetObject.h \
                SAbstractObjDialog.h    
								
SOURCES    +=	SatViewer.cpp \
                SWindow.cpp \
                SDlgOptions.cpp \
                SLocDialog.cpp \
                ../dialogs/sgp4/Sgp4Dialog.cpp \
                ../models/sgp4/Sgp4Model.cpp \
#                jscalc/SScriptFrame.cpp \
                ogl/GLSatWidget.cpp \
                ogl/GLSatAbstractWidget.cpp \
                ogl/GLSatWidget3d.cpp \
                ogl/satogl.cpp \
                satutils/Satellite.cpp \
                satutils/TleReader.cpp \
                locutils/Location.cpp \
                zrvutils/ZrvIoList.cpp \ 
                crd/crd.cpp \
                tleupd/SUpdater.cpp \
#                jswidgets/SWidget.cpp \
#                jswidgets/SWidgetList.cpp \
                uchecker/UCheck.cpp \
                ogl/globj/GLObjMaterial.cpp \
                ogl/globj/GLObjecter.cpp \
                ogl/glsprite/GLSprite.cpp \
                ogl/SatWidgetObject.cpp \
                SAbstractObjDialog.cpp
								
RESOURCES   =	ui/SatViewer.qrc

FORMS       +=  ui/SatViewer.ui \
                ui/options.ui \
                ui/settings.ui \
                ui/sat.ui \
                ui/loc.ui \
                ui/jscalc.ui \
                ui/tleupd.ui \
                ui/jswidgetlist.ui \
                ui/mapsettings.ui \
                ui/earthsettings.ui

FORMS       += ../dialogs/sgp4/ui/sgp4.ui

TRANSLATIONS = satviewer_fr.ts \
               satviewer_de.ts \
               satviewer_es.ts \
               satviewer_ru.ts

CODECFORTR = UTF-8

win32:{
	RC_FILE = satviewer.rc
}
