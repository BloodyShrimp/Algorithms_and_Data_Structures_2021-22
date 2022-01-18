#ifndef BLOCK
#define BLOCK
#include <iostream>
#include <ctime>
#include <iomanip>

class Block
{
private:
    std::string hash;
    std::string prevHash;
    std::string data;
    time_t timestamp;
    size_t nonce;
    int zeros;
public:
    Block();
    Block(std::string _data, std::string _prevHash, int zerosAtBeg);
    std::string generateHash();
    std::string mineBlock();
    std::string getHash();
    std::string getPrevHash();
    std::string getData();
    time_t getTimestamp();
    bool isHashValid(std::string _hash);
    bool startsWith(std::string mainString, std::string substring);
    std::string int_to_hex(size_t i);
};

#endif // BLOCK
