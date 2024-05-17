#include <iostream>
#include "BitSet.h"

int main(int argc, char *argv[]){
    BitSet b1(131), b2(131), b3(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    b1+=b2;
    cout << "b1+b2= " << b1 <<endl;
}