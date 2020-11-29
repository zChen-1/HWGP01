#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Rectangle} {}
    ~Rectangle() override { }


private:

};


#endif // RECTANGLE_H
