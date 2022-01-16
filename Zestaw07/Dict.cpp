#include "Dict.hpp"
#include <iostream>
#include <string>
#include <fstream>
using Pair = std::pair<std::string, std::string>;

int main(int argc, const char *argv[])
{
    Dict<std::string, std::string> dictionary;
    std::string file_name = argv[1];
    std::ifstream file(file_name);
    std::string key;
    std::string val;
    std::string input;

    if (!file)
    {
        throw std::out_of_range("No such file.");
    }

    while (file >> key >> val)
    {
        dictionary.insert(Pair(key, val));
    }

    file.close();

    while (std::cin >> input)
    {
        if (dictionary.find(input))
        {
            std::cout << dictionary[input] << std::endl;
        }
        else
        {
            std::cout << "-" << std::endl;
        }
    }
}