#ifndef __REF__
#define __REF__
#include "RemoteControl.h"
#include <iostream>

class Refrigerator : public RemoteControl{
public:
    void turnON();
    void turnOFF();
};
#endif