#include "deleteshape.h"
#include "ui_deleteshape.h"
#include <QMessageBox>
#include <QDebug>

deleteshape::deleteshape(QWidget *parent, const int &shapeCountFromMain) :
    QDialog(parent),
    ui(new Ui::deleteshape),
    shapeCount {shapeCountFromMain}
{
    ui->setupUi(this);
}

deleteshape::~deleteshape()
{
    delete ui;
}

void deleteshape::on_buttonBox_accepted()
{
    QMessageBox msgBox(this);
    msgBox.setText("The canvas has been modified.");
    msgBox.setInformativeText(("Are you sure you want to delete shape\n# " + ui->shapeIDLineEdit->text() + "?"));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
    msgBox.setDefaultButton(QMessageBox::Save);
    int choice = msgBox.exec();

    switch (choice) {
      case QMessageBox::Save:
        // delete shape from vector
        shapeCount -= 1;
        break;
      case QMessageBox::Discard:
        qDebug() << "DBG: Shape has NOT been deleted.";
        break;
      default:
        qDebug() << "ERR: Default case in deleteshape::on_buttonBox_accepted";
        break;
    }

}
