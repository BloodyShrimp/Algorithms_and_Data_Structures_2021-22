#include "BinaryTree.hpp"
#include <iostream>

int main()
{
    int n;
    int temp;
    BinaryTree drzewko = BinaryTree();
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> temp;
        drzewko.insert(temp);
    }
    std::cout << drzewko.size() << " " << drzewko.depth() << " " << drzewko.minimum() << " " << drzewko.maximum() << std::endl;
    drzewko.preorder();
    for(int i = 1; i < 10; i++)
    {
        if(drzewko.search(i) == nullptr)
        {
            std::cout << "No" << std::endl;
        }
        else
        {
            std::cout << "Yes" << std::endl;
        }
    }
}