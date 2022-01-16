#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    T temp;
    int size = (int)v.size();
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        for (int i = 1; i < size; i++)
        {
            if (v[i - 1] > v[i])
            {
                temp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = temp;
                swapped = true;
            }
        }
    }
}

int main()
{
    int input;
    std::vector<int> numbers;

    while (std::cin >> input)
    {
        numbers.push_back(input);
    }

    auto start = std::chrono::high_resolution_clock::now();
    sort<int>(numbers);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << elapsed.count() << std::endl;

    // for (const auto &i : numbers)
    // {
    //     std::cout << i << std::endl;
    // }
}