#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T13:36:28
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRM
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
    dlgitem.cpp \
    logindialog.cpp \
    airlogindialog.cpp \
    useitem.cpp \
    userticket.cpp

HEADERS  += mainwindow.h \
    ks_bintree.h \
    ks_linklist.h \
    ks_queue.h \
    ks_queue_2.h \
    logindialog.h \
    logindialog.h \
    dlgitem.h \
    connection.h \
    airlogindialog.h \
    useritem.h \
    userticket.h

FORMS    += \
    dlgitem.ui \
    logindialog.ui \
    mainwindow.ui \
    airlogindialog.ui \
    useritem.ui \
    userticket.ui

RC_FILE += myapp.rc

RESOURCES += \
    rc.qrc
