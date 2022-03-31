#if !defined(QUEUE)
#define QUEUE
#if !defined(NODE)
#include "../Node/node.hpp"
#endif
#include <assert.h>

template <class type_g>
class queue
{

private:
    node<type_g> *head;
    node<type_g> *tail;
    int length;

public:
    queue()
    {
        this->head = this->tail = nullptr;
        this->length = 0;
    }
    void enqueue(node<type_g> *new_node)
    {
        if (!this->head)
        {
            this->head = this->tail = new_node;
            this->length++;
            return;
        }

        this->tail->setNext(new_node);
        this->tail = this->tail->getNext();
    }
    void dequeue()
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
        return this->length == 0;
    }
    node<type_g> *front()
    {
        if (this->head)
            return this->head;
        return nullptr;
    }
    node<type_g> *last()
    {
        if (this->tail)
            return this->tail;
        return nullptr;
    }
};

#endif // QUEUE
