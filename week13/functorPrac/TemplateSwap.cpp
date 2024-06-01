#include <iostream>
using namespace std;

template<class T>
struct Swap{
    void operator() (T& a, T& b);
};

template<class T>
void Swap<T>::operator() (T& a, T& b){
    if (&a == &b) throw exception();
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){
    Swap<int> sw; // sw <- functor
    int i = 1, j = 2;

    cout << i << " " << j << endl;
    try{
        sw(i, j); // sw.operator()(i,j);
    }
    catch(...){
        cout << "swappint identical variables." << endl;
    }
    cout << i << " " << j << endl;

    try{
        Swap<int>()(i, j); // temp object를 이용한 functor
    }
    catch(...){
        cout << "swappint identical variables." << endl;
    }
    cout << i << " " << j << endl;
}