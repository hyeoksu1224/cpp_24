#ifndef __REMOTE__
#define __REMOTE__

// 순수 가상 함수란?
// 함수의 헤더만 존재하고 함수의 몸체는 없는 함수.
// 추상 클래스 : 순수 가상 함수를 하나라도 가지고 있는 클래스
// 추상 클래스는 객체를 생성할 수 없는 클래스
// 추상적인 개념을 표현하는데 적당하다..
class RemoteControl{
public:
    //순수 가상 함수 정의
    virtual void turnON() = 0;
    virtual void turnOFF() = 0;
};
#endif