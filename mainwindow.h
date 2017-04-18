#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class TheoryScreen;
class MainMenu;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:
    void to_menu();
    void to_theory();
    //void to_block();
    //void to_code();
private:
    MainMenu *menuScreen = 0;
    TheoryScreen *theoryScreen = 0;
};

#endif // MAINWINDOW_H
