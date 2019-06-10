#-------------------------------------------------
#
# Project created by QtCreator 2019-06-10T14:20:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gmshapitest
TEMPLATE = app

DESTDIR = $$PWD/../bin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

#win32-msvc|win32-msvc.net|win32-msvc2002|win32-msvc2003|win32-msvc2005|win32-msvc2008|win32-msvc2010|win32-msvc2012|win32-msvc2013 {
#    CONFIG(debug, debug|release):LIBS += $$_PRO_FILE_PWD_/../bin/gmsh.lib
#        else:LIBS += $$_PRO_FILE_PWD_/../bin/gmsh.lib
#}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h \
    include/gmsh.h


win32:CONFIG(release, debug|release): LIBS += -L$$_PRO_FILE_PWD_/../bin/ -lgmsh
else:win32:CONFIG(debug, debug|release): LIBS += -L$$_PRO_FILE_PWD_/../bin/ -lgmsh



INCLUDEPATH += $$PWD/../bin
DEPENDPATH += $$PWD/../bin
