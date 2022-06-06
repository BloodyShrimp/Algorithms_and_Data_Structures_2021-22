#ifndef SET
#define SET
#include <iostream>

template <class T>
class Set
{
public:
    Set();
    void insert(T value);                // wstawia wartość value jeśli jej nie było w zbiorze, wpp operacja pusta
    void remove(T value);                // usuwa wartość value jeśli była w zbiorze, wpp operacja pusta
    bool contains(T value);              // sprawdza czy value jest w zbiorze
    void Union(const Set &other);        // dodaje do zbioru elementy z innego zbioru przekazanego jako argument
    void intersection(const Set &other); // wykonuje przcięcie zbioru z innym zbiorem
    void difference(const Set &other);   // znajduje roznice zbioru z innym zbiorem
    void printSet();

private:
    struct Node
    {                         // Zagnieżdżona klasa węzła
        T x;                  // Element przechowywany przez węzeł listy, guard = size
        Node *prev = nullptr; // Wskaźnik do poprzedniego węzła, guard = tail
        Node *next = nullptr; // Wskaźnik do kolejnego węzła, guard = head
    };
    Node guard; // x = size, prev = tail, next = head
};

template <class T>
Set<T>::Set()
{
    guard.next = &guard;
    guard.prev = &guard;
}

template <class T>
void Set<T>::insert(T value)
{
    Node *before_this = guard.next;
    Node *temp = new Node();
    while (true)
    {
        if (before_this->x == value)
        {
            return;
        }
        else if (value < before_this->x || before_this == &guard)
        {
            temp->x = value;
            temp->next = before_this;
            temp->prev = before_this->prev;
            temp->next->prev = temp;
            temp->prev->next = temp;
            return;
        }
        before_this = before_this->next;
    }
}

template <class T>
void Set<T>::remove(T value)
{
    Node *popped = guard.next;
    while (popped != &guard)
    {
        if (popped->x == value)
        {
            popped->prev->next = popped->next;
            popped->next->prev = popped->prev;
            delete popped;
            return;
        }
        else if (value < popped->x)
        {
            return;
        }
        popped = popped->next;
    }

    return;
}

template <class T>
bool Set<T>::contains(T value)
{
    Node *iterator = guard.next;
    while (true)
    {
        if (iterator->x == value)
        {
            return true;
        }
        else if (value < iterator->x || iterator == &guard)
        {
            return false;
        }
        iterator = iterator->next;
    }
    return false;
}

template <class T>
void Set<T>::Union(const Set &other)
{
    Node *original_iterator = guard.next;
    Node *other_iterator = other.guard.next;
    while (other_iterator != &other.guard)
    {
        if (original_iterator->x == other_iterator->x)
        {
            original_iterator = original_iterator->next;
            other_iterator = other_iterator->next;
        }
        else if (original_iterator == &guard || original_iterator->x > other_iterator->x)
        {
            Node *temp = new Node();
            temp->x = other_iterator->x;
            temp->next = original_iterator;
            temp->prev = original_iterator->prev;
            temp->next->prev = temp;
            temp->prev->next = temp;
            other_iterator = other_iterator->next;
        }
        else if (original_iterator->x < other_iterator->x)
        {
            original_iterator = original_iterator->next;
        }
    }
}

template <class T>
void Set<T>::intersection(const Set &other)
{
    Node *original_iterator = guard.next;
    Node *other_iterator = other.guard.next;
    Node *temp = new Node();
    while (original_iterator != &guard)
    {
        std::cout << "w petli" << std::endl;
        if (original_iterator->x == other_iterator->x)
        {
            std::cout << "takie same" << std::endl;
            original_iterator = original_iterator->next;
            other_iterator = other_iterator->next;
        }
        else if (other_iterator == &other.guard || original_iterator->x < other_iterator->x)
        {
            std::cout << "other wieksze" << std::endl;
            temp = original_iterator->next;
            original_iterator->prev->next = original_iterator->next;
            original_iterator->next->prev = original_iterator->prev;
            delete original_iterator;
            original_iterator = temp;
        }
        else if (original_iterator->x > other_iterator->x)
        {
            std::cout << "original wieksze" << std::endl;
            other_iterator = other_iterator->next;
        }
    }
}

template <class T>
void Set<T>::difference(const Set &other)
{
    Node *original_iterator = guard.next;
    Node *other_iterator = other.guard.next;
    Node *temp = new Node();
    while (original_iterator != &guard && other_iterator != &other.guard)
    {
        if (original_iterator->x == other_iterator->x)
        {
            temp = original_iterator->next;
            original_iterator->prev->next = original_iterator->next;
            original_iterator->next->prev = original_iterator->prev;
            delete original_iterator;
            original_iterator = temp;
            other_iterator = other_iterator->next;
        }
        else if (original_iterator->x > other_iterator->x)
        {
            other_iterator = other_iterator->next;
        }
        else if (original_iterator->x < other_iterator->x)
        {
            original_iterator = original_iterator->next;
        }
    }
}

template <class T>
void Set<T>::printSet()
{
    Node *iterator = guard.next;
    while (iterator != &guard)
    {
        std::cout << iterator->x << std::endl;
        iterator = iterator->next;
    }
}

#endif // SET