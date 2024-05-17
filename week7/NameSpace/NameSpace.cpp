#include "NameSpace.h"

void Graphics::draw(){
    cout << "Graphics 이름 공간 안의 draw()" << endl;
}

void Graphics::message(){
    cout << "Graphics 이름 공간 안의 message()" << endl;
}

void Network::send(char* ){
    cout << "Network 이름 공간 안의 send()" << endl;
}

void Network::message(){
    cout << "Network 이름 공간 안의 message()" << endl;
}