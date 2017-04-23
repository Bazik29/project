/********************************************************************************
** Form generated from reading UI file 'blocks.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKS_H
#define UI_BLOCKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Blocks
{
public:
    QAction *actionLevel1;
    QAction *start_2;
    QAction *level2;
    QGraphicsView *graphicsView;
    QPushButton *level_1;
    QPushButton *level_2;
    QPushButton *level_3;
    QPushButton *level_4;
    QPushButton *level_5;
    QPushButton *level_6;
    QPushButton *level_7;
    QPushButton *level_8;
    QPushButton *back;
    QPushButton *start;
    QLineEdit *Level2_edit;
    QLineEdit *Level3_edit_1;
    QLineEdit *Level3_edit_2;
    QLineEdit *Level3_edit_3;
    QLineEdit *Level4_edit_1;
    QLineEdit *Level4_edit_2;
    QLineEdit *Level5_edit_1;
    QLineEdit *Level5_edit_2;
    QLineEdit *inter_edit_3;
    QLineEdit *inter_edit_2;
    QLineEdit *inter_edit_1;
    QPushButton *back_small;
    QPushButton *retry;
    QPushButton *CL;
    QPushButton *stop;

    void setupUi(QWidget *Blocks)
    {
        if (Blocks->objectName().isEmpty())
            Blocks->setObjectName(QStringLiteral("Blocks"));
        Blocks->setEnabled(true);
        Blocks->resize(1280, 720);
        Blocks->setMinimumSize(QSize(1280, 720));
        Blocks->setMaximumSize(QSize(1280, 720));
        Blocks->setAutoFillBackground(false);
        Blocks->setStyleSheet(QStringLiteral(""));
        actionLevel1 = new QAction(Blocks);
        actionLevel1->setObjectName(QStringLiteral("actionLevel1"));
        start_2 = new QAction(Blocks);
        start_2->setObjectName(QStringLiteral("start_2"));
        level2 = new QAction(Blocks);
        level2->setObjectName(QStringLiteral("level2"));
        graphicsView = new QGraphicsView(Blocks);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 30, 1261, 661));
        graphicsView->setStyleSheet(QStringLiteral("#graphicsView { border-style: none; }"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setInteractive(true);
        level_1 = new QPushButton(Blocks);
        level_1->setObjectName(QStringLiteral("level_1"));
        level_1->setGeometry(QRect(55, 304, 284, 132));
        level_1->setStyleSheet(QLatin1String("#level_1 {\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level1_normal.png);\n"
"}\n"
"\n"
"#level_1:hover{\n"
"     background-image: url(Blocks/buttons/level1_hover.png);\n"
"}\n"
" \n"
"#level_1:pressed {\n"
"    background-image: url(Blocks/buttons/level1_clicked.png);\n"
"}"));
        level_2 = new QPushButton(Blocks);
        level_2->setObjectName(QStringLiteral("level_2"));
        level_2->setGeometry(QRect(345, 304, 284, 132));
        level_2->setStyleSheet(QLatin1String("#level_2{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level2_normal.png);\n"
"}\n"
"\n"
"#level_2:hover{\n"
"     background-image: url(Blocks/buttons/level2_hover.png);\n"
"}\n"
" \n"
"#level_2:pressed {\n"
"    background-image: url(Blocks/buttons/level2_clicked.png);\n"
"}"));
        level_3 = new QPushButton(Blocks);
        level_3->setObjectName(QStringLiteral("level_3"));
        level_3->setGeometry(QRect(674, 304, 284, 132));
        level_3->setStyleSheet(QLatin1String("#level_3{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level3_normal.png);\n"
"}\n"
"\n"
"#level_3:hover{\n"
"     background-image: url(Blocks/buttons/level3_hover.png);\n"
"}\n"
" \n"
"#level_3:pressed {\n"
"    background-image: url(Blocks/buttons/level3_clicked.png);\n"
"}"));
        level_4 = new QPushButton(Blocks);
        level_4->setObjectName(QStringLiteral("level_4"));
        level_4->setGeometry(QRect(965, 304, 284, 132));
        level_4->setStyleSheet(QLatin1String("#level_4{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level4_normal.png);\n"
"}\n"
"\n"
"#level_4:hover{\n"
"     background-image: url(Blocks/buttons/level4_hover.png);\n"
"}\n"
" \n"
"#level_4:pressed {\n"
"    background-image: url(Blocks/buttons/level4_clicked.png);\n"
"}"));
        level_5 = new QPushButton(Blocks);
        level_5->setObjectName(QStringLiteral("level_5"));
        level_5->setGeometry(QRect(55, 441, 284, 132));
        level_5->setStyleSheet(QLatin1String("#level_5{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level5_normal.png);\n"
"}\n"
"\n"
"#level_5:hover{\n"
"     background-image: url(Blocks/buttons/level5_hover.png);\n"
"}\n"
" \n"
"#level_5:pressed {\n"
"    background-image: url(Blocks/buttons/level5_clicked.png);\n"
"}"));
        level_6 = new QPushButton(Blocks);
        level_6->setObjectName(QStringLiteral("level_6"));
        level_6->setGeometry(QRect(345, 441, 284, 132));
        level_6->setStyleSheet(QLatin1String("#level_6{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level6_normal.png);\n"
"}\n"
"\n"
"#level_6:hover{\n"
"     background-image: url(Blocks/buttons/level6_hover.png);\n"
"}\n"
" \n"
"#level_6:pressed {\n"
"    background-image: url(Blocks/buttons/level6_clicked.png);\n"
"}"));
        level_7 = new QPushButton(Blocks);
        level_7->setObjectName(QStringLiteral("level_7"));
        level_7->setGeometry(QRect(674, 441, 284, 132));
        level_7->setStyleSheet(QLatin1String("#level_7{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level7_normal.png);\n"
"}\n"
"\n"
"#level_7:hover{\n"
"     background-image: url(Blocks/buttons/level7_hover.png);\n"
"}\n"
" \n"
"#level_7:pressed {\n"
"    background-image: url(Blocks/buttons/level7_clicked.png);\n"
"}"));
        level_8 = new QPushButton(Blocks);
        level_8->setObjectName(QStringLiteral("level_8"));
        level_8->setGeometry(QRect(964, 441, 284, 132));
        level_8->setStyleSheet(QLatin1String("#level_8{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/level8_normal.png);\n"
"}\n"
"\n"
"#level_8:hover{\n"
"     background-image: url(Blocks/buttons/level8_hover.png);\n"
"}\n"
" \n"
"#level_8:pressed {\n"
"    background-image: url(Blocks/buttons/level8_clicked.png);\n"
"}"));
        back = new QPushButton(Blocks);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(42, 602, 178, 83));
        back->setStyleSheet(QLatin1String("#back{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/back_normal.png);\n"
"}\n"
"\n"
"#back:hover{\n"
"     background-image: url(Blocks/buttons/back_hover.png);\n"
"}\n"
" \n"
"#back:pressed {\n"
"    background-image: url(Blocks/buttons/back_clicked.png);\n"
"}"));
        start = new QPushButton(Blocks);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(1083, 602, 178, 83));
        start->setStyleSheet(QLatin1String("#start{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/start_normal.png);\n"
"}\n"
"\n"
"#start:hover{\n"
"     background-image: url(Blocks/buttons/start_hover.png);\n"
"}\n"
" \n"
"#start:pressed {\n"
"    background-image: url(Blocks/buttons/start_clicked.png);\n"
"}"));
        Level2_edit = new QLineEdit(Blocks);
        Level2_edit->setObjectName(QStringLiteral("Level2_edit"));
        Level2_edit->setGeometry(QRect(658, 301, 41, 41));
        Level2_edit->setCursor(QCursor(Qt::IBeamCursor));
        Level2_edit->setFocusPolicy(Qt::StrongFocus);
        Level2_edit->setStyleSheet(QLatin1String("#Level2_edit { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3);\n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level3_edit_1 = new QLineEdit(Blocks);
        Level3_edit_1->setObjectName(QStringLiteral("Level3_edit_1"));
        Level3_edit_1->setGeometry(QRect(670, 196, 41, 41));
        QFont font;
        font.setFamily(QStringLiteral("Adigiana 2"));
        Level3_edit_1->setFont(font);
        Level3_edit_1->setCursor(QCursor(Qt::IBeamCursor));
        Level3_edit_1->setStyleSheet(QLatin1String("#Level3_edit_1 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level3_edit_2 = new QLineEdit(Blocks);
        Level3_edit_2->setObjectName(QStringLiteral("Level3_edit_2"));
        Level3_edit_2->setGeometry(QRect(918, 264, 41, 41));
        Level3_edit_2->setFont(font);
        Level3_edit_2->setCursor(QCursor(Qt::IBeamCursor));
        Level3_edit_2->setStyleSheet(QLatin1String("#Level3_edit_2 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level3_edit_3 = new QLineEdit(Blocks);
        Level3_edit_3->setObjectName(QStringLiteral("Level3_edit_3"));
        Level3_edit_3->setGeometry(QRect(406, 462, 41, 41));
        Level3_edit_3->setFont(font);
        Level3_edit_3->setCursor(QCursor(Qt::IBeamCursor));
        Level3_edit_3->setStyleSheet(QLatin1String("#Level3_edit_3 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level4_edit_1 = new QLineEdit(Blocks);
        Level4_edit_1->setObjectName(QStringLiteral("Level4_edit_1"));
        Level4_edit_1->setGeometry(QRect(869, 249, 41, 41));
        Level4_edit_1->setFont(font);
        Level4_edit_1->setCursor(QCursor(Qt::IBeamCursor));
        Level4_edit_1->setStyleSheet(QLatin1String("#Level4_edit_1 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level4_edit_2 = new QLineEdit(Blocks);
        Level4_edit_2->setObjectName(QStringLiteral("Level4_edit_2"));
        Level4_edit_2->setGeometry(QRect(557, 344, 41, 41));
        Level4_edit_2->setFont(font);
        Level4_edit_2->setCursor(QCursor(Qt::IBeamCursor));
        Level4_edit_2->setStyleSheet(QLatin1String("#Level4_edit_2 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level5_edit_1 = new QLineEdit(Blocks);
        Level5_edit_1->setObjectName(QStringLiteral("Level5_edit_1"));
        Level5_edit_1->setGeometry(QRect(654, 234, 41, 41));
        Level5_edit_1->setFont(font);
        Level5_edit_1->setCursor(QCursor(Qt::IBeamCursor));
        Level5_edit_1->setStyleSheet(QLatin1String("#Level5_edit_1 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        Level5_edit_2 = new QLineEdit(Blocks);
        Level5_edit_2->setObjectName(QStringLiteral("Level5_edit_2"));
        Level5_edit_2->setGeometry(QRect(910, 334, 41, 41));
        Level5_edit_2->setFont(font);
        Level5_edit_2->setCursor(QCursor(Qt::IBeamCursor));
        Level5_edit_2->setStyleSheet(QLatin1String("#Level5_edit_2 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        inter_edit_3 = new QLineEdit(Blocks);
        inter_edit_3->setObjectName(QStringLiteral("inter_edit_3"));
        inter_edit_3->setGeometry(QRect(932, 317, 41, 41));
        inter_edit_3->setFont(font);
        inter_edit_3->setCursor(QCursor(Qt::IBeamCursor));
        inter_edit_3->setStyleSheet(QLatin1String("#inter_edit_3 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        inter_edit_2 = new QLineEdit(Blocks);
        inter_edit_2->setObjectName(QStringLiteral("inter_edit_2"));
        inter_edit_2->setGeometry(QRect(396, 317, 41, 41));
        inter_edit_2->setFont(font);
        inter_edit_2->setCursor(QCursor(Qt::IBeamCursor));
        inter_edit_2->setStyleSheet(QLatin1String("#inter_edit_2 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        inter_edit_1 = new QLineEdit(Blocks);
        inter_edit_1->setObjectName(QStringLiteral("inter_edit_1"));
        inter_edit_1->setGeometry(QRect(658, 218, 41, 41));
        inter_edit_1->setFont(font);
        inter_edit_1->setCursor(QCursor(Qt::IBeamCursor));
        inter_edit_1->setStyleSheet(QLatin1String("#inter_edit_1 { \n"
"border: none; \n"
"background-color: rgba(255, 255, 255, 0%); \n"
"color:rgb(17,51,3); \n"
"font-family: Adigiana 2 ; \n"
"font-size: 50px;\n"
"}"));
        back_small = new QPushButton(Blocks);
        back_small->setObjectName(QStringLiteral("back_small"));
        back_small->setGeometry(QRect(566, 591, 178, 83));
        back_small->setStyleSheet(QLatin1String("#back_small {\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/back_normal.png);\n"
"}\n"
"\n"
"#back_small:hover{\n"
"     background-image: url(Blocks/buttons/back_hover.png);\n"
"}\n"
" \n"
"#back_small:pressed {\n"
"    background-image: url(Blocks/buttons/back_clicked.png);\n"
"}"));
        retry = new QPushButton(Blocks);
        retry->setObjectName(QStringLiteral("retry"));
        retry->setGeometry(QRect(348, 395, 284, 132));
        retry->setStyleSheet(QLatin1String("#retry{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/restart_normal.png);\n"
"}\n"
"\n"
"#retry:hover{\n"
"     background-image: url(Blocks/buttons/restart_hover.png);\n"
"}\n"
" \n"
"#retry:pressed {\n"
"    background-image: url(Blocks/buttons/restart_clicked.png);\n"
"}"));
        CL = new QPushButton(Blocks);
        CL->setObjectName(QStringLiteral("CL"));
        CL->setGeometry(QRect(668, 395, 284, 132));
        CL->setStyleSheet(QLatin1String("#CL{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/CL_normal.png);\n"
"}\n"
"\n"
"#CL:hover{\n"
"     background-image: url(Blocks/buttons/CL_hover.png);\n"
"}\n"
" \n"
"#CL:pressed {\n"
"    background-image: url(Blocks/buttons/CL_clicked.png);\n"
"}"));
        stop = new QPushButton(Blocks);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(1083, 602, 178, 83));
        stop->setStyleSheet(QLatin1String("#stop{\n"
"    border: none;\n"
"    background-image: url(Blocks/buttons/stop_normal.png);\n"
"}\n"
"\n"
"#stop:hover{\n"
"     background-image: url(Blocks/buttons/stop_hover.png);\n"
"}\n"
" \n"
"#stop:pressed {\n"
"    background-image: url(Blocks/buttons/stop_clicked.png);\n"
"}"));

        retranslateUi(Blocks);

        QMetaObject::connectSlotsByName(Blocks);
    } // setupUi

    void retranslateUi(QWidget *Blocks)
    {
        actionLevel1->setText(QApplication::translate("Blocks", "level1", Q_NULLPTR));
        start_2->setText(QApplication::translate("Blocks", "actionstart", Q_NULLPTR));
        level2->setText(QApplication::translate("Blocks", "level2", Q_NULLPTR));
        level_1->setText(QString());
        level_2->setText(QString());
        level_3->setText(QString());
        level_4->setText(QString());
        level_5->setText(QString());
        level_6->setText(QString());
        level_7->setText(QString());
        level_8->setText(QString());
        back->setText(QString());
        start->setText(QString());
        Level2_edit->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level3_edit_1->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level3_edit_2->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level3_edit_3->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level4_edit_1->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level4_edit_2->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level5_edit_1->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        Level5_edit_2->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        inter_edit_3->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        inter_edit_2->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        inter_edit_1->setText(QApplication::translate("Blocks", "0", Q_NULLPTR));
        back_small->setText(QString());
        retry->setText(QString());
        CL->setText(QString());
        stop->setText(QString());
        Q_UNUSED(Blocks);
    } // retranslateUi

};

namespace Ui {
    class Blocks: public Ui_Blocks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKS_H
