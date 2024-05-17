#include "Circle.h"

int main(){
    Point p(3,4);
    Circle c1; c1.print();
    Circle c2(2); c2.print();
    Circle c3(-1, -2); c3.print();
    Circle c4(4, 5, 1); c4.print();
    Circle c5(p, 5); c5.print();
}