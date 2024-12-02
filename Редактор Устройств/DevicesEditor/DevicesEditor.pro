QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


FORMS += \
    deviceeditdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    constants.h \
    datavalidators.h \
    deviceeditdialog.h \
    scene/devices/deviceabstract.h \
    scene/devices/pc.h \
    scene/devices/phone.h \
    scene/devices/printer.h \
    scene/devices/server.h \
    scene/planning/furnitureabstract.h \
    scene/planning/ladder.h \
    scene/planning/window.h \
    xml/filereader.h \
    scene/graphicsscene.h \
    scene/graphicsview.h \
    scene/planning/door.h \
    scene/planning/house.h \
    scene/planning/wall.h \
    widget.h \
    xml/xmlitemabstract.h

SOURCES += \
    datavalidators.cpp \
    deviceeditdialog.cpp \
    main.cpp \
    scene/devices/deviceabstract.cpp \
    scene/devices/pc.cpp \
    scene/devices/phone.cpp \
    scene/devices/printer.cpp \
    scene/devices/server.cpp \
    scene/planning/furnitureabstract.cpp \
    scene/planning/ladder.cpp \
    scene/planning/window.cpp \
    xml/filereader.cpp \
    scene/graphicsscene.cpp \
    scene/graphicsview.cpp \
    scene/planning/door.cpp \
    scene/planning/house.cpp \
    scene/planning/wall.cpp \
    widget.cpp \
    xml/xmlitemabstract.cpp

RESOURCES += \
    assets.qrc
