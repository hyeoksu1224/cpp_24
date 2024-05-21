#include <iostream>
#include "BitSet.h"

int main(int argc, char *argv[]){
    BitSet b1(132), b2(131); //main에 try - catch가 필요하겠다.
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    try{
        cout << "b1+b2= " << b1 + b2 <<endl;
    }
    catch (IncompatibleException& i){
        cout << "In + operation, the operands are not compatible." << endl;
        cout << "The size of the first Bitset is " << i.nbits1 << endl;
        cout << "The size of the second Bitset is " << i.nbits2 << endl;
    }
}