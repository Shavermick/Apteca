TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    userinterface.cpp \
    apothecary.cpp \
    invoice.cpp \
    salesinvoice.cpp \
    expense.cpp \
    purchaseinvoice.cpp \
    report.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    userinterface.h \
    apothecary.h \
    invoice.h \
    datetype.h \
    salesinvoice.h \
    expense.h \
    purchaseinvoice.h \
    report.h

