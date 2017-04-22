#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T15:29:51
#
#-------------------------------------------------

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    mainwindow.cpp \
    mainmenu.cpp \
    theoryscreen.cpp \
    blocks.cpp

HEADERS  += \
    mainwindow.h \
    mainmenu.h \
    theoryscreen.h \
    blocks.h

FORMS    += mainmenu.ui \
    blocks.ui

RESOURCES +=

DISTFILES += \
    Theory/images/9.3.PNG \
    Theory/images/9.4.PNG \
    Theory/images/p3.png \
    Theory/images/p5.png \
    Theory/images/p6.1.png \
    Theory/images/p6.2.PNG \
    Theory/images/p6.3.png \
    Theory/images/p6.4.PNG \
    Theory/images/p7.png \
    Theory/images/p9.1.PNG \
    Theory/images/p9.2.PNG \
    Theory/CustButton.qml \
    Theory/MainPage.qml \
    Theory/Page1.qml \
    Theory/Page10.qml \
    Theory/Page11.qml \
    Theory/Page2.qml \
    Theory/Page3.qml \
    Theory/Page4.qml \
    Theory/Page5.qml \
    Theory/Page6.qml \
    Theory/Page7.qml \
    Theory/Page8.qml \
    Theory/Page9.qml
