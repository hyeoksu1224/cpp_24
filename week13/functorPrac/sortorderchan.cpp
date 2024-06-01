#include <iostream>
#include <map>
#include <set>
#include <string>
#include <functional>
using namespace std;

template <class T>
void print_container(const set<T>& container, string s = "") {
    cout << s << "(" << container.size() << "): ";
    for (auto it = container.begin(); it != container.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <class T>
void print_container(const set<T, greater<T>>& container, string s = "") {
    cout << s << "(" << container.size() << "): ";
    for (auto it = container.begin(); it != container.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <class K, class V>
void print_container(const map<K, V>& container, string s = "") {
    cout << s << "(" << container.size() << "): ";
    for (auto it = container.begin(); it != container.end(); ++it)
        cout << "[" << it->first << " : " << it->second << "] ";
    cout << endl;
}

template <class K, class V>
void print_container(const map<K, V, greater<K>>& container, string s = "") {
    cout << s << "(" << container.size() << "): ";
    for (auto it = container.begin(); it != container.end(); ++it)
        cout << "[" << it->first << ": " << it->second << "] ";
    cout << endl;
}

int main(){
    char a[10] = {'c', 'a', 'x', 'a', 'c', 'b', 'x', 'c', 'b', 'y'};

    set<char> s(&a[0], &a[10]);
    map<int, char> m;
    for (int i = 0; i < 10; i++) m[i] = a[i];

    set<char, greater<char>> s2(&a[0], &a[10]); // template parameter에는 클래스
    map<int, char, greater<int>> m2; // template parameter에는 클래스
    for (int i = 0; i < 10; i++) m2[i] = a[i];

    print_container(s, "s = "); // 작은 int부터 정렬 오름차순
    print_container(s2, "s2 = "); // 큰 int부터 정렬 내림차순 (greater)
    print_container(m, "m = "); // 오름차순
    print_container(m2, "m2 = "); // 내림차순 (greater)
}