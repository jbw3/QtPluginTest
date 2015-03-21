#-------------------------------------------------
#
# Project created by QtCreator 2015-02-19T21:11:56
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ../../bin/plugins/Buttons
TEMPLATE = lib

DEFINES += BUTTONS_LIBRARY

SOURCES += buttons.cpp \
    dialog.cpp

HEADERS += buttons.h\
        buttons_global.h \
    dialog.h

INCLUDEPATH += ../../main

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# -----------------------------------------------------------------------
# Keep auto-generated source and object files in separate directory
# -----------------------------------------------------------------------
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
# -----------------------------------------------------------------------

FORMS += \
    dialog.ui
