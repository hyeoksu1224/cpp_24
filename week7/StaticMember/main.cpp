#include "Car.h"

int main(){
    Car c1, carArray[10];
    Car* ptr = new Car[30];

    cout << "Number of Cars is " << Car::numberOfCars << endl;
    cout << "Number of Cars is " << c1.numberOfCars << endl; 
    cout << "Number of Cars is " << carArray[0].numberOfCars << endl; 
    cout << "Number of Cars is " << ptr->numberOfCars << endl; 
    return 0;
}