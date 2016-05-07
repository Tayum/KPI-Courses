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
    dragonenemy.cpp \
    generalstate.cpp \
    achievements.cpp \
    army.cpp \
    hirearmy.cpp \
    perks.cpp \
    achievementsmenu.cpp \
    heropowersmenu.cpp \
    settingsmenu.cpp \
    globalstatsmenu.cpp

HEADERS  += battlefield.h \
    dragonenemy.h \
    generalstate.h \
    achievements.h \
    army.h \
    hirearmy.h \
    perks.h \
    achievementsmenu.h \
    heropowersmenu.h \
    settingsmenu.h \
    globalstatsmenu.h

FORMS    += battlefield.ui \
    hirearmy.ui \
    perks.ui \
    achievementsmenu.ui \
    heropowersmenu.ui \
    settingsmenu.ui \
    globalstatsmenu.ui

DISTFILES +=

RESOURCES += \
    mediaresources.qrc
