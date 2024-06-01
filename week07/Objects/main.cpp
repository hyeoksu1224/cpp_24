#include "Car.h"

int main(){
    Car carArray[3] = { // 객체들로 배열을 만들 수 있다.
        Car(10, "White"),
        Car(20, "Red"),
        Car(0, "Blue") // 객체 별로 생성자를 호출할 수 있다.
    };
    for (int i = 0; i < 3; i++){
        carArray[i].display();
    }
    Car myCar; //정적 메모리 할당으로 객체를 생성
    Car* pCar = new Car[3]; // 동적 메모리 할당으로 객체를 생성
                            // 동적으로 객체 배열을 할당받을 땐 생성자의 인자를 지정할 수 없다.
                            // 즉, 디폴트 생성자가 필요하다.
    delete[] pCar;
    pCar = new Car(10, "Red"); // 객체 하나를 동적으로 생성할 때엔 생성자의 인자를 지정할 수 있다.
    pCar->speed = 100; //객체 포인터를 통해서 멤버에 접근할 수 있다.
    pCar->display();   // x->y 는 (*x).y 를 의미한다.
    delete pCar;
    return 0;
}

// this는 현재 코드를 실행하는 객체를 가리키는 포인터이다.
// this가 필요한 예
// void Car::setSpeed(int speed){
//    if(speed > 0) this->speed = speed; // speed는 매개변수, this->speed는 멤버변수
//    else this->speed = 0;
//}
// 멤버 함수임을 강조하고 싶을 때에도 사용 가능