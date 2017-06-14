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
    view.cpp \
    c01graphicsscene.cpp \
    c02toolbutton.cpp \
    c02qbuttongroup.cpp \
    c02qtoolbutton.cpp \
    c03statemachinebase.cpp \
    c03statemachinepositioner.cpp \
    c03statemachinefactory.cpp \
    c04scenecontext.cpp \
    c04globalcontext.cpp \
    c05graphicsitem.cpp \
    C03StateMachineDrawObject.cpp

HEADERS  += mainwindow.h \
    chip.h \
    view.h \
    c01graphicsscene.h \
    c02toolbutton.h \
    c02qbuttongroup.h \
    c02qtoolbutton.h \
    c03statemachinebase.h \
    c03statemachinepositioner.h \
    c03statemachinefactory.h \
    c04scenecontext.h \
    c04globalcontext.h \
    c05graphicsitem.h \
    C03StateMachineDrawObject.h

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
