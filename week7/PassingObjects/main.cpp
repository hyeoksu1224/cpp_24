#include "Car.h"

int main(){
    Car redCar(100, "Red"), blueCar(50, "Blue");
    redCar.display(); blueCar.display();
    swapObjects(redCar, blueCar);
    redCar.display(); blueCar.display();
    pointerSwap(&redCar, &blueCar);
    redCar.display(); blueCar.display();
    refSwap(redCar, blueCar);
    redCar.display(); blueCar.display();

    Car myCar;
    myCar.display();
    myCar = buyCar("Green"); // 객체의 치환 연산이 실행됐다.
                             // 할당 연산자 operator = 를 정의하지 않았다면
                             // 자동으로 디폴트 할당 연산자가 추가된다.
                             // 자동 디폴트 할당 연산자
                             // Car& Car::operator =(const Car& c2){
                             // speed = c2.speed;
                             // color = c2.color;
                             // return *this;  
                             //}
    myCar.display();

    Car* ptr = new Car[3];
    // cout << *ptr == *(ptr + 1) << endl; // compile error : 연산자 오버로딩이 되지 않음.
    ptr->display();
    (ptr + 1)->display();
    *ptr = redCar; // 디폴트 할당 연산자가 수행됨.
    ptr->display(); 
    return 0;
}