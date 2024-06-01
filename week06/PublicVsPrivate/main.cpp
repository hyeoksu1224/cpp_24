#include "Employee.h"

int main(){
    Employee e;
    //e.salary = 300; //compile error. why? private변수는 외부에서 접근 불가
    //e.age = 300; //compile error. why? private변수는 외부에서 접근 불가
    //int sa = e.getSalary = 300; //compile error. why? private함수는 외부에서 접근 불가
    string s = e.getName();
    int a = e.getAge();
}