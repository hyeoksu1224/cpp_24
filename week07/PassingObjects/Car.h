#ifndef __CAR__
#define __CAR__
#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    string color;
public:
    Car(int s = 0, string c = "White");
    void display();
};
void swapObjects(Car c1, Car c2);
void pointerSwap(Car* c1, Car* c2);
void refSwap(Car& c1, Car& c2);

Car buyCar(string color);
#endif