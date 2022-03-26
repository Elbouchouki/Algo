#if !defined(NODE)
#define NODE

template <class type_g>
class node
{
private:
    type_g value;
    node *next;

    node *prev; // for deque

public:
    node()
    {
        this->value = 0;
        this->next = nullptr;
    }
    node(type_g value)
    {
        this->value = value;
        this->next = nullptr;
    }
    node(type_g value, node<type_g> *next)
    {
        this->value = value;
        this->next = next;
    }
    void setNext(node<type_g> *next)
    {
        this->next = next;
    }
    void setPrev(node<type_g> *prev)
    {
        this->prev = prev;
    }
    node<type_g> *getNext()
    {
        return this->next;
    }
    node<type_g> *getPrev()
    {
        return this->prev;
    }

    void setVal(type_g value)
    {
        this->value = value;
    }

    type_g getVal()
    {
        return value;
    }
};

#endif // NODE
