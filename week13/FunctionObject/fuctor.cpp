// A function Object or functor
// 함수 호출처럼 사용할 수 있는 객체
// 즉, 실행문에서 object()의 형태로 사용할 수 있는 객체
// functor에서는 operator ()가 overloaded되었다.
// object이기 때문에 설계도 즉, 클래스가 필요하다.
// 선언문에서는 괄호가 붙어도 생성자를 호출한다 (클래스라서)

#include <iostream>
using namespace std;

struct Cmp{ // functor class
    bool operator() (const int& a, const int& b) const{
        return a % 3 < b % 3;
    }
};

template<class F>
bool compare_ints2(const int& a, const int& b, F f){
    // 함수 포인터의 타입을 template로 받았기 때문에 어떤 type의 함수라도 받을 수 있다.
    return f(a,b);
}

int main(){
    Cmp obj; // Cmp type의 객체 obj 선언
    int i = 7, j = 5;

    cout << i << " " << j << endl;
    cout << "obj(i, j) returns " << obj(i,j) << endl; // obj의 () 연산자 즉, functor사용됨

    // obj 없이 functor를 사용하려면 temp obj를 생성해준 뒤 사용해야 한다.

    cout << "Cmp()(i, j) returns " << Cmp()(i, j)<< endl; // Cmp()에서 ()는 필수적이다.

    // template function을 이용한 function parameter
    cout << "result of comparison : " << compare_ints2(i, j, Cmp());
    // function parameter는 obj로 받는다.
}