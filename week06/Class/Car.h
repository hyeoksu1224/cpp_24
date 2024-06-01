#ifndef __CAR__
#define __CAR__
#include <iostream>
#include <string>
using namespace std;

// 클래스의 구성
// 클래스는 객체의 설계도라 할 수 있다.
// 클래스는 멤버 변수와 멤버 함수로 이루어진다.
// 멤버 변수는 객체의 속성을 나타낸다.
// 멤버 함수는 객체의 동작을 나타낸다.
class Car{
public:  //멤버 변수 선언
    int speed;
    int gear;
    string color;

    //멤버 함수 선언
    void speedUp();
    void speedDown();
};
#endif