
TARGET = satviewer-rotator
DESTDIR = .

MOC_DIR = build
UI_DIR = build
RCC_DIR = build
OBJECTS_DIR = build

CONFIG  += console debug c++11
QT      += gui core widgets network

QMAKE_CXXFLAGS_DEBUG += -O0

HEADERS += \
    ../gui/RotatorWidget.h \
    ../gui/RotatorRadar.h \
    ../utils/Rotator.h

SOURCES += \
    satviewer-rotator.cpp \
    ../gui/RotatorRadar.cpp \
    ../gui/RotatorWidget.cpp \
    ../utils/Rotator.cpp

RESOURCES = ../gui/SatViewer.qrc

FORMS += ../gui/ui/rotator.ui
