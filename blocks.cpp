#include "blocks.h"
#include "ui_blocks.h"

Blocks::Blocks(QWidget *parent) : QWidget(parent),
    ui(new Ui::Blocks)
{
    ui->setupUi(this);
    set_subMenuFon();
    ui->back->setVisible(false);
    ui->start->setVisible(false);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QPixmap background(QApplication::applicationDirPath()+"/Blocks/change_level.png");
    back = scene->addPixmap(background);
    connect(ui->level_1,SIGNAL(clicked()),this,SLOT(on_actionLevel1_clicked()));
    connect(ui->level_2,SIGNAL(clicked()),this,SLOT(on_actionLevel2_clicked()));
    connect(ui->level_3,SIGNAL(clicked()),this,SLOT(on_actionLevel3_clicked()));
    connect(ui->level_4,SIGNAL(clicked()),this,SLOT(on_actionLevel4_clicked()));
    connect(ui->level_5,SIGNAL(clicked()),this,SLOT(on_actionLevel5_clicked()));
    connect(ui->level_6,SIGNAL(clicked()),this,SLOT(on_actionLevel6_clicked()));
    connect(ui->level_7,SIGNAL(clicked()),this,SLOT(on_actionLevel7_clicked()));
    connect(ui->level_8,SIGNAL(clicked()),this,SLOT(on_actionLevel8_clicked()));
    connect(ui->back,SIGNAL(clicked()),this,SLOT(on_back_clicked()));
    connect(ui->CL,SIGNAL(clicked()),this,SLOT(on_back_clicked()));
    connect(ui->stop,SIGNAL(clicked()),this,SLOT(on_action_stop()));
    connect(ui->retry,SIGNAL(clicked()),this,SLOT(on_action_stop()));
    connect(ui->start,SIGNAL(clicked()),this,SLOT(on_actionActionstart_triggered()));
    ui->Level2_edit->setVisible(false);
    ui->Level3_edit_1->setVisible(false);
    ui->Level3_edit_2->setVisible(false);
    ui->Level3_edit_3->setVisible(false);
    ui->Level4_edit_1->setVisible(false);
    ui->Level4_edit_2->setVisible(false);
    ui->Level5_edit_1->setVisible(false);
    ui->Level5_edit_2->setVisible(false);
    ui->inter_edit_1->setVisible(false);
    ui->inter_edit_2->setVisible(false);
    ui->inter_edit_3->setVisible(false);
    ui->retry->setVisible(false);
    ui->stop->setVisible(false);
    ui->CL->setVisible(false);
    timer = new QTimer();
    failed = false;
}
void Blocks::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void Blocks::Endgame(){
    ui->Level2_edit->setVisible(false);
    ui->Level3_edit_1->setVisible(false);
    ui->Level3_edit_2->setVisible(false);
    ui->Level3_edit_3->setVisible(false);
    ui->Level4_edit_1->setVisible(false);
    ui->Level4_edit_2->setVisible(false);
    ui->Level5_edit_1->setVisible(false);
    ui->Level5_edit_2->setVisible(false);
    ui->inter_edit_1->setVisible(false);
    ui->inter_edit_2->setVisible(false);
    ui->inter_edit_3->setVisible(false);
    ui->retry->setVisible(true);
    ui->CL->setVisible(true);
    ui->start->setVisible(false);
    ui->stop->setVisible(false);
    ui->back->setVisible(false);
    if (failed){
        QPixmap lose(QApplication::applicationDirPath()+"/Blocks/failed.png");
        Dialog = scene->addPixmap(lose);
        Dialog->setPos(311,151);
    } else {
        QPixmap win(QApplication::applicationDirPath()+"/Blocks/Win.png");
        Dialog = scene->addPixmap(win);
        Dialog->setPos(311,151);
    }
}

