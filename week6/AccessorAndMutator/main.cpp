#include "Car.h"

int main(){
    Car c;
    
    c.setSpeed(10);
    cout << c.getSpeed() << endl;
    //c.setColor("White");
    cout << c.getColor() << endl;
    return 0;
}