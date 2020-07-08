#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T23:08:15
#
#-------------------------------------------------
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 128v03
TEMPLATE = app


SOURCES += main.cpp\
    login.cpp \
    main_interface.cpp \
    parking.cpp \
    register_user.cpp \
    reservation.cpp \
    status.cpp \
    summary.cpp \
    past.cpp

HEADERS  += \
    login.h \
    main_interface.h \
    parking.h \
    register_user.h \
    reservation.h \
    status.h \
    summary.h \
    past.h

FORMS    += \
    login.ui \
    main_interface.ui \
    parking.ui \
    register_user.ui \
    reservation.ui \
    status.ui \
    summary.ui \
    past.ui

SUBDIRS += \
    Sqlite_DB.pro \
    Sqlite_DB.pro \
    Sqlite_DB.pro

DISTFILES +=

RESOURCES += \
    images.qrc
