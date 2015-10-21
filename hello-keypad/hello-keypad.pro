#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T15:58:56
#
#-------------------------------------------------

QT       += qml quick
QT       += serialport

QT       -= gui

TARGET = hello-keypad
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    keypad.cpp

HEADERS += \
    keypad.h

target.path = /home/adpermana/qt
INSTALLS += target

DISTFILES += \
    main.qml

RESOURCES += \
    qml.qrc
