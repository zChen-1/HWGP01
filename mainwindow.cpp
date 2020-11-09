#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cWindow;
}

void MainWindow::on_actionContact_Us_triggered()
{
    cWindow = new ContactUs(this);
    cWindow->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    cWindow->show();
}
