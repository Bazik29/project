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
    void setPage(int index);
    int getPage();
    void resetProgress();
private:
    QQuickWidget *quickWidget;
    int page = 0;
    const QString FileName = "pageTheory";
    void loadFromFile();
    void writeToFile(int num);
};


#endif // THEORYSCREEN_H
