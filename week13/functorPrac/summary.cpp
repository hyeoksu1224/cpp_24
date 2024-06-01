// 함수 인자가 functor로 선언되어 있을 때 function pointer를 인자로 넘겨줄 수 없다.
// 함수 인자가 function pointer로 선언되어 있을 때 functor를 인자로 넘겨줄 수 없다.
// template function을 이용하면 functor와 function pointer를 다 함수 인자로 사용할 수 있다.

#include <iostream>
using namespace std;

struct Cmp{
    bool operator()(const int& a, const int& b) const{
        return a % 3 < b % 3;
    }
};

bool cmp_f(const int& a, const int& b){
    return a % 3 < b % 3;
}

bool compare_ints1(const int& a,const int& b, bool(*f)(const int&, const int&)){
    // return type이 bool이고 const int& 두 개를 parameter로 갖는 function pointer를 parameter로 갖는다.
    // functor를 argument로 받을 수 없고, function pointer만 받을 수 있다.
    return f(a,b);
}

template<class F>
bool compare_ints2(const int& a, const int& b, F f){
    // template parameter이기 때문에 functor와 function pointer 둘 다 받을 수 있다. 
    return f(a,b);
}

bool compare_ints3(const int& a, const int& b, Cmp f){
    // object parameter를 갖는다.
    // 이 경우 functor를 인자로 받을 수 있지만 function pointer는 받을 수 없다.
    return f(a, b);
}

int main(){ 
    int i = 7, j = 5;

    cout << i << " " << j << endl;
    cout << "result of comparison (1) : " << compare_ints1(i, j, cmp_f) << endl;
    // 함수 포인터 인자 : cmp_f라는 함수 이름만 전달해줘도 된다.
    // cout << "result of comparison (2) : " << compare_ints1(i, j, Cmp()) << endl;
    // Cmp()라는 임시 객체(functor)를 인자에 전달해준다면 컴파일 에러. 함수 포인터만 가능하다.
    cout << "result of comparison (3) : " << compare_ints2(i, j, cmp_f) << endl;
    cout << "result of comparison (4) : " << compare_ints2(i, j, Cmp()) << endl;
    // template parameter는 functor function pointer 둘 다 받을 수 있다.
    // cout << "result of comparison (5) : " << compare_ints3(i, j, cmp_f) << endl;
    // function pointer를 인자에 전달해준다면 컴파일 에러. functor 객체만 가능하다.
    cout << "result of comparison (6) : " << compare_ints3(i, j, Cmp()) << endl;

}