#include "deque.hpp"
#include <iostream>
int main()
{
    deque<int> d = deque<int>();
    for (int i = 0; i < 10; i++)
    {
        d.push_back(new node<int>(i + 1));
        d.push_front(new node<int>(i - 1));
        std::cout << d.begin()->getVal() << std::endl;
        std::cout << d.back()->getVal() << std::endl;
        std::cout << "-" << d.size() << std::endl;
    }
    std::cout << d.size() << std::endl;

    return 0;
}