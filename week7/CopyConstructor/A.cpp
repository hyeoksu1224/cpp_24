#include "A.h"

A::A(int v) : p(v) {
    cout << this << " : A(int) called\n";
}

A::A(const A& obj){
    p = obj.p;
    cout << this << " : A(const A& " << &obj << ")\n";
}

A::~A(){
    cout << this << " : ~A() called\n";
}

int A::getP(){
    return p;
}

void A::setP(int v){
    p = (v < 0) ? 0 : v;
}

A A::return_this(){
    return *this;
}

A plusOne(A c){
    A result(c.getP() + 1);
    return result;
}