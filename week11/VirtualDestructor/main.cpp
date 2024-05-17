#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main(){
    Animal* a1 = new Dog();
    a1->speak();
    delete a1;

    Animal* a2 = new Cat();
    a2->speak();
    delete a2;
    return 0;
}
//소멸자가 virtual로 선언되지 않으면 super class의 소멸자만 실행된다.