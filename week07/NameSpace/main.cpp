#include <iostream>
using namespace std;

int mode; //전역 변수

void message(){
    cout << "전역 공간 안의 message()" << endl;
}

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

int main(){
    using namespace Graphics; // using 이름공간::식별자 문을 사용하면 이름 공간 안의 식별자는 이름 공간을 붙이지 않아도 접근이 가능하다.
                              // using Network::speed; speed = 100; complie error가 발생하지 않는다!
                              // using namespace 이름공간 문을 사용하면 이름공간 안의 모든 것을 이름공간 붙이지 않고 접근이 가능하다.
                              // using namespace Network; speed = 19200; send("This is a test"); Network의 함수, 식별자에 해당한다.
    //x = y = 100;   // using 문 사용 안할 시 compile error!
    //speed = 22900; // using 문 사용 안할 시 compile error!
    //draw();        // using 문 사용 안할 시 compile error!

    ::mode = 1; //using문 사용 시 전역 변수에 접근하려면 :: 필요
    Graphics::mode = 1;
    Network::mode = 2;

    Graphics::message();
    Network::message();
    ::message(); //using 문 사용 시 전역 함수에 접근하려면 :: 필요
    return 0;
}