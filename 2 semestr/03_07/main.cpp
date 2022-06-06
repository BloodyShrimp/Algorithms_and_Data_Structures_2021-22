#include "set.hpp"
#include <iostream>

int main()
{
    Set<std::string> zbior;
    Set<std::string> other;
    zbior.insert("foo");
    zbior.insert("bar");
    other.insert("bar");
    other.insert("baz");
    zbior.printSet();
    std::cout << std::string(20, '=') << std::endl;
    other.printSet();
    std::cout << std::string(20, '=') << std::endl;
    zbior.intersection(other);
    zbior.printSet();
}