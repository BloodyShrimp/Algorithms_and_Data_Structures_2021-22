#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <stdexcept>

class List
{
public:
    List();
    void push_front(int x);    // Dołącza element na początek listy
    int pop_front();           // Usuwa i zwraca element z początku listy
    void push_back(int x);     // Dołącza element na koniec listy
    int pop_back();            // Usuwa i zwraca element z końca listy
    int size();                // Zwraca liczbę elementów w liście
    bool empty();              // Zwraca true gdy lista jest pusta
    void clear();              // Czyści listę
    int find(int x);           // Zwraca pozycję pierwszego elementu o wartości x
    int erase(int i);          // Usuwa i zwraca element na pozycji i
    void insert(int i, int x); // Wstawia element x przed pozycję i
    int remove(int x);         // Usuwa wystąpienia x i zwraca ich liczbę
private:
    struct Node
    {                      // Zagnieżdżona klasa węzła
        int x;             // Element przechowywany przez węzeł listy, guard = size
        Node *prev = nullptr; // Wskaźnik do poprzedniego węzła, guard = tail
        Node *next = nullptr; // Wskaźnik do kolejnego węzła, guard = head
    };

    Node guard; // x = size, prev = tail, next = head
};

List::List()
{
    guard.next = &guard;
    guard.prev = &guard;
    guard.x = 0;
}

void List::push_front(int x)
{
    Node *temp = new Node();
    Node *before_this = guard.next;
    temp->x = x;
    temp->next = before_this;
    temp->prev = before_this->prev;
    temp->next->prev = temp;
    temp->prev->next = temp;
    guard.x++;
}

int List::pop_front()
{
    Node *popped = guard.next;
    if (popped == &guard)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int temp_int = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    guard.x--;
    return temp_int;
}

void List::push_back(int x)
{
    Node *temp = new Node();
    Node *before_this = &guard;
    temp->x = x;
    temp->next = before_this;
    temp->prev = before_this->prev;
    temp->next->prev = temp;
    temp->prev->next = temp;
    guard.x++;
}

int List::pop_back()
{
    Node *popped = guard.prev;
    if (popped == &guard)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int temp_int = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    guard.x--;
    return temp_int;
}

int List::size()
{
    return guard.x;
}

bool List::empty()
{
    return guard.x == 0;
}

void List::clear()
{
    Node *ptr = guard.next;
    Node *temp_ptr;
    while (ptr != &guard)
    {
        temp_ptr = ptr->next;
        delete ptr;
        ptr = temp_ptr;
    }
    guard.next = &guard;
    guard.prev = &guard;
    guard.x = 0;
}

int List::find(int x)
{
    Node *temp = guard.next;
    int index = 0;
    while (temp != &guard)
    {
        if (temp->x == x)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int List::erase(int i)
{
    if (i > guard.x - 1 || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    Node *popped = guard.next;
    if (popped == &guard)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    for (int j = 0; j < i; j++)
    {
        popped = popped->next;
    }
    int temp_int = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    guard.x--;
    return temp_int;
}

void List::insert(int i, int x)
{
    if (i > guard.x - 1 || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    Node *temp = new Node();
    Node *before_this = guard.next;
    for (int j = 0; j < i; j++)
    {
        before_this = before_this->next;
    }
    temp->x = x;
    temp->next = before_this;
    temp->prev = before_this->prev;
    temp->next->prev = temp;
    temp->prev->next = temp;
    guard.x++;
}

int List::remove(int x)
{
    int index;
    int counter = 0;
    while ((index = find(x)) != -1)
    {
        erase(index);
        counter++;
        guard.x--;
    }

    return counter;
}

#endif // LINKEDLIST
