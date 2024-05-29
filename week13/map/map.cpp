// map : 사전과 같은 구조, python의 dict 생각하면 된다. 키를 제시하면 해당 값을 찾을 수 있다.
// <key, value> pairs가 순서대로 저장되어 있다. pair 들의 집합
// key는 first, value는 second
// operator[] key가 제시되면 값의 reference 반환
// 양방향 반복자
// multimap : 키 값의 중복을 허용하는 map이다.
// 연관 컨테이너 : 원소들을 접근할 때 순차적 접근이 아니라 key 값에 의해 접근된다.
// 연관 컨테이너는 순차 접근을 위한 [] 연산자가 없다.
// 그러나 원소들은 정렬되어 저장된다 (보통 이진 탐색 트리로 구현된다.)

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    map<char, string> mymap;

    mymap['a'] = "an element"; // mymap.insert(pair<char,string>('a', "an element"))와 같다.
    mymap['b'] = "another element";
    mymap['c'] = mymap['b'];
    mymap['a'] = "a new element"; // 키는 유일하다. 이 라인은 자동으로 무시된다.

    cout << "mymap contains " << mymap.size() << " elements." << endl;

    cout << "mymap['a'] is " << mymap['a'] << endl;
    cout << "mymap['b'] is " << mymap['b'] << endl;
    cout << "mymap['c'] is " << mymap['c'] << endl;
    cout << "mymap['d'] is " << mymap['d'] << endl; // d라는 키를 가진 pair가 없었는데, 생긴다.

    cout << "mymap ontains" << mymap.size() << " elements." << endl;

    map<char,int> myMap;
    myMap['b'] = 100;
    myMap['a'] = 200;
    myMap['c'] = 300; // 키를 기준으로 정렬되어 저장된다.

    auto it = myMap.begin();
    for (; it != myMap.end(); it++) cout << it->first << " => " << it->second << endl;

    multimap<char, int> mymultimap;

    mymultimap.insert(pair<char, int>('a',100)); // multimap에는 operator[]가 없다.
    mymultimap.insert(pair<char, int>('z',150));
    mymultimap.insert(pair<char, int>('b',75));
    mymultimap.insert(pair<char, int>('c',300)); // 키를 기준으로 정렬되어 저장된다.
    mymultimap.insert(pair<char, int>('a',30)); // 키의 중복이 허용된다.

    multimap<char,int> anothermultimap;
    anothermultimap.insert(mymultimap.begin(), mymultimap.find('c')); // 키가 c인 첫 번째 원소

    cout << "mymultimap contains : \n";
    auto itm = mymultimap.begin();
    for (; itm != mymultimap.end(); itm++) cout << itm->first << " => " << itm->second << endl;
    
    itm = anothermultimap.begin();
    for (; itm != anothermultimap.end(); itm++) cout << itm->first << " => " << itm->second << endl;

    multimap<char, int> mymm;
    mymm.insert(pair<char,int>('a', 10));
    mymm.insert(pair<char,int>('b', 20));
    mymm.insert(pair<char,int>('b', 30));
    mymm.insert(pair<char,int>('b', 40));
    mymm.insert(pair<char,int>('c', 50));
    mymm.insert(pair<char,int>('c', 60));
    mymm.insert(pair<char,int>('d', 60));
    cout << "mymm contains: \n";
    for (char ch = 'a'; ch <= 'd'; ch++){
        pair<multimap<char,int>::iterator, multimap<char, int>::iterator> ret;
        ret = mymm.equal_range(ch); // 가장 먼저 나오는 ch가 first, 가장 나중에 나오는 ch의 다음 원소가 second
        cout << ch << " =>";
        for (multimap<char, int>::iterator itmm = ret.first; itmm != ret.second; itmm++)
        cout << ' ' << itmm->second;
        cout << endl;
    }
}