#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1;
    string s2("I");
    string s3 = s2;
    string s4 = "you"; 

    cout << "s1 : \"" << s1 << "\" size " << s1.size() << endl; // 널 문자를 제외한 문자열의 길이를 반환
    cout << "s2 : \"" << s2 << "\" size " << s2.size() << endl;
    cout << "s3 : \"" << s3 << "\" size " << s3.size() << endl;
    cout << "s4 : \"" << s4 << "\" size " << s4.size() << endl;

    s1 = s2 + " and " + s4;
    cout << "s1 : \"" << s1 << "\" size " <<s1.size() << endl;
    s1.clear(); // 문자열을 지우고 null 문자열("")로 만든다.
    cout << "s1 : \"" << s1 << "\" size " << s1.size() << endl;
    cout << "is s1 empty? " << s1.empty() << endl; // 문자열이 null 문자열이면 true를 반환한다.

    s4[0] = 'Y'; //0번째 원소를 Y로 치환한다.
    cout << "s4 : \"" << s4 << "\" size " << s4.size() << endl;

    s1 = "abcdefghijklmnopqrstuvwxyz";
    int i = s1.find('c'); // 문자열 혹은 문자가 발견되는 첫 번째 인덱스를 반환
    cout << "c is the " << i << "-th alphabet.\n";
    i = s1.find('c', i+1); // pos의 위치부터 문자열 혹은 문자가 발견되는 첫 번째 인덱스를 반환
    cout << "the next c is the " << i << "-th alphabet.\n"; // 찾지 못하면 public static member constant string::npos (= -1) 반환
    i = s1.find("efg");
    cout << "efg starts at " << i << "-th alphabet.\n";
    cout << s2 << " < " << s4 << " : " << (s2 < s4) << endl;
    cout << s2 << " == " << s4 << " : " << (s2 == s4) << endl;

    cout << "Write a word to insert : ";
    cin >> s3;
    s1.insert(0, s3); //pos 위치에 문자열 혹은 문자를 삽입
    cout << "s1 : \"" << s1 << "\" size " << s1.size() <<endl;
    s1.erase(1, 3); //pos 위치부터 len개 문자를 삭제
    cout << "s1 : \"" << s1 << "\" size " << s1.size() <<endl;
    return 0;
}