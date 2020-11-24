#ifndef DELETESHAPE_H
#define DELETESHAPE_H

#include <QDialog>

namespace Ui {
class deleteshape;
}

class deleteshape : public QDialog
{
    Q_OBJECT

public:
    explicit deleteshape(QWidget *parent = nullptr);
    ~deleteshape();

private:
    Ui::deleteshape *ui;
};

#endif // DELETESHAPE_H
