#include "A.h"

A::A(int n) : c(n){}

void A::display() const{
    cout << this << " ] " << c << " , ";
    cout << hundred << endl;
}

void A::display(){
    cout << this << " ] " << c << " , ";
    cout << hundred << endl;
}