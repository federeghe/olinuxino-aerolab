#Includes common configuration for all subdirectory .pro files.
INCLUDEPATH += . ..
WARNINGS += -Wall

TEMPLATE = lib
CONFIG += staticlib	# If you want shared library remove this line

# The following keeps the generated files at least somewhat separate 
# from the source files.
UI_DIR = build/uics
MOC_DIR = build/mocs
OBJECTS_DIR = build/objs

