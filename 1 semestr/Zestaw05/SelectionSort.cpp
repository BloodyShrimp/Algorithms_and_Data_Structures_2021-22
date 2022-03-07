#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    T temp;
    int min;
    int size = (int)v.size();

    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = v[min];
            v[min] = v[i];
            v[i] = temp;
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