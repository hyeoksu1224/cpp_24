#ifndef __DOG__
#define __DOG__
#include <iostream>
#include "Animal.h"

class Dog : public Animal{
public:
    Dog();
    ~Dog();
    void speak();
};
#endif