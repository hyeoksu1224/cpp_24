#include "A.h"

A::A(int v){
    cout << this << " : A(int) called\n";
    p = v;
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