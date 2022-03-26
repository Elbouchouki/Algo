#include "stack.hpp"
#include <iostream>

int main()
{
    stack<int> *s = new stack<int>();
    s->push(new node<int>(1));
    s->push(new node<int>(2));
    s->push(new node<int>(3));
    s->push(new node<int>(4));

    while (s->top())
    {
        node<int> *node = s->top();
        std::cout << s->size() << std::endl;
        std::cout << node->getVal() << " ";
        s->pop();
    }
    std::cout << s->size() << std::endl;

    std::cout << std::endl;
    return 0;
}