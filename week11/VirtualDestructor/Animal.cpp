#include "Animal.h"

Animal::Animal(){
    cout << "Animal 생성자" << endl;
}

Animal::~Animal(){
    cout << "Animal 소멸자" << endl; 
}

void Animal::speak(){
    cout << "Animal speak()" << endl;
}