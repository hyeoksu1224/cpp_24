#include "A.h"

//private 멤버 변수를 초기화 리스트를 통해 간단히 초기화 했다.
A::A(int v) : p(v) {
    cout << this << " : A(int) called\n";
    //p = v; //초기화 리스트를 사용했기 때문에 이 실행문은 필요 없다.
}
// const type은 선언과 동시에 초기화해야 한다.
// 상수 멤버 변수의 경우 const가 붙었기 때문에 실행문에서 값을 변경할 수 없다.
// 하지만 초기화리스트를 이용한다면 각 instance마다 상수 멤버 변수의 값을 다르게 할 수 있다. 

A::~A(){
    cout << this << " : ~A() called\n";
}

int A::getP(){
    return p;
}

// reference type도 초기화 리스트가 필요하다.
B::B(int& v) : r(v) {
    cout << this << " : B(int) called\n";
} 

B::~B(){
    cout << this << " : ~B() called\n";
}

int B::getR(){
    return r;
}

void B::setR(int v){
    r = v;
}