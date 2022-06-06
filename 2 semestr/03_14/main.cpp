#include <string>
#include "set.hpp"

int main()
{
    Set<int> set_1, set_2;

    for (int i = 0; i <= 7; i++)
    {
        // set_1.printSet();
        // std::cout << std::endl;
        set_1.insert(i);
    }
    for (int i = 5; i <= 10; i++)
    {
        // set_1.printSet();
        // std::cout << std::endl;
        set_2.insert(i);
    }
    // set_1.printSet();
    // std::cout << std::endl;

    set_1.difference(set_2);

    // set_1.printSet();
    // std::cout << std::endl;

    // for (int i = 0; i <= 4; i++)
    // {
    //     std::cout << i << " "<< (set_1.contains(i)) << std::endl;
    // }
    // for (int i = 5; i <= 10; i++)
    // {
    //     std::cout << i << " "<< (!(set_1.contains(i))) << std::endl;
    // }
    for (int i = 0; i <= 4; i++)
    {
        std::cout << set_1.contains(i) << std::endl;
    }
    for (int i = 5; i <= 10; i++)
    {
        std::cout << !set_1.contains(i) << std::endl;
    }
}

// 0 1 2 3 4 5 6 7
// 5 6 7 8 9 10