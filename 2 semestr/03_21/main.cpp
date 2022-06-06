#include <iostream>
#include "bitset.hpp"

int main()
{
    BitSet<0, 15> secik;
    BitSet<0, 15> other;

    secik.insert(-1);
    secik.printSet();
}