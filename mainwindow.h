#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include "contactUs.h"
#include "logindialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionContact_Us_triggered();

    void on_actionLogin_triggered();

    void on_actionLog_Out_triggered();

    void loginAdminAccess(bool loginSuccess);

private:
    Ui::MainWindow *ui;
    ContactUs *cWindow;
    logindialog *lDialog;

    bool isAdministrator;
};
#endif // MAINWINDOW_H
