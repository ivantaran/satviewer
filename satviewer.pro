
TARGET = satviewer
DESTDIR = .

MOC_DIR = build
UI_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

CONFIG  += console debug c++11
QT      += gui core sql widgets network qml

HEADERS += \
    SatViewer.h \
    SWindow.h \
    SDlgOptions.h \
    SLocDialog.h \
    dialogs/sgp4/Sgp4Dialog.h \
    models/sgp4/SGP4.h \
    models/sgp4/Sgp4Model.h \
    models/sun/sunmodel.h \
    jscalc/SScriptFrame.h \
    ogl/GLSatAbstractWidget.h \
    ogl/GLSatWidget.h \
    ogl/RadarWidget.h \
    ogl/GLSatWidget3d.h \
    ogl/satogl.h \
    satutils/Satellite.h \
    satutils/TleReader.h \
    locutils/Location.h \
    zrvutils/ZrvIoList.h \
    crd/crd.h \
    tleupd/SUpdater.h \
    sql/dbsql.h \
    jswidgets/SWidget.h \
    jswidgets/SWidgetList.h \
    uchecker/UCheck.h \
    ogl/globj/GLObjMaterial.h \
    ogl/globj/GLObjecter.h \
    ogl/glsprite/GLSprite.h \
    ogl/SatWidgetObject.h

SOURCES += \
    main.cpp \
    SatViewer.cpp \
    SWindow.cpp \
    SDlgOptions.cpp \
    SLocDialog.cpp \
    dialogs/sgp4/Sgp4Dialog.cpp \
    models/sgp4/SGP4.cpp \
    models/sgp4/Sgp4Model.cpp \
    models/sun/sunmodel.c \
    jscalc/SScriptFrame.cpp \
    ogl/GLSatAbstractWidget.cpp \
    ogl/GLSatWidget.cpp \
    ogl/RadarWidget.cpp \
    ogl/GLSatWidget3d.cpp \
    ogl/satogl.cpp \
    satutils/Satellite.cpp \
    satutils/TleReader.cpp \
    locutils/Location.cpp \
    zrvutils/ZrvIoList.cpp \ 
    crd/crd.cpp \
    tleupd/SUpdater.cpp \
    jswidgets/SWidget.cpp \
    jswidgets/SWidgetList.cpp \
    uchecker/UCheck.cpp \
    ogl/globj/GLObjMaterial.cpp \
    ogl/globj/GLObjecter.cpp \
    ogl/glsprite/GLSprite.cpp \
    ogl/SatWidgetObject.cpp
                                
RESOURCES = ui/SatViewer.qrc

FORMS += \
    ui/SatViewer.ui \
    ui/options.ui \
    ui/settings.ui \
    ui/sat.ui \
    ui/loc.ui \
    ui/jscalc.ui \
    ui/tleupd.ui \
    ui/jswidgetlist.ui \
    ui/mapsettings.ui \
    ui/earthsettings.ui \
    dialogs/sgp4/ui/sgp4.ui

TRANSLATIONS = \
    satviewer_fr.ts \
    satviewer_de.ts \
    satviewer_es.ts \
    satviewer_ru.ts

CODECFORTR = UTF-8

#win32:{
#    RC_FILE = satviewer.rc
#}

pvs_studio.target = analyze
#pvs_studio.output = true
pvs_studio.format = fullhtml
pvs_studio.cxxflags = -std=c++11
pvs_studio.sources = $${SOURCES}
include(PVS-Studio.pri)
