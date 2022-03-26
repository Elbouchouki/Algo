#include "queue.hpp"
#include <iostream>
int main()
{
    queue<int> *q = new queue<int>();
    std::cout << q->isEmpty() << std::endl;

    for (int i = 1; i <= 10; i++)
    {
        q->enqueue(new node<int>(i));
    }
    std::cout << q->front()->getVal() << std::endl;
    std::cout << q->isEmpty() << std::endl;
    std::cout << q->last()->getVal() << std::endl;
    while (!q->isEmpty())
    {
        std::cout << q->front()->getVal() << std::endl;
        q->dequeue();
    }
    return 0;
}