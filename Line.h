#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line(int front, int end) : Shape{device, id, ShapeType::Line} {}
    ~Line() override { }

    void set_points(const QPoint& point_begin, const QPoint& point_end);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    QPoint point_begin;
    QPoint point_end;
};

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Polyline} {}
    ~Polyline() override { }

    void set_point(const QPoint& point);

    void draw(const int translate_x = 0, const int translate_y = 0) override;

private:
    vector<QPoint> points;
};

#endif // LINE_H
