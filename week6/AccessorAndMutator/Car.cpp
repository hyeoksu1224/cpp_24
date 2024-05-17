#include "Car.h"

int Car::getSpeed(){
    return speed;
}

// 설정자의 매개 변수를 통하여 잘못된 값이 전달되는 경우 이를 사전에 차단할 수 있다.
void Car::setSpeed(int s){
    speed = (s > 0) ? 0 : s;
} // 0 또는 음수가 전달되면 speed를 0으로 설정하는구나!

string Car::getColor(){
    return color;
}
// 접근자만을 제공하면 자동적으로 읽기만 가능한 멤버 변수를 만들 수 있다.
/*void Car::setColor(string c){
    color = c;
}
*/
// color 변수는 읽기만 가능하고, 수정할 수 없다.