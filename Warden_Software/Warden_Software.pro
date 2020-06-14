QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buildbutton.cpp \
    custombutton.cpp \
    inspector.cpp \
    inspectorelement.cpp \
    main.cpp \
    mainwindow.cpp \
    savebutton.cpp \
    treeviewlayout.cpp \
    qjsonmodel.cpp

HEADERS += \
    buildbutton.h \
    custombutton.h \
    inspector.h \
    inspectorelement.h \
    libs/Warden.hpp \
    mainwindow.h \
    savebutton.h \
    treeviewlayout.h \
    qjsonmodel.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Warden_Software_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L../build-Warden_lib/ -lWarden_lib
INCLUDEPATH = ../Warden_lib/

LIBS += -L"../SFML-master/lib/"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "../SFML-master/include"
DEPENDPATH += "../SFML-master/include"
