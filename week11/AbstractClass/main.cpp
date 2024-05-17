#include "RemoteControl.h"
#include "Refrigerator.h"
#include "Television.h"

int main(){
    Television* pt = new Television();
    pt->turnON();
    pt->turnOFF();

    Refrigerator* pr = new Refrigerator();
    pr->turnON();
    pr->turnOFF();

    delete pt;
    delete pr;
    return 0;
}