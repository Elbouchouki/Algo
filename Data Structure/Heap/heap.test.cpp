#include "heap.hpp"
#include <iostream>

int main()
{
    max_heap<int> heap =  max_heap<int>();
    heap.insert(19);
    heap.insert(2);
    heap.insert(3);
    heap.insert(17);
    heap.insert(7);
    heap.insert(100);
    heap.insert(36);
    heap.insert(25);
    heap.insert(1);
    heap.print_tree();
    cout <<"\n";
    cout << heap.extract_max();
    cout <<"\n";
    heap.print_tree();
    cout <<"\n";
    
    return 0;
}



