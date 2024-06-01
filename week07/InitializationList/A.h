#ifndef __A__
#define __A__
#include <iostream>
#include <string>
using namespace std;

// 소멸자 : 객체의 생성 및 사용 이후 객체의 소멸을 담당한다.
// 소멸자는 클래스 이름에 ~가 붙는다.
// 값을 반환하지 않는다.
// public 멤버 함수로 선언된다.
// 매개변수를 받지 않는다.
// 중복 정의도 불가능하다.

class A{
    //private 멤버변수 선언
    const int p;
public:
    // A의 default 생성자
    A(int v = 0);
    // A의 소멸자
    ~A(); 
    // P의 접근자
    int getP();
};

class B{
    //private 멤버변수 reference type으로 선언
    // reference type은 선언과 동시에 초기화해야 한다.
    //이 경우 초기화 리스트가 반드시 필요함.
    int& r;
public:
    B(int& x);
    ~B();
    //R의 접근자
    int getR();
    //R의 설정자
    void setR(int v);
};

// 멤버변수를 효율적으로 초기화 시킬 수 있다.
// 초기화 리스트 미사용 시 멤버변수를 만들기 위해 기본 생성자를 호출한 후, 대입 연산자를 호출한다.
// 초기화 리스트 사용 시 기본 생성자를 호출하여 임시 변수를 만들 필요 없이, 한번에 초기화 된다.
#endif