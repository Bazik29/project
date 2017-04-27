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
    Theory/Page9.qml \
    Interface/back_clicked.png \
    Interface/back_hover.png \
    Interface/back_normal.png \
    Interface/background.png \
    Interface/bs_clicked.png \
    Interface/bs_hover.png \
    Interface/bs_normal.png \
    Interface/check_checked.png \
    Interface/check_unchecked.png \
    Interface/indic_1.png \
    Interface/indic_1_current.png \
    Interface/indic_1_future.png \
    Interface/indic_2.png \
    Interface/indic_2_current.png \
    Interface/indic_2_future.png \
    Interface/menu_clicked.png \
    Interface/menu_hover.png \
    Interface/menu_normal.png \
    Interface/next_clicked.png \
    Interface/next_hover.png \
    Interface/next_normal.png \
    Interface/ps_clicked.png \
    Interface/ps_hover.png \
    Interface/ps_normal.png \
    Interface/radio_empty.png \
    Interface/radio_full.png \
    Interface/retry_clicked.png \
    Interface/retry_hover.png \
    Interface/retry_normal.png \
    Interface/th_clicked.png \
    Interface/th_hover.png \
    Interface/th_normal.png \
    Interface/wrong_answer.png \
    Interface/backg_s.psd \
    MainMenu/background.png \
    MainMenu/bs_clicked.png \
    MainMenu/bs_hover.png \
    MainMenu/bs_normal.png \
    MainMenu/next_hover.png \
    MainMenu/next_normal.png \
    MainMenu/ps_clicked.png \
    MainMenu/ps_hover.png \
    MainMenu/ps_normal.png \
    MainMenu/th_clicked.png \
    MainMenu/th_hover.png \
    MainMenu/th_normal.png \
    Theory/controls/back_clicked.png \
    Theory/controls/back_hover.png \
    Theory/controls/back_normal.png \
    Theory/controls/check_checked.png \
    Theory/controls/check_unchecked.png \
    Theory/controls/indic_1.png \
    Theory/controls/indic_1_current.png \
    Theory/controls/indic_1_future.png \
    Theory/controls/indic_2.png \
    Theory/controls/indic_2_current.png \
    Theory/controls/indic_2_future.png \
    Theory/controls/menu_clicked.png \
    Theory/controls/menu_hover.png \
    Theory/controls/menu_normal.png \
    Theory/controls/next_clicked.png \
    Theory/controls/next_hover.png \
    Theory/controls/next_normal.png \
    Theory/controls/radio_empty.png \
    Theory/controls/radio_full.png \
    Theory/controls/retry_clicked.png \
    Theory/controls/retry_hover.png \
    Theory/controls/retry_normal.png \
    Theory/controls/wrong_answer.png \
    Theory/TCheckBox.qml \
    Theory/TRadioGroup.qml \
    Theory/TRadioButton.qml \
    Theory/TFrameBackgroung.qml \
    Blocks/Adigiana_2.ttf \
    Blocks/buttons/back_clicked.png \
    Blocks/buttons/back_hover.png \
    Blocks/buttons/back_normal.png \
    Blocks/buttons/back_small_clicked.png \
    Blocks/buttons/back_small_hover.png \
    Blocks/buttons/back_small_normal.png \
    Blocks/buttons/CL_clicked.png \
    Blocks/buttons/CL_hover.png \
    Blocks/buttons/CL_normal.png \
    Blocks/buttons/level1_clicked.png \
    Blocks/buttons/level1_hover.png \
    Blocks/buttons/level1_normal.png \
    Blocks/buttons/level2_clicked.png \
    Blocks/buttons/level2_hover.png \
    Blocks/buttons/level2_normal.png \
    Blocks/buttons/level3_clicked.png \
    Blocks/buttons/level3_hover.png \
    Blocks/buttons/level3_normal.png \
    Blocks/buttons/level4_clicked.png \
    Blocks/buttons/level4_hover.png \
    Blocks/buttons/level4_normal.png \
    Blocks/buttons/level5_clicked.png \
    Blocks/buttons/level5_hover.png \
    Blocks/buttons/level5_normal.png \
    Blocks/buttons/level6_clicked.png \
    Blocks/buttons/level6_hover.png \
    Blocks/buttons/level6_normal.png \
    Blocks/buttons/level7_clicked.png \
    Blocks/buttons/level7_hover.png \
    Blocks/buttons/level7_normal.png \
    Blocks/buttons/level8_clicked.png \
    Blocks/buttons/level8_hover.png \
    Blocks/buttons/level8_normal.png \
    Blocks/buttons/restart_clicked.png \
    Blocks/buttons/restart_hover.png \
    Blocks/buttons/restart_normal.png \
    Blocks/buttons/start_clicked.png \
    Blocks/buttons/start_hover.png \
    Blocks/buttons/start_normal.png \
    Blocks/buttons/stop_clicked.png \
    Blocks/buttons/stop_hover.png \
    Blocks/buttons/stop_normal.png \
    Blocks/apple.png \
    Blocks/back_level.png \
    Blocks/back_submenu.png \
    Blocks/back_with.png \
    Blocks/back_with_reverse.png \
    Blocks/back_without.png \
    Blocks/back_without_reverse.png \
    Blocks/bin_empty.png \
    Blocks/bin_full.png \
    Blocks/bin_fullover.png \
    Blocks/bin_middle.png \
    Blocks/change_level.png \
    Blocks/crying_with.png \
    Blocks/crying_without.png \
    Blocks/egik_mini.png \
    Blocks/egik_mini_cry.png \
    Blocks/egik_mini_failed.png \
    Blocks/egik_mini_success.png \
    Blocks/failed.png \
    Blocks/front_with.png \
    Blocks/front_with_reverse.png \
    Blocks/front_without.png \
    Blocks/front_without_reverse.png \
    Blocks/left_with.png \
    Blocks/left_with_reverse.png \
    Blocks/left_without.png \
    Blocks/left_without_reverse.png \
    Blocks/level1_back.png \
    Blocks/level2_back.png \
    Blocks/level3_back.png \
    Blocks/level4_back.png \
    Blocks/level5_back.png \
    Blocks/level6_back.png \
    Blocks/level7_back.png \
    Blocks/level8_back.png \
    Blocks/right_with.png \
    Blocks/right_with_reverse.png \
    Blocks/right_without.png \
    Blocks/right_without_reverse.png \
    Blocks/status_bar.png \
    Blocks/Win.png \
    Theory/controls/clear_clicked.png \
    Theory/controls/clear_hover.png \
    Theory/controls/clear_normal.png \
    myapp.rc

RC_FILE = myapp.rc
