#include <iostream>
#include <queue>
using namespace std;

struct Cmp{
    bool operator() (const int& a, const int& b) const{
        return a % 3 < b % 3;
    }
};


int main(){
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //priority_queue<int> pq(v, v + 10); // default로 값이 높을수록 우선순위 높게 정렬

    priority_queue<int, vector<int>, Cmp> pq(v, v + 10);
    // pq의 타입(int), 데이터 저장 및 힙연산등을 지원하는 기본컨테이너 타입(vector<int>), 비교 함수를 인자로 갖는다.
    // function parameter는 obj를 넘겨줬으나, template parameter에는 class를 넘겨준다.

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}