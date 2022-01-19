#include "SHA256.hpp"
#include <iostream>

int main()
{
    std::string hash = sha256("Dupa");
    std::cout << hash << std::endl;
}