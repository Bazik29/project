#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont("Blocks/Adigiana_2.ttf");
    MainWindow w;
    w.show();

    return a.exec();
}
