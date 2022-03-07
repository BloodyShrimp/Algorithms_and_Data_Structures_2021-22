#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    T temp;
    int size = (int)v.size();
    // int shifts = 0;

    for(int i = 1; i < size; i++)
    {
        temp = v[i];
        int j = i - 1;
        for(; j >= 0 && v[j] > temp; j--)
        {
            v[j+1] = v[j];
            // shifts++;
        }
        v[j+1] = temp;
        // shifts++;
    }

    // std::cerr << "Shifts: " << shifts << std::endl;
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