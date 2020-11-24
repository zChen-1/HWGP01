#include "deleteshape.h"
#include "ui_deleteshape.h"

deleteshape::deleteshape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteshape)
{
    ui->setupUi(this);
    ui->areYouSureLabel->setVisible(false); // label is false on init
}

deleteshape::~deleteshape()
{
    delete ui;
}
