#if !defined(NODE)
#define NODE

template <class type_g>
class node
{
private:
    type_g value;
    node *next;

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

    node<type_g> *getNext()
    {
        return this->next;
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
