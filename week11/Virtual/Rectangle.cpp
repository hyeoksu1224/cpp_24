#include "Rectangle.h"

void Rectangle::setWidth(int w){
    width = w;
}

void Rectangle::setHeight(int h){
    height = h;
}

void Rectangle::draw(){
    Shape::draw();
    std::cout << "Rectangle : " << width << " x " << height;
}