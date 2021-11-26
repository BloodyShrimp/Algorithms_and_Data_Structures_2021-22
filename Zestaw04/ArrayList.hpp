#ifndef ARRAYLIST
#define ARRAYLIST
#include <iostream>
#include <stdexcept>
#define MAX 10000

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
private:
    int arr[MAX] = {0};
    int tail = 0; // indeks za ostatnim elementem, rozmiar listy
};

List::List()
{
}

void List::push_front(int x)
{
    if (tail == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    int pos = 0; // pozycja na którą wstawiamy
    for (int i = tail; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = x;
    tail++;
}

int List::pop_front()
{
    if (tail == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int pos = 0; // pozycja którą usuwamy
    int popped = arr[pos];
    for (int i = pos; i < tail; i++)
    {
        arr[i] = arr[i + 1];
    }

    tail--;
    return popped;
}

void List::push_back(int x)
{
    if (tail == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    arr[tail] = x;
    tail++;
}

int List::pop_back()
{
    if (tail == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int popped = arr[tail - 1];
    tail--;
    return popped;
}

int List::size()
{
    return tail;
}

bool List::empty()
{
    return tail == 0;
}

void List::clear()
{
    tail = 0;
}

int List::find(int x)
{
    for (int i = 0; i < tail; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int List::erase(int i)
{
    if (i > tail - 1 || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    if (tail == 0)
    {
        throw std::out_of_range("Popping an empty list.\n");
    }
    int pos = i; // pozycja którą usuwamy
    int popped = arr[pos];
    for (int i = pos; i < tail; i++)
    {
        arr[i] = arr[i + 1];
    }

    tail--;
    return popped;
}

void List::insert(int i, int x)
{
    if (i > tail || i < 0)
    {
        throw std::out_of_range("There is no such index.\n");
    }
    if (tail == MAX)
    {
        throw std::out_of_range("Pushing on full list.\n");
    }
    int pos = i; // pozycja na którą wstawiamy
    for (int i = tail; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = x;
    tail++;
}

int List::remove(int x)
{
    int index;
    int counter = 0;
    while ((index = find(x)) != -1)
    {
        erase(index);
        counter++;
        tail--;
    }

    return counter;
}

#endif // ARRAYLIST
