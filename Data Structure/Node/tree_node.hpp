#if !defined(TREE_NODE)
#define TREE_NODE

template <class type_g>
class tree_node
{
private:
    type_g value;
    tree_node *right;
    tree_node *left;

public:
    tree_node()
    {
        this->value = 0;
        this->right = nullptr;
    }
    tree_node(type_g value)
    {
        this->value = value;
        this->right = nullptr;
    }
    tree_node(type_g value, tree_node<type_g> *right)
    {
        this->value = value;
        this->right = right;
    }
    void setRight(tree_node<type_g> *right)
    {
        this->right = right;
    }
    void setLeft(tree_node<type_g> *left)
    {
        this->left = left;
    }
    tree_node<type_g> *getRight()
    {
        return this->right;
    }
    tree_node<type_g> *getLeft()
    {
        return this->left;
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

#endif // TREE_NODE
