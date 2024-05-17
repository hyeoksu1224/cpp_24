#include "Point.h"

Point::Point(int x, int y) : x(x){
    this->y = y;
}

void Point::print(){
    cout << "( " << x << ", " << y << " ) ";
}