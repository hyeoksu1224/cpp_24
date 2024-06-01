// lambda : function pointer에 해당
// 이름이 없는 함수이다. []가 lambda 함수임을 알려줌

#include <iostream>
#include <functional>
// functional을 사용해야 
// 함수 포인터, 멤버 함수 포인터, 람다 함수 등을 함수 객체로 변환하거나,
// std::bind를 사용하여 함수 객체를 생성하고 특정 인자를 바인딩할 수 있다.
using namespace std;

bool cmp_f(const int& a, const int& b){
    return a % 3 < b % 3;
}

bool compare_ints1(const int& a, const int& b, bool(*f)(const int& a, const int& b)){
    return f(a, b);
}

int main(){
    void (*fp)() = [](){
        cout << "a function()" << endl;
    };
    // 이름이 없고, return type이 없다.
    // lambda 함수는 return type을 정의하지 않는다.

    fp();
    // 기존에는 foo라는 함수를 function pointer로 사용할 때
    // void (*fp)() = foo; 와 같이 사용했다.

    int i = 7, j = 5;
    bool (*fp1)(const int & a, const int & b) = [](const int& a, const int& b){
        return a % 3 < b % 3;
    }; // cmp_f와 같다.
    auto fp2 = [](const int& a, const int& b){
        return a % 3 < b % 3;
    }; // auto로 인해 fp는 자연스럽게 bool function pointer type이 된다.

    cout << i << " " << j << endl;
    cout << "result of comparison : " << compare_ints1(i, j, cmp_f) << endl;
    cout << "result of comparison : " << compare_ints1(i, j, fp1) << endl;
    cout << "result of comparison : " << compare_ints1(i, j, fp2) << endl;
    cout << "result of comparison : " << compare_ints1(i, j, [](const int& a, const int& b){
                                                                return a % 3 < b % 3;
                                                                }
                                                                ) << endl;
    // function pointer 자리에 lambda를 넣을 수 있다.
}