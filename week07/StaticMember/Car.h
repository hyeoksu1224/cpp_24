#ifndef __CAR__
#define __CAR__
#include <iostream>
#include <string>
using namespace std;

class Car{
    string color;
    int serial;
    static int s;
    const static int j = 1; // 정수 혹은 enmeration의 const만 class 선언 내에서 초기화할 수 있다.
    const static int* p;
public:
    int speed;
    static int numberOfCars;
    Car(int s = 0, string c = "White");
    void display();
};
#endif