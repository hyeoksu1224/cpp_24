#include "Kvector.h"

Kvector::Kvector(int sz, int value){
    //cout << this << " : Kvector(" << sz << "," << value << ") \n";
    len = sz;
    m = new int[len];
    for(int i=0;i<len;i++) m[i]=value;
}

Kvector::Kvector(const Kvector& v){
    //cout << this << " : Kvector(*" << &v << ") \n";
    len = v.len;
    m = new int [len];
    int value = *(v.m);
    for(int i=0;i<len;i++) m[i]=value;
}

Kvector::~Kvector(){
    //cout << this << " : ~Kvector() \n";
    delete[] m;
}

void Kvector::print(){
    for(int i=0;i<len;i++) std::cout<<m[i]<<" ";
        std::cout<<std::endl;
}

void Kvector::clear(){
    delete[] m;
    m=nullptr;
    len=0;
}

int Kvector::size() const{
    return len;
}

Kvector& Kvector::operator=(const Kvector& v){
    std::cout << "Kvector::operator= " << &v << std::endl;
    delete[] m;
    len = v.size();
    m = new int[len];
    for(int i=0;i<len;i++) m[i]=v.m[i];
    return *this;
}

bool operator ==(const Kvector &v, const Kvector &w){
    bool value=true;
    for(int i=0;i<v.size();i++){
        if(v.m[i]!=w.m[i]){
            value=false;
            break;
        }
    }
    return (v.size() == w.size()) && (value);
}
bool operator !=(const Kvector& v,const Kvector& w){
    return !(v==w);
}
std::ostream& operator <<(std::ostream& os, const Kvector& v){
    for(int i=0;i<v.size();i++) os<<v.m[i]<<' ';
    return os;
}