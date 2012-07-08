TEMPLATE = lib
DESTDIR  = ../../bin/plugins
TARGET = model_sun
HEADERS += SatModel.h ../../satviewer/satutils/Satellite.h
SOURCES += SatModel.cpp ../../satviewer/satutils/Satellite.cpp
DEFINES += QT_DLL
CONFIG  += qt shared warn_on release
