#include "Cat.h"

Cat::Cat(){
    cout << "Cat 생성자" << endl;
}

Cat::~Cat(){
    cout << "Cat 소멸자" << endl;
}

void Cat::speak(){
    cout << "야옹" << endl;
}