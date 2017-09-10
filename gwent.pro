#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T20:55:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gwent
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    cards.cpp \
    battlefield.cpp \
    cardfactory.cpp \
    register.cpp \
    ui_cardbutton.cpp \
    ui_standardbutton.cpp \
    ui_cardslot.cpp \
    ui_tonextpagebutton.cpp \
    ui_toprepagebutton.cpp \
    w_edit.cpp \
    cardset.cpp \
    ui_cardsetbutton.cpp \
    ui_standarddialog.cpp \
    w_game.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    cards.h \
    battlefield.h \
    cardfactory.h \
    ui_cardbutton.h \
    ui_standardbutton.h \
    ui_cardslot.h \
    ui_tonextpagebutton.h \
    ui_toprepagebutton.h \
    cardEnum.h \
    w_edit.h \
    cardset.h \
    ui_cardsetbutton.h \
    ui_standarddialog.h \
    w_game.h

FORMS += \
        mainwindow.ui \
    dialog.ui

RESOURCES += \
    ui.qrc

