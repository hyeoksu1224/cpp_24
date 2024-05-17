#ifndef __RECTANGLE__
#define __RECTANGLE__
#include <iostream>
#include "Shape.h"

class Rectangle : public Shape{
    int width, height;
public:
    void setWidth(int w);
    void setHeight(int h);
    void draw();
};
#endif