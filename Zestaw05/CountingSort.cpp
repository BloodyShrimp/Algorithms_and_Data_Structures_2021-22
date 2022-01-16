#include <iostream>
#include <vector>
#include <chrono>

template <class T>
void sort(std::vector<T> &v)
{
    int size = (int)v.size();
    int k = 10000001;
    std::vector<int> count(k, 0);
    std::vector<T> output(size);
    int j;

    for(int i = 0; i < size; i++)
    {
        j = v[i];
        count[j]++;
    }

    for(int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        j = v[i];
        count[j]--;
        output[count[j]] = v[i];
    }

    v = output;
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