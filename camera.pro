#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T20:38:34
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += extserialport
CONFIG += resources_big
TARGET = camera
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mouse.cpp \
    secdialog.cpp

HEADERS  += mainwindow.h \
    mouse.h \
    secdialog.h

FORMS    += mainwindow.ui \
    secdialog.ui
QMAKE_CXXFLAGS += -std=gnu++14


include(lib/qextserialport/src/qextserialport.pri)

RESOURCES += \
    imagens.qrc \
