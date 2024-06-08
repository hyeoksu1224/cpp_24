// STL 알고리즘의 분류
// 불변경 알고리즘 : 데이터를 변경하지 않음
// 변경 알고리즘 : 데이터가 변경됨
// 변경 알고리즘 : parameter로 container를 갖고, container 안의 원소가 바뀐다.
// fill, copy, for_each, transform, 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void myfunction(int i){
    cout << ' ' << i;
}

int op_increase(int i){ return ++ i; }

struct myclass{
    void operator()(int i){cout << ' ' << i;}
}myobject;

int main(){
    vector<int> myvector(8); // int vector, 0이 8개
    fill(myvector.begin(),myvector.begin() + 4, 5); // vector는 random access iterator, + 가능
    // myvector를 시작부터 4번째까지 5로 변경
    fill(myvector.begin() + 3, myvector.end() - 2, 8);
    // myvector를 4번째부터 마지막 -2 번째까지 8로 변경

    cout << "myvector contains:";
    auto it = myvector.begin();
    for (; it != myvector.end(); it++) cout << " " << *it;
    cout << endl;

    int myints[] = {10, 20, 30, 50, 50, 60, 70};
    vector<int> myvector2(7);
    // iterator 뿐만 아니라 배열의 주소도 받을 수 있음 template class라
    copy(myints, myints + 7, myvector2.begin());
    // 범위 내의 값을 복사해, 3번째 인자의 iterator에 저장
    cout << "myvector2 contains:";
    it = myvector2.begin();
    for (; it != myvector2.end(); it++) cout << " " << *it;
    cout << endl;

    vector<int> myvector3;
    myvector3.push_back(10);
    myvector3.push_back(20);
    myvector3.push_back(30);

    auto f = [](int val) {cout << ' ' << val;};
    cout << "myvector3 contains:";
    for_each(myvector3.begin(), myvector3.end(), myfunction); // function pointer를 인자로 받음
    // 각 주소가 참조하는 값에 함수를 적용한다. 이 경우 띄어쓰기와 i를 출력
    cout << endl;

    cout << "myvector3 contains:";
    for_each(myvector3.begin(), myvector3.end(), myobject); // functor를 인자로 받음, tmp object myclass()로 대체 가능
    cout << endl;

    cout << "myvector3 contains:";
    for_each(myvector3.begin(), myvector3.end(), f); // lambda 함수의 주소를 인자로 받음
    cout << endl;

    cout << "myvector3 contains:";
    for_each(myvector3.begin(), myvector3.end(), [](int val){
        cout << ' ' << val;
    }); // lambda 함수를 인자로 받음
    cout << endl;

    vector<int> foo;
    vector<int> bar;

    for (int i = 1; i < 6; i++) foo.push_back(i * 10);
    bar.resize(foo.size());

    // 조작할 container의 시작점, 끝점, 저장할 container의 시작점, 단항연산
    transform(foo.begin(), foo.end(), bar.begin(), op_increase);
    // bar에는 11, 21, 31, 41, 51이 저장되어있다.
    // 조작할 container의 시작점, 끝점, 2번째 operand의 시작점, 저장할 container의 시작점, 이항연산
    transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), plus<int>());
    // foo에는 11 + 10, 21 + 20, 31 + 30, 41 + 40, 51 + 50이 저장되어 있다. 

    cout << "foo contains:";
    it = foo.begin();
    for (; it != foo.end(); it++) cout << ' ' << *it;
    cout << endl;
}