void Blocks::onTimer(){
    switch (direction){
        case 1: {player->moveBy(-1,0);
        if ((int)player->pos().rx() % 2 == 0){
            if (withapple){
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_with.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            else {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            } else {
                if (withapple){
                QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_with_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                } else {
                 QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_without_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                }
            }
        if (player->pos().rx()<distance){
            timer->stop();
            step+=1;
            switch (level){
            case 1: level1_start(step); break;
            case 2: level2_start(step); break;
            case 3: level3_start(step); break;
            case 4: level4_start(step); break;
            case 5: level5_start(step); break;
            case 6: level6_start(step); break;
            case 7: level7_start(step); break;
            case 8: level8_start(step); break;
            }
        }}  break;
    case 2: {
            player->moveBy(1,0);
            if ((int)player->pos().rx() % 2 == 0){
                if (withapple){
                QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_with.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                }
                else {
                QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                }
                } else {
                    if (withapple){
                    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_with_reverse.png");
                    changepixmap(player->pos().rx(),player->pos().ry(),egik);
                    } else {
                     QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without_reverse.png");
                    changepixmap(player->pos().rx(),player->pos().ry(),egik);
                    }
                }
            if (player->pos().rx()==distance){
                timer->stop();
                step+=1;
                switch (level){
                case 1: level1_start(step); break;
                case 2: level2_start(step); break;
                case 3: level3_start(step); break;
                case 4: level4_start(step); break;
                case 5: level5_start(step); break;
                case 6: level6_start(step); break;
                case 7: level7_start(step); break;
                case 8: level8_start(step); break;
                }
            }
    }  break;
        case 3: {player->moveBy(0,-1);
        if ((int)player->pos().ry() % 2 == 0){
            if (withapple){
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/back_with.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            else {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/back_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            } else {
                if (withapple){
                QPixmap egik(QApplication::applicationDirPath()+"/Blocks/back_with_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                } else {
                 QPixmap egik(QApplication::applicationDirPath()+"/Blocks/back_without_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                }
            }
            if (player->pos().ry()<distance){
                timer->stop();
                step+=1;
                switch (level){
                case 1: level1_start(step); break;
                case 2: level2_start(step); break;
                case 3: level3_start(step); break;
                case 4: level4_start(step); break;
                case 5: level5_start(step); break;
                case 6: level6_start(step); break;
                case 7: level7_start(step); break;
                case 8: level8_start(step); break;
                }
            }}  break;
        case 4: {player->moveBy(0,1);
        if ((int)player->pos().ry() % 2 == 0){
            if (withapple){
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_with.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            else {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            }
            } else {
                if (withapple){
                QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_with_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                } else {
                 QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without_reverse.png");
                changepixmap(player->pos().rx(),player->pos().ry(),egik);
                }
            }
            if (player->pos().ry()>distance){
                timer->stop();
                step+=1;
                switch (level){
                case 1: level1_start(step); break;
                case 2: level2_start(step); break;
                case 3: level3_start(step); break;
                case 4: level4_start(step); break;
                case 5: level5_start(step); break;
                case 6: level6_start(step); break;
                case 7: level7_start(step); break;
                case 8: level8_start(step); break;
                }
            }}  break;
    }
}

Blocks::~Blocks()
{
    delete ui;
}

void Blocks::on_back_clicked(){
    set_subMenuFon();
    if (timer->isActive())
        timer->stop();
    ui->Level2_edit->setVisible(false);
    ui->Level3_edit_1->setVisible(false);
    ui->Level3_edit_2->setVisible(false);
    ui->Level3_edit_3->setVisible(false);
    ui->Level4_edit_1->setVisible(false);
    ui->Level4_edit_2->setVisible(false);
    ui->Level5_edit_1->setVisible(false);
    ui->Level5_edit_2->setVisible(false);
    ui->inter_edit_1->setVisible(false);
    ui->inter_edit_2->setVisible(false);
    ui->inter_edit_3->setVisible(false);
    ui->back->setVisible(false);
    ui->start->setVisible(false);
    ui->level_1->setVisible(true);
    ui->level_2->setVisible(true);
    ui->level_3->setVisible(true);
    ui->level_4->setVisible(true);
    ui->level_5->setVisible(true);
    ui->level_6->setVisible(true);
    ui->level_7->setVisible(true);
    ui->level_8->setVisible(true);
    ui->back_small->setVisible(true);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    scene->clear();
    QPixmap background(QApplication::applicationDirPath()+"/Blocks/change_level.png");
    back = scene->addPixmap(background);
}

void Blocks::on_actionLevel1_clicked()
{
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 1; step = 1; withapple = false; failed = false;
    ui->back->setVisible(true);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    ui->back_small->setVisible(false);
    scene->clear();
    QPixmap level1_back(QApplication::applicationDirPath()+"/Blocks/level1_back.png");
    back = scene->addPixmap(level1_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple->setPos(610,255);
    player->setPos(367,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    minieg1 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
}

void Blocks::changepixmap(qreal x, qreal y, QPixmap change){
    player->setVisible(false);
    player = scene->addPixmap(change);
    player->setPos(x,y);
}

void Blocks::level1_start(int step){
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        distance = player->pos().rx()+210;
        timer->start();
    } break;
    case 2: {
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        distance = player->pos().ry()+200;
        timer->start();
    } break;
    case 3: {
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_with.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        apple->setVisible(false);
        withapple = true;
        direction = 4;
        distance = player->pos().ry()+180;
        timer->start();
    } break;
    case 4: {
        player->setVisible(false);
        minieg1->setVisible(false);
        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
        minieg1 = scene->addPixmap(minieg);
        minieg1->setPos(1171,24);
        Endgame();
    } break;
    }
}

void Blocks::level2_start(int step){
    numberofegik = ui->Level2_edit->text().toInt();
    int current;
    if (!finish) current = 1; else current = 2;
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (!finish)
        distance = player->pos().rx()+210; else
        distance = player->pos().rx()+310;
        timer->start();
    } break;
    case 2: {
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        distance = player->pos().ry()+180;
        timer->start();
    } break;
    case 3: {
       if (current>numberofegik){
           QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
           changepixmap(player->pos().rx(),player->pos().ry(),egik);
           direction = 2;
           distance = player->pos().rx()+210;
           timer->start();
       } else {
           QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_without.png");
           changepixmap(player->pos().rx(),player->pos().ry(),egik);
           direction = 1;
           distance = player->pos().rx()-210;
           timer->start();
       }
    } break;
    case 4: {
           if (current>numberofegik){
               QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
               changepixmap(player->pos().rx(),player->pos().ry(),egik);
               direction = 4;
               distance = player->pos().ry()+110;
               if (apple2ex){
                   apple2->setVisible(false);
                   apple2ex = false;
                   withapple = true;
               } else {
                   crying = true;
                   withapple = false;
                   if (current==1){
                       minieg1->setVisible(false);
                       QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                       minieg1 = scene->addPixmap(minieg);
                       minieg1->setPos(1171,24);
                   } else {
                       minieg2->setVisible(false);
                       QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                       minieg2 = scene->addPixmap(minieg);
                       minieg2->setPos(1171,86);
                   }
               }
               timer->start();
           } else {
               QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_without.png");
               changepixmap(player->pos().rx(),player->pos().ry(),egik);
               direction = 4;
               distance = player->pos().ry()+110;
               if (appleex){
                   apple->setVisible(false);
                   appleex = false;
                   withapple = true;
               } else {
                   crying = true;
                   withapple = false;
                   if (current==1){
                       minieg1->setVisible(false);
                       QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                       minieg1 = scene->addPixmap(minieg);
                       minieg1->setPos(1171,24);
                   } else {
                       minieg2->setVisible(false);
                       QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                       minieg2 = scene->addPixmap(minieg);
                       minieg2->setPos(1171,86);
                   }
               }
               timer->start();
           }
       } break;
    case 5: {
        if (current>numberofegik){
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/right_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            direction = 1;
            distance = player->pos().rx()-210;
            timer->start();
        } else {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            direction = 2;
            distance = player->pos().rx()+210;
            timer->start();
        }
    } break;
    case 6: {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_with.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            direction = 4;
            distance = player->pos().ry()+200;
            timer->start();
    } break;
   case 7: {
        player->setVisible(false);
        if (current==1){
            if (!crying){
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } else {
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            }
        } else {
            if (!crying){
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } else {
                failed = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            }
        }
        Blocks::step = 8;
        level2_start(Blocks::step);
    } break;
    case 8: {
         if (!finish){
         Blocks::step = 1;
         player = player2; withapple = false; finish = true; crying = false;
         level2_start(Blocks::step);
         } else {
            Endgame();
         }
     } break;
    }
}

void Blocks::on_action_stop(){
    if (timer->isActive()){
        timer->stop();
    }
    switch (level){
        case 1: on_actionLevel1_clicked(); break;
        case 2: on_actionLevel2_clicked(); break;
        case 3: on_actionLevel3_clicked(); break;
        case 4: on_actionLevel4_clicked(); break;
        case 5: on_actionLevel5_clicked(); break;
        case 6: on_actionLevel6_clicked(); break;
        case 7: on_actionLevel7_clicked(); break;
        case 8: on_actionLevel8_clicked(); break;
    }
}

void Blocks::on_actionActionstart_triggered(){
    ui->start->setVisible(false);
    ui->stop->setVisible(true);
    switch (level){
    case 1: level1_start(step); break;
    case 2: { level2_start(step);
    } break;
    case 3: {
        numberofegik = ui->Level3_edit_1->text().toInt();
        numberofapples1 = ui->Level3_edit_3->text().toInt();
        numberofapples = ui->Level3_edit_2->text().toInt();
        level3_start(step);
    } break;
    case 4: {
        numberofcounts = ui->Level4_edit_1->text().toInt();
        numberofapples = ui->Level4_edit_2->text().toInt();
        level4_start(step);} break;
    case 5: level5_start(step); break;
    case 6: level6_start(step); break;
    case 7: level7_start(step); break;
    case 8: level8_start(step); break;
    }
}

void Blocks::SwitchrightBinCount(int n){
   int x,y;
    switch (n){
        case 0: {
        QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_empty.png");
        x = bin2->pos().rx(); y = bin2->pos().ry();
        bin2->setVisible(false);
        bin2 = scene->addPixmap(bin_);
        bin2->setPos(x,y);
    } break;
    case 1: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_middle.png");
    x = bin2->pos().rx(); y = bin2->pos().ry();
    bin2->setVisible(false);
    bin2 = scene->addPixmap(bin_);
    bin2->setPos(x,y);
} break;
    case 2: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_full.png");
    x = bin2->pos().rx(); y = bin2->pos().ry();
    bin2->setVisible(false);
    bin2 = scene->addPixmap(bin_);
    bin2->setPos(x,y);
} break;
    case 3: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_fullover.png");
    x = bin2->pos().rx(); y = bin2->pos().ry();
    bin2->setVisible(false);
    bin2 = scene->addPixmap(bin_);
    bin2->setPos(x,y);
} break;
    }
}

void Blocks::SwitchleftBinCount(int n){
   int x,y;
    switch (n){
        case 0: {
        QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_empty.png");
        x = bin->pos().rx(); y = bin->pos().ry();
        bin->setVisible(false);
        bin = scene->addPixmap(bin_);
        bin->setPos(x,y);
    } break;
    case 1: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_middle.png");
    x = bin->pos().rx(); y = bin->pos().ry();
    bin->setVisible(false);
    bin = scene->addPixmap(bin_);
    bin->setPos(x,y);
} break;
    case 2: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_full.png");
    x = bin->pos().rx(); y = bin->pos().ry();
    bin->setVisible(false);
    bin = scene->addPixmap(bin_);
    bin->setPos(x,y);
} break;
    case 3: {
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_fullover.png");
    x = bin->pos().rx(); y = bin->pos().ry();
    bin->setVisible(false);
    bin = scene->addPixmap(bin_);
    bin->setPos(x,y);
} break;
    }
}

void Blocks::level3_start(int step){
    int current;
    if (!finish) current = 1; else current = 2;
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (!finish)
        distance = player->pos().rx()+210; else
        distance = player->pos().rx()+310;
        timer->start();
    } break;
    case 2: {
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        distance = player->pos().ry()+80;
        timer->start();
    } break;
    case 3: {
        if (current>numberofegik){
            direction = 2;
            distance = player->pos().rx()+250;
            timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-250;
            timer->start();
        }
    } break;
   case 4: {
       if (current>numberofegik){
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        distance = player->pos().ry()+60;
        timer->start();
       } else {
           QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
           changepixmap(player->pos().rx(),player->pos().ry(),egik);
           direction = 4;
           distance = player->pos().ry()+80;
           timer->start();
       }
    } break;
   case 5: {
        if (current>numberofegik){
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        distance = player->pos().ry()+120;
        timer->start();
        } else {
            direction = 4;
            if (!withapple){
                if (bincount==0){
                apple->setVisible(false);
                withapple = true;
                } else
                if (bincount==1){
                    apple2->setVisible(false);
                    withapple = true;
                } else {
                    crying = true;
                    withapple = false;
                    if (current==1){
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } else {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    }
                }
            }
            distance = player->pos().ry()+100;
            timer->start();
        }
        }
            break;
   case 6: {
        if (current>numberofegik){
        direction = 4;
        if (!withapple){
            if (bin1count==0){
            apple3->setVisible(false);
            withapple = true;
            } else
            if (bin1count==1){
                apple4->setVisible(false);
                withapple = true;
            } else {
                crying = true;
                withapple = false;
                if (current==1){
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } else {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                }
            }
        }
        distance = player->pos().ry()+100;
        timer->start();
        } else {
            if (withapple){
                bincount+=1;
                withapple = false;
                SwitchrightBinCount(bincount);
            }
            distance = player->pos().ry()+100;
            timer->start();
        }
    } break;
    case 7: {
        if (current>numberofegik){
        if (withapple){
            bin1count+=1;
            withapple = false;
            SwitchleftBinCount(bin1count);
        }
         QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
         changepixmap(player->pos().rx(),player->pos().ry(),egik);
         direction = 2;
         distance = player->pos().rx()+210;
         timer->start();
        } else {
            if (numberofapples1!=0){
            direction = 1;
            distance = player->pos().rx()-200;
            timer->start();
            } else {
                if (current==1){
                    if (bincount<2){
                        crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                    }
                } else {
                    if (bincount<2){
                        crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                    }
                }
                direction = 2;
                distance = player->pos().rx()+210;
                Blocks::step = 10;
                timer->start();
            }
        }
     } break;
    case 8: {
        if (current>numberofegik){
         QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
         changepixmap(player->pos().rx(),player->pos().ry(),egik);
         direction = 3;
         distance = player->pos().ry()-210;
         timer->start();
        } else {
            QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
            changepixmap(player->pos().rx(),player->pos().ry(),egik);
            direction = 3;
            distance = player->pos().ry()-210;
            timer->start();
        }
     } break;
    case 9: {
        if (current>numberofegik){
         QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
         changepixmap(player->pos().rx(),player->pos().ry(),egik);
         direction = 1;
         distance = player->pos().rx()-230;
         timer->start();
        } else {
            direction = 2;
            distance = player->pos().rx()+210;
            timer->start();
        }
     } break;
    case 10: {
        if (current>numberofegik){
          if (numberofapples!=0){
              Blocks::step = 5;
              numberofapples--;
              level3_start(Blocks::step);
          } else {
              if (current==1){
                  if (bin1count<2){
                      crying = true;
                  minieg1->setVisible(false);
                  QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                  minieg1 = scene->addPixmap(minieg);
                  minieg1->setPos(1171,24);
                  }
              } else {
                  if (bin1count<2){
                      crying = true;
                  minieg2->setVisible(false);
                  QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                  minieg2 = scene->addPixmap(minieg);
                  minieg2->setPos(1171,86);
                  }
              }
              QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
              changepixmap(player->pos().rx(),player->pos().ry(),egik);
              direction = 1;
              distance = player->pos().rx()-210;
              timer->start();
          }
        } else {
            Blocks::step=5;
            numberofapples1--;
            level3_start(Blocks::step);
        }

     } break;
    case 11: {
        QPixmap egik(QApplication::applicationDirPath()+"/Blocks/front_without.png");
        changepixmap(player->pos().rx(),player->pos().ry(),egik);
        direction = 4;
        if (current>numberofegik)
        distance = player->pos().ry()+350; else distance = player->pos().ry()+150;
        timer->start();
    } break;
    case 12: {
        player->setVisible(false);
        if (current==1){
            if (crying){
            minieg1->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg1 = scene->addPixmap(minieg);
            minieg1->setPos(1171,24);
            } else {
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            }
        } else {
            if (crying){
                failed = true;
            minieg2->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg2 = scene->addPixmap(minieg);
            minieg2->setPos(1171,86);
            } else {
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            }
        }
        if (!finish){
            finish = true;
            Blocks::step = 1;
            player = player2;
            level3_start(Blocks::step);
        } else {
            Endgame();
        }
    } break;
    }
}

