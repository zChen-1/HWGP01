#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>

namespace Ui {
class addShape;
}

class addShape : public QDialog
{
    Q_OBJECT

public:
    explicit addShape(QWidget *parent = nullptr);

    void initInput();

    ~addShape();

private slots:

private:
    Ui::addShape *ui;
};

#endif // ADDSHAPE_H
