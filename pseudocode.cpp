#include "pseudocode.h"
#include "ui_pseudocode.h"

PseudoCode::PseudoCode(QWidget *parent) : QWidget(parent),
    ui(new Ui::PseudoCode)
{
    ui->setupUi(this);
}
PseudoCode::~PseudoCode()
{
    delete ui;
}
