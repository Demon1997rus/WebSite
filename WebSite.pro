QT += core network sql
QT -= gui

TARGET = WebSite

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += src/main.cpp \
    src/global/global.cpp \
    src/requestermapper.cpp \
    src/controllers/logincontroller.cpp \
    src/controllers/registercontroller.cpp \
    src/controllers/transportcontroller.cpp \
    src/controllers/servicescontroller.cpp \
    src/controllers/aboutcontroller.cpp \
    src/controllers/contactscontroller.cpp \
    src/controllers/ordercontroller.cpp \
    src/utils/order.cpp \
    src/controllers/myorderscontroller.cpp \
    src/database/database.cpp

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/QtWebApp/templateengine/templateengine.pri)
include(../QtWebApp/QtWebApp/logging/logging.pri)

OTHER_FILES = etc/website.ini \
        data/styles.css \
        data/login.html \
        data/main.html \
        data/registration.html \
        data/contacts.html \
        data/about.html \
        data/services.html \
        data/order.html


HEADERS += \
    src/global/global.h \
    src/requestermapper.h \
    src/controllers/logincontroller.h \
    src/controllers/registercontroller.h \
    src/controllers/transportcontroller.h \
    src/controllers/servicescontroller.h \
    src/controllers/aboutcontroller.h \
    src/controllers/contactscontroller.h \
    src/controllers/ordercontroller.h \
    src/utils/order.h \
    src/controllers/myorderscontroller.h \
    src/database/database.h
