#ifndef SET
#define SET

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
    void difference(const Set &other);   // znajduje zbioru z innym zbiorem

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
    // for (int i = 0; i < list.size(); i++)
    // {
    //     if (value == list[i])
    //     {
    //         return;
    //     }
    //     else if (value > list[i])
    //     {
    //         list.insert(i, value);
    //     }
    // }

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
    // for (int i = 0; i < list.size(); i++)
    // {
    //     if (value == list[i])
    //     {
    //         list.erase(i);
    //     }
    //     else if (value > list[i])
    //     {
    //         return;
    //     }
    // }

    Node *popped = guard.next;
    while (popped != &guard)
    {
        if (popped->x == value)
        {
            popped->prev->next = popped->next;
            popped->next->prev = popped->prev;
            delete popped;
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
    // for (int i = 0; i < list.size(); i++)
    // {
    //     if (value == list[i])
    //     {
    //         return true;
    //     }
    // }

    // return false;
}

#endif // SET

// 1 2 4
