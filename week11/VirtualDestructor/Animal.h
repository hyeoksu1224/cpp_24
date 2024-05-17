#ifndef __ANIMAL__
#define __ANIMAL__
#include <iostream>
using namespace std;

class Animal{
public:
    Animal();
    virtual ~Animal();
    virtual void speak();
};
#endif