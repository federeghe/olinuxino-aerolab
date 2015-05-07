# Only call subdirectory pro files

TEMPLATE = subdirs


# main must be the last:
CONFIG += ordered c++11
SUBDIRS = gui logic

SUBDIRS += main


