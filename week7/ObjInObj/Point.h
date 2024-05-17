#ifndef __POINT__
#define __POINT__
#include <iostream>
using namespace std;

class Point{
    int x, y;
public:
    Point(int x = 0, int y = 0);
    void print();
};

#endif