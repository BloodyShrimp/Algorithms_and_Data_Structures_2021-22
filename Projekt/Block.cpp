#include "Block.hpp"

Block::Block()
{
    data = "";
    prevHash = "";
    timestamp = std::time(nullptr);
    zeros = 5;
    nonce = 0;
    hash = generateHash();
}

Block::Block(std::string _data, std::string _prevHash, int zerosAtBeg)
{
    data = _data;
    prevHash = _prevHash;
    timestamp = std::time(nullptr);
    zeros = zerosAtBeg;
    nonce = 0;
    hash = mineBlock();
}

std::string Block::generateHash()
{
    std::string _hash = "";
    std::string dataToHash = prevHash + std::to_string(timestamp) + data + std::to_string(nonce);
    const std::hash<std::string> hasher;
    std::size_t hashResult = hasher(dataToHash);
    _hash = int_to_hex(hashResult);
    return _hash;
}

std::string Block::mineBlock()
{
    std::string _hash = generateHash();
    while (!isHashValid(_hash))
    {
        nonce++;
        _hash = generateHash();
    }
    return _hash;
}

std::string Block::getHash()
{
    return hash;
}

std::string Block::getPrevHash()
{
    return prevHash;
}

std::string Block::getData()
{
    return data;
}

time_t Block::getTimestamp()
{
    return timestamp;
}

bool Block::isHashValid(std::string _hash)
{
    return startsWith(_hash, std::string(zeros, '0'));
}

bool Block::startsWith(std::string mainString, std::string substring)
{
    if (mainString.find(substring) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Block::int_to_hex(std::size_t i)
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(size_t) * 2) << std::hex << i;
    return stream.str();
}

void Block::printBlock()
{
    time_t saveTime = getTimestamp();
    std::cout << std::string(30, '=') << std::endl;
    std::cout << "Block added. " << std::endl;
    std::cout << std::string(30, '=') << std::endl;
    std::cout << "Data: " << getData() << std::endl;
    std::cout << "Timestamp: " << std::put_time(std::localtime(&saveTime), "%Y-%m-%d %H:%M:%S") << std::endl;
    std::cout << "Hash: " << getHash() << std::endl;
    std::cout << "Previous hash: " << getPrevHash() << std::endl;
    std::cout << "Is hash valid? " << std::boolalpha << isHashValid(getHash()) << std::endl;
    std::cout << std::string(30, '=') << std::endl;
}