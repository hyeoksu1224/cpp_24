#ifndef __CAR__
#define __CAR__
#include <iostream>
#include <string>
using namespace std;

class Car{
    string color;
public:
    int speed;
    Car(int s = 0, string c = "white");
    void display();
};
#endif