#-------------------------------------------------
#
# Project created by QtCreator 2018-11-05T22:49:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ErasmusIO
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    coursedialog.cpp \
    widget.cpp \
    loginstudent.cpp \
    loginteacher.cpp \
    menustudent.cpp \
    menuteacher.cpp \
    newuser.cpp \
    newstudent.cpp \
    newteacher.cpp \
    createstudent.cpp

HEADERS += \
        mainwindow.h \
    coursedialog.h \
    widget.h \
    loginstudent.h \
    loginteacher.h \
    menustudent.h \
    menuteacher.h \
    newuser.h \
    newstudent.h \
    newteacher.h \
    createstudent.h

FORMS += \
        mainwindow.ui \
    coursedialog.ui \
    widget.ui \
    loginstudent.ui \
    loginteacher.ui \
    menustudent.ui \
    menuteacher.ui \
    newuser.ui \
    newstudent.ui \
    newteacher.ui \
    createstudent.ui \
    universityinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
