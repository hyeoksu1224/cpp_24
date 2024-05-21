#include <iostream>
using namespace std;

class NonPositiveException{
public:
    int v;
    NonPositiveException(int v = 0) : v(v) {}
};

class ZeroException : public NonPositiveException{}; // 예외 클래스는 보통 아주 단순하다.
// 예외 클래스를 상속하여 만들었다. superClass의 초기값이 주어졌기 때문에 가능

int main(){
    int v;
    try{
        cout << " enter a value : ";
        cin >> v;
        if (v < 0) throw NonPositiveException(v); // throw 문은 클래스 타입의 객체도 던질 수 있다.
        if (v == 0) throw ZeroException();
    }
    catch (ZeroException& e){
        cout << "Zero \n";
    }
    catch (NonPositiveException& e){ // catch 문의 순서가 서로 바뀔 경우 ZeroCatch가 안됨.
                                     // Zero는 NonPos의 상속이기 때문에 upcasting이 implicit 하게 일어나서
        cout << "Negative Value : " << e.v << endl;
    }
    cout << v << endl;
    return 0;
}