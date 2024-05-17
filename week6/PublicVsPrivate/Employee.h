#ifndef __EMPLOYEE__
#define __EMPLOYEE__
#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name; // private로 선언된 멤버변수.
    int salary;  // 멤버변수는 클래스 안에서 그러나, 멤버 함수 외부에서 정의되는 변수이다.
    int age;     // 아무것도 지정하지 않으면 디폴트로 private를 가진다.
    int getSalary();
public:
    int getAge();
    string getName();
};
#endif