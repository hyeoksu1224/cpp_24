#include "Car.h"

Car globalCar;


// 객체의 사용 operator .
// 객체를 이용해서 멤버에 접근할 수 있다.
// Car myCar; mycar.speed = 100
// myCar 객체로부터 speed라는 멤버 변수에 접근한다는 뜻
// 멤버 변수에 접근하기 위해서는 . 연산자를 사용
// 객체도 pointer, reference 사용이 가능하다.
// Car* pCar = &myCar;
// -> 연산자 사용이 가능하다.
// pCar->speed = 120; == (*pCar).speed = 120;
// pCar->speedUp();
int main(){
    Car localCar;
    globalCar.speed = 100;
    localCar.speed = 60;
    localCar.color = "White";

    cout << "현재 global 차의 속도는 " << globalCar.speed << endl;
    cout << "현재 local 차의 속도는 " << localCar.speed << endl;

    return 0;
}