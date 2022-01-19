#ifndef BLOCKCHAIN
#define BLOCKCHAIN
#include "LinkedList.hpp"
#include "Block.hpp"

class BlockChain
{
private:
    // method creating the genesis block
    Block createGenesisBlock();
    // list containing the blockchain
    List<Block> chain;
    // number of zeros required at the beggining of the hash
    int complexity;
public:
    // constructor
    BlockChain(int _complexity);
    // method returning the chain
    List<Block> getChain();
    // Block *getLatestBlock();
    
    // check whether the blockchain is valid i.e. the hashes are valid and the blocks are mined
    bool isChainValid();
    // add new block
    void addBlock(std::string data);
    // print out the information about the blockchain
    void printChain();
};

#endif // BLOCKCHAIN
