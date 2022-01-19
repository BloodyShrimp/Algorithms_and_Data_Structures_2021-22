#include "BlockChain.hpp"
using namespace std;

int main()
{
    int complexity;
    cout << "Podaj ilosc zer na poczatku hasha. (od 0 do 15)" << endl;
    cin >> complexity;
    BlockChain blockchain(complexity);
    cout << "Komendy: " << endl;
    cout << "A x - dodaj blok o zawartosci x" << endl;
    cout << "P - wyswietl blockchain" << endl;
    cout << "E - wyjdz z programu" << endl;
    char command;
    bool run = true;
    string data;
    while (run)
    {
        cin >> command;
        switch (command)
        {
        case 'A':
            cin >> data;
            blockchain.addBlock(data);
            break;
        case 'P':
            blockchain.printChain();
            break;
        case 'E':
            run = false;
            break;
        }
    }
}