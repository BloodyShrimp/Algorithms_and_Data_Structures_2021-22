#ifndef CURSORLIST
#define CURSORLIST
#include <iostream>
#include <stdexcept>
#define MAX 10000
#define NIL -1
class List
{
public:
    List();
    void push_front(int x);    // Dołącza element na początek listy
    int pop_front();           // Usuwa i zwraca element z początku listy
    void push_back(int x);     // Dołącza element na koniec listy
    int pop_back();            // Usuwa i zwraca element z końca listy
    int size();                // Zwraca liczb  ę elementów w liście
    bool empty();              // Zwraca true gdy lista jest pusta
    void clear();              // Czyści listę
    int find(int x);           // Zwraca pozycję pierwszego elementu o wartości x
    int erase(int i);          // Usuwa i zwraca element na pozycji i
    void insert(int i, int x); // Wstawia element x przed pozycję i
    int remove(int x);         // Usuwa wystąpienia x i zwraca ich liczbę
    int addNode();
    void deleteNode(int cursor);

private:
    struct Node
    {             // Zagnieżdżona klasa węzła
        int x;    // Element przechowywany przez węzeł listy
        int next; // Indeks kolejnego węzła
    };
    Node arr[MAX];  // Tablica węzłów
    int head = NIL; // Indeks pierwszego węzła
    int tail = NIL; // Indeks ostatniego węzła
    int lsize = 0;  // Rozmiar listy
    int spare = 0;  // Indeks pierwszego nieużytego elementu tablicy
};

int List::addNode()
{
    if (spare != NIL)
    {
        int new_index = spare;
        spare = arr[spare].next;
        if (head == NIL)
        {
            head = new_index;
            tail = new_index;
            arr[new_index].next = NIL;
        }
        lsize++;
        return new_index;
    }
    else
    {
        return NIL;
    }
}

void List::deleteNode(int cursor)
{
    arr[cursor].next = spare;
    spare = cursor;
    lsize--;
    if (lsize == 0)
    {
        head = NIL;
        tail = NIL;
    }
}

List::List()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        arr[i].next = i + 1;
    }
    arr[MAX - 1].next = NIL;
}

void List::push_front(int x)
{
    if (lsize == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    int new_index = addNode();
    arr[new_index].x = x;
    arr[new_index].next = head;
    head = new_index;
}

int List::pop_front()
{
    if (lsize == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int popped_index = head;
    int temp_int = arr[popped_index].x;
    head = arr[popped_index].next;
    deleteNode(popped_index);
    return temp_int;
}

void List::push_back(int x)
{
    if (lsize == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    int new_index = addNode();
    arr[new_index].x = x;
    arr[new_index].next = NIL;
    arr[tail].next = new_index;
    tail = new_index;
}

int List::pop_back()
{
    if (lsize == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int popped_index = tail;
    int temp_int = arr[popped_index].x;
    int list_start = head;
    for (int i = 0; i < lsize - 2; i++)
    {
        list_start = arr[list_start].next;
    }
    tail = list_start;
    arr[list_start].next = NIL;
    deleteNode(popped_index);
    return temp_int;
}

int List::size()
{
    return lsize;
}

bool List::empty()
{
    return lsize == 0;
}

void List::clear()
{
    for (int i = 0; i < MAX - 1; i++)
    {
        arr[i].next = i + 1;
    }
    arr[MAX - 1].next = NIL;
    head = NIL;
    tail = NIL;
    spare = 0;
    lsize = 0;
}

int List::find(int x)
{
    int index = head;
    for (int i = 0; i < lsize; i++)
    {
        if(arr[index].x == x)
        {
            return i;
        }
        index = arr[index].next;
    }

    return -1;
}

int List::erase(int i)
{
    if (i > lsize - 1 || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    if (lsize == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int after_this = head; // indeks elementu przed usuwanym
    int pos = i; // pozycja którą usuwamy
    int temp_int;
    if (pos == 0)
    {
        temp_int = pop_front();
        return temp_int;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        after_this = arr[after_this].next;
    }
    int to_delete = arr[after_this].next; // indeks usuwanego elementu
    temp_int = arr[to_delete].x;
    arr[after_this].next = arr[to_delete].next;
    if (arr[after_this].next == NIL)
    {
        tail = after_this;
    }
    deleteNode(to_delete);
    return temp_int;
}

void List::insert(int i, int x)
{
    if (i > lsize || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    if (lsize == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    int pos = i; // pozycja na którą wstawiamy
    if (pos == 0)
    {
        push_front(x);
        return;
    }
    int index = addNode();
    arr[index].x = x;
    int after_this = head;
    for (int j = 0; j < pos - 1; j++)
    {
        after_this = arr[after_this].next;
    }
    arr[index].next = arr[after_this].next;
    arr[after_this].next = index;
}

int List::remove(int x)
{
    int index;
    int counter = 0;
    while ((index = find(x)) != -1)
    {
        erase(index);
        counter++;
    }

    return counter;
}

#endif // CURSORLIST
