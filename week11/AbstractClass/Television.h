#ifndef __TV__
#define __TV__
#include "RemoteControl.h"
#include <iostream>

class Television : public RemoteControl{
public:
    void turnON();
    void turnOFF();
};
#endif