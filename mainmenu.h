#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>


namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
signals:
    void to_theory();
    void to_block();
    void to_code();
private slots:
    void on_TheoryButton_clicked();
    void on_BlockButton_clicked();
    void on_CodeButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
