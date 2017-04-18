#include "mainwindow.h"
#include <QGridLayout>

#include "mainmenu.h"
#include "theoryscreen.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    menuScreen(new MainMenu(this)),
    theoryScreen(new TheoryScreen(this))
{
    setWindowTitle("самое лучшее название для самой лучшей проги эвар");
    QGridLayout *layout(new QGridLayout(this));
    layout->setMargin(0);
    layout->addWidget(menuScreen, 0, 0, 1, 1);
    layout->addWidget(theoryScreen, 0, 0, 1, 1);

    connect(menuScreen, SIGNAL(to_theory()), SLOT(to_theory()));
    connect(theoryScreen, SIGNAL(to_menu()), SLOT(to_menu()));

    menuScreen->show();
    theoryScreen->hide();
}

MainWindow::~MainWindow()
{
    delete theoryScreen;
    delete menuScreen;
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
