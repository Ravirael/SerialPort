#-------------------------------------------------
#
# Project created by QtCreator 2016-02-27T12:17:10
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG += C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialport.cpp \
    hexstring.cpp

HEADERS  += mainwindow.h \
    serialport.h \
    mappedcombobox.h \
    hexstring.h

FORMS    += mainwindow.ui
