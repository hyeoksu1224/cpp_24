#include <iostream>
using namespace std;

// 일반화 프로그래밍 : 일반적인 코드를 작성하고 이 코드를 다양한 타입의 객체에 대하여 재사용하는 프로그래밍 기법
// template <class(typename 써도 됨) T>
// T 함수이름(T x, T y) 자료형이 변수처럼 표기되어있구나!
template <class T>
void increase(T& v){ v += 1; }

// template specialization
template<>
void increase(int*& v){ v += 2;}
// 함수가 specialization, default template 둘 다 해당한다면
// specialization을 실행한다!

// function overloading
void increase(int*& v){ v += 3; }
// 함수가 function overloading, specialization, default template
// 셋 다 해당한다면 function overloading을 실행한다.

// function overloading
// 이 경우는 ref type이 아니기 때문에 specilization이 불가능
void increase(char *ptr) { *ptr += 1; }

// 여러 type의 매개변수를 가지는 template 함수

template <class T1, class T2>
void copy(T1 a1[], T2 a2[], int n){
    for (int i = 0; i < n; i++) a1[i] = a2[i];
}


int main(){
    int i = 1;
    cout << "i = " << i << endl;
    increase(i);
    cout << "i = " << i << endl;

    int *p = &i;
    cout << "p = " << p << endl;
    increase(p);
    cout << "p = " << p << endl;

    char c[] = "abcdefg";
    cout << "c[5] = " << c[5] << endl;
    increase(c[5]);
    cout << "c[5] = " << c[5] << endl;

    cout << "c = " << (void *)c << " " << c << endl;
    // 배열 이름은 변수가 아니므로 reference에 치환될 수 없다.
    increase(c);
    cout << "c = " << (void *)c << " " << c << endl;

    int v_i[5];
    double v_d[5] = { 1.1, 2.1, 3.1, 4.1, 5.1};

    copy(v_i, v_d, 5);
    for (int i = 0; i < 5; i++) cout << v_i[i] << endl;
}