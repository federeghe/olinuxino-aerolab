TEMPLATE = app

QT += gui widgets
LIBS += -L../build -lgui

INCLUDEPATH += include/ ../gui/include/

SOURCES += main.cpp

# Will build the final executable in the main project directory.
TARGET = ../build/project
