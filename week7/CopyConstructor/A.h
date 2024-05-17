#ifndef __A__
#define __A__
#include <iostream>
#include <string>
using namespace std;

// 복사 생성자 : 자신과 같은 타입의 객체를 매개 변수로 받는 생성자
// 복사 생성자가 없으면 자동으로 모든 멤버 변수의 값을 복사하는 디폴트 복사 생성자가 생성된다.

class A{
    //private 멤버변수 선언
    int p;
public:
    // A의 default 생성자
    A(int v = 0);
    A(const A& obj);
    // A의 소멸자
    ~A(); 
    // P의 접근자
    int getP();
    // P의 설정자
    void setP(int v);
    A return_this();
};

A plusOne(A c);
#endif