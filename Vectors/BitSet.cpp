#include "BitSet.h"

BitSet::BitSet(int sz) : Bvector(sz) {}

void BitSet::insert(int v) {
    if (v >= 0 && v < NBITS) {
        set(v);
    }
}

BitSet& BitSet::operator+=(const BitSet& v) {
    // 두 operands의 최대 원소 갯수 (NBITS)가 다르면 IncompatibleException을 발생하도록 변경하라
    // uncompatibleException은 std::exception class를 상속하여
    // 멤버 변수 (2개) 와 생성자 구현 필요
    
    if (NBITS == v.NBITS) {
        for (int i = 0; i < len; i++) {
            m[i] |= v.m[i]; // 32bit를 한번에 bitwise or 연산.
                            // bit 단위로 연산하는 것보다 훨씬 빠름 for (int i = 0; i < NBITS; i++) if (bit(i) || v.bit(i)) set(i);
        }
    }
    else throw IncompatibleException(NBITS, v.NBITS);
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
        if (s.bit(i)) { // s[i] 를 사용해도 됨
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