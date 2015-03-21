#-------------------------------------------------
#
# Project created by QtCreator 2015-02-26T10:50:15
#
#-------------------------------------------------

QT       += widgets
QT       -= gui

CONFIG += c++11

TARGET = ../../bin/plugins/RunPy
TEMPLATE = lib

DEFINES += RUNPY_LIBRARY

SOURCES += runpy.cpp \
    dialog.cpp

HEADERS += runpy.h\
        runpy_global.h \
    dialog.h

FORMS += dialog.ui

INCLUDEPATH += ../../main
macx
{
    INCLUDEPATH += /Library/Frameworks/Python.framework/Versions/2.7/include/python2.7
    LIBS += -L/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/config -ldl -framework CoreFoundation -lpython2.7
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}

# Keep auto-generated source and object files in separate directory
OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
