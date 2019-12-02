
TARGET = satviewer
DESTDIR = .

MOC_DIR = build
UI_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

CONFIG  += console debug c++11
QT      += gui core sql widgets network qml

QMAKE_CXXFLAGS_DEBUG += -O0

HEADERS += \
    SatViewer.h \
    SatViewer.h \
    utils/models/sgp4/SGP4.h \
    utils/models/sgp4/Sgp4Model.h \
    utils/models/sun/sunmodel.c \
    utils/ogl/GLSatAbstractWidget.h \
    utils/ogl/GLSatWidget.h \
    utils/ogl/RadarWidget.h \
    utils/ogl/GLSatWidget3d.h \
    utils/ogl/globj/GLObjMaterial.h \
    utils/ogl/globj/GLObjecter.h \
    utils/ogl/glsprite/GLSprite.h \
    utils/ogl/SatWidgetObject.h \
    utils/Rotator.h \
    utils/Satellite.h \
    utils/TleReader.h \
    utils/Location.h \
    utils/ZrvIoList.h \ 
    gui/RotatorSettings.h \
    gui/RotatorWidget.h \
    gui/SWindow.h \
    gui/SDlgOptions.h \
    gui/SLocDialog.h \
    gui/Sgp4Dialog.h \
    gui/SWidget.h \
    gui/SWidgetList.h \
    gui/UCheck.h \
    gui/SScriptFrame.h \
    gui/SUpdater.h

SOURCES += \
    main.cpp \
    SatViewer.cpp \
    utils/models/sgp4/SGP4.cpp \
    utils/models/sgp4/Sgp4Model.cpp \
    utils/models/sun/sunmodel.c \
    utils/ogl/GLSatAbstractWidget.cpp \
    utils/ogl/GLSatWidget.cpp \
    utils/ogl/RadarWidget.cpp \
    utils/ogl/GLSatWidget3d.cpp \
    utils/ogl/globj/GLObjMaterial.cpp \
    utils/ogl/globj/GLObjecter.cpp \
    utils/ogl/glsprite/GLSprite.cpp \
    utils/ogl/SatWidgetObject.cpp \
    utils/Rotator.cpp \
    utils/Satellite.cpp \
    utils/TleReader.cpp \
    utils/Location.cpp \
    utils/ZrvIoList.cpp \ 
    gui/RotatorSettings.cpp \
    gui/RotatorWidget.cpp \
    gui/SWindow.cpp \
    gui/SDlgOptions.cpp \
    gui/SLocDialog.cpp \
    gui/Sgp4Dialog.cpp \
    gui/SWidget.cpp \
    gui/SWidgetList.cpp \
    gui/UCheck.cpp \
    gui/SScriptFrame.cpp \
    gui/SUpdater.cpp
                                
RESOURCES = gui/SatViewer.qrc

FORMS += \
    gui/ui/SatViewer.ui \
    gui/ui/options.ui \
    gui/ui/settings.ui \
    gui/ui/sat.ui \
    gui/ui/loc.ui \
    gui/ui/jscalc.ui \
    gui/ui/tleupd.ui \
    gui/ui/jswidgetlist.ui \
    gui/ui/mapsettings.ui \
    gui/ui/earthsettings.ui \
    gui/ui/earthsettings.ui \
    gui/ui/rotator.ui \
    gui/ui/rotatorSettings.ui \
    gui/ui/sgp4.ui

TRANSLATIONS = \
    gui/translations/satviewer_fr.ts \
    gui/translations/satviewer_de.ts \
    gui/translations/satviewer_es.ts \
    gui/translations/satviewer_ru.ts

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
