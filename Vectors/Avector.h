#ifndef __AVECTOR__
#define __AVECTOR__
#include <iostream>
#include "Kvector.h"

#define N 3
class Avector : public Kvector{
    char* table;
    int table_len;
public:
    Avector(int sz = 0, int v = 0, const char* t = "abc");
    Avector(const Avector& v);
    ~Avector();
    void setTable(const char* t);
    Avector& operator =(const Avector& v);
};
#endif