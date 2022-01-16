#include <iostream>
#include <random>

int main(int argc, const char *argv[])
{
    int n = atoi(argv[1]);
    int max = atoi(argv[2]);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, max);

    std::cout << max << std::endl;

    for(int i = 1; i < n; i++)
    {
        std::cout << dist(rng) << std::endl;
    }
}