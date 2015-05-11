! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += serialport

#FORMS += mainwindow.ui
INCLUDEPATH += include/
HEADERS += include/serialport.hpp
SOURCES += serialport.cpp

# Will build in the main project directory.
TARGET = ../build/logic