void Blocks::level4_start(int step){
    switch (step){
        case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (currentegik == 1)
        distance = player->pos().rx()+420;
        else if (currentegik == 2) distance = player->pos().rx()+520;
        else if (currentegik == 3) distance = player->pos().rx()+620;
        timer->start();
    } break;
        case 2: {
        direction = 4;
        distance = player->pos().ry()+110;
        timer->start();
} break;
    case 3: {
        if (currentcount<numberofcounts){
    direction = 1;
    currentcount++;
    distance = player->pos().rx()-330;
    timer->start();
        } else {
            if (bincount+bin1count<6){
                switch (currentegik){
                    case 1: {
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } break;
                case 2: {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                } break;
                case 3: {
                    crying = true;
                    minieg3->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg3 = scene->addPixmap(minieg);
                    minieg3->setPos(1171,149);
                } break;
                }
            }
            Blocks::step = 13;
            level4_start(Blocks::step);
        }
} break;
    case 4: {
    direction = 4;
    if (appleex){
        appleex = false; apple->setVisible(false); withapple = true; applenumber++;
    } else if (apple2ex){
        apple2ex = false; apple2->setVisible(false); withapple = true; applenumber++;
    } else if (apple3ex){
        apple3ex = false; apple3->setVisible(false); withapple = true; applenumber++;
    } else if (apple4ex){
        apple4ex = false; apple4->setVisible(false); withapple = true; applenumber++;
    } else if (apple5ex){
        apple5ex = false; apple5->setVisible(false); withapple = true; applenumber++;
    } else if (apple6ex){
        apple6ex = false; apple6->setVisible(false); withapple = true; applenumber++;
    } else {
        switch (currentegik){
            case 1: {
            crying = true;
            minieg1->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
            minieg1 = scene->addPixmap(minieg);
            minieg1->setPos(1171,24);
        } break;
        case 2: {
            crying = true;
            minieg2->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
            minieg2 = scene->addPixmap(minieg);
            minieg2->setPos(1171,86);
        } break;
        case 3: {
            crying = true;
            minieg3->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
            minieg3 = scene->addPixmap(minieg);
            minieg3->setPos(1171,149);
        } break;
        }
    }
    distance = player->pos().ry()+110;
    timer->start();
} break;
    case 5: {
        if (applenumber>numberofapples){
            direction = 2;
            distance = player->pos().rx()+220;
            timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-220;
            timer->start();
        }
} break;
    case 6: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
} break;
    case 7: {
        if (applenumber>numberofapples){
            if (withapple){
                if (bin1count<3){
                bin1count++;
                SwitchrightBinCount(bin1count);
                withapple = false;
                } else {
                    withapple = true;
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    }
                }
            }
            distance = 4;
            distance = player->pos().ry()+60;
            timer->start();
        } else {
            if (withapple){
                if (bincount<3){
                bincount++;
                SwitchleftBinCount(bincount);
                withapple = false;
                } else {
                    withapple = true;
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    }
                }
            }
            distance = 4;
            distance = player->pos().ry()+60;
            timer->start();
        }
} break;
    case 8: {
        if (applenumber>numberofapples){
            direction = 1;
            distance = player->pos().rx()-580;
            timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-140;
            timer->start();
        }
    } break;
    case 9: {
        direction = 3;
        distance = player->pos().ry()-330;
        timer->start();
    } break;
    case 10: {
        direction = 2;
        distance = player->pos().rx()+710;
        timer->start();
    } break;
    case 11: {
        direction = 4;
        distance = player->pos().ry()+60;
        timer->start();
    } break;
    case 12: {
        if (currentcount<numberofcounts){
        Blocks::step = 3;
        level4_start(Blocks::step);
        } else {
            Blocks::step = 13;
            level4_start(Blocks::step);
        }
    } break;
    case 13: {
        direction = 2;
        distance = player->pos().rx()+160;
        timer->start();
    } break;
    case 14: {
        direction = 4;
        distance = player->pos().ry()+260;
        timer->start();
    } break;
    case 15: {
        direction = 1;
        distance = player->pos().rx()-150;
        timer->start();
    } break;
    case 16: {
        direction = 4;
        distance = player->pos().ry()+120;
        timer->start();
    } break;
    case 17: {
        if (currentegik==3){
        if (bincount+bin1count<6){
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            }
        }
        player->setVisible(false);
        if (crying){
            failed = true;
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            }
        } else {
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            }
        }
        if (currentegik == 1){
            player = player2;
            currentegik++;
            currentcount = 1;
            crying = false;
            Blocks::step = 1;
            level4_start(Blocks::step);
        } else if (currentegik==2){
            player = player3;
            currentcount = 1;
            crying = false;
            currentegik++;
            Blocks::step = 1;
            level4_start(Blocks::step);
        } else {
            Endgame();
        }
    } break;
    }
}

