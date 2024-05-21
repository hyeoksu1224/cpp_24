#include <iostream>
#include "Bvector.h"

class IncompatibleException : public std::exception{
public:
    int nbits1, nbits2;
    IncompatibleException(int nbits1 = 131, int nbits2 = 131) : nbits1(nbits1), nbits2(nbits2){}
};

class BitSet : public Bvector{
public:
    BitSet(int sz=32);
void insert(int v);
BitSet& operator+=(const BitSet& v);
friend BitSet operator+(BitSet v1, const BitSet& v2);
friend std::ostream& operator<<(std::ostream& os, const BitSet& s);
};