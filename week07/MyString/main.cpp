#include "MyString.h"

int main(){
    MyString s1;
    MyString s2("C++");
    MyString s3(s2);
    s1.print();
    s2.print();
    s3.print();
    return 0;
}