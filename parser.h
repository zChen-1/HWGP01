#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include "vector.h"
// Shape, Line, Circle... etc has to be done
// #include "shape.h"
// #include "line.h"
// #include "circle.h"
// #include "polygon.h"
// #include "polyline.h"
// #include "rectangle.h"
// #include "square.h"
// #include "ellipse.h"
// #include "text.h"

using namespace std;

gp::vector<Shape*> ParseFile(int size);
Shape* readLine(ifstream &in, int id);
Shape* readPolyLine(ifstream &in, int id);
Shape* readPolygon(ifstream &in, int id);
Shape* readRectangle(ifstream &in, int id);
Shape* readSquare(ifstream &in, int id);
Shape* readEllipse(ifstream &in, int id);
Shape* readCircle(ifstream &in, int id);
Shape* ReadText(ifstream& in,int id);
QColor getColor(string color);
PenStyle getPenStyle(string style);
BrushStyle getBrushStyle(string brush);
PenJoinStyle getPJStyle(string join);
PenCapStyle getPCStyle(string cap);

#endif // PARSER_H
