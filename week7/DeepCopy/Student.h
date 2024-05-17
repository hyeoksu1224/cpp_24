#ifndef __STUDENT__
#define __STUDENT__
#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 100

// 얕은 복사 문제
// 멤버가 포인터 형인 경우 멤버 변수의 값만 복사하면 안되는 경우가 발생한다.
// 이를 Shallow copy problem이라 한다.
// 멤버가 포인터 형일 때 얕은 복사를 했을 경우
// 두 instance의 멤버 변수가 모두 하나의 주소를 가리킨다.
// 즉, 나는 하나의 instance의 멤버변수만 변경하고 싶지만, shallow copy 때문에
// 두 개의 instance의 멤버 변수 모두 변경된다.
// 즉, 동적 메모리 할당을 통해 새로 메모리 공간을 할당해주어야 한다.

class Student{
    //private 멤버 변수 선언
    int id;
    char* name;
public:
    Student(int n, const char* s);
    ~Student();
    Student(const Student& st);
    void setName(const char* s);
    void print();
};
#endif