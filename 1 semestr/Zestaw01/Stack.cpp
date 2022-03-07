#include "ArrayStack.hpp"
#include <iostream>

int main(int argc, const char *argv[])
{
    Stack stos(1000000);
    int operations_amount;
    char operation;
    int element;
    std::cin >> operations_amount;
    for (int i = 0; i < operations_amount; i++)
    {
        std::cin >> operation;
        switch (operation)
        {
        case 'A':
            std::cin >> element;
            stos.push(element);
            break;
        case 'D':
            if (stos.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << stos.pop() << std::endl;
            }
            break;
        case 'S':
            std::cout << stos.size() << std::endl;
            break;
        }
    }
}