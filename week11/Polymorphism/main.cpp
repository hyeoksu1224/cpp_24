#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

int main(){
    Rectangle r;
    r.setOrigin(1,1);
    r.setWidth(3);
    r.draw(); std::cout << std::endl;

    Shape *p_s;
    p_s = &r; //Rectangle의 주소를 shape pointer로 implicit upcasting
    p_s->setOrigin(10,10);
    //p_s->setWidth(100); //compile error. why? : p_s is not Rectangle pointer
    p_s->draw(); std::cout << std::endl;

    Rectangle *p_r;
    p_r = (Rectangle *)p_s; //Shape pointer를 Rectangle pointer로. 변환 생성자는 필요 x
    p_r->setOrigin(8,8);
    p_r->setWidth(16);
    p_r->draw(); std::cout << std::endl;

    ((Circle *)p_s)->setRadius(11); //shape pointer를 Circle pointer로 downcasting, 명시 필요
    ((Circle *)p_s)->draw(); std::cout << std::endl;
    p_r->draw(); std::cout << std::endl;

    Shape& s = r; //implicit upcasting Rectangle->Shape
    s.setOrigin(5,5);
    //s.setWidth(7); //complie error. why? s is not Rectangle
    s.draw(); std::cout << std::endl;

    //Rectangle& r_r = (Rectangle)s; //complie error. why? Shape -> Rectangle 변환 생성자가 없음

    Circle c;
    c.setOrigin(0,0);
    c.draw();
    std::cout << std::endl;
    move(r, 1, 1);
    move(c, 2, 2);
    r.draw();
    std::cout << std::endl;
    c.draw();
    std::cout << std::endl;
}