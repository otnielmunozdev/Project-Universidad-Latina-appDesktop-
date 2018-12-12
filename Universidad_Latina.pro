#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T13:44:06
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Universidad_Latina
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#win32 {
#    CONFIG += embed_manifest_exe
#    QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrador\'uiAccess=\'false\'"
#}

SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow1.cpp \
    unila.cpp \
    unila2.cpp \
    unila3.cpp \
    unila4.cpp

HEADERS  += mainwindow.h \
    mainwindow1.h \
    unila.h \
    unila2.h \
    unila3.h \
    unila4.h

FORMS    += mainwindow.ui \
    mainwindow1.ui \
    unila.ui \
    unila2.ui \
    unila3.ui \
    unila4.ui

RESOURCES += \
    imagenes.qrc
