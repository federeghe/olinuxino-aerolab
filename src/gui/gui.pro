! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

#FORMS += gui.ui
#HEADERS += gui.h
SOURCES += test.cpp

# Will build in the main project directory.
TARGET = ../build/gui

