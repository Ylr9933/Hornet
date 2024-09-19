QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_FILE = icon.rc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attackstate.cpp \
    backstate.cpp \
    dashstate.cpp \
    defencestate.cpp \
    duckstate.cpp \
    idlestate.cpp \
    jumpstate.cpp \
    lwalkstate.cpp \
    lwallstate.cpp \
    main.cpp \
    rwalkstate.cpp \
    rwallstate.cpp \
    state.cpp \
    statemachine.cpp \
    trayicon.cpp \
    widget.cpp

HEADERS += \
    attackstate.h \
    backstate.h \
    dashstate.h \
    defencestate.h \
    duckstate.h \
    idlestate.h \
    jumpstate.h \
    lwalkstate.h \
    lwallstate.h \
    rwalkstate.h \
    rwallstate.h \
    state.h \
    statemachine.h \
    trayicon.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    icon.rc


