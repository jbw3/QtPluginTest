#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T12:11:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = ../bin/PluginTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    plugininterface.h

FORMS    += mainwindow.ui \
    dialog.ui

# -----------------------------------------------------------------------
# Keep auto-generated source and object files in separate directory
# -----------------------------------------------------------------------
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
# -----------------------------------------------------------------------
