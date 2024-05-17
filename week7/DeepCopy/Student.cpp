#include "Student.h"

Student::Student(int n, const char* s){
    id = n;
    name = new char[NAME_LEN];
    strncpy(name, s, NAME_LEN); // s를 널 문자를 포함하여 처음부터 NAME_LEN 만큼 복사해서 name에 넘겨준다.
                                // s의 문자 수가 NAME_LEN보다 적다면 모자란 부분은 \0로 패딩된다.
    name[NAME_LEN - 1] = '\0';  // strncpy는 복사 시 무조건 끝에 널 문자가 오지 않는다. 따라서 마지막에 널문자를 삽입해준다. 
}

Student::~Student(){
    delete[] name;
}

Student::Student(const Student& st){
    id = st.id;
    name = new char[NAME_LEN];
    strncpy(name, st.name, NAME_LEN);
    name[NAME_LEN - 1] = '\0';
}

void Student::setName(const char* s){
    strncpy(name, s, NAME_LEN);
    name[NAME_LEN - 1] = '\0';
}

void Student::print(){
    cout << this << " ] " << " name : " << name;
    cout << " id : " << id << endl;
}