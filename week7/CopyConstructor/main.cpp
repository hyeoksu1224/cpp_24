#include "A.h"

int main(){
    A a1(10), a2(a1);
    cout << a1.getP() << endl;
    cout << a2.getP() << endl;
    a2 = plusOne(a1).return_this();
    cout << a2.getP() << endl;
    return 0;
}