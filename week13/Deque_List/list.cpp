// list : random access가 안되는 deque 즉, [] operator가 없음
// bidirectional iterator
// 이중 연결 리스트로 구현

// 반복자의 종류
// 전향 반복자 : ++ 연산자만 가능
// stack, linked list, queue가 여기 해당
// 양방향 반복자 : ++ 연산자와 -- 연산자가 가능
// list, set, map이 여기 해당
// 무작위 접근 반복자 : +, -, <, >, [] 연산자 사용 가능
// vector, deque가 여기 해당

// template<class T>
// void print_container(const T& container, string s = ""){ 
//     cout << s << "(" << container.size() << ")";
//     auto it = container.begin();
//     for(; it < container.end(); it++) cout << *it << " ";
//     cout << endl;
//     // < 연산자가 포함, 무작위 접근 반복자가 아닌 list, set 등등은 사용 불가
//     // vector와 deque가 사용 가능
// }
// template<class T>
// void print_container(vector<T> v, string s = ""){ 
//     cout << s;
//     for(int i = 0; i<v.size(); i++) cout << v[i] << " ";
//     cout << endl;
//     // [] 연산자가 포함, 무작위 접근 반복자가 아니면 사용 불가능하다.
// }

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
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
    deque<char> dq(v.begin(), v.end()); // 반복자로 범위 설정, deepCopy
    list<char> l1(3, 'x'); // size는 3, x로 초기화
    list<char> l2(&a[0], &a[4]); // 포인터를 인자로 l2 생성
    list<char> l3(dq.begin(), dq.end()); // iterator로 deep copy
    print_container(v, "v= ");
    print_container(dq, "dq= ");
    print_container(l1, "l1= ");
    print_container(l2, "l2= ");
    print_container(l3, "l3= ");
    l2.push_front('+'); // 가장 앞에 + 삽입
    print_container(l2, "at 56 l2= ");
    l2.push_back('-'); // 가장 뒤에 - 삽입
    print_container(l2, "at 58 l2= ");
    l2.pop_front(); // 가장 앞에 삭제
    print_container(l2, "at 60 l2= ");
    l2.pop_back(); // 가장 뒤에 삭제
    print_container(l2, "at 62 l2= ");
    // cout << l2[0] << endl; //compile error! list는 무작위접근반복자가 아니라 []operator가 없다
    auto it = l2.insert(l2.begin(),'*'); // 시작점에 * 삽입
    print_container(l2, "at 65 l2= ");
    cout << "return value points " << *it << endl; // it는 시작점 *를 가리킴
    it = l2.insert(l2.begin(), 2, '$'); // 시작점에 $ 두 개 삽입
    print_container(l2, "at 68 l2= ");
    cout << "return value points " << *it << endl; // 새로 삽입된 첫 번째 요소 가리킴
    // it = l2.insert(l2.begin() + 1, v.begin() + 2, v.begin() + 4); // compile error! list는 양방향반복자라 + 사용 불가
    it = l2.begin(); it++; // + 1(int) 연산은 안되지만 ++연산과 -- 연산은 가능
    it = l2.insert(it, v.begin() + 2, v.begin() + 4); // v의 3번째 ~ 4번째 원소 l2의 두번째 자리에 삽입
    print_container(l2, "at 73 l2= ");
    cout << "return value points " << *it << endl; // 첫 번째로 삽입된 요소를 가리킨다. v[3] z
    it = l2.erase(l2.begin()); // 첫 번째 원소 삭제
    print_container(l2, "at 76 l2= ");
    cout << "return value points " << *it << endl; // 마지막으로 삭제된 요소 다음의 요소
    // it = l2.erase(l2.begin() + 3, l2.end() - 1); // compile error! + - 연산 불가
    it++; it++; it++; // ++ 연산은 가능
    auto end_it = l2.end(); end_it--; // -- 연산도 가능
    it = l2.erase(it, end_it); // 반복자 두 개 사이 범위를 삭제 [it, end_it)
    print_container(l2, "at 82 l2= ");
    cout << "return value points " << *it << endl; // 마지막으로 삭제된 요소 다음의 요소
}