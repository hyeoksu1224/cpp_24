#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

template<class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << ' ';
    cout << endl;
}

// map, multimap의 원소는 pair이므로 출력 연산자를 정의해주어야 한다.
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
    os << "[" << p.first << "] " << p.second;
    return os;
}

bool less_than5(int i) { return i < 5; }

#define N 10
int main(){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v(&a[0], &a[N]);
    list<int> l(&a[0], &a[N]);

    print_container(v, "v = ");
    vector<int>::iterator it, it2;
    it = v.begin();
    cout << "*it = " << *it << endl;
    cout << "*(it + 2) = " << *(it + 2) << endl;
    cout << "*it[2] = " << it[2] << endl;
    it2 = it + 5;
    cout << "*it2 = " << *it2 << endl;
    cout << "*it2 - it = " << it2 - it << endl;

    print_container(l, "l = ");
    list<int>::iterator lit, lit2;
    lit = l.begin();
    cout << "*lit = " << *lit << endl;
    // cout << "*(lit + 2) = " << *(lit + 2) << endl; // compile error! random access iterator가 아니기 때문에 + 연산자 사용 X
    // cout << "*lit[2] = " << lit[2] << endl; // list iterator는 bidirection iterator! operator[]가 오버로드 X
    // lit2 = lit + 5; // bidirection iterator는 + 연산 불가
    lit2 = lit; for(int i = 0; i < 5; i++) lit2++;
    cout << "*lit2 = " << *lit2 << endl;
    // cout << "*lit2 - lit = " << lit2 - lit << endl; // bidirection : - 연산 불가
    cout << "distance(lit, lit2) = " << distance(lit, lit2) << endl;

    int b[] = {8, 7, 0, 3, 1, 2, 5, 0, 9, 1, 4, 6};
    v.assign(&b[0], &b[12]);
    deque<int> dq(v.begin(), v.end());
    list<int> li(v.begin(), v.end());
    set<int> s(v.begin(), v.end());
    map<int, int> m;
    for (int i = 0; i < 12; i++) m[i] = b[i];
    print_container(v, "v = ");
    print_container(dq, "dq = ");
    print_container(li, "li = ");
    print_container(s, "s = ");
    print_container(m, "m = ");

    cout << "find in vector<>" << endl;
    // 주어진 범위 내에서 3번째 인자를 가진 첫 번째 iterator를 반환한다.
    it = find(v.begin(), v.end(), 0);
    while(it != v.end()){
        cout << "0 is in " << it - v.begin() << "-th element" << endl;
        it = find(it + 1, v.end(), 0);
    }
    cout << "count in vector<>" << endl;
    // 주어진 범위 내에서 3번째 인자를 가진 iterator의 갯수 반환
    int cnt = count(v.begin(), v.end(), 0);
    cout << "There are " << cnt << " 0s in v." << endl;

    cout << "find in list<>" << endl;
    lit = find(li.begin(), li.end(), 0);
    while(lit != li.end()){
        cout << "0 is in " << distance(li.begin(), lit) << "-th element" << endl; // bidirection이기 때문에 -가 아닌 distance
        lit = find(++lit, li.end(), 0); // 이 경우 후위 표기로 연산하면 안됨. 후위표기는 연산 전을 인자로 전달
    }

    cout << "find_if in vector<>" << endl;
    // 주어진 범위 내에서 3번째 함수 결과가 참인 첫 번째 iterator 반환
    it = find_if(v.begin(), v.end(), less_than5);
    while(it != v.end()){
        cout << *it << " is less than " << it - v.begin() << "-th position." << endl;
        it = find_if(it + 1, v.end(), less_than5);
    }
    cout << "count_if in vector<>" << endl;
    cnt = count_if(v.begin(), v.end(), less_than5);
    cout << "There are " << cnt << " (less than 5) numbers in v." << endl;
}