TEMPLATE = app
TARGET = patchwork-generator

CONFIG += c++11

QT += widgets gui printsupport

SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/patchworkview.cpp

HEADERS += include/mainwindow.h \
           include/patchworkview.h

INCLUDEPATH += include