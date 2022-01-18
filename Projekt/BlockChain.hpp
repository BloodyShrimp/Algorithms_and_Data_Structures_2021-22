#ifndef BLOCKCHAIN
#define BLOCKCHAIN
#include "LinkedList.hpp"
#include "Block.hpp"

class BlockChain
{
private:
    Block createGenesisBlock();
    List<Block> chain;
    int complexity; // ilosc 0 na poczatku hasha wymagana do dodania bloku
public:
    BlockChain(int _complexity);
    List<Block> getChain();
    // Block *getLatestBlock();
    bool isChainValid();
    void addBlock(std::string data);
    void printChain();
};

#endif // BLOCKCHAIN
