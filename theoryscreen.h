#ifndef THEORYSCREEN_H
#define THEORYSCREEN_H

#include <QWidget>
#include <QQuickWidget>


class TheoryScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TheoryScreen(QWidget *parent = 0);
    ~TheoryScreen();

signals:
    void to_menu();
public slots:

private:
    QQuickWidget* quickWidget;
};

#endif // THEORYSCREEN_H
