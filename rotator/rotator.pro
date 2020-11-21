
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
    ../gui/RotatorRadar.h \
    ../gui/RotatorWidget.h \
    ../utils/Rotator.h \
    ../utils/satmath.h

SOURCES += \
    satviewer-rotator.cpp \
    ../gui/RotatorRadar.cpp \
    ../gui/RotatorWidget.cpp \
    ../utils/Rotator.cpp \
    ../utils/satmath.c

RESOURCES = ../gui/SatViewer.qrc

FORMS += ../gui/ui/rotator.ui
