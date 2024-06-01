#include "A.h"

int main(){
    A arr[2] = {A(1), A(2)};
    for (int i = 0; i < 2; i++) arr[i].display();
    A* ptr = new A[3];
    for (int i = 0; i < 3; i++) (ptr + i)->display();
}