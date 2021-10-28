#ifndef LINKEDQUEUE
#define LINKEDQUEUE
#include <stdexcept>
#include <iostream>
class Queue
{
public:
    Queue(); // Konstruktor domyślny
    ~Queue();
    void push(int x); // Wstawia element x do kolejki (także enqueue)
    int pop();        // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    int size();       // Zwraca liczbę elementów w kolejce
    bool empty();     // Sprawdza czy kolejka jest pusta
private:
    struct Node
    {
        int value;
        Node *next;
    };
    Node *head; // wskazuje na najstarszy (pierwszy) obiekt
    Node *tail; // wskazuje na ostatni (najmłodszy) węzeł
    int msize;  // ilość elementów w kolejce
};

Queue::Queue()
{
    head = NULL;
    tail = NULL;
    msize = 0;
}

Queue::~Queue()
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

void Queue::push(int x)
{
    Node *temp = new Node();
    temp->value = x;
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        msize++;
        return;
    }

    tail->next = temp;
    tail = temp;
    msize++;
}

int Queue::pop()
{
    if (head == NULL)
    {
        throw std::out_of_range("Popping an empty queue.\n");
    }

    Node *temp = head;
    int temp_int = temp->value;
    head = head->next;
    if (head == NULL)
    {
        tail = NULL;
    }
    free(temp);
    msize--;
    return temp_int;
}

int Queue::size()
{
    return msize;
}

bool Queue::empty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // LINKEDQUEUE
