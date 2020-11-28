#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class addShape;
}

class addShape : public QDialog
{
    Q_OBJECT

public:
    explicit addShape(QWidget *parent = nullptr, const int &shapeCountFromMain = 0);

    void initInput();
    int getShapeCount() const;

    ~addShape();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::addShape *ui;

    int shapeCount; // TEMP, TODO replace with vector later
};

#endif // ADDSHAPE_H
