TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    userinterface.cpp \
    apothecary.cpp \
    invoice.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    userinterface.h \
    apothecary.h \
    invoice.h \
    datetype.h

