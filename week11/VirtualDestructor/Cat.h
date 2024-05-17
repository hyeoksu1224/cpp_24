#ifndef __CAT__
#define __CAT__
#include <iostream>
#include "Animal.h"

class Cat : public Animal{
public:
    Cat();
    ~Cat();
    void speak();
};
#endif