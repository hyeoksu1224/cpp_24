#include <iostream>
using namespace std;

class NonPositiveException{
public:
    int v;
    NonPositiveException(int v = 0) : v(v) {}
};

class ZeroException : public NonPositiveException{};
void foo(){
    int v;
    cout << "enter a value : ";
    cin >> v;
    if (v < 0) throw NonPositiveException(v);
    if (v == 0) throw ZeroException();
    cout << "foo\n";
} // 함수가 Catch하지 않는 경우. 그냥 throw만 해준다.

void fooCatch(){
    try{
        int v;
        cout << "enter a value : ";
        cin >> v;
        if (v < 0) throw NonPositiveException(v);
        if (v == 0) throw ZeroException();
        cout << "foo\n";
    }
    catch(...){
        cout << "foo catches exception\n";
    }
} // main에서 catch는 절대 수행되지 않는다. foo에서 모두 catch하기 때문

void fooCatThr(){
    try{
        int v;
        cout << "enter a value : ";
        cin >> v;
        if (v < 0) throw NonPositiveException(v);
        //if (v < 0) throw -1; // 예외를 throw했는데 처리되지 않으면, abort()가 호출되어 프로그램 종료
        if (v == 0) throw ZeroException();
        cout << "foo\n";
    }
    catch(...){
        cout << "foo catches exception\n";
        throw; // catch에서 다시 throw -> error 처리가 미완됐으니 main에서 마저 해라!
    }
}

int main(){
    int v;
    try{
        //foo();
        //fooCatch();
        fooCatThr();
    }
    catch (ZeroException& e){
        cout << "Zero \n";
    }
    catch (NonPositiveException& e){
        cout << "NonPositive Value : " << e.v << endl;
    }
    cout << "main" << endl;
    return 0;
}