#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"

class Text : public Shape
{
public:
    Text(QPaintDevice * device = nullptr, int id = -1) : Shape{device, id, ShapeType::Text} { }
    ~Text() override { }

private:


};

#endif // TEXT_H
