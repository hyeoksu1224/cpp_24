// 함수를 매개변수로 사용하는 방법
// 1. function pointer
// 2. function object(functor)

#include <iostream>
#include <cstdlib>
using namespace std;

void myIntFunc(int x){
    cout << x << endl;
}

void foo(){
    cout << "foo\n";
}

void bar(){
    cout << "bar\n";
}

// 함수 포인터를 사용하는 방법은 전통적인 방법이다.
// 함수 포인터는 주로 함수 매개변수로 보내져서 사용된다.
// foo와 bar는 포인터를 이용해 함수의 인자 보낼 함수
// *를 이용해 포인터 처리 해줘야하고, 함수기 때문에 괄호를 붙여야한다.
// 매개변수의 type과 인자로 보내줄 함수의 return type이 같아야 한다.
void f(int i, void (*f1)(), void (*f2)()){
    if (i > 0) f1(); else f2();
}

bool cmp_f(const int& a, const int& b){
    return a % 3 < b % 3;
}

bool compare_ints1(const int& a, const int& b, bool (*f)(const int&, const int&)){
    // const int& type을 두 개 가지는 bool타입 함수 포인터를 매개변수로 받는다.
    return f(a,b);
}

int compare(const void *first, const void *second){
    int v1 = *(int*)first;
    int v2 = *(int*)second;
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int main(){
    int i;
    cout << "enter a number : ";
    cin >> i;
    f(i, foo, bar); // 함수의 이름만 인자로 입력해준다. 괄호는 X
    // foo와 bar는 function pointer

    void (*foo2)(int); // void 함수 포인터 타입의 변수 foo2
    foo2 = myIntFunc; // foo2 = &myIntFunc 함수명은 그 자체로 주소 값이 될 수 있다. & 붙이는건 자유
    foo2(2); // (*foo2)(2)
    
    int j = 5; i = 7;
    cout << i << " " << j << endl;
    cout << "result of comparison : " << boolalpha << compare_ints1(i, j, cmp_f) << endl; // cmp_f가 f매개변수에 대입된다.
    // 즉, 매개변수에 함수가 전달됨.

    int a[10];
    for (i = 0; i < 10; i++) a[i] = 10 - i;
    for (i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;

    qsort(a, 10, sizeof(int), compare);

    for (i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

// C에서는 qsort라는 cstdlib의 함수가 존재한다.
// 배열을 정렬하는데 사용한다.
// 배열의 주소, 배열의 요소 갯수, 배열 요소의 크기, 비교 함수에 대한 함수포인터를 매개변수로 갖는다.
// 비교 함수는 두 요소를 비교하여, 그 결과를 정수로 반환한다.
// 같으면 0, 첫번째 인자가 두번째 인자보다 크면 양수, 첫 번째 인자가 두 번째 인자보다 작으면 음수
// qsort의 시간 복잡도는 O(n ln n)