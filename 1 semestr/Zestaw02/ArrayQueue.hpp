#ifndef ARRAYQUEUE
#define ARRAYQUEUE
#include <stdexcept>
#include <iostream>
class Queue
{
public:
    Queue();             // Konstruktor domyślny z romiarem 10^6
    Queue(int max_size); // Konstruktor z rozmiarem tablicy
    ~Queue();
    void push(int x); // Wstawia element x do kolejki (także enqueue)
    int pop();        // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    int size();       // Zwraca liczbę elementów w kolejce
    bool empty();     // Sprawdza czy kolejka jest pusta
private:
    int mhead = 0; // indeks najstarszego (piewszego) obiektu
    int mtail = 0; // indeks komórki do której wstawimy kolejny obiekt
    int msize = 0; // ilość elementów w tablicy
    int *mdata;
    int mcapacity = 0;
};

Queue::Queue()
{
    mcapacity = 1000000;
    mdata = new int[mcapacity];
}

Queue::Queue(int max_size)
{
    mcapacity = max_size;
    mdata = new int[max_size];
}

Queue::~Queue()
{
    delete[] mdata;
}

void Queue::push(int x)
{
    if (mhead == mtail && msize == mcapacity)
    {
        throw std::out_of_range("Pushing into a full queue.\n");
    }
    else
    {
        mdata[mtail] = x;
        mtail = (mtail + 1) % mcapacity;
        msize++;
    }
}

int Queue::pop()
{
    if (mhead == mtail && msize == 0)
    {
        throw std::out_of_range("Popping an empty queue.\n");
    }
    else
    {
        int temp = mdata[mhead];
        mhead = (mhead + 1) % mcapacity;
        msize--;
        return temp;
    }
}

int Queue::size()
{
    return msize;
}

bool Queue::empty()
{
    if (mhead == mtail && msize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // ARRAYQUEUE
