#include "Student.h"

int main(){
    Student s1(20212047, "Shin"), s2(s1);
    s1.print(); s2.print();
    s2.setName("Kim");
    s1.print(); s2.print();
    return 0;
}