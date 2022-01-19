#include "LinkedList.hpp"
#include "Block.hpp"
#include "BlockChain.hpp"

BlockChain::BlockChain(int _complexity)
{
    complexity = _complexity;
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

Block BlockChain::createGenesisBlock()
{
    Block genesis("Genesis", "None", complexity);
    return genesis;
}

void BlockChain::addBlock(std::string data)
{
    std::string prevHash = chain[chain.size() - 1].getHash();
    Block newBlock(data, prevHash, complexity);
    chain.push_back(newBlock);
    chain[chain.size() - 1].printBlock();
}

List<Block> BlockChain::getChain()
{
    return chain;
}

bool BlockChain::isChainValid()
{
    bool is_hash_valid = true;
    bool is_previous_hash_valid = true;
    bool is_block_mined = true;
    bool flag = true;
    std::string previousHash;
    for(int i = 0; i < chain.size(); i++)
    {
        previousHash = i == 0 ? "None" : chain[i - 1].getHash();
        is_hash_valid = chain[i].getHash() == chain[i].generateHash();
        is_previous_hash_valid = previousHash == chain[i].getPrevHash();
        is_block_mined = chain[i].isHashValid(chain[i].getHash());
        flag = is_hash_valid && is_previous_hash_valid && is_block_mined;
        if(!flag)
        {
            break;
        }
    }

    return flag;
}

void BlockChain::printChain()
{
    for(int i = 0; i < chain.size(); i++)
    {
        time_t saveTime = chain[i].getTimestamp();
        std::cout << std::string(30, '=') << std::endl;
        std::cout << "Block nr " << i << std::endl;
        std::cout << std::string(30, '=') << std::endl;
        std::cout << "Data: " << chain[i].getData() << std::endl;
        std::cout << "Timestamp: " << std::put_time(std::localtime(&saveTime), "%Y-%m-%d %H:%M:%S") << std::endl;
        std::cout << "Hash: " << chain[i].getHash() << std::endl;
        std::cout << "Previous hash: " << chain[i].getPrevHash() << std::endl;
        std::cout << "Is hash valid? " << std::boolalpha << chain[i].isHashValid(chain[i].getHash()) << std::endl;
    }

    std::cout << std::string(30, '=') << std::endl;
    std::cout << "Is chain valid? " << std::boolalpha << isChainValid() << std::endl;
}