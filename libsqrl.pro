#-------------------------------------------------
#
# Project created by QtCreator 2013-10-10T21:02:49
#
#-------------------------------------------------

QT       -= core gui

TARGET = libsqrl
TEMPLATE = lib

DEFINES += LIBSQRL_LIBRARY

SOURCES += \
    key_generator.cpp \
    sqrl_client.cpp \
    scrypt.cpp

HEADERS += libsqrl.h\
        libsqrl_global.h \
    types.h \
    key_generator.h \
    sqrl_client.h \
    scrypt.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
