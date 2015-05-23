#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T01:01:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT2048
TEMPLATE = app


SOURCES += main.cpp\
        qt2048.cpp \
    board.cpp \
    game.cpp \
    playing.cpp

HEADERS  += qt2048.h \
    board.h \
    game.h \
    playing.h

FORMS    += qt2048.ui \
    playing.ui

RESOURCES += \
    2048picture.qrc
