#include <iostream>
#include <vector>
#include <string>
using namespace std;

// template Function print_vector
template <class T>
void print_vector(vector<T> v, string s = ""){
    cout << s << "(" << v.size() << ") "; // string (size) elements...
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v(3, 5);
    print_vector(v, "16. v : ");
    v.resize(6);
    print_vector(v, "18. v : ");
    v[1] = 100; v[5] = -1;
    print_vector(v, "20. v : ");
    cout << "v.front() = " << v.front() << endl;
    cout << "v.back() = " << v.back() << endl;

    v.push_back(100);
    print_vector(v, "25. v : ");
    v.pop_back();
    print_vector(v, "27. v : ");
    v.clear();
    print_vector(v, "29. v : ");

    vector<int> v1(3);
    print_vector(v1, "32. v1 : ");
    v1[0] = 0; v1[1] = 1; v1[2] = 2;
    print_vector(v1,"34. v1 : ");
    // v[3] = 5; //run time error! size를 늘리지 않으면 error발생
    v1.push_back(5);
    print_vector(v1, "37. v1 = ");
}