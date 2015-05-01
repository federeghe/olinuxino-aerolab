# Only call subdirectory pro files

TEMPLATE = subdirs
SUBDIRS = gui

# logic must be last (for main):
CONFIG += ordered
SUBDIRS += logic


