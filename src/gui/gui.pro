! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets serialport

FORMS += mainwindow.ui
INCLUDEPATH += include/
HEADERS += include/mainwindow.hpp
SOURCES += mainwindow.cpp

# Will build in the main project directory.
TARGET = ../build/gui

