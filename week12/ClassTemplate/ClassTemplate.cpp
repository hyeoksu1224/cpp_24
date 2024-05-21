// Class Template : 클래스를 찍어내는 틀
#include <iostream>
using namespace std;

template <class T>
class Box{
    T data;
public:
    Box();
    void set(T value);
    T get();
};

template<class T>
Box<T>::Box(){}
template<class T>
void Box<T>::set(T value) { data = value; }
template<class T>
T Box<T>::get(){ return data; }
// 클래스 외부에 template class의 멤버 함수를 정의할 때.. 좀 힘들다.
// 가능하면 클래스 내부에서 함수를 정의하는 것이 좋다.

// !!!템플릿 클래스 컴파일 시 주의할 점!!!
// main.cpp에서 Box<int>를 사용하고, Box.cpp에서 Template Class의 멤버 함수들이 정의되어 있다면 실행파일을 만들 수 없다...
// main.cpp 안에 template <class T> class Box의 멤버함수들이 정의되어있어야하므로 보통 Box.h 헤더 안에서 멤버 함수까지 구현하고 main.cpp에서 #include <Box.h>로 포함
// 클래스를 사용하는 코드(main함수)에 따라서 실제 클래스를 만들어야 하기 때문에
// 템플릿 클래스의 선언과 정의는 그 클래스를 사용하는 소스 코드에 포함되어 함께 compile 되어야 한다.
// 따로 컴파일 한 뒤 link만 해서는 안된다. box.o를 complie할 때는 Box<int>를 만들지 않는다..
// 이게 exceptionClass 쪽에서도 적용이 되는가? -> 따로 서치
// 기존에 exceptionClass를 makefile로 link해서 컴파일하려 했으나 실패한 경험.. 한번 시도해보자...

template <class T1, class T2>
class Box2{
    T1 data1;
    T2 data2;
public:
    Box2(){}
    void set1(T1 value){ data1 = value; }
    void set2(T2 value){ data2 = value; }
    T1 get1(){ return data1; }
    T2 get2(){ return data2; }
};

int main(){
    Box<int> b1; //<>를 사용해서 template class인 것을 알려준다.
    b1.set(100);
    cout << b1.get() << endl;

    Box<double> b2;
    b2.set(3.14);
    cout << b2.get() << endl;

    Box2<int, double> b;
    b.set1(100);
    b.set2(3.14);
    cout << b.get1() << " , " <<b.get2() << endl;
    return 0;
}