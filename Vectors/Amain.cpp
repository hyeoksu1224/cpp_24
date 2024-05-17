#include "Kvector.h"
#include "Avector.h"

int main(int argc, char *argv[]){
    Avector v(3,1,"abc"); v.print();
    Avector* p = new Avector(v); p->print();
    Kvector* kp = new Avector(2, 5, "xyz"); kp->print();
    delete kp;
    delete p;
    return 0;
}