#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T09:47:39
#
#-------------------------------------------------

QT       += core gui \
            network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = battle_progress_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginregisterdialog.cpp \
    gameserver.cpp \
    admincontrolform.cpp

HEADERS  += mainwindow.h \
    loginregisterdialog.h \
    gameserver.h \
    admincontrolform.h

FORMS    += mainwindow.ui \
    loginregisterdialog.ui \
    admincontrolform.ui
