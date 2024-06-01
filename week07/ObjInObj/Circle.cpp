#include "Circle.h"

Circle::Circle(int r) : center(0,0), radius(r){}

Circle::Circle(Point p, int r): center(p), radius(r){}

Circle::Circle(int x, int y, int r) : center(x,y), radius(r){}

void Circle::print(){
    center.print();
    cout << " : " << radius << endl;
}