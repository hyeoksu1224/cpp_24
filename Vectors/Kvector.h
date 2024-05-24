#ifndef __KVECTOR__
#define __KVECTOR__
#include <iostream>

template <class T>
class Kvector;

template <class T>
class Kvector{
protected:
    T *m;
    int len;
public:
    Kvector(int sz=0, T value = 0);
    Kvector(const Kvector& v);
virtual ~Kvector();
virtual void print() const;
    void clear();
    int size() const;
    Kvector<T>& operator =(const Kvector<T>& v);
    T& operator[](int idx){ return m[idx]; }
const T& operator[](int idx) const{ return m[idx]; }

    T sum() const{
        if (len == 0) return T();
        T s = m[0];
        for (int i = 1; i < len; i++) s+=m[i];
        return s;
    }

friend bool operator ==(const Kvector<T>& v, const Kvector<T>& w){
    bool value = true;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != w[i]) {
            value = false;
            break;
        }
    }
    return (v.size() == w.size()) && value;
}

friend bool operator!=(const Kvector<T>& v, const Kvector<T>& w){
    return !(v == w);
}

friend std::ostream& operator<<(std::ostream& os, const Kvector& s){
    for (int i = 0; i < s.size(); i++){
        os << s[i] << ' ';
    }
    return os;
}
};

template <class T>
Kvector<T>::Kvector(int sz, T value) : len(sz){
    //cout << this << " : Kvector(" << sz << "," << value << ") \n";
    if (!sz){ m = NULL; return; }
    m = new T[sz];
    for(int i = 0; i < len; i++) m[i] = value;
}

template <class T>
Kvector<T>::Kvector(const Kvector<T>& v){
    //cout << this << " : Kvector(*" << &v << ") \n";
    len = v.len;
    if (!len){ m = NULL; return; }
    m = new T [len];
    for(int i = 0; i < len; i++) m[i] = v.m[i];
}

template <class T>
Kvector<T>::~Kvector(){
    //cout << this << " : ~Kvector() \n";
    delete[] m;
}

template <class T>
void Kvector<T>::print() const{
    std::cout << "Kvector<T>\n";
}

template <class T>
void Kvector<T>::clear(){
    delete[] m;
    m = nullptr;
    len = 0;
}

template <class T>
int Kvector<T>::size() const{
    return len;
}

template <class T>
Kvector<T>& Kvector<T>::operator=(const Kvector<T>& v){
    // std::cout << "Kvector::operator= " << &v << std::endl;
    delete[] m;
    len = v.size();
    m = new T[len];
    for(int i=0;i<len;i++) m[i]=v.m[i];
    return *this;
}

// template <class T>
// bool operator ==(const Kvector<T> &v, const Kvector<T> &w){
//     bool value=true;
//     for(int i=0;i<v.size();i++){
//         if(v.m[i] != w.m[i]){
//             value=false;
//             break;
//         }
//     }
//     return (v.size() == w.size()) && (value);
// }
// 
// template <class T>
// bool operator !=(const Kvector<T>& v,const Kvector<T>& w){
//     return !(v==w);
// }
// 
// template <class T>
// std::ostream& operator <<(std::ostream& os, const Kvector<T>& v){
//     for(int i=0;i<v.size();i++) os<<v.m[i]<<' ';
//     return os;
// }
#endif