#include "addshape.h"
#include "ui_addshape.h"

addShape::addShape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addShape)
{
    ui->setupUi(this);
    initInput();
}

/*!
 * \brief addShape::~addShape
 * deletes ui
 */
addShape::~addShape()
{
    delete ui;
}

/*!
 * \brief addShape::initInput
 * Initializes all of the input boxes to be disabled when window is first opened.
 */
void addShape::initInput() {

}
