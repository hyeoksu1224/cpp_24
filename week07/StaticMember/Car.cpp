#include "Car.h"

// static 멤버 변수는 초기화 리스트로 초기화 할 수 없다.
Car::Car(int s, string c) : speed(s), color(c) /*, s(s)*/{ serial = ++numberOfCars;}

void Car::display(){
    cout << this << " ] " << serial << ", ";
    cout << speed << " , " << color << endl;
}

// static member variable의 초기화는 class 밖에서 해주어야 한다.
// 이 변수는 클래스의 객체가 없어도 존재한다.
int Car::numberOfCars = 0;

// 초기화 문에서는 static keyword를 사용하면 안된다.
int Car::s = 0;

// const static 멤버 변수의 경우엔 const를 반드시 사용한다.
const int Car::j = 0;

int g;
const int* Car::p = &g;

// static keyword
// static local variable : 지역 변수를 정적으로 할당한다.
// static global variable/function : 선언된 파일 외부에서 접근을 불가능하게 한다.
// static member variable : 클래스 공통으로 공유하는 변수
