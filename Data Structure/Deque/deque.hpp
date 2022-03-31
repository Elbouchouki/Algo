#if !defined(DEQUE)
#define DEQUE
#if !defined(NODE)
#include "../Node/node.hpp"
#endif
#include <assert.h>

template <class type_g>
class deque
{

private:
    node<type_g> *front;
    node<type_g> *rear;
    int length;

public:
    deque()
    {
        this->front = this->rear = nullptr;
        this->length = 0;
    }
    void push_front(node<type_g> *new_node)
    {
        if (!this->length++)
        {
            this->front = this->rear = new_node;
            return;
        }
        new_node->setNext(this->front);
        this->front = new_node;
    }
    void pop_front()
    {
        if (!this->front)
            return;
        node<type_g> *temp = this->front;
        this->front = this->front->getNext();
        delete (temp);
        this->length--;
    }
    void push_back(node<type_g> *new_node)
    {
        if (!this->length++)
        {
            this->front = this->rear = new_node;
            return;
        }
        this->rear->setNext(new_node);
        this->rear = new_node;
    }
    void pop_back()
    {
        if (!this->rear)
            return;
        node<type_g> *temp = this->rear;
        this->rear = this->front->getPrev()->setNext(nullptr);
        delete (temp);
        this->length--;
    }
    int size()
    {
        return this->length;
    }
    node<type_g> *begin()
    {
        return this->front;
    }
    node<type_g> *back()
    {
        return this->rear;
    }
};

#endif // DEQUE
