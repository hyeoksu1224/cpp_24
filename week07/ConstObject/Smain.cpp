#include "MyString.h"

int main(){
    const MyString s1("const"); // const로 선언된 pointer에 const를 대입할 수 있다.
    MyString s2("C++"); // const로 선언된 pointer에 non-const를 대입할 수 있다.
    MyString s3(s1); // const로 선언된 reference에 non-const를 대입할 수 있다.
    s1.print();
    s2.print();
    s3.print();
    return 0;
}