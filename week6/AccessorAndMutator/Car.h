#ifndef __CAR__
#define __CAR__
#include <iostream>
#include <string>
using namespace std;

// 접근자 (accessor) : 멤버 변수의 값을 반환한다.
// 설정자 (mutator)  : 멤버 변수의 값을 설정한다.

class Car{
    //private 멤버변수 선언
    int speed;
    string color = "Red";
public:
    // speed 접근자
    int getSpeed();
    // speed 설정자
    void setSpeed(int s);
    // color 접근자
    string getColor();
    // color 설정자
    void setColor(string c);
};

// 접근자와 설정자의 장점
// 설정자의 매개 변수를 통하여 잘못된 값이 전달되는 경우 이를 사전에 차단할 수 있다.
// 멤버 변수값을 필요할 때마다 계산하여 반환할 수 있다.
// 접근자만을 제공하면 자동적으로 읽기만 가능한 멤버 변수를 만들 수 있다.
#endif