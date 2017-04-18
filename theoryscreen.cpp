#include "theoryscreen.h"
#include <QGridLayout>

TheoryScreen::TheoryScreen(QWidget *parent) : QWidget(parent),
    quickWidget(new QQuickWidget(this))
{
     QGridLayout *layout(new QGridLayout(this));
     layout->addWidget(quickWidget, 0, 0, 1, 1);
     //quickWidget->setco
     quickWidget->setSource(QUrl("qrc:/Theory/FirstPage.qml"));
     quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
}
