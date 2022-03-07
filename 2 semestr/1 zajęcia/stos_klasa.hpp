#ifndef STOS_KLASA
#define STOS_KLASA

class StackOfChars
{
    char data[16];
    int top_idx;

public:
    StackOfChars();
    ~StackOfChars();
    bool empty();
    char top();
    void push(char x);
    void pop();
};

#endif // STOS_KLASA
