! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += widgets serialport gui

FORMS += mainwindow.ui settingsdialog.ui settingstabserialport.ui rawserialtab.ui gpiotab.ui
INCLUDEPATH += include/ ../logic/include/ ../../lib/A20-gpio-cpp/
HEADERS += include/mainwindow.hpp include/settingsdialog.hpp include/settingstab.hpp include/settingstabserialport.hpp include/rawserialtab.hpp include/gpiotab.hpp
SOURCES += mainwindow.cpp settingsdialog.cpp settingstabserialport.cpp rawserialtab.cpp gpiotab.cpp

SOURCES += ../../lib/A20-gpio-cpp/A20-gpio.cpp ../../lib/A20-gpio-cpp/gpio_lib.c

# Will build in the main project directory.
TARGET = ../build/gui
