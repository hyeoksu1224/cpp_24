#include <iostream>
#include <queue>
using namespace std;

class Rectangle{
    int width, height;
public:
    Rectangle(int w = 0, int h = 0): width(w), height(h) {}
    int area(){ return width * height; }
    friend ostream& operator<<(ostream& os, Rectangle r);
};
ostream& operator <<(ostream& os, Rectangle r){
    os << r.width << " x " << r.height << endl;
    return os;
}

class RectangleCmp{
public:
    bool operator()(Rectangle& r1, Rectangle& r2){
        return (r1.area() < r2.area()) ? true : false;
        // 3항 연산자 사용, r1의 면적이 넓으면 참 아니면 거짓
    }
};

int main(){
    priority_queue<Rectangle, vector<Rectangle>, RectangleCmp> pq;
    // template parameter에는 class를 넘겨줘야 한다.
    pq.push(Rectangle(4, 5));
    pq.push(Rectangle(3, 5));
    pq.push(Rectangle(4, 8));

    while(!pq.empty()){
        cout << pq.top();
        pq.pop();
    }
}