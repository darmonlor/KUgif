#-------------------------------------------------
#
# Project created by QtCreator 2015-09-12T22:01:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kugif
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lib/frame.cpp \
    lib/animation.cpp

HEADERS  += mainwindow.h \
    lib/frame.h \
    lib/animation.h

FORMS    += mainwindow.ui
