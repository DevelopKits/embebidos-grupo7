#-------------------------------------------------
#
# Project created by QtCreator 2013-09-26T00:15:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = buttonGUI
    target.files = buttonGUI
    target.path = /home/root

TEMPLATE = app
INSTALLS += target

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-0.10


SOURCES += main.cpp\
        opengui.cpp \
    mediacontrol.cpp

HEADERS  += opengui.h \
    mediacontrol.h

FORMS    += opengui.ui
