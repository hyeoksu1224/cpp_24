#ifndef __SHAPE__
#define __SHAPE__
#include <iostream>

class Shape{
protected:
    int x, y;
public:
    void setOrigin(int x = 0, int y = 0);
virtual void draw(); //virtual : super class pointer로 멤버함수를 호출하더라도 sub class의 종류에 따라 서로 다른 멤버함수가 호출되게 해 준다.
};
void move(Shape& s, int dx, int dy);
#endif