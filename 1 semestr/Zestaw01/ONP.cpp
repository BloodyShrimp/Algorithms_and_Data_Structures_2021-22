#include <iostream>
#include <stack>
#include "LinkedStack.hpp"

int main()
{
    Stack stos;
    std::string input;
    std::string wynik;
    std::getline(std::cin, input);
    for (auto znak : input)
    {
        if (znak >= '0' && znak <= '9')
        {
            wynik += znak;
        }
        else if(znak == ' ')
        {
            if(wynik.back() != ' ' && !wynik.empty())
            {
                wynik += ' ';
            }
        }
        else if (znak == '(')
        {
            stos.push('(');
        }
        else if (znak == ')')
        {
            while (stos.top() != '(')
            {
                wynik += stos.top();
                stos.pop();
            }
            stos.pop();
        }
        else
        {
            stos.push(znak);
        }
    }
    std::cout << wynik << std::endl;
}