void Blocks::level5_start(int step){
    numberofegik = ui->Level5_edit_1->text().toInt();
    numberofegik2 = ui->Level5_edit_2->text().toInt();
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (currentegik == 1)
        distance = player->pos().rx()+210;
        else if (currentegik == 2) distance = player->pos().rx()+310;
        else if (currentegik == 3) distance = player->pos().rx()+410;
        timer->start();
    } break;
    case 2: {
        direction = 4;
        distance = player->pos().ry()+120;
        timer->start();
    } break;
    case 3: {
        if (currentegik>numberofegik){
        direction = 2;
        distance = player->pos().rx()+250;
        timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-230;
            timer->start();
        }
    } break;
    case 4: {
        if (currentegik>numberofegik){
        direction = 4;
        distance = player->pos().ry()+90;
        timer->start();
        } else {
            direction = 4;
            distance = player->pos().ry()+250;
            timer->start();
        }
    } break;
    case 5: {
        if (currentegik>numberofegik){
                if (currentegik<numberofegik1){
                    direction = 2;
                    distance = player->pos().rx()+240;
                    timer->start();
                } else {
                    direction = 1;
                    distance = player->pos().rx()-240;
                    timer->start();
                }
        } else {
            direction = 2;
            distance = player->pos().rx()+220;
            timer->start();
        }
    } break;
    case 6:{
        if (currentegik>numberofegik){
        direction = 4;
        distance = player->pos().ry()+90;
        timer->start();
        } else {
            Blocks::step = 9;
            level5_start(Blocks::step);
        }
    } break;
    case 7:{
        if (currentegik<numberofegik1){
            if (apple2ex){
                if (!withapple){
                apple2ex = false;
                apple2->setVisible(false);
                withapple = true;
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    }
                }
            } else {
                withapple = false;
                switch (currentegik){
                    case 1: {
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } break;
                case 2: {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                } break;
                case 3: {
                    crying = true;
                    minieg3->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg3 = scene->addPixmap(minieg);
                    minieg3->setPos(1171,149);
                } break;
                }
            }
            direction = 4;
            distance = player->pos().ry()+60;
            timer->start();
        } else {
            if (appleex){
                if (!withapple){
                appleex = false;
                apple->setVisible(false);
                withapple = true;
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    }
                }
            } else {
                withapple = false;
                switch (currentegik){
                    case 1: {
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } break;
                case 2: {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                } break;
                case 3: {
                    crying = true;
                    minieg3->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg3 = scene->addPixmap(minieg);
                    minieg3->setPos(1171,149);
                } break;
                }
            }
            direction = 4;
            distance = player->pos().ry()+60;
            timer->start();
        }

    } break;
   case 8:{
        direction = 1;
        if (currentegik<numberofegik1)
            distance = player->pos().rx()-500; else
            distance = player->pos().rx()-30;
        timer->start();
    } break;
    case 9:{
         direction = 4;
         distance = player->pos().ry()+140;
         timer->start();
     } break;
    case 10:{
        player->setVisible(false);
        if (crying){
            failed = true;
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            }
        } else {
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            }
        }
         if (currentegik==1){
             player = player2;
             withapple = false;
             crying = false;
             currentegik++;
             Blocks::step=1;
             level5_start(Blocks::step);
         } else if (currentegik==2) {
             player = player3;
             crying = false;
             currentegik++;
             withapple = false;
             Blocks::step=1;
             level5_start(Blocks::step);
         } else {
            Endgame();
         }
     } break;
    }
}

