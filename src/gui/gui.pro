! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets serialport

FORMS += mainwindow.ui settingsdialog.ui
INCLUDEPATH += include/
HEADERS += include/mainwindow.hpp include/settingsdialog.hpp
SOURCES += mainwindow.cpp settingsdialog.cpp

# Will build in the main project directory.
TARGET = ../build/gui

