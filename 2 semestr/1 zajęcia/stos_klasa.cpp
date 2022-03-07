#include "stos_klasa.hpp"


StackOfChars::StackOfChars()
{
    top_idx = -1;
}

StackOfChars::~StackOfChars()
{
    // w destruktorze nic nie trzeba robić
}

bool StackOfChars::empty()
{
    return top_idx < 0;
}

char StackOfChars::top()
{
    return data[top_idx];
}

void StackOfChars::push(char x)
{
    data[++top_idx] = x;
}

void StackOfChars::pop()
{
    --top_idx;
}