#ifndef __KVECTOR__
#define __KVECTOR__
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Kvector{
protected:
    int *m;
    int len;
public:
    Kvector(int sz=0, int value=0);
    Kvector(const Kvector& v);
    virtual ~Kvector();
    virtual void print();
    void clear();
    int size() const;
Kvector& operator =(const Kvector& v);
friend bool operator ==(const Kvector& v, const Kvector& w);
friend bool operator!=(const Kvector& v, const Kvector& w);
int& operator[](int idx){ return m[idx]; }
const int& operator[](int idx) const{ return m[idx]; }
friend std::ostream& operator<<(std::ostream& os, const Kvector& s);
};
#endif