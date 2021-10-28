#include "LinkedQueue.hpp"
#include <iostream>

int main(int argc, const char *argv[])
{
    Queue kolejka;
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
            kolejka.push(element);
            break;
        case 'D':
            if (kolejka.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << kolejka.pop() << std::endl;
            }
            break;
        case 'S':
            std::cout << kolejka.size() << std::endl;
            break;
        }
    }
}