void Blocks::level6_start(int step){
    numberofegik = ui->inter_edit_1->text().toInt();
    numberofegik1 = ui->inter_edit_2->text().toInt();
    numberofegik2 = ui->inter_edit_3->text().toInt();
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (currentegik == 1){
        distance = player->pos().rx()+200;
        timer->start();
        }
        else if (currentegik == 2){
            distance = player->pos().rx()+300;
            timer->start();
        }
        else if (currentegik == 3){
            distance = player->pos().rx()+400;
            timer->start();
        }
        else if (currentegik == 4){
            player->setVisible(false);
            distance = player->pos().rx()+500;
            timer->start();
        }
    } break;
    case 2: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 3: {
        if (currentegik>numberofegik){
        direction = 2;
        distance = player->pos().rx()+270;
        timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-250;
            timer->start();
        }
    } break;
    case 4: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 5: {
        if (currentegik>numberofegik){
            if (currentegik<numberofegik2){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
               } else {
            if (currentegik<numberofegik1){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
        }
    } break;
    case 6: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 7: {
        if (currentegik>numberofegik){
            if (currentegik<numberofegik2){
                if (apple4ex){
                    apple4ex = false; withapple = true; apple4->setVisible(false);
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            } else {
                if (apple3ex){
                   apple3ex = false; withapple = true; apple3->setVisible(false);
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            }
        } else {
            if (currentegik<numberofegik1){

            } else {
                if (appleex){
                    appleex = false; withapple = true; apple->setVisible(false);
                } else if (apple2ex) {
                    apple2ex = false; withapple = true; apple2->setVisible(false);
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            }
        }
        direction = 4;
        distance = player->pos().ry()+60;
        timer->start();
    } break;
    case 8: {
        if (currentegik>numberofegik){
            if (currentegik<numberofegik2){
                direction = 1;
                distance = player->pos().rx()-450;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-130;
                timer->start();
            }
        } else {
            if (currentegik<numberofegik1){
                direction = 2;
                distance = player->pos().rx()+110;
                timer->start();
            } else {
                direction = 2;
                distance = player->pos().rx()+400;
                timer->start();
            }
        }

    } break;
    case 9: {
        direction =4;
        distance = player->pos().ry()+140;
        timer->start();
    } break;
    case 10: {
        if (crying){
            failed = true;
        switch (currentegik){
            case 1: {
            crying = true;
            minieg1->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg1 = scene->addPixmap(minieg);
            minieg1->setPos(1171,24);
        } break;
        case 2: {
            crying = true;
            minieg2->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg2 = scene->addPixmap(minieg);
            minieg2->setPos(1171,86);
        } break;
        case 3: {
            crying = true;
            minieg3->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg3 = scene->addPixmap(minieg);
            minieg3->setPos(1171,149);
        } break;
        case 4: {
            crying = true;
            minieg4->setVisible(false);
            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
            minieg4 = scene->addPixmap(minieg);
            minieg4->setPos(1171,211);
        } break;
        }
        } else {
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            case 4: {
                crying = true;
                minieg4->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg4 = scene->addPixmap(minieg);
                minieg4->setPos(1171,211);
            } break;
            }
        }
       if (currentegik==1){
           player=player2;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level6_start(Blocks::step);
       } else if (currentegik==2){
           player=player3;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level6_start(Blocks::step);
       } else if (currentegik==3){
           player=player4;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level6_start(Blocks::step);
       } else {
            Endgame();
       }
    } break;
    }
}

void Blocks::level8_start(int step){
    numberofegik = ui->inter_edit_1->text().toInt();
    numberofegik1 = ui->inter_edit_2->text().toInt();
    numberofegik2 = ui->inter_edit_3->text().toInt();
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (currentegik == 1){
        distance = player->pos().rx()+200;

        timer->start();
        }
        else if (currentegik == 2){
            distance = player->pos().rx()+280;
            timer->start();
        }
        else if (currentegik == 3){
            distance = player->pos().rx()+360;
            timer->start();
        }
        else if (currentegik == 4){
            distance = player->pos().rx()+440;
            timer->start();
        }
        else if (currentegik == 5){
            distance = player->pos().rx()+520;
            timer->start();
        }
    } break;
    case 2: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 3: {
        if (currentegik<numberofegik){
        direction = 2;
        distance = player->pos().rx()+270;
        timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-250;
            timer->start();
        }
    } break;
    case 4: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 5: {
        if (currentegik<numberofegik){
            if (currentegik>numberofegik2){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
               } else {
            if (currentegik<numberofegik1){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
        }
    } break;
    case 6: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 7: {
        if (currentegik<numberofegik){
            if (currentegik>numberofegik2){
                if (!withapple){
                switch (currentegik){
                    case 1: {
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } break;
                case 2: {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                } break;
                case 3: {
                    crying = true;
                    minieg3->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg3 = scene->addPixmap(minieg);
                    minieg3->setPos(1171,149);
                } break;
                case 4: {
                    crying = true;
                    minieg4->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg4 = scene->addPixmap(minieg);
                    minieg4->setPos(1171,211);
                } break;
                case 5: {
                    crying = true;
                    minieg5->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg5 = scene->addPixmap(minieg);
                    minieg5->setPos(1171,274);
                } break;
                }
                }
            } else {
                if (apple3ex){
                    if (!withapple){
                   apple3ex = false; withapple = true; apple3->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        case 5: {
                            crying = true;
                            minieg5->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg5 = scene->addPixmap(minieg);
                            minieg5->setPos(1171,274);
                        } break;
                        }
                    }
                } else if (apple4ex){
                    if (!withapple){
                    apple4ex = false; withapple = true; apple4->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        case 5: {
                            crying = true;
                            minieg5->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg5 = scene->addPixmap(minieg);
                            minieg5->setPos(1171,274);
                        } break;
                        }
                    }
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    case 5: {
                        crying = true;
                        minieg5->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg5 = scene->addPixmap(minieg);
                        minieg5->setPos(1171,274);
                    } break;
                    }
                }
            }
        } else {
            if (currentegik<numberofegik1){
                if (!withapple){
                switch (currentegik){
                    case 1: {
                    crying = true;
                    minieg1->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg1 = scene->addPixmap(minieg);
                    minieg1->setPos(1171,24);
                } break;
                case 2: {
                    crying = true;
                    minieg2->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg2 = scene->addPixmap(minieg);
                    minieg2->setPos(1171,86);
                } break;
                case 3: {
                    crying = true;
                    minieg3->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg3 = scene->addPixmap(minieg);
                    minieg3->setPos(1171,149);
                } break;
                case 4: {
                    crying = true;
                    minieg4->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg4 = scene->addPixmap(minieg);
                    minieg4->setPos(1171,211);
                } break;
                case 5: {
                    crying = true;
                    minieg5->setVisible(false);
                    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                    minieg5 = scene->addPixmap(minieg);
                    minieg5->setPos(1171,274);
                } break;
                }
                }
            } else {
                if (appleex){
                    if (!withapple){
                    appleex = false; withapple = true; apple->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        case 5: {
                            crying = true;
                            minieg5->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg5 = scene->addPixmap(minieg);
                            minieg5->setPos(1171,274);
                        } break;
                        }
                    }
                } else if (apple2ex){
                    if (!withapple){
                    apple2ex = false; withapple = true; apple2->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        case 5: {
                            crying = true;
                            minieg5->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg5 = scene->addPixmap(minieg);
                            minieg5->setPos(1171,274);
                        } break;
                        }
                    }
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    case 5: {
                        crying = true;
                        minieg5->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg5 = scene->addPixmap(minieg);
                        minieg5->setPos(1171,274);
                    } break;
                    }
                }
            }
        }
        direction = 4;
        distance = player->pos().ry()+60;
        timer->start();
    } break;
    case 8: {
        if (currentegik<numberofegik){
            if (currentegik>numberofegik2){
                direction = 1;
                distance = player->pos().rx()-450;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-130;
                timer->start();
            }
        } else {
            if (currentegik<numberofegik1){
                direction = 2;
                distance = player->pos().rx()+110;
                timer->start();
            } else {
                direction = 2;
                distance = player->pos().rx()+400;
                timer->start();
            }
        }

    } break;
    case 9: {
        direction =4;
        distance = player->pos().ry()+140;
        timer->start();
    } break;
    case 10: {
        if (crying){
            failed = true;
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            case 4: {
                crying = true;
                minieg4->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg4 = scene->addPixmap(minieg);
                minieg4->setPos(1171,211);
            } break;
            case 5: {
                crying = true;
                minieg5->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg5 = scene->addPixmap(minieg);
                minieg5->setPos(1171,274);
            } break;
            }
        } else {
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            case 4: {
                crying = true;
                minieg4->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg4 = scene->addPixmap(minieg);
                minieg4->setPos(1171,211);
            } break;
            case 5: {
                crying = true;
                minieg5->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg5 = scene->addPixmap(minieg);
                minieg5->setPos(1171,274);
            } break;
            }
        }
        player->setVisible(false);
       if (currentegik==1){
           player=player2;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level8_start(Blocks::step);
       } else if (currentegik==2){
           player=player3;
           crying = false;
           currentegik++;
           withapple = true;
           Blocks::step=1;
           level8_start(Blocks::step);
       } else if (currentegik==3){
           player=player4;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level8_start(Blocks::step);
       } else if (currentegik==4){
           player=player5;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level8_start(Blocks::step);
       } else {
            Endgame();
       }
    } break;
    }
}

