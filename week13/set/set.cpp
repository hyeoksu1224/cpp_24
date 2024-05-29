// set : 중복이 없는 자료들이 정렬되어 저장된다.
// 집합은 동일한 키를 중복해서 가질 수 없고, 크기순으로 정렬된다.
// 집합의 반복자는 양방향반복자이다.
// multiset : 자료의 중복이 허용되는 set이다.
// 연관 컨테이너 : 원소들을 접근할 때 순차적 접근이 아니라 key 값에 의해 접근된다.
// 연관 컨테이너는 순차 접근을 위한 [] 연산자가 없다.
// 그러나 원소들은 정렬되어 저장된다 (보통 이진 탐색 트리로 구현된다.)

#include <iostream>
#include <set>
using namespace std;

// 연관 컨테이너는 insert시 위치를 안 준다. 
int main(){
    set<int> mySet;
    set<int>::iterator it;

    for (int i = 5; i >= 0; i--) mySet.insert(i * 10);

    it = mySet.find(20);
    mySet.erase(it);
    mySet.erase(mySet.find(40));
    cout << "mySet contains: ";
    for (it = mySet.begin(); it != mySet.end(); ++it) cout << ' ' << *it;
    cout << endl;

    mySet.clear();
    for (int i = 1; i < 5; i++) mySet.insert(i * 3);
    for (int i = 0; i < 10; i++){
        cout << i;
        // count : 인자 값이 있으면 1 없으면 0 반환
        if (mySet.count(i) != 0) cout << " is an element of mySet." << endl;
        else cout << " is not an element of mySet." << endl;
    }

    int myints[] = {10, 73, 12, 22, 73, 73, 12};
    multiset<int> myMultiSet(myints, myints + 7);
    // multiset의 count : 인자 값이 몇 개 있는지 반환
    cout << "73 appears " << myMultiSet.count(73) << " times in myMulitSet." << endl;

    // multiset도 마찬가지로 내부에서 정렬된 상태로 저장되어 있다.
    auto itm = myMultiSet.begin();
    for (; itm != myMultiSet.end(); itm++) cout << *itm << " ";
    cout << endl;

    mySet.clear();
    set<int>::iterator itlow, itup;
    for (int i = 1; i < 10; i++) mySet.insert(i * 10);

    itlow = mySet.lower_bound(30); // 30보다 크거나 같은 첫 번째 원소
    itup = mySet.upper_bound(60); // 60보다 큰 첫 번째 원소. lower에서 등호가 없음
    cout << *itlow << " " << *itup << endl;
    mySet.erase(itlow, itup);

    cout << "mySet contains : ";
    it = mySet.begin();
    for (; it != mySet.end(); it++) cout << ' ' << *it;
    cout << endl;

    mySet.clear();
    for (int i = 1; i <= 5; i++) mySet.insert(i * 10);
    pair<set<int>::const_iterator, set<int>::const_iterator> ret;
    ret = mySet.equal_range(30); // 30의 lower first에, upper second에
    // pait type이 아닌 반복자에 할당하면 30의 lower만 반환
    cout << "the lower bound points to " << *ret.first << endl;
    cout << "the upper bound points to " << *ret.second << endl;
    
    int myints2[] = {77, 30, 16, 2, 30, 30};
    myMultiSet.clear();
    myMultiSet.insert(myints2, myints2 + 6);
    pair<multiset<int>::iterator, multiset<int>::iterator> ret2;
    ret2 = myMultiSet.equal_range(30);
    // 30중 가장 앞에 위치한 것이 first, 모든 30이 끝나고 바로 다음 원소가 second
    myMultiSet.erase(ret2.first, ret2.second);
    cout << "myMultiSet contains: ";
    itm = myMultiSet.begin();
    for (; itm != myMultiSet.end(); itm++) cout << ' ' << *itm;
    cout << endl;
}