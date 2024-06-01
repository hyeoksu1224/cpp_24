#include <iostream>
#include <functional>
using namespace std;

template<class T>
struct myGreater
{
    bool operator() (const T& a, const T& b) const{
        return a > b;
    }
};

template<class F>
bool compare_ints2(const int& a, const int& b, F f){
    return f(a,b);
}

int main(){
    myGreater<int> obj;
    greater<int> obj2;
    int i = 7, j = 5;
    bool r;
    
    r = obj(i, j);
    cout << i << " > " << j << " : " << boolalpha << r << endl;


    r = myGreater<int>()(i, j);
    cout << i << " > " << j << " : " << boolalpha << r << endl;

    r = compare_ints2(i, j, obj); // function parameter는 객체로 전달
    cout << i << " > " << j << " : " << boolalpha << r << endl;

    r = compare_ints2(i, j, myGreater<int>()); // function parameter는 객체로 전달해야한다.
    cout << i << " > " << j << " : " << boolalpha << r << endl;

    r = greater<int>()(i, j);
    cout << i << " > " << j << " : " << boolalpha << r << endl;

    r = compare_ints2(i, j, obj2); // function parameter는 객체로 전달해야한다.
    cout << i << " > " << j << " : " << boolalpha << r << endl;

    r = compare_ints2(i, j, greater<int>()); // function parameter는 객체로 전달해야한다.
    cout << i << " > " << j << " : " << boolalpha << r << endl;
}