#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactUs.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    isAdministrator = false;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cWindow;
    delete lDialog;
}

void MainWindow::on_actionContact_Us_triggered()
{
    cWindow = new ContactUs(this);
    cWindow->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    cWindow->show();
}

void MainWindow::on_actionLogin_triggered()
{
    lDialog = new logindialog;
    lDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinMaxButtonsHint);
    lDialog->exec();
    isAdministrator = lDialog->getIsLoggedIn();
    // qDebug() << "isAdministrator: " << isAdministrator;
}

void MainWindow::on_actionLog_Out_triggered()
{
    if(!isAdministrator) {
        QMessageBox::information(this, "Error", "User is not logged in.");
    }else{
        QMessageBox::information(this, "Success", "User is now logged out.");
        isAdministrator = false;
    }
}

void MainWindow::loginAdminAccess(bool loginAccess) {
   isAdministrator = loginAccess;
}
