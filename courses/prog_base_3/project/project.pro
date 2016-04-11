#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T15:57:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        battlefield.cpp \
    currentstate.cpp \
    dragonenemy.cpp \
    generalstate.cpp

HEADERS  += battlefield.h \
    currentstate.h \
    dragonenemy.h \
    generalstate.h

FORMS    += battlefield.ui
