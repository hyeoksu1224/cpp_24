#include "Shape.h"

void Shape::setOrigin(int x, int y){
    this->x = x; this->y = y;
}
void Shape::draw(){
    std::cout << "Shape ( " << x << ", " << y << " ) "; 
}
void move(Shape& s, int dx, int dy){
    s.setOrigin(dx, dy);
}