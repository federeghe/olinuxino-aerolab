# Only call subdirectory pro files

TEMPLATE = subdirs


# main must be the last:
CONFIG += ordered
SUBDIRS = gui logic

SUBDIRS += main


