QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += serialport

RC_FILE += icon_config.rc

LIBS += -Ldll -lws2_32

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libmodbus/modbus-data.c \
    libmodbus/modbus-rtu.c \
    libmodbus/modbus-tcp.c \
    libmodbus/modbus.c \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    libmodbus/config.h \
    libmodbus/modbus-private.h \
    libmodbus/modbus-rtu-private.h \
    libmodbus/modbus-rtu.h \
    libmodbus/modbus-tcp-private.h \
    libmodbus/modbus-tcp.h \
    libmodbus/modbus-version.h \
    libmodbus/modbus.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    QtResource.qrc

DISTFILES += \
    icon_config.rc
