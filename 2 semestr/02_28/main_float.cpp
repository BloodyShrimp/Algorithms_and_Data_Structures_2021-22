#include "stos_szablon.hpp"
#include <iostream>

int main()
{
    Stack<float> stos;
    for(int i = 0; i < 17; i++)
    {
        stos.push(i * 13.79);
        std::cout << stos.top() << std::endl;
    }

    for(int i = 0; i < 16; i++)
    {
        std::cout << stos.top() << std::endl;
        stos.pop();
    }
}