#-------------------------------------------------
#
# Project created by QtCreator 2014-12-27T16:54:11
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reads_Profiler_server
TEMPLATE = app

wince*: {
    DEPLOYMENT_PLUGIN += qsqlite
}

SOURCES += main.cpp\
    qsqlconnectiondialog.cpp \
    connectionwidget.cpp \
    browser.cpp

HEADERS  += qsqlconnectiondialog.h \
    connectionwidget.h \
    browser.h

FORMS    +=  qsqlconnectiondialog.ui \
    browserwidget.ui
