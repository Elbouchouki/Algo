#include "node.hpp"
#include <iostream>

int main()
{
    node<int> *ptr_node = new node<int>(1);
    node<int> _node = node<int>(2, ptr_node);
    std::cout << ptr_node->getVal() << std::endl;
    std::cout << _node.getVal() << std::endl;
    _node.setVal(41);
    std::cout << _node.getVal() << std::endl;
    std::cout << _node.getNext()->getVal() << std::endl;
    return 0;
}