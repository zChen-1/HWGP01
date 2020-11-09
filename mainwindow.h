#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactus.h"
#include "login.h"

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

private:
    Ui::MainWindow *ui;
    ContactUs *cWindow;
    login *lWindow;
};
#endif // MAINWINDOW_H
