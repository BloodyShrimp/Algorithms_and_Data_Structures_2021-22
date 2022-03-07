#ifndef STOS_SZABLON
#define STOS_SZABLON
#include <cstdlib>
template <typename T, unsigned int stack_size = 16>
class Stack
{
    T data[stack_size];
    int top_idx;
public:
    Stack();
    ~Stack();
    bool empty();
    T top();
    void push(T x);
    void pop();
};

template <typename T, unsigned int stack_size>
Stack<T, stack_size>::Stack()
{
    top_idx = -1;
}

template <typename T, unsigned int stack_size>
Stack<T, stack_size>::~Stack()
{
    // w destruktorze nic nie trzeba robić
}

template <typename T, unsigned int stack_size>
bool Stack<T, stack_size>::empty()
{
    return top_idx < 0;
}

template <typename T, unsigned int stack_size>
T Stack<T, stack_size>::top()
{
    return data[top_idx];
}

template <typename T, unsigned int stack_size>
void Stack<T, stack_size>::push(T x)
{
    if(top_idx == stack_size)
    {
        std::abort();
    }
    data[++top_idx] = x;
}

template <typename T, unsigned int stack_size>
void Stack<T, stack_size>::pop()
{
    if(empty())
    {
        std::abort();
    }
    --top_idx;
}

#endif // STOS_SZABLON
