#-------------------------------------------------
#
# Project created by QtCreator 2016-06-09T11:18:23
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    doors.cpp \
    manager.cpp \
    elevator.cpp

HEADERS  += mainwindow.h \
    doors.h \
    elevator.h \
    manager.h

FORMS    += mainwindow.ui

DISTFILES += \
    lab4.qmodel
