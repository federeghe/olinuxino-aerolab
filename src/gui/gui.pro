! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets serialport

FORMS += mainwindow.ui settingsdialog.ui settingstabserialport.ui rawserialtab.ui
INCLUDEPATH += include/ ../logic/include/
HEADERS += include/mainwindow.hpp include/settingsdialog.hpp include/settingstab.hpp include/settingstabserialport.hpp include/rawserialtab.hpp
SOURCES += mainwindow.cpp settingsdialog.cpp settingstabserialport.cpp rawserialtab.cpp

# Will build in the main project directory.
TARGET = ../build/gui
