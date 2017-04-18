#include "mainwindow.h"
#include <QGridLayout>

#include "mainmenu.h"
#include "theoryscreen.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    menuScreen(new MainMenu(this)),
    theoryScreen(new TheoryScreen(this))
{
    QGridLayout *layout(new QGridLayout(this));

    layout->addWidget(menuScreen, 0, 0, 1, 1);
    layout->addWidget(theoryScreen, 0, 0, 1, 1);

    connect(menuScreen, SIGNAL(to_theory()), SLOT(to_theory()));
    connect(theoryScreen, SIGNAL(to_menu()), SLOT(to_menu()));

    menuScreen->show();
    theoryScreen->hide();
}

void MainWindow::to_menu()
{
    theoryScreen->hide();
    menuScreen->show();
}

void MainWindow::to_theory()
{
    menuScreen->hide();
    theoryScreen->show();
}
