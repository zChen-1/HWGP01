#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class logindialog;
}

class logindialog : public QDialog
{
    Q_OBJECT

public:
    explicit logindialog(QWidget *parent = nullptr);
    ~logindialog();

    bool getIsLoggedIn() {return isLoggedIn;};

private slots:
    void on_pushButton_clicked();

private:
    Ui::logindialog *ui;
    bool isLoggedIn;
};

#endif // LOGINDIALOG_H
