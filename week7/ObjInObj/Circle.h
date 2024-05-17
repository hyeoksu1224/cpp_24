#ifndef __CIRCLE__
#define __CIRCLE__
#include "Point.h"

class Circle{
    Point center;
    int radius;
public:
    Circle(int r);
    Circle(Point p = Point(0, 0), int r = 0);
    Circle(int x, int y, int r = 0);
    void print();
};
#endif