#include "logindialog.h"
#include "ui_logindialog.h"

logindialog::logindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logindialog)
{
    isLoggedIn = false;
    ui->setupUi(this);
}

logindialog::~logindialog()
{
    delete ui;
}

void logindialog::on_pushButton_clicked()
{
    // Login information to test against.
    // for demo purposes only
    QString username = "Admin";
    QString password = "password";

    // Input data
    QString usernameInput = ui->usernameField->text();
    QString passwordInput = ui->passwordField->text();

    // debug
    // qDebug() << "usr: " << usernameInput << " pw: " << passwordInput;

    if(usernameInput == username && passwordInput == password) {
        QMessageBox::information(this, "Success", "Logged in as Administrator.");
        isLoggedIn = true;
        this->close();
    }else {
        QMessageBox::information(this, "Error", "Incorrect login information.");
        isLoggedIn = false;
    }
}
