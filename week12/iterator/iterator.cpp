// 반복자
// 현재 처리하고 있는 자료의 위치를 기억하는 객체의 클래스
// 포인터 타입과 유사하다.
// 역참조 연산자 * 사용 가능
// ++연산자 사용 가능
// container class 내부에서 각각 다르게 정의되어있다. list 따로, vector 따로...

// v.begin()은 컨테이너 v의 첫 번째 요소를 가리키는 반복자 반환
// v.end()는 컨테이너 v의 마지막 요소의 다음 가상의 요소를 가리키는 반복자 반환

// 컨테이너에서 다음 요소를 가리키기 위한 ++ 연산자 (필수),
// ==과 != 연산자, 반복자가 가리키는 요소의 값을 추출하기 위한 역참조 연산자 *

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
void print_vector(vector<T> v, string s = ""){
    cout << s << "(" << v.size() << ") ";
    auto it = v.begin(); // auto : it의 type을 compiler가 맞춰준다. RHS에서 반환되는 값의 type에 자동 맞춤 즉, =가 없으면 안됨.
    for(; it != v.end(); it++) cout << *it << " ";
    cout << endl;
}

#define N 3

int main(){
    vector<int> v1(N, 5);
    print_vector(v1, "v1 = ");
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v2(&a[0], &a[5]); // 배열 원소에 대한 pointer
                                  // 주소 2개의 범위 값을 deepCopy, [a, b)
                                  // a[0], a[1], a[2], a[3], a[4]를 deepCopy한다.
    print_vector(v2, "v2 = ");
    vector<int> v3(v2); // copyConstructor
    print_vector(v3, "v3 = ");
    vector<int> v4(&v3[1], &v3[4]); // container 내부 배열 원소에 대한 pointer를 주소 범위로
    print_vector(v4, "v4 = ");
    vector<int> v5(v3.begin() + 1, v3.begin() + 4); // container의 iterator
    print_vector(v5, "v5 = ");


    vector<int>::iterator it = v1.begin(); //auto 써도 됨 위에 auto는 필수지만 여긴 선택..return type을 이미 알고 있기 때문
    for(; it != v1.end(); it++) *it = 10;
    print_vector(v1, "v1= ");

    vector<string> vec;
    vec.push_back("MILK");
    vec.push_back("BREAD");
    vec.push_back("BUTTER");
    print_vector(vec, "vec = ");
    vec.insert(vec.begin() + 1, "APPLE"); // vec[1]에 APPLE 삽입, 뒤에 있는 원소들 뒤로 한 칸씩
    print_vector(vec, "vec = ");
    vec.pop_back();
    print_vector(vec, "vec = ");

    vector<char> v(3, 'x');
    print_vector(v, "v = ");
    char c[] = {'a', 'b', 'c', 'd', 'e'};
    vector<char>::iterator itr;
    itr = v.insert(v.begin(), 'p'); // itr == v.begin()
    print_vector(v, "v = ");
    cout << "return value points " << *itr << endl;
    itr = v.insert(v.end(), 2, 'z'); // itr == --(--v.end())
    print_vector(v, "v = ");
    cout << "return value points " << *itr << endl;
    itr = v.insert(v.begin(), &c[0], &c[2]); // itr == v.begin()
    print_vector(v, "v = ");
    cout << "return value points " << *itr << endl;
    itr = v.insert(v.begin() + 1, '*'); // itr == ++v.begin()
    print_vector(v, "v = ");
    cout << "return value points " << *itr << endl;
}