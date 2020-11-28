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
    explicit deleteshape(QWidget *parent = nullptr, const int &shapeCountFromMain = 0);
    ~deleteshape();

    /*!
     * \brief getShapeCount
     * \return shapeCount
     */
    int getShapeCount() {return shapeCount;};


private slots:
    void on_buttonBox_accepted();

private:
    Ui::deleteshape *ui;

    int shapeCount; // temp TODO remove
};

#endif // DELETESHAPE_H
