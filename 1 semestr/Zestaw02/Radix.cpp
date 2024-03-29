#include "LinkedQueue.hpp"
#include <vector>
#include <iostream>
#include <iterator>

void radix(std::vector<int> &v)
{
    Queue index[10];
    int number;
    int dividor = 1;
    for (int i = 0; i < 9; i++)
    {
        for (const auto &n : v)
        {
            number = n / dividor;
            number = number % 10;
            index[number].push(n);
        }
        v.clear();
        for (int j = 0; j < 10; j++)
        {
            while (!index[j].empty())
            {
                v.push_back(index[j].pop());
            }
        }
        dividor *= 10;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::vector<int> wektor(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    radix(wektor);
    for(const auto& i : wektor)
    {
        std::cout << i << std::endl;
    }
}