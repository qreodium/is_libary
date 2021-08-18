QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
tst_rentedtest.cpp \
rentedinfo.cpp

HEADERS += \
rentedinfo.h

