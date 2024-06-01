// STL Container Adapter
// 순차 컨테이너에 제약을 가해서 데이터들이 정해진 방식으로만 입출력
// stack : 먼저 입력된 데이터가 나중에 출력되는 자료구조
// queue : 먼저 입력된 데이터가 먼저 출력되는 자료구조
// priority queue : 큐의 일종으로 큐의 요소들이 우선순위를 가지고 있으며, 우선순위가 높은 요소가 먼저 출력되는 자료구조

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    stack<int> st;
    for (int i = 0; i < 10; i++) st.push(i); //0부터 9까지 push
    while(!st.empty()){
        cout << "Stack top : " << st.top() << " " << endl;
        st.pop();
    } // 9가 가장 나중에 입력됐기 때문에 가장 먼저 pop되고, 0이 가장 먼저 입력됐기 때문에 가장 나중에 pop된다.
    cout << endl;

    queue<int> qu;
    for (int i = 0; i < 10; i++) qu.push(i);
    while(! qu.empty()){
        cout << "Queue front : " << qu.front() << " " << endl;
        qu.pop();
    } // 가장 먼저 입력된 0이 가장 먼저 pop되고, 가장 나중에 입력된 9가 가장 나중에 pop된다.
    cout << endl;

    priority_queue<int> pq;
    for (int i = 0; i < 10; i++) pq.push(i);

    while(! pq.empty()){
        cout << "priority queue top : " << pq.top() << " " << endl;
        pq.pop();
    } // queue지만 top을 사용하고, default로 높은 값일수록 높은 우선순위를 가진다.
      // 따라서 가장 높은 우선순위를 가진 9가 제일 먼저 pop되고, 0까지 순서대로 pop된다.
      // pq의 type이 bulit-in type이 아니라면 우선순위를 어떻게 정의할 수 있을까?
      // 비교하는 함수를 만들어 제공할 수 있다.
}