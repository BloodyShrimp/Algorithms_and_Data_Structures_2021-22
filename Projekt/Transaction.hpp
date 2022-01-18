#ifndef TRANSACTION
#define TRANSACTION
#include <iostream>

struct Transaction
{
    double amount;
    std::string senderKey;
    std::string receiverKey;
    time_t timestamp;

    Transaction(){};

    Transaction(double _amount, std::string sender, std::string receiver, time_t time)
    {
        amount = _amount;
        senderKey = sender;
        receiverKey = receiver;
        timestamp = time;
    };
};

#endif // TRANSACTION
