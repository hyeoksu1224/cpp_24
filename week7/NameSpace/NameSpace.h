#ifndef __NAME__
#define __NAME__
#include <iostream>
using namespace std;

namespace Graphics{
    int mode;
    int x, y;
    void draw();
    void message();
}

namespace Network{
    int mode, speed;
    void send(char* );
    void message();
}

#endif