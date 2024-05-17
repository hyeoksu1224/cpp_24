#ifndef __CIRCLE__
#define __CIRCLE__
#include <iostream>
#include "Shape.h"

class Circle : public Shape{
    int radius;
public:
    void setRadius(int r);
    void draw();
};
#endif