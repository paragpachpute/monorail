#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T13:39:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = railway2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    history.cpp \
    homepage.cpp \
    profile.cpp \
    showfare.cpp \
    booking.cpp \
    sqlconnect.cpp

HEADERS  += mainwindow.h \
    history.h \
    homepage.h \
    profile.h \
    showfare.h \
    booking.h \
    mysql.h

FORMS    += mainwindow.ui \
    homepage.ui \
    history.ui \
    profile.ui \
    showfare.ui \
    booking.ui
