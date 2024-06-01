#include "Car.h"

Car::Car(int s, string c) : speed(s), color(c){}

void Car::display(){
    cout << this << " ] " << speed << ", " << color << endl;
}

// 아래 함수는 local에서 값의 전환만 일어나고, 실제 객체의 전환은 이뤄지지 않는다.
// 이를 해결하기 위해 포인터를 매개변수로 전달해야 한다.
void swapObjects(Car c1, Car c2){
    Car tmp;
    tmp = c1;
    c1 = c2;
    c2 = tmp;
}

// 포인터가 매개변수
void pointerSwap(Car* c1, Car* c2){
    Car tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

// 객체의 레퍼런스가 매개변수인 경우에도 가능
void refSwap(Car& c1, Car& c2){
    Car tmp;
    tmp = c1;
    c1 = c2;
    c2 = tmp;
}

// 함수가 객체를 반환하는 경우
Car buyCar(string color){
    Car tmp(30, color);
    tmp.display();
    return tmp;
}