#include "Avector.h"

Avector::Avector(int sz, int v, const char* t) : Kvector(sz, v){
    cout << this << " : Avector(" << sz << ',' << v << " ,\"" << t << "\")\n";
    table_len = strlen(t);
    table = new char[table_len + 1];
    strcpy(table, t);
}

Avector::Avector(const Avector& v) : Kvector(v){
    cout << this << " : Avector(*" << &v <<")\n";
    setTable(v.table);
}

Avector::~Avector(){
    cout << this << " : ~Avector() \n";
    delete[] table;
}

void Avector::setTable(const char* t){
    delete[] table;
    table_len = strlen(t);
    table = new char[table_len + 1];
    strcpy(table, t);
}

Avector& Avector::operator =(const Avector& v){
    setTable(v.table);
    this->Kvector::operator=(v);
    return *this;
}