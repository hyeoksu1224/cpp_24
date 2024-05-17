#include "Dog.h"

Dog::Dog(){
    cout << "Dog 생성자" << endl;
}

Dog::~Dog(){
    cout << "Dog 소멸자" << endl;
}

void Dog::speak(){
    cout << "멍멍" << endl;
}