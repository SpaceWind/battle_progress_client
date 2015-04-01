#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T09:47:39
#
#-------------------------------------------------

QT       += core gui \
            network
CONFIG	+= c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = battle_progress_client
TEMPLATE = app

SOURCES += src/main.cpp
include(src/system/system.pri)
include(src/ui/controls/controls.pri)
include(src/utils/utils.pri)
include(src/views/views.pri)


include(src/ui/ui.pri)



RESOURCES += \
    main.qrc
