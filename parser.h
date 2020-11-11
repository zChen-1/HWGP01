#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include "vector.h"
#include "shape.h"
#include "line.h"
#include "circle.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "text.h"

using namespace std;

gp::vector<Shape*> ParseFile(int size);
Shape* readLine(ifstream &inFile, int id);
Shape* readPolyLine(ifstream &inFile, int id);
Shape* readPolygon(ifstream &inFile, int id);
Shape* readRectangle(ifstream &inFile, int id);
Shape* readSquare(ifstream &inFile, int id);
Shape* readEllipse(ifstream &inFile, int id);
Shape* readCircle(ifstream &inFile, int id);
Shape* ReadText(ifstream& inFile,int id);
QColor getColor(string color);
PenStyle getPenStyle(string style);
BrushStyle getBrushStyle(string brush);
PenJoinStyle getPJStyle(string join);
PenCapStyle getPCStyle(string cap);

#endif // PARSER_H
