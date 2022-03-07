#ifndef ARRAYSTACK
#define ARRAYSTACK
#include <stdexcept>
#include <iostream>
class Stack
{
public:
    Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
    ~Stack();            // Destruktor
    void push(int x);    // Wstawia element na stos
    int pop();           // Usuwa element ze stosu i zwraca jego wartość
    int size();          // Zwraca liczbę elementów na stosie
    bool empty();        // Sprawdza czy stos jest pusty
private:
    int top;      // indeks za ostatnim elementem
    int max_size; // pojemnosc stosu
    int *data;    // tablica stosu
};

Stack::Stack(int capacity)
{
    top = 0;
    max_size = capacity;
    data = new int[capacity];
}

Stack::~Stack()
{
    delete[] data;
}

void Stack::push(int x)
{
    if (top == max_size)
    {
        throw std::out_of_range("Pushing on a full stack.\n");
    }
    else
    {
        data[top++] = x;
    }
}

int Stack::pop()
{
    if (top == 0)
    {
        throw std::out_of_range("Popping an empty stack.\n");
    }
    else
    {
        return data[--top];
    }
}

int Stack::size()
{
    return top;
}

bool Stack::empty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // ARRAYSTACK
