#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
    os << "[" << p.first << "]" << p.second;
    return os;
}
template <class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ") ";
    auto it = container.begin();
    for(; it!= container.end(); it++) cout << *it << " ";
    cout << endl;
}

int main(){
    char a[10] = {'c', 'a', 'x', 'a', 'c', 'b', 'x', 'c', 'b', 'y'};
    vector<char> v; deque<char> dq; list<char> li; set<char> s; multiset<char> ss;
    map<int, char> m; multimap<int, char> mm;
    for (int i = 0; i < 10; i++){
        v.push_back(a[i]); // v[i] = a[i]만으로는 불가 왜? size.. capacity를 미리 늘려주거나 push
        dq.push_back(a[i]); // vector와 동일
        li.push_back(a[i]); // bidirectional이기 때문에 li[] = a[i] 불가
        s.insert(a[i]); 
        ss.insert(a[i]);
        m[i] = a[i]; // m[i] = a[i] 로 사용 가능, 자리를 새로 만들어줌
        mm.insert(pair<int,char>(i, a[i]));
    }
    print_container(v, "v= ");
    print_container(dq, "dq= ");
    print_container(li, "li= ");
    print_container(s, "s= ");
    print_container(ss, "ss= ");
    print_container(m, "m= ");
    print_container(mm, "mm= ");
}