// contactUs.cpp by Paul Jo

#include "contactUs.h"
#include "ui_contactUs.h"

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
}

ContactUs::~ContactUs()
{
    delete ui;
}
