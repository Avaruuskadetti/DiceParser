#-------------------------------------------------
#
# Project created by QtCreator 2013-12-24T13:06:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

include(node/node.pri)
include(irc/irc.pri)

TARGET = diceParser
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    diceparser.cpp \
    diceresult.cpp \
    range.cpp \
    booleancondition.cpp \
    validator.cpp \
    die.cpp \
    result.cpp \
    scalarresult.cpp \
    parsingtoolbox.cpp \
    stringresult.cpp


HEADERS += \
    diceparser.h \
    diceresult.h \
    range.h \
    booleancondition.h \
    validator.h \
    die.h \
    result.h \
    scalarresult.h \
    parsingtoolbox.h \
    stringresult.h

OTHER_FILES += README.md \
    HelpMe.md


#QMAKE_CXXFLAGS += -O0
