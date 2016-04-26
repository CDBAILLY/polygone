#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T15:32:00
#
#-------------------------------------------------



QT += widgets
qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PolyGone
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chip.cpp \
    view.cpp

HEADERS  += mainwindow.h \
    chip.h \
    view.h

FORMS    += mainwindow.ui

SUBDIRS += \
    chip.pro

RESOURCES += \
    images.qrc

DISTFILES += \
    fileprint.png \
    qt4logo.png \
    rotateleft.png \
    rotateright.png \
    zoomin.png \
    zoomout.png
