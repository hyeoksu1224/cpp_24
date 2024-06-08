#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

template<class T>
void print_container(const T& container, string s = ""){
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for (; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}

bool myfunction(int i, int j){ return i > j; }

struct myClass{
    bool operator() (int i, int j){ return i > j; }
}myObject;

bool compare_as_ints(double i, double j){
    return (int(i) < int(j));
}

#define N 12
int main(){
    int a[] = {8, 7, 0, 3, 1, 2, 5, 0, 9, 1, 4, 6};
    vector<int> v1(&a[0], &a[N]);
    print_container(v1, "v = ");

    vector<int>::iterator it;
    // 범위 내에서 3번째 인자와 같은 값을 가지면 삭제한다.
    // 원본의 순서를 변경하지 않는다.
    // 원소가 제거된 후 새로운 끝 위치를 반환한다.
    // 실제 container의 크기를 변환하진 않음
    // 실제로 값이 제거된 자리를 채우지 않고, 원래 컨테이너의 마지막 요소들을 그대로 남겨두기 때문에
    // 8 7 3 1 2 5 9 1 4 6 4 6이 출력된다
    it = remove(v1.begin(), v1.end(), 0);
    print_container(v1, "v = ");

    // vector의 member function
    // .erase()는 범위만큼을 아예 삭제하고, size도 범위만큼 줄어든다.
    // 따라서 삭제를 완전히 수행하기 위해선 erase를 같이 수행해야 한다.
    v1.erase(it, v1.end());
    print_container(v1, "v = ");

    vector<int> v(&a[0], &a[N]);
    print_container(v, "1. v = ");
    // default : 값의 오름차순
    sort(v.begin(), v.end());
    print_container(v, "2. v = ");
    // 무작위로 섞는다.
    random_shuffle(v.begin(), v.end());
    print_container(v, "3. v = ");
    // myfunction으로 정렬 : 값의 내림차순
    sort(v.begin(), v.end(), myfunction);
    print_container(v, "4. v = ");
    // 무작위로 섞는다.
    random_shuffle(v.begin(), v.end());
    print_container(v, "5. v = ");
    // function pointer가 아닌 functor로 정렬한다.
    sort(v.begin(), v.end(), myObject);
    print_container(v, "6. v = ");
    // 무작위로 섞는다.
    random_shuffle(v.begin(), v.end());
    print_container(v, "7. v = ");
    // functional의 template class인 greater<>를 사용한다.
    // greater<>()를 내장 함수 객체라고 한다.
    sort(v.begin(), v.end(), greater<>());
    print_container(v, "8. v = ");
    // 무작위로 섞는다.
    random_shuffle(v.begin(), v.end());
    print_container(v, "9. v = ");
    // lambda 함수로 정렬한다.
    sort(v.begin(), v.end(), [](int i, int j){
        return i > j;
    });
    print_container(v, "0. v = ");

    double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};
    vector<double> myvector;
    // vector.assign()
    // 벡터의 기존 내용을 지우고, 새롭게 지정한 값들로 벡터를 채운다.
    // 벡터의 크기를 재설정하고 새로운 값을 할당한다.
    myvector.assign(mydoubles, mydoubles + 8);

    cout << "using default comparison: ";
    stable_sort(myvector.begin(), myvector.end());
    auto itv = myvector.begin();
    for(; itv != myvector.end(); itv ++) cout << *itv << ' ';
    cout << endl;

    myvector.assign(mydoubles, mydoubles + 8);
    cout << "using 'compare_as_ints' : ";
    // stable sort는 원래 순서를 보존한다!
    stable_sort(myvector.begin(), myvector.end(), compare_as_ints);
    itv = myvector.begin();
    for(; itv != myvector.end(); itv ++) cout << *itv << ' ';
    // 정수부만 비교, 정수부가 똑같이 1인 경우 원래 순서를 보존하여 정렬한다.
    cout << endl;

    int myints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> intvector(myints, myints+ 9);

    // 첫 번째부터 5번째까지 부분만 정렬
    partial_sort(intvector.begin(), intvector.begin() + 5, intvector.end());
    // 함수를 인자로 전달해 정렬을 구현할 수 있다.
    partial_sort(intvector.begin(), intvector.begin() + 5, intvector.end(), myfunction);
    cout << "intvector contains: ";
    for (it = intvector.begin(); it != intvector.end(); it ++) cout << *it << ' ';
    cout << endl;

    v.assign(&a[0], &a[N]);
    print_container(v, "1.v = ");

    sort(v.begin(), v.end());
    print_container(v, "2.v = ");

    random_shuffle(v.begin(), v.end());
    print_container(v, "3.v = ");

    // 5번째 원소를 기준으로, 왼쪽은 5번째 원소보다 작은 원소, 오른쪽은 5번째 원소보다 큰 원소
    nth_element(v.begin(), v.begin() + 4, v.end());
    print_container(v, "4.v = ");
}