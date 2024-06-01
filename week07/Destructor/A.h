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
    int p;
public:
    // A의 default 생성자
    A(int v = 0);
    // A의 소멸자
    ~A(); 
    // P의 접근자
    int getP();
    // P의 설정자
    void setP(int v);
};

// 소멸자를 정의하지 않는다면 디폴트 소멸자가 자동으로 생성된다.
// 메모리 누수를 방지하기 위해서 동적 할당 받은 메모리를 반납하는 소멸자가 반드시 필요하다.
#endif