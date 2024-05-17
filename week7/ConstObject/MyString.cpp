#include "MyString.h"

MyString::MyString(char *str){
    cout << this << " " << str << "] MyString(char*)\n";
}
MyString::MyString(const char *str){
    if(!str){
        p = new char[1];
        p[0] = '\0';
        return;
    }
    p = new char[strlen(str) + 1];
    strcpy(p, str);
    cout << this << " " << str << "] MyString(const char *)\n";
}

MyString::MyString(const MyString& s){
    p = new char[s.size() + 1];
    strcpy(p, s.p);
    cout << this << " " << s.p << "] MyString(const MyString&)\n";
}

MyString::~MyString(){
    delete[] p;
}

void MyString::print() const { cout << p << endl;}

int MyString::size() const { return strlen(p);}