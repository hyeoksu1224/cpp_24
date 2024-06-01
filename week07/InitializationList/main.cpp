#include "A.h"

A a2(3);
int g;
B b2(g);
int main(){
    A a1;
    cout << a1.getP() << endl;
    cout << a2.getP() << endl;

    int i = 100;
    B b1(i);
    cout << b1.getR() << endl; b1.setR(-1);
    cout << b1.getR() << " i : " << i <<endl;

    cout << b2.getR() << endl; b2.setR(-2);
    cout << b2.getR() << " g : " << g <<endl;

    return 0;
}