QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentication.cpp \
    booksinfo.cpp \
    database.cpp \
    editbook.cpp \
    edituser.cpp \
    main.cpp \
    mainwindow.cpp \
    newbook.cpp \
    newuser.cpp \
    readersinfo.cpp \
    rentedinfo.cpp \
    workersinfo.cpp

HEADERS += \
    authentication.h \
    booksinfo.h \
    config.h \
    database.h \
    editbook.h \
    edituser.h \
    mainwindow.h \
    newbook.h \
    newuser.h \
    readersinfo.h \
    rentedinfo.h \
    workersinfo.h

FORMS += \
    authentication.ui \
    editbook.ui \
    edituser.ui \
    mainwindow.ui \
    newbook.ui \
    newuser.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
