#include "CursorList.hpp"
#include <iostream>

int main()
{
    List lista;
    int operations_amount;
    char operation;
    int element;
    int second_element;
    int index;
    std::cin >> operations_amount;
    for (int i = 0; i < operations_amount; i++)
    {
        std::cin >> operation;
        switch (operation)
        {
        case 'F':
            std::cin >> element;
            lista.push_front(element);
            break;
        case 'B':
            std::cin >> element;
            lista.push_back(element);
            break;
        case 'f':
            if (lista.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << lista.pop_front() << std::endl;
            }
            break;
        case 'b':
            if (lista.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << lista.pop_back() << std::endl;
            }
            break;
        case 'R':
            std::cin >> element;
            std::cin >> second_element;
            if ((index = lista.find(element)) == -1)
            {
                std::cout << "FALSE" << std::endl;
            }
            else
            {
                lista.erase(index);
                lista.insert(index, second_element);
                std::cout << "TRUE" << std::endl;
            }
            break;
        case 'S':
            std::cout << lista.size() << std::endl;
            break;
        }
    }
}