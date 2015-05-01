TEMPLATE = app

SOURCES += main.cpp

LIBS += -L../build -lgui

# Will build the final executable in the main project directory.
TARGET = ../build/project
