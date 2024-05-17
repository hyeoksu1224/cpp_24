#include "A.h"

A::A(){
    cout << "A() called\n";
    p = 1;
}

A::A(int v){
    cout << "A(int) called\n";
    p = v;
}

int A::getP(){
    return p;
}

void A::setP(int v){
    p = (v < 0) ? 0 : v;
}