#include <iostream>
#include <ctime>

int main()
{
    srand((unsigned)time(NULL));
    int max = 1000001;
    int operation_amount = rand() % max;
    std::cout << operation_amount << std::endl;
    for (int i = 0; i < operation_amount; i++)
    {
        switch (rand() % 3)
        {
        case 0:
            std::cout << "A " << rand() % max << std::endl;
            break;
        case 1:
            std::cout << "D" << std::endl;
            break;
        case 2:
            std::cout << "S" << std::endl;
            break;
        }
    }
}