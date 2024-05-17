#ifndef __MYSTRING__
#define __MYSTRING__
#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    char *p;
public:
    MyString(const char *str = NULL);
    MyString(char *str = NULL);
    MyString(const MyString& s);
    ~MyString();
    void print() const;
    int size() const;
};
#endif