#include "theoryscreen.h"
#include <QGridLayout>
#include <QQmlContext>

TheoryScreen::TheoryScreen(QWidget *parent) : QWidget(parent),
    quickWidget(new QQuickWidget(this))
{
    QGridLayout *layout(new QGridLayout(this));
    layout->setMargin(0);
    layout->addWidget(quickWidget, 0, 0, 1, 1);

    QQmlContext *context = quickWidget->rootContext();
    context->setContextProperty("TheoryScreen", this);

    quickWidget->setSource(QUrl("qrc:/Theory/FirstPage.qml"));
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}

TheoryScreen::~TheoryScreen()
{
    delete quickWidget;
}
