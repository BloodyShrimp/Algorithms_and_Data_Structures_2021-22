#include "BlockChain.hpp"

int main()
{
    BlockChain simonCoin(2);
    simonCoin.addBlock("Raz");
    simonCoin.addBlock("Dwa");
    simonCoin.addBlock("Trzy");
    simonCoin.getChain().pop_back();
    std::cout << simonCoin.getChain().size() << std::endl;
    simonCoin.getChain().erase(1);
    std::cout << simonCoin.getChain().size() << std::endl;
    simonCoin.printChain();
}