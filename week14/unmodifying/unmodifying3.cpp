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

#define N 11
int main(){
    int a[] = {8, 7, 0, 3, 1, 2, 0, 9, 1, 4, 6};
    vector<int> v(&a[0], &a[N]);
    print_container(v, "v = ");
    vector<int>::iterator it, low, up;
    sort(v.begin(), v.end());
    print_container(v, "sorting v = ");
    // lower, upper는 sorting해야 쓸 수 있다.
    low = lower_bound(v.begin(), v.end(), 1);
    up = upper_bound(v.begin(), v.end(), 1);

    // lower_bound는 값보다 크거나 같은 첫 번째 iterator
    // upper_bound는 값보다 큰 첫 번째 iterator 
    cout << "1's lower_bound at position " << (low - v.begin()) << endl;
    cout << "1's upper_bound at position " << (up - v.begin()) << endl;

    pair<vector<int>::iterator, vector<int>::iterator> bounds;
    bounds = equal_range(v.begin(), v.end(), 1);

    // 내림차순으로 정렬 greater<int>()는 내장 객체
    sort(v.begin(), v.end(), greater<int>());
    print_container(v, "sorting v= ");
    // equal_range는 iterator pair를 반환, first에 lower, second에 upper
    // default로 sorting된 것이 아니라면 4번째 인자로 sorting functor
    bounds = equal_range(v.begin(), v.end(), 1, greater<int>());

    cout << "bound at position " << bounds.first - v.begin() << " and " << bounds.second - v.begin() << endl;
    // set은 기본적으로 정렬된 자료구조이기 때문에 equal_range, lower_bound, upper_bound가 존재한다.

    sort(v.begin(), v.end());
    print_container(v, "v = ");
    int wanted = 5;
    bool isInIt = binary_search(v.begin(), v.end(), wanted);

    if (isInIt) cout << wanted << " is found." << endl;
    else{
        // 5가 있을 자리. 여긴 lower, upper 둘 다 상관 없음
        it = lower_bound(v.begin(), v.end(), wanted);
        v.insert(it, wanted);
    }
    print_container(v,"v = ");

    int myints[] = {20, 40, 60, 80, 100};
    vector<int> myvector(myints, myints + 5);
    
    // equal은 bool 값을 반환.
    // a와 b를 비교한다고 가정.
    // a의 비교할 범위의 시작과 끝, b의 시작
    // b의 끝은 인자로 넣지 않는다. 길이가 같기 때문
    if(equal(myvector.begin(), myvector.end(), myints)) cout << "The contents of both sequences are equal." << endl;
    else cout << "The contents of both sequences differ." << endl;

    myvector[3] = 81;
    // 4번째 인자로 비교할 함수를 전달할 수 있다.
    if(equal(myvector.begin(), myvector.end(), myints, equal_to<int>())) cout << "The contents of both sequences are equal." << endl;
    else cout << "The contents of both sequences differ." << endl;
}