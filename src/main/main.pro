TEMPLATE = app

QT += gui widgets serialport
LIBS += -L../build -lgui -llogic

INCLUDEPATH += include/ ../gui/include/ ../logic/include/ ../

SOURCES += main.cpp

# Will build the final executable in the main project directory.
TARGET = ../build/project
