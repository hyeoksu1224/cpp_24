#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

int main(){
    Rectangle r;
    r.setOrigin(1,1);
    r.setWidth(3); r.setHeight(3);

    Circle c;
    c.setOrigin(4,4);
    c.setRadius(5);

    Shape shapeArray[2];

    shapeArray[0] = r;
    shapeArray[1] = c;

    for (int i = 0; i < 2; i++){
        shapeArray[i].draw();
        std::cout << std::endl;
    }

    Shape* shapePtrs[2];
    shapePtrs[0] = &r;
    shapePtrs[1] = &c;

    for (int i = 0; i < 2; i++){
        shapePtrs[i]->draw();
        std::cout << std::endl;
    }
}