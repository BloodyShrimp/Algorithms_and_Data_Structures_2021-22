#include "stos_szablon.hpp"
#include <iostream>
#include <string>

int main()
{
    Stack<char> s1, s2;

    s1.push('a');
    s1.push('b');
    s1.push('c');

    while (! s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }

    while (! s2.empty()) {
        std::cout << s2.top() << '\n';
        s2.pop();
    }

    Stack<std::string, 5> ss;

    ss.push("foo");
    ss.push("bar");
    ss.push("baz");

    while (! ss.empty()) {
        std::cout << ss.top() << '\n';
        ss.pop();
    }

    return 0;
}