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
    admincontrolform.cpp \
    helpers.cpp \
    classspecsdialog.cpp \
    newherodialog.cpp \
    heropreviewwindow.cpp \
    spellrequirementsdialog.cpp \
    spellscalesdialog.cpp \
    customdroplistcombobox.cpp

HEADERS  += mainwindow.h \
    loginregisterdialog.h \
    gameserver.h \
    admincontrolform.h \
    helpers.h \
    classspecsdialog.h \
    newherodialog.h \
    heropreviewwindow.h \
    spellrequirementsdialog.h \
    spellscalesdialog.h \
    customdroplistcombobox.h

FORMS    += mainwindow.ui \
    loginregisterdialog.ui \
    admincontrolform.ui \
    classspecsdialog.ui \
    newherodialog.ui \
    heropreviewwindow.ui \
    spellrequirementsdialog.ui \
    spellscalesdialog.ui

RESOURCES += \
    main.qrc
