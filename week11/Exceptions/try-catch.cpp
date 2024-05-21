#include <iostream>
using namespace std;

int main(){
    bool x = false;
    bool y = true;
    try{ //multiple catch blocks
        if (x) throw 1;
        if (y) throw 'a';
        cout << "hi!" << endl;
    }
    catch (int e){ // 인자의 타입이 일치되는 예외만 처리한다.
        cout << "int catch!" << endl;
    }
    catch (char e){ // 매개 변수 type이 다른 여러 개의 catch blocks가 있을 수 있다.
        cout << "char catch!" << endl;
    } // 매개 변수 type이 일치하는 !!한 개의 catch block!!만 수행된다.
      // 순서는 앞에서부터
    catch(...){ // 모든 예외를 처리할 수 있다.
        cout << "I can Catch anything!" << endl;
    }
    cout << "hello!" << endl; // catch block이 수행되면 그 다음에는 정상 수행된다.
}

// x == true && y == false
// int catch! \n hello! 출력

// x == true && y == true
// int catch! \n hello! 출력

// x == false && y == true
// char catch! \n hello! 출력

// x == false && y == false
// hi! \n hello! 출력