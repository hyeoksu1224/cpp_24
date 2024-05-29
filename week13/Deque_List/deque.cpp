// deque : vector class의 전단과 후단에서 모두 요소를 추가하고 삭제하는 것을 허용한다.

#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;
template <class T>
void print_container(const T& container, string s=""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}

int main(){
    char a[] = {'a', 'b', 'c', 'd', 'e', 'x', 'y', 'z', 'w'};
    vector<char> v(&a[5], &a[9]); // 포인터를 인자로 v를 생성한다.
    deque<char> dq1(3, 'x'); // size 3, x로 초기화
    deque<char> dq2(&a[0], &a[4]); // 포인터를 인자로 dq2 생성
    deque<char> dq3(v.begin(), v.end()); // v의 시작부터 끝까지 deep copy
    print_container(v, "v= ");
    print_container(dq1, "dq1= ");
    print_container(dq2, "dq2= ");
    print_container(dq3, "dq3= ");
    dq2.push_front('+');
    print_container(dq2, "at 27 dq2= ");
    dq2.push_back('-');
    print_container(dq2, "at 29 dq2= ");
    dq2.pop_front();
    print_container(dq2, "at 31 dq2= ");
    dq2.pop_back();
    print_container(dq2, "at 33 dq2= ");
    cout << "at 34 dq2[0] = " << dq2[0] << endl; // operator []로 container의 index에 접근 가능
    auto it = dq2.insert(dq2.begin(), '*'); // '*'가 삽입 된 제일 첫 번째 주소를 반환, auto가 자동 형변환
    print_container(dq2, "at 36 dq2= ");
    cout << "at 37 dq2[0] = " << dq2[0] << endl; // dq2[0]에 *가 삽입되었다
    cout << "return value points " << *it << endl; // iterator는 *를 가리킨다.
    it = dq2.insert(dq2.begin(), 2, '$'); // dq2의 시작지점에 $를 두 개 삽입한다.
    print_container(dq2, "at 40 dq2= ");
    cout << "return value points " << *it << endl; // 새로 삽입된 첫 번째 요소를 가리킨다.
    it = dq2.insert(dq2.begin() + 1, v.begin() +2, v.begin() + 4); // begin() + 1에 v의 3번째, 4번째를 원소를 삽입
    print_container(dq2, "at 43 dq2= ");
    cout << "return value points " << *it << endl; // 첫 번째로 삽입된 요소를 가리킨다
    it = dq2.erase(dq2.begin()); // 첫 번째 원소를 지운다.
    print_container(dq2, "at 46 dq2= ");
    cout << "return value points " << *it << endl; // it는 마지막으로 삭제된 요소 다음의 요소
    it = dq2.erase(dq2.begin() + 3, dq2.end() - 1); // 4번째 ~ 7번째 4개 삭제
    print_container(dq2, "at 49 dq2= ");
    cout << "return value points " << *it << endl; // 마지막으로 삭제된 요소 다음의 요소

    // 반복자의 종류
    // 전향 반복자 : ++ 연산자만 가능
    // stack, linked list, queue가 여기 해당
    // 양방향 반복자 : ++ 연산자와 -- 연산자가 가능
    // list, set, map이 여기 해당
    // 무작위 접근 반복자 : +, -, <, >, [] 연산자 사용 가능
    // vector, deque가 여기 해당
    
    //template<class T>
    //void print_container(const T& container, string s = ""){ 
    //    cout << s << "(" << container.size() << ")";
    //    auto it = container.begin();
    //    for(; it < container.end(); it++) cout << *it << " ";
    //    cout << endl;
    //    // < 연산자가 포함, 무작위 접근 반복자가 아닌 list, set 등등은 사용 불가
    //    // vector와 deque가 사용 가능
    //}

    //template<class T>
    //void print_container(vector<T> v, string s = ""){ 
    //    cout << s;
    //    for(int i = 0; i<v.size(); i++) cout << v[i] << " ";
    //    cout << endl;
    //    // [] 연산자가 포함, 무작위 접근 반복자가 아니면 사용 불가능하다.
    //}
}