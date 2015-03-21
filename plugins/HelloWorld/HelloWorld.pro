#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T14:24:12
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ../../bin/plugins/HelloWorld
TEMPLATE = lib

DEFINES += HELLOWORLD_LIBRARY

SOURCES += helloworld.cpp

HEADERS += helloworld.h\
        helloworld_global.h

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
