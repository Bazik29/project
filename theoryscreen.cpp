#include "theoryscreen.h"
#include <QGridLayout>
#include <QQmlContext>
#include <QQmlProperty>
#include <QFile>

TheoryScreen::TheoryScreen(QWidget *parent) : QWidget(parent),
    quickWidget(new QQuickWidget(this))
{
    loadFromFile();
    QGridLayout *layout(new QGridLayout(this));
    layout->setMargin(0);
    layout->addWidget(quickWidget, 0, 0, 1, 1);

    QQmlContext *context = quickWidget->rootContext();
    context->setContextProperty("TheoryScreen", this);

    quickWidget->setSource(QUrl("qrc:/Theory/MainPage.qml"));
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

TheoryScreen::~TheoryScreen()
{
    writeToFile(page);
    delete quickWidget;
}

void TheoryScreen::setPage(int index)
{
    page = index;
}

int TheoryScreen::getPage()
{
    return page;
}

void TheoryScreen::loadFromFile()
{
    QFile fileIn(FileName);
    if (fileIn.open(QIODevice::ReadOnly)) {
        QTextStream readStream(&fileIn);
        readStream >> page;
        fileIn.close();
    }
    else page = 0;
}

void TheoryScreen::writeToFile(int num)
{
    QFile fileOut(FileName);
    if (fileOut.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream writeStream(&fileOut);
        writeStream << num;
        fileOut.close();
    }
}

void TheoryScreen::resetProgress()
{
    page = 0;
    writeToFile(page);
}
