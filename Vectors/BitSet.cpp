#include "BitSet.h"

BitSet::BitSet(int sz) : Bvector(sz) {}

void BitSet::insert(int v) {
    if (v >= 0 && v < NBITS) {
        set(v);
    }
}

BitSet& BitSet::operator+=(const BitSet& v) {
    if (NBITS == v.NBITS) {
        for (int i = 0; i < len; i++) {
            m[i] |= v.m[i];
        }
    }
    return *this;
}

BitSet operator+(BitSet v1, const BitSet& v2) {
    v1 += v2;
    return v1;
}

std::ostream& operator<<(std::ostream& os, const BitSet& s) {
    os << "{ ";
    bool first = true;
    for (int i = 0; i < s.size(); i++) {
        if (s.bit(i)) {
            if (!first) {
                os << ", ";
            }
            os << i;
            first = false;
        }
    }
    os << " }";
    return os;
}