void Blocks::level7_start(int step){
    numberofegik = ui->inter_edit_1->text().toInt();
    numberofegik1 = ui->inter_edit_2->text().toInt();
    numberofegik2 = ui->inter_edit_3->text().toInt();
    switch (step){
    case 1: {
        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(onTimer()));
        timer->setInterval(1000 / 120);
        direction = 2;
        if (currentegik == 1){
        distance = player->pos().rx()+200;
        timer->start();
        }
        else if (currentegik == 2){
            distance = player->pos().rx()+300;

            timer->start();
        }
        else if (currentegik == 3){
            distance = player->pos().rx()+400;

            timer->start();
        }
        else if (currentegik == 4){
            player->setVisible(false);
            distance = player->pos().rx()+500;
            timer->start();
        }
    } break;
    case 2: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 3: {
        if (currentegik>numberofegik){
        direction = 2;
        distance = player->pos().rx()+270;
        timer->start();
        } else {
            direction = 1;
            distance = player->pos().rx()-250;
            timer->start();
        }
    } break;
    case 4: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 5: {
        if (currentegik>numberofegik){
            if (currentegik>numberofegik2){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
               } else {
            if (currentegik>numberofegik1){
                direction = 2;
                distance = player->pos().rx()+160;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-150;
                timer->start();
            }
        }
    } break;
    case 6: {
        direction = 4;
        distance = player->pos().ry()+100;
        timer->start();
    } break;
    case 7: {
        if (currentegik>numberofegik){
            if (currentegik>numberofegik2){
                   if (!withapple){
                       switch (currentegik){
                           case 1: {
                           crying = true;
                           minieg1->setVisible(false);
                           QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                           minieg1 = scene->addPixmap(minieg);
                           minieg1->setPos(1171,24);
                       } break;
                       case 2: {
                           crying = true;
                           minieg2->setVisible(false);
                           QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                           minieg2 = scene->addPixmap(minieg);
                           minieg2->setPos(1171,86);
                       } break;
                       case 3: {
                           crying = true;
                           minieg3->setVisible(false);
                           QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                           minieg3 = scene->addPixmap(minieg);
                           minieg3->setPos(1171,149);
                       } break;
                       case 4: {
                           crying = true;
                           minieg4->setVisible(false);
                           QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                           minieg4 = scene->addPixmap(minieg);
                           minieg4->setPos(1171,211);
                       } break;
                       }
                   }
            } else {
                if (apple3ex){
                    if (!withapple){
                   apple3ex = false; withapple = true; apple3->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        }
                    }
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            }
        } else {
            if (currentegik>numberofegik1){
                if (apple2ex){
                    if (!withapple){
                    apple2ex = false; withapple = true; apple2->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        }
                    }
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            } else {
                if (appleex){
                    if (!withapple){
                    appleex = false; withapple = true; apple->setVisible(false);
                    } else {
                        switch (currentegik){
                            case 1: {
                            crying = true;
                            minieg1->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg1 = scene->addPixmap(minieg);
                            minieg1->setPos(1171,24);
                        } break;
                        case 2: {
                            crying = true;
                            minieg2->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg2 = scene->addPixmap(minieg);
                            minieg2->setPos(1171,86);
                        } break;
                        case 3: {
                            crying = true;
                            minieg3->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg3 = scene->addPixmap(minieg);
                            minieg3->setPos(1171,149);
                        } break;
                        case 4: {
                            crying = true;
                            minieg4->setVisible(false);
                            QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                            minieg4 = scene->addPixmap(minieg);
                            minieg4->setPos(1171,211);
                        } break;
                        }
                    }
                } else {
                    switch (currentegik){
                        case 1: {
                        crying = true;
                        minieg1->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg1 = scene->addPixmap(minieg);
                        minieg1->setPos(1171,24);
                    } break;
                    case 2: {
                        crying = true;
                        minieg2->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg2 = scene->addPixmap(minieg);
                        minieg2->setPos(1171,86);
                    } break;
                    case 3: {
                        crying = true;
                        minieg3->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg3 = scene->addPixmap(minieg);
                        minieg3->setPos(1171,149);
                    } break;
                    case 4: {
                        crying = true;
                        minieg4->setVisible(false);
                        QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_cry.png");
                        minieg4 = scene->addPixmap(minieg);
                        minieg4->setPos(1171,211);
                    } break;
                    }
                }
            }
        }
        direction = 4;
        distance = player->pos().ry()+60;
        timer->start();
    } break;
    case 8: {
        if (currentegik>numberofegik){
            if (currentegik>numberofegik2){
                direction = 1;
                distance = player->pos().rx()-450;
                timer->start();
            } else {
                direction = 1;
                distance = player->pos().rx()-130;
                timer->start();
            }
        } else {
            if (currentegik>numberofegik1){
                direction = 2;
                distance = player->pos().rx()+110;
                timer->start();
            } else {
                direction = 2;
                distance = player->pos().rx()+400;
                timer->start();
            }
        }

    } break;
    case 9: {
        direction =4;
        distance = player->pos().ry()+140;
        timer->start();
    } break;
    case 10: {
        if (crying){
            failed = true;
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            case 4: {
                crying = true;
                minieg4->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_failed.png");
                minieg4 = scene->addPixmap(minieg);
                minieg4->setPos(1171,211);
            } break;
            }
        } else {
            switch (currentegik){
                case 1: {
                crying = true;
                minieg1->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg1 = scene->addPixmap(minieg);
                minieg1->setPos(1171,24);
            } break;
            case 2: {
                crying = true;
                minieg2->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg2 = scene->addPixmap(minieg);
                minieg2->setPos(1171,86);
            } break;
            case 3: {
                crying = true;
                minieg3->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg3 = scene->addPixmap(minieg);
                minieg3->setPos(1171,149);
            } break;
            case 4: {
                crying = true;
                minieg4->setVisible(false);
                QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini_success.png");
                minieg4 = scene->addPixmap(minieg);
                minieg4->setPos(1171,211);
            } break;
            }
        }
        player->setVisible(false);
       if (currentegik==1){
           player=player2;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level7_start(Blocks::step);
       } else if (currentegik==2){
           player=player3;
           crying = false;
           currentegik++;
           withapple = false;
           Blocks::step=1;
           level7_start(Blocks::step);
       } else if (currentegik==3){
           player=player4;
           crying = false;
           currentegik++;
           withapple = true;
           Blocks::step=1;
           level7_start(Blocks::step);
       } else {
            Endgame();
       }
    } break;
    }
}

