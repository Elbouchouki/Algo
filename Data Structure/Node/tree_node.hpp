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
        this->left = nullptr;
    }
    tree_node(type_g value)
    {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
    tree_node(type_g value, tree_node<type_g> *left, tree_node<type_g> *right)
    {
        this->value = value;
        this->right = right;
        this->left = left;
    }
    void setRight(tree_node<type_g> *right)
    {
        this->right = right;
    }
    void setLeft(tree_node<type_g> *left)
    {
        this->left = left;
    }
    tree_node<type_g> *getRight() const
    {
        return this->right;
    }
    tree_node<type_g> *getLeft() const
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
    bool hasRight() const{
        return this->right != nullptr;
    }
    bool hasLeft() const{
        return this->left != nullptr;
    }
    bool isLeaf() const{
        return (this->right == nullptr) && (this->left == nullptr);
    }
    bool operator<(tree_node<type_g> & node){
        return this->value < node.value;
    }
};

#endif // TREE_NODE
