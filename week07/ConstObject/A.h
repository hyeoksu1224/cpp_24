#ifndef __A__
#define __A__
#include <iostream>
using namespace std;

class A{
    // 생성자의 초기화 리스트에서 초기화 하면 상수의 값을 object마다 다르게 할 수 있다.
    const int c;
    // 선언문에서 초기화 했기 때문에 class 전체에서 똑같은 상수
    const int hundred = 100;
public:
    A(int n = 0);
    void display() const; // 이 함수 안에서는 멤버 변수의 값을 변경할 수 없다.
                          // const 선언 된 object에 대해서는 const 멤버 함수만 호출할 수 있다.
                          // 실제로 멤버 변수를 바꾸지 않아도 const 선언이 안되어 있으면 호출 불가능
                          // const 수식어도 function signature에 포함되어 있다. -> 중복 가능
    void display();
};
#endif

// Call by ref/pointer 인 경우에만 인자의 const 선언이 의미가 있다.
// Call by value의 경우 실 인자의 값이 바뀌지 않기 때문이다.

// non - const로 선언된 ref/pointer에는 non-const만 대입할 수 있다.
// const로 선언된 ref/pointer에는 const/non-const에 대입할 수 있다.