/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *BlockButton;
    QPushButton *CodeButton;
    QPushButton *TheoryButton;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(1280, 720);
        MainMenu->setMinimumSize(QSize(0, 0));
        MainMenu->setMaximumSize(QSize(1280, 720));
        MainMenu->setStyleSheet(QLatin1String("background-image:  url(MainMenu/background.png);\n"
""));
        BlockButton = new QPushButton(MainMenu);
        BlockButton->setObjectName(QStringLiteral("BlockButton"));
        BlockButton->setGeometry(QRect(498, 360, 284, 132));
        BlockButton->setMinimumSize(QSize(0, 40));
        BlockButton->setStyleSheet(QLatin1String("#BlockButton{\n"
"    border: none;\n"
"    background-image: url(MainMenu/bs_normal.png);\n"
"}\n"
"\n"
"#BlockButton:hover{\n"
"     background-image: url(MainMenu/bs_hover.png);\n"
"}\n"
" \n"
"#BlockButton:pressed {\n"
"    background-image: url(MainMenu/bs_clicked.png);\n"
"}"));
        CodeButton = new QPushButton(MainMenu);
        CodeButton->setObjectName(QStringLiteral("CodeButton"));
        CodeButton->setGeometry(QRect(786, 360, 284, 132));
        CodeButton->setMinimumSize(QSize(0, 40));
        CodeButton->setStyleSheet(QLatin1String("#CodeButton{\n"
"    border: none;\n"
"    background-image: url(MainMenu/ps_normal.png);\n"
"}\n"
"\n"
"#CodeButton:hover{\n"
"     background-image: url(MainMenu/ps_hover.png);\n"
"}\n"
" \n"
"#CodeButton:pressed {\n"
"    background-image: url(MainMenu/ps_clicked.png);\n"
"}"));
        TheoryButton = new QPushButton(MainMenu);
        TheoryButton->setObjectName(QStringLiteral("TheoryButton"));
        TheoryButton->setGeometry(QRect(210, 360, 284, 132));
        TheoryButton->setMinimumSize(QSize(0, 40));
        TheoryButton->setBaseSize(QSize(0, 0));
        TheoryButton->setStyleSheet(QLatin1String("#TheoryButton{\n"
"    border: none;\n"
"    background-image: url(MainMenu/th_normal.png);\n"
"}\n"
"\n"
"#TheoryButton:hover{\n"
"     background-image: url(MainMenu/th_hover.png);\n"
"}\n"
" \n"
"#TheoryButton:pressed {\n"
"    background-image: url(MainMenu/th_clicked.png);\n"
"}"));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QString());
        BlockButton->setText(QString());
        CodeButton->setText(QString());
        TheoryButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
