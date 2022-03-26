#if !defined(STACK)
#define STACK
#if !defined(NODE)
#include "../Node/node.hpp"
#endif
#include "assert.h"

template <class type_g>
class stack
{
private:
    node<type_g> *head;
    int length;

public:
    stack()
    {
        this->head = nullptr;
        this->length = 0;
    }
    ~stack()
    {
        while (this->head)
        {
            this->pop();
        }
    }
    node<type_g> *top()
    {
        return this->head;
    }
    void push(node<type_g> *new_node)
    {
        new_node->setNext(this->head);
        this->head = new_node;
        this->length++;
    }
    void pop()
    {
        // assert(this->head);
        if (!this->head)
            return;
        node<type_g> *temp_node = this->head;
        this->head = this->head->getNext();
        delete (temp_node);
        this->length--;
    }
    int size()
    {
        return this->length;
    }
    bool isEmpty()
    {
        return (this->length == 0);
    }
};

#endif
