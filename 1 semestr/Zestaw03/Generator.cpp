#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL));
    int max = 1001;
    int operation_amount = rand() % max;
    std::cout << operation_amount << std::endl;
    for (int i = 0; i < operation_amount; i++)
    {
        switch (rand() % 6)
        {
        case 0:
            std::cout << "F " << rand() % max << std::endl;
            break;
        case 1:
            std::cout << "B " << rand() % max << std::endl;
            break;
        case 2:
            std::cout << "f" << std::endl;
            break;
        case 3:
            std::cout << "b" << std::endl;
            break;
        case 4:
            std::cout << "R " << rand() % max << " " << rand() % max << std::endl;
            break;
        case 5:
            std::cout << "S" << std::endl;
            break;
        }
    }
}