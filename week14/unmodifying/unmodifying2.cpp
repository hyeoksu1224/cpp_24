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

bool myfunction(int i , int j){ return i < j; }

#define N 12
int main(){
    vector<int>::iterator it;
    list<int>::iterator it2;
    set<int>::iterator it3;

    int a[] = {8, 7, 0, 3, 1, 2, 5, 0, 9, 1, 4, 6};
    vector <int> v(&a[0], &a[N]);
    deque<int> dq(v.begin(), v.end());
    list<int> li(v.begin(), v.end());
    set<int> s(v.begin(), v.end());
    map<int, int> m;
    for (int i = 0; i < N; i++) m[i] = a[i];
    print_container(v, "v = ");
    print_container(dq, "dq = ");
    print_container(li, "li = ");
    print_container(s, "s = ");
    print_container(m, "m = ");

    // set은 중복 원소를 허용하지 않기 때문에,
    // find(s.begin(), s.end(), 0)와
    // s.find(0)가 같다. count도 마찬가지.
    cout << "find in set<>" << endl;
    it3 = find(s.begin(), s.end(), 0);
    while(it3 != s.end()){
        cout << "0 is in " << distance(s.begin(), it3) << "-th element" << endl;
        it3 = find(++it3, s.end(), 0);
    }
    it3 = s.find(0);
    cout << "0 is in " << distance(s.begin(), it3) << "-th element" << endl;

    cout << "count in set<>" << endl;
    int cnt = count(s.begin(), s.end(), 0);
    cout << "There are " << cnt << " 0s in s." << endl;

    cnt = s.count(0);
    cout << "There are " << cnt << " 0s in s." << endl;

    // find는 value를 찾지만, search는 subsequence를 찾는다.
    cout << "search in list<>" << endl;
    // 첫 두 인자는 찾을 범위, 세번째 네번째 인자는 찾고자 하는 subsequence
    it2 = search(li.begin(), li.end(), v.begin() + 2, v.begin() + 4);
    cout << *(v.begin() + 2) << ", " << *(v.begin() + 3) << "is in " << distance(li.begin(), it2) << "-th position in li." << endl;

    int myints[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    v.assign(myints, myints + 9);

    sort(v.begin(), v.end());
    cout << "looking for a 3...";
    // binary_search는 bool 값을 반환한다. 있으면 1 없으면 0
    // binary_search는 sorting된 자료에서 탐색하는 것으로, sorting된 자료에만 사용
    if (binary_search(v.begin(), v.end(), 3)) cout << "found!" << endl;
    else cout << "not found." << endl;

    sort(v.begin(), v.end(), myfunction);
    cout << "looking for a 6...";
    // sorting 방법이 default가 아닌 사용자 정의 함수일 경우 4번째 인자에 사용자 정의 함수 전달
    if (binary_search(v.begin(), v.end(), 6, myfunction)) cout << "found!" << endl;
    else cout << "not found." << endl;
}