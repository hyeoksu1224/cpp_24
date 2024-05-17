#include "Car.h"

Car::Car(int s, string c) : speed(s), color(c){}
void Car::display(){
    cout << this << " ] " << speed << ", " << color << endl;
}