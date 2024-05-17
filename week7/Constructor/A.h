#ifndef __A__
#define __A__
#include <iostream>
#include <string>
using namespace std;

// 생성자 : 객체가 생성될 때에 필드에 초기 값을 제공하고 필요한 초기화 절차를 실행하는 멤버 함수
// 생성자는 클래스 이름과 동일하다.
// 반환값이 없다.
// 반드시 public이어야 한다.
// 중복 정의할 수 있다.

// Default constructor
// parameter가 없는 생성자 혹은 parameter가 모두 default 값을 갖는 생성자
// 클래스의 생성자가 정의되지 않으면 compiler가 자동으로 생성한다.

class A{
    //private 멤버변수 선언
    int p;
public:
    A(); // 이 라인을 주석처리하면 compile error가 발생. why? 생성자가 하나라도 있으면 디폴트 생성자가 자동 생성 X
    A(int v); // int v = 0 으로 default parameter를 준다면 위 라인을 주석처리하더라도 complie error X
              // default parameter를 준 경우  A(int v = 0)이 default constructor가 된다.
              // 두 생성자 모두 주석처리할 경우 default constructor가 자동으로 생성된다.
              // 이 경우 default constructor는 아무 것도 하지 않기 때문에
              // 지역 변수는 초기화 되지 않고 (쓰레기 값) 전역 변수는 0으로 초기화된다. 
    // P의 접근자
    int getP();
    // P의 설정자
    void setP(int v);
};

#endif