TEMPLATE = lib
DESTDIR  = ../../bin/dialogs
TARGET = sgp4_dialog

HEADERS += SObjDialog.h \
    ../../satviewer/satutils/Satellite.h \
    ../../satviewer/ogl/GLSatAbstractWidget.h \
    ../../satviewer/zrvutils/ZrvIoList.h \
    ../../satviewer/SAbstractObjDialog.h
    
SOURCES += SObjDialog.cpp \
    ../../satviewer/satutils/Satellite.cpp \
    ../../satviewer/ogl/GLSatAbstractWidget.cpp \
    ../../satviewer/zrvutils/ZrvIoList.cpp \
    ../../satviewer/SAbstractObjDialog.cpp

FORMS = ui/sat.ui
QT =  gui core opengl
DEFINES += QT_DLL
CONFIG  += qt shared warn_on release
