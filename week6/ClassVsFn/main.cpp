#include <iostream>
#include <string>
using namespace std;

int my_strlen(const char* str);
char* my_strcpy(char* d, const char* s);
char* my_strcat(char *d, const char* s);

int main(){
    char s1[10], s2[10] = "xxx"; // s2의 크기를 20으로 증가

    my_strcpy(s1,"12");
    cout << "length of " << s1 << " is "<< my_strlen(s1) << endl;

    my_strcpy(s2, s1);
    my_strcat(s2, "ab");
    cout << "length of " << s2 << " is " << my_strlen(s2) << endl;

    string s3, s4 = "xxx";

    s3 = "12";
    cout << "length of " << s3 << " is " <<s3.length() << endl;

    s4 = s3 + "ab";
    cout << "length of " << s4 << " is " << s4.size() << endl;
}

// 클래스를 이용해 객체를 만들고, 데이터와 함수를 객체로 묶는 캡슐화를 통해 코드를 짰다.
// 절차지향 프로그래밍 방식으로 함수만을 이용해 구현했을 때보다 훨씬 직관적이고, 쉽다.

int my_strlen(const char* str){
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

char* my_strcpy(char* d, const char* s){
    char* r = d;
    for(; *s; s++)
        *r++ = *s;
    *r = '\0';
    return d;
}

char* my_strcat(char* d, const char* s){
    char* r = d;
    while(*d) d++; // d 포인터를 문자열 끝으로 이동
    while(*s) *d++ = *s++; // s를 d에 복사
    *d = '\0'; // 끝에 널 문자 추가
    return r;
}

/*


int my_strlen(const char* str){
    int i;
    for(i = 0; *str != '\0'; i++);
    return i;
}

char* my_strcpy(char* d, const char* s){
    char* r = d;
    for(; *s; s++)
        *r++ = *s;
    *r = '\0';
    return d;
}

char* my_strcat(char* d, const char* s){
    char* r = d;
    for(; *d; d++) *d++ = *s;
    *d = '\0';
    return r;
}
*/