#include "mainwindow.h"
#include <QGridLayout>

#include "mainmenu.h"
#include "theoryscreen.h"
#include "blocks.h"
#include "pseudocode.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    menuScreen(new MainMenu(this)),
    theoryScreen(new TheoryScreen(this)),
    blockScreen(new Blocks(this)),
    codeScreen(new PseudoCode(this))
{
    setWindowTitle("Click&Learn");

    setMinimumSize(1280, 720);
    setMaximumSize(1280, 720);
    QGridLayout *layout(new QGridLayout(this));
    layout->setMargin(0);
    layout->addWidget(menuScreen, 0, 0, 1, 1);
    layout->addWidget(theoryScreen, 0, 0, 1, 1);
    layout->addWidget(blockScreen, 0, 0, 1, 1);
    layout->addWidget(codeScreen, 0, 0, 1, 1);


    connect(menuScreen, SIGNAL(to_theory()), SLOT(show_theory()));
    connect(menuScreen, SIGNAL(to_block()), SLOT(show_block()));
    connect(menuScreen, SIGNAL(to_code()), SLOT(show_code()));

    connect(theoryScreen, SIGNAL(to_menu()), SLOT(show_menu()));
    connect(blockScreen, SIGNAL(to_menu()), SLOT(show_menu()));
    connect(codeScreen, SIGNAL(to_menu()), SLOT(show_menu()));

    show_menu();
}

MainWindow::~MainWindow()
{
    delete menuScreen;
    delete theoryScreen;
    delete blockScreen;
    delete codeScreen;
}

void MainWindow::show_menu()
{
    theoryScreen->hide();
    blockScreen->hide();
    codeScreen->hide();
    menuScreen->show();
}

void MainWindow::show_theory()
{
    menuScreen->hide();
    blockScreen->hide();
    codeScreen->hide();
    theoryScreen->show();
}

void MainWindow::show_block()
{
    menuScreen->hide();
    codeScreen->hide();
    theoryScreen->hide();
    blockScreen->show();
}

void MainWindow::show_code()
{
    menuScreen->hide();
    theoryScreen->hide();
    blockScreen->hide();
    codeScreen->show();
}
