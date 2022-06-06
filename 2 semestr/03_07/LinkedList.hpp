#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <stdexcept>

template <class T>
class List
{
public:
    List();
    void push_front(T x);        // Dołącza element na początek listy
    T pop_front();               // Usuwa i zwraca element z początku listy
    void push_back(T x);         // Dołącza element na koniec listy
    T pop_back();                // Usuwa i zwraca element z końca listy
    int size();                  // Zwraca liczbę elementów w liście
    bool empty();                // Zwraca true gdy lista jest pusta
    void clear();                // Czyści listę
    int find(T x);               // Zwraca pozycję pierwszego elementu o wartości x
    T erase(int i);              // Usuwa i zwraca element na pozycji i
    void insert(int i, T x);     // Wstawia element x przed pozycję i
    int remove(T x);             // Usuwa wystąpienia x i zwraca ich liczbę
    T &operator[](const int &i); // operator [] zwraca referencję do wartości na pozycji i
    bool is_present(T x);


    struct Node
    {                         // Zagnieżdżona klasa węzła
        T x;                  // Element przechowywany przez węzeł listy, guard = size
        Node *prev = nullptr; // Wskaźnik do poprzedniego węzła, guard = tail
        Node *next = nullptr; // Wskaźnik do kolejnego węzła, guard = head
    };

    int Lsize = 0;
    Node guard; // x = size, prev = tail, next = head
};

template <class T>
List<T>::List()
{
    guard.next = &guard;
    guard.prev = &guard;
    Lsize = 0;
}

template <class T>
void List<T>::push_front(T x)
{
    Node *temp = new Node();
    Node *before_this = guard.next;
    temp->x = x;
    temp->next = before_this;
    temp->prev = before_this->prev;
    temp->next->prev = temp;
    temp->prev->next = temp;
    Lsize++;
}

template <class T>
T List<T>::pop_front()
{
    Node *popped = guard.next;
    if (popped == &guard)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    T temp_T = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    Lsize--;
    return temp_T;
}

template <class T>
void List<T>::push_back(T x)
{
    Node *temp = new Node();
    Node *before_this = &guard;
    temp->x = x;
    temp->next = before_this;
    temp->prev = before_this->prev;
    temp->next->prev = temp;
    temp->prev->next = temp;
    Lsize++;
}

template <class T>
T List<T>::pop_back()
{
    Node *popped = guard.prev;
    if (popped == &guard)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    T temp_T = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    Lsize--;
    return temp_T;
}

template <class T>
int List<T>::size()
{
    return Lsize;
}

template <class T>
bool List<T>::empty()
{
    return Lsize == 0;
}

template <class T>
void List<T>::clear()
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
    Lsize = 0;
}

template <class T>
int List<T>::find(T x)
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

template <class T>
T List<T>::erase(int i)
{
    if (i > Lsize - 1 || i < 0)
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
    T temp_T = popped->x;
    popped->prev->next = popped->next;
    popped->next->prev = popped->prev;
    delete popped;
    Lsize--;
    return temp_T;
}

template <class T>
void List<T>::insert(int i, T x)
{
    if (i > Lsize - 1 || i < 0)
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
    Lsize++;
}

template <class T>
int List<T>::remove(T x)
{
    int index;
    int counter = 0;
    while ((index = find(x)) != -1)
    {
        erase(index);
        counter++;
        Lsize--;
    }

    return counter;
}

template <class T>
T &List<T>::operator[](const int &i)
{
    if (i > Lsize - 1 || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    Node *ref = guard.next;
    for (int j = 0; j < i; j++)
    {
        ref = ref->next;
    }
    return ref->x;
}

template <class T>
bool List<T>::is_present(T x)
{
    if (find(x) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif // LINKEDLIST
