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
    custombutton.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    custombutton.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Warden_Software_fr_FR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lwarden
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lwarden
else:unix: LIBS += -L$$PWD/libs/ -lwarden

INCLUDEPATH += $$PWD/libs/Warden.hpp $$PWD/../Warden_Lib/include/engine $$PWD/../Warden_Lib/include/engine/data $$PWD/../Warden_Lib/include/engine/core $$PWD/../Warden_Lib/include/engine/display $$PWD/../Warden_Lib/include/engine/error
DEPENDPATH += $$PWD/libs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -ljsoncpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -ljsoncpp
else:unix: LIBS += -L$$PWD/libs/ -ljsoncpp

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/libjsoncpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/libjsoncpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/jsoncpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/jsoncpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/libs/libjsoncpp.a
