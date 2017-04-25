#ifndef PSEUDOCODE_H
#define PSEUDOCODE_H

#include <QWidget>
#include <QPicture>
#include <QTCore>
#include <QtGUI>
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

namespace Ui {
class PseudoCode;
}

class PseudoCode : public QWidget
{
    Q_OBJECT

public:
    explicit PseudoCode(QWidget *parent = 0);
    ~PseudoCode();
signals:
    void to_menu();
protected:

private:
    Ui::PseudoCode *ui;
};

#endif // PSEUDOCODE_H
