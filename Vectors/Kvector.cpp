//#include "Kvector.h"

template <class T>
class Kvector;

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
T Kvector<T>::size() const{
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