#include "Circle.h"

void Circle::setRadius(int r){
    radius = r;
}

void Circle::draw(){
    Shape::draw();
    std::cout << "Circle : " << radius;
}