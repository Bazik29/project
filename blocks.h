#ifndef BLOCKS_H
#define BLOCKS_H

#include <QWidget>
#include <QPicture>
#include <QTCore>
#include <QtGUI>
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class Blocks;
}

class Blocks : public QWidget
{
    Q_OBJECT

public:
    explicit Blocks(QWidget *parent = 0);
    ~Blocks();
    void paintEvent(QPaintEvent *);
signals:
    void to_menu();
protected:
    void draw();
    void level1_start(int step);
    void level2_start(int step);
    void level3_start(int step);
    void level4_start(int step);
    void level5_start(int step);
    void level6_start(int step);
    void level7_start(int step);
    void level8_start(int step);
    void changepixmap(qreal x, qreal y, QPixmap change);
    void SwitchleftBinCount(int n);
    void SwitchrightBinCount(int n);
    void Endgame();
private:
    Ui::Blocks *ui;
    QGraphicsScene *scene;
    QGraphicsItem *player;
    QGraphicsItem *player2;
    QGraphicsItem *player3;
    QGraphicsItem *player4;
    QGraphicsItem *player5;
    QGraphicsItem *apple;
    bool appleex;
    bool apple2ex;
    bool apple3ex;
    bool apple4ex;
    bool apple5ex;
    bool apple6ex;
    QGraphicsItem *apple2;
    QGraphicsItem *apple3;
    QGraphicsItem *apple4;
    QGraphicsItem *apple5;
    QGraphicsItem *apple6;
    QGraphicsItem *bin;
    QGraphicsItem *bin2;
    QGraphicsItem *back;
    QGraphicsItem *statusbar;
    QGraphicsItem *minieg1;
    QGraphicsItem *minieg2;
    QGraphicsItem *minieg3;
    QGraphicsItem *minieg4;
    QGraphicsItem *minieg5;
    QGraphicsItem *Dialog;
    QTimer *timer;
    int bincount;
    int currentegik;
    int bin1count;
    int applenumber;
    int currentcount;
    int numberofegik;
    int numberofegik1;
    int numberofegik2;
    int numberofapples1;
    int numberofapples;
    int numberofcounts;
    int step;
    int level;
    int direction;
    int distance;
    bool withapple;
    bool finish;
    bool crying;
    bool failed;
    void set_levelFon();
    void set_subMenuFon();
private slots:
    void onTimer();
    void on_actionLevel1_clicked();
    void on_actionActionstart_triggered();
    void on_action_stop();
    void on_actionLevel2_clicked();
    void on_actionLevel3_clicked();
    void on_actionLevel4_clicked();
    void on_actionLevel5_clicked();
    void on_actionLevel6_clicked();
    void on_actionLevel7_clicked();
    void on_actionLevel8_clicked();
    void on_back_clicked();
    void on_back_small_clicked();
};

#endif // BLOCKS_H
