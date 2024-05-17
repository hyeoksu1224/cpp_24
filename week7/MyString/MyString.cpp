#include "MyString.h"

MyString::MyString(const char* str){
    if (!str){ //if (str == nullptr)
        p = new char[1];
        p[0] = '\0';
        return ;
    }
    p = new char[strlen(str) + 1];
    strcpy(p, str);
}

MyString::MyString(MyString& s){
    p = new char[s.size() + 1];
    strcpy(p, s.p);
}

MyString::~MyString(){
    delete[] p;
}

void MyString::print(){
    cout << p << endl;
}

int MyString::size(){
    return strlen(p);
}