void Blocks::on_actionLevel8_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 8; step = 1; withapple = false; currentegik = 1; numberofegik = 2; numberofegik1 = 1; numberofegik2 = 4;
    appleex = true; apple2ex = true; apple3ex = true; apple4ex=true; crying = false;  failed = false;
    ui->back->setVisible(true);
    ui->inter_edit_1->setVisible(true);
    ui->inter_edit_2->setVisible(true);
    ui->inter_edit_3->setVisible(true);
    ui->start->setVisible(true);
    ui->back_small->setVisible(false);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    scene->clear();
    QPixmap level8_back(QApplication::applicationDirPath()+"/Blocks/level8_back.png");
    back = scene->addPixmap(level8_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap egikwith(QApplication::applicationDirPath()+"/Blocks/left_with.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    player3 = scene->addPixmap(egikwith);
    player4 = scene->addPixmap(egik);
    player5 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple3=scene->addPixmap(appl);
    apple4=scene->addPixmap(appl);
    apple->setPos(179,355);
    apple2->setPos(196,355);
    apple3->setPos(710,355);
    apple4->setPos(730,355);
    player->setPos(367,0);
    player2->setPos(287,0);
    player3->setPos(207,0);
    player4->setPos(127,0);
    player5->setPos(47,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg3 = scene->addPixmap(minieg);
    minieg4 = scene->addPixmap(minieg);
    minieg5 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
    minieg3->setPos(1171,149);
    minieg4->setPos(1171,211);
    minieg5->setPos(1171,274);
}

void Blocks::on_actionLevel7_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 7; step = 1; withapple = false; currentegik = 1; numberofegik = 2; numberofegik1 = 1; numberofegik2 = 3;
    appleex = true; apple2ex = true; apple3ex = true; crying = false;  failed = false;
    ui->back->setVisible(true);
    ui->inter_edit_1->setVisible(true);
    ui->inter_edit_2->setVisible(true);
    ui->inter_edit_3->setVisible(true);
    ui->start->setVisible(true);
    ui->back_small->setVisible(false);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    scene->clear();
    QPixmap level7_back(QApplication::applicationDirPath()+"/Blocks/level7_back.png");
    back = scene->addPixmap(level7_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap egikwith(QApplication::applicationDirPath()+"/Blocks/left_with.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    player3 = scene->addPixmap(egik);
    player4 = scene->addPixmap(egikwith);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple3=scene->addPixmap(appl);
    apple->setPos(190,355);
    apple2->setPos(496,355);
    apple3->setPos(722,355);
    player->setPos(367,0);
    player2->setPos(267,0);
    player3->setPos(167,0);
    player4->setPos(67,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg3 = scene->addPixmap(minieg);
    minieg4 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
    minieg3->setPos(1171,149);
    minieg4->setPos(1171,211);
}

void Blocks::on_actionLevel6_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 6; step = 1; withapple = false; currentegik = 1; numberofegik = 2; numberofegik1 = 1; numberofegik2 = 4;
    appleex = true; apple2ex = true; apple3ex = true; apple4ex = true; crying = false;  failed = false;
    ui->back->setVisible(true);
    ui->inter_edit_1->setVisible(true);
    ui->inter_edit_2->setVisible(true);
    ui->inter_edit_3->setVisible(true);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    ui->back_small->setVisible(false);
    scene->clear();
    QPixmap level6_back(QApplication::applicationDirPath()+"/Blocks/level6_back.png");
    back = scene->addPixmap(level6_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    player3 = scene->addPixmap(egik);
    player4 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple3=scene->addPixmap(appl);
    apple4=scene->addPixmap(appl);
    apple->setPos(179,355);
    apple2->setPos(202,355);
    apple3->setPos(722,355);
    apple4->setPos(1035,355);
    player->setPos(367,0);
    player2->setPos(267,0);
    player3->setPos(167,0);
    player4->setPos(67,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg3 = scene->addPixmap(minieg);
    minieg4 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
    minieg3->setPos(1171,149);
    minieg4->setPos(1171,211);
}

void Blocks::on_actionLevel5_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 5; step = 1; withapple = true; currentegik = 1; numberofegik = 0; numberofegik1 = 0;
    appleex = true; apple2ex = true; crying = false;  failed = false;
    ui->back->setVisible(true);
    ui->Level5_edit_1->setVisible(true);
    ui->Level5_edit_2->setVisible(true);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    ui->back_small->setVisible(false);
    scene->clear();
    QPixmap level5_back(QApplication::applicationDirPath()+"/Blocks/level5_back.png");
    back = scene->addPixmap(level5_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap egikwith(QApplication::applicationDirPath()+"/Blocks/left_with.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egikwith);
    player2 = scene->addPixmap(egik);
    player3 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple->setPos(619,362);
    apple2->setPos(1084,362);
    player->setPos(367,0);
    player2->setPos(267,0);
    player3->setPos(167,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg3 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
    minieg3->setPos(1171,149);
}

void Blocks::on_actionLevel4_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 4; step = 1; withapple = false; numberofcounts = 0; finish = false; bincount = 0; bin1count=0;
    numberofapples = 0; currentegik = 1; applenumber = 0; currentcount = 1; crying = false;  failed = false;
    appleex = true; apple2ex = true; apple3ex = true; apple4ex = true; apple5ex = true; apple6ex = true;
    ui->back->setVisible(true);
    ui->Level4_edit_1->setVisible(true);
    ui->Level4_edit_2->setVisible(true);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    ui->back_small->setVisible(false);
    scene->clear();
    QPixmap level4_back(QApplication::applicationDirPath()+"/Blocks/level4_back.png");
    back = scene->addPixmap(level4_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    player3 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple3=scene->addPixmap(appl);
    apple4=scene->addPixmap(appl);
    apple5=scene->addPixmap(appl);
    apple6=scene->addPixmap(appl);
    apple->setPos(443,178);
    apple2->setPos(464,178);
    apple3->setPos(485,178);
    apple4->setPos(507,178);
    apple5->setPos(529,178);
    apple6->setPos(551,178);
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_empty.png");
    bin = scene->addPixmap(bin_);
    bin2 = scene->addPixmap(bin_);
    bin->setPos(250,347);
    bin2->setPos(694,347);
    player->setPos(367,0);
    player2->setPos(267,0);
    player3->setPos(167,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg3 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
    minieg3->setPos(1171,149);
}

void Blocks::on_actionLevel3_clicked(){
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 3; step = 1; withapple = false; numberofegik = 0; finish = false; bincount = 0; bin1count=0;
    numberofapples = 0; numberofapples1 = 0; crying = false;  failed = false;
    appleex = true; apple2ex = true;
    ui->Level3_edit_1->setVisible(true);
    ui->Level3_edit_2->setVisible(true);
    ui->Level3_edit_3->setVisible(true);
    ui->back->setVisible(true);
    ui->back_small->setVisible(false);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    scene->clear();
    QPixmap level3_back(QApplication::applicationDirPath()+"/Blocks/level3_back.png");
    back = scene->addPixmap(level3_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple3=scene->addPixmap(appl);
    apple4=scene->addPixmap(appl);
    apple->setPos(380,210);
    apple2->setPos(340,210);
    apple3->setPos(885,320);
    apple4->setPos(845,320);
    QPixmap bin_(QApplication::applicationDirPath()+"/Blocks/bin_empty.png");
    bin = scene->addPixmap(bin_);
    bin2 = scene->addPixmap(bin_);
    bin->setPos(835,390);
    bin2->setPos(325,275);
    player->setPos(367,0);
    player2->setPos(267,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
}

void Blocks::on_actionLevel2_clicked()
{
    set_levelFon();
    ui->stop->setVisible(false);
    ui->start->setVisible(false);
    ui->retry->setVisible(false);
    ui->CL->setVisible(false);
    level = 2; step = 1; withapple = false; numberofegik = 0; finish = false; crying = false;  failed = false;
    appleex = true; apple2ex = true;
    ui->Level2_edit->setVisible(true);
    ui->back->setVisible(true);
    ui->start->setVisible(true);
    ui->level_1->setVisible(false);
    ui->level_2->setVisible(false);
    ui->level_3->setVisible(false);
    ui->level_4->setVisible(false);
    ui->level_5->setVisible(false);
    ui->level_6->setVisible(false);
    ui->level_7->setVisible(false);
    ui->level_8->setVisible(false);
    ui->back_small->setVisible(false);
    scene->clear();
    QPixmap level2_back(QApplication::applicationDirPath()+"/Blocks/level2_back.png");
    back = scene->addPixmap(level2_back);
    QPixmap egik(QApplication::applicationDirPath()+"/Blocks/left_without.png");
    QPixmap appl(QApplication::applicationDirPath()+"/Blocks/apple.png");
    player = scene->addPixmap(egik);
    player2 = scene->addPixmap(egik);
    apple = scene->addPixmap(appl);
    apple2=scene->addPixmap(appl);
    apple->setPos(310,320);
    apple2->setPos(895,320);
    player->setPos(367,0);
    player2->setPos(267,0);
    QPixmap status_bar(QApplication::applicationDirPath()+"/Blocks/status_bar.png");
    statusbar = scene->addPixmap(status_bar);
    statusbar->setPos(1151,18);
    QPixmap minieg(QApplication::applicationDirPath()+"/Blocks/egik_mini.png");
    minieg1 = scene->addPixmap(minieg);
    minieg2 = scene->addPixmap(minieg);
    minieg1->setPos(1171,24);
    minieg2->setPos(1171,86);
}

void Blocks::on_back_small_clicked()
{
    emit to_menu();
}

void Blocks::set_levelFon()
{
    setStyleSheet("background-image: url(Blocks/back_level.png)");
}

void Blocks::set_subMenuFon()
{
    setStyleSheet("background-image: url(Blocks/back_submenu.png)");
}
