#include <iostream>
#include <vector>
using namespace std;

// STL : 표준 템플릿 라이브러리
// 많은 프로그래머들이 공통적으로 사용하는 자료구조와 알고리즘을 template으로 구현한 클래스
// namespace std에 포함되어 있다.

// 컨테이너, 반복자, 알고리즘으로 구성되어있다.
// 컨테이너 : 자료를 저장하는 구조. 벡터, 리스트, 맵, 집합, 큐, 스택 등
// 반복자 : 컨테이너 안에서 정의되는 클래스. 포인터의 역할
// 알고리즘 : 정렬이나 탐색과 같은 다양한 알고리즘이 구현되어 있다.

// 순차 컨테이너 : 자료를 내가 저장하는 순서대로 저장
// 벡터, 덱, 리스트가 존재

#define N 3

int main(){
    // 벡터 == 동적 배열 == 스마트 배열
    // 템플릿으로 설계
    // Kvector와 유사 : 동적으로 배열의 크기가 변경되는 기능이 구현되어있음

    vector<int> v; // int type의 벡터(동적배열) v1 선언

    cout << "v.size() = " << v.size() << endl; // v에 할당된 배열의 크기
    cout << "v.max_size() = " << v.max_size() << endl; // v에 사용 가능한 최대 크기
    cout << "v.empty() = " << v.empty() << endl; // v가 비었는가? 즉, v.size() == 0인가?
    // cout << "v[0] = " << v[0] << endl; // v의 첫 번째 원소에 접근, 
                                            // v가 비었기 때문에 segmentation fault or runtime error!

    vector<int> v1(3); // size가 3인 배열을 할당

    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.max_size() = " << v1.max_size() << endl;
    cout << "v1.empty() = " << v1.empty() << endl;
    cout << "v1.capacity() = " << v1.capacity() << endl; // capacity : 적당히 미리 공간을 할당
    cout << "v1[0] = " << v1[0] << endl;

    vector<int> v2(N, 5); // size가 3인 배열을 전부 5로 초기화

    cout << "v2.size() = " << v2.size() << endl;
    cout << "v2.max_size() = " << v2.max_size() << endl;
    cout << "v2.empty() = " << v2.empty() << endl;
    cout << "v2.capacity() = " << v2.capacity() << endl; // capacity : 적당히 미리 공간을 할당
    cout << "v2 = ";
    for (int i = 0; i < N; i++) cout << v2[i] << " ";
    cout << endl;
    
    v2[0] = 1;
    v2[1] = 2;
    // v2[4] = 3; //run time error! 크기가 3인데 v2[4]에 access
    cout << "v2 = ";
    for (int i = 0; i < N; i++) cout << v2[i] << " ";
    cout << endl;

    v2.resize(6);
    cout << "v2.size() = " << v2.size() << endl;
    cout << "v2.max_size() = " << v2.max_size() << endl;
    cout << "v2.empty() = " << v2.empty() << endl;
    cout << "v2.capacity() = " << v2.capacity() << endl;
    v2[4] = 3; //resize(6)을 했기 때문에, error X
    cout << "v2 = ";
    for (int i = 0; i < 6; i++) cout << v2[i] << " ";
    cout << endl;
}