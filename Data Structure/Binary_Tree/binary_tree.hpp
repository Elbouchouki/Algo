#if !defined(BINARY_TREE)
#define BINARY_TREE
#include "../Node/tree_node.hpp"

template <class type_g>
class binary_tree
{
    tree_node<type_g> * root:
    int length;
public:
    tree_node(): length(0) {
        this->root = nullptr;
    }
    int size() const{
        return this->length;
    }
};

#endif // BINARY_TREE
