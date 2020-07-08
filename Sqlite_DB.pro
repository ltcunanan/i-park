#-------------------------------------------------
#
# Project created by QtCreator 2018-10-08T17:26:51
#
#-------------------------------------------------
QT += sql
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sqlite_DB
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    main_interface.cpp \
    parking.cpp \
    reservation.cpp \
    register_user.cpp

HEADERS  += login.h \
    main_interface.h \
    parking.h \
    reservation.h \
    register_user.h

FORMS    += login.ui \
    main_interface.ui \
    parking.ui \
    reservation.ui \
    register_user.ui
