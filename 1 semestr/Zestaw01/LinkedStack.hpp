#ifndef LINKEDSTACK
#define LINKEDSTACK
#include <stdexcept>
#include <iostream>

class Stack
{
public:
    Stack(int capacity); // Konstruktor. Argumentem jest rozmiar stosu.
    Stack();
    ~Stack();         // Destruktor
    void push(int x); // Wstawia element na stos
    int pop();        // Usuwa element ze stosu i zwraca jego wartość
    int size();       // Zwraca liczbę elementów na stosie
    bool empty();     // Sprawdza czy stos jest pusty
    int top();

private:
    struct Node
    {
        int value;
        Node *previous;
    };
    Node *top_node;        // obiekt wskazujący na ostatni element
    int current_size; // aktualna ilosc elementow na stosie
    int max_size;     // maksymalna pojemnosc stosu
};

Stack::Stack(int capacity)
{
    top_node = NULL;
    max_size = capacity;
    current_size = 0;
}

Stack::Stack()
{
    top_node = NULL;
    current_size = 0;
    max_size = -1;
}

Stack::~Stack()
{
    while (top_node != NULL)
    {
        Node *temp = top_node;
        top_node = top_node->previous;
        temp->previous = NULL;
        free(temp);
    }
}

void Stack::push(int x)
{
    if (current_size == max_size)
    {
        throw std::out_of_range("Pushing on a full stack.\n");
    }
    else
    {
        Node *temp = new Node();
        temp->value = x;
        temp->previous = top_node;
        top_node = temp;
        current_size++;
    }
}

int Stack::pop()
{
    if (top_node == NULL)
    {
        throw std::out_of_range("Popping an empty stack.\n");
    }
    else
    {
        Node *temp = top_node;
        top_node = top_node->previous;
        int return_value = temp->value;
        temp->previous = NULL;
        free(temp);
        current_size--;
        return return_value;
    }
}

int Stack::size()
{
    return current_size;
}

bool Stack::empty()
{
    return top_node == NULL;
}

int Stack::top()
{
    if (top_node == NULL)
    {
        throw std::out_of_range("Popping an empty stack.\n");
    }
    else
    {
        Node *temp = top_node;
        int return_value = temp->value;
        return return_value;
    }
}

#endif // LINKEDSTACK
