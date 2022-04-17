#if !defined(BST)
#define BST

#include "../../Node/tree_node.hpp"
#include <iostream>

using namespace std;

template<class type_g>
class bst{

  tree_node<type_g> * root;
  tree_node<type_g> * _insert(type_g,tree_node<type_g> *);
  tree_node<type_g> * _remove(type_g,tree_node<type_g> *);

  // extract min & max
  type_g _extract_max(tree_node<type_g> *);
  type_g _extract_min(tree_node<type_g> *);

  // traversal
  void _in_order(tree_node<type_g> *);
  void _pre_order(tree_node<type_g> *);
  void _post_order(tree_node<type_g> *);

  // print tree
  void _print_tree(const string& prefix, tree_node<type_g>* node, bool isLeft);
public:
  bst();
  void insert(type_g);
  void remove(type_g);
  bool isEmpty() const;

  // traversal
  void in_order();
  void pre_order();
  void post_order();

  // extract min & max
  type_g max();
  type_g min();

  // print tree
  void print_tree();


};


// constructeur
template<class type_g>
bst<type_g>::bst(){
  this->root = nullptr;
}
// isEmpty
template<class type_g>
bool bst<type_g>::isEmpty() const{
  return this->root == nullptr;
}

// insertion
template<class type_g>
void bst<type_g>::insert(type_g value){
  this->root = this->_insert(value,this->root);
}

template<class type_g>
tree_node<type_g> * bst<type_g>::_insert(type_g value,tree_node<type_g> *root){
  if(root == nullptr) {
    return new tree_node<type_g>(value); 
  }
  if(value<root->getVal()){
    root->setLeft(this->_insert(value,root->getLeft()));
  }
  else{
    root->setRight(this->_insert(value,root->getRight()));
  }
  return root;
}


// extract min & max
// max
template<class type_g>
type_g bst<type_g>::max(){
  return this->_extract_max(this->root);
}

template<class type_g>
type_g bst<type_g>::_extract_max(tree_node<type_g> *root){
  if(root== nullptr) return -1;

  tree_node<type_g> *tmp = root;
  while(tmp->hasRight()) tmp=tmp->getRight();
  return tmp->getVal();
}
// min
template<class type_g>
type_g bst<type_g>::min(){
  return this->_extract_min(this->root);
}

template<class type_g>
type_g bst<type_g>::_extract_min(tree_node<type_g> *root){
  if(root== nullptr) return -1;
  
  tree_node<type_g> *tmp = root;
  while(tmp->hasLeft()) tmp=tmp->getLeft();
  return tmp->getVal();
}


// deletion
template<class type_g>
void bst<type_g>::remove(type_g value){
  this->root = this->_remove(value,this->root);
}
template<class type_g>
tree_node<type_g> * bst<type_g>::_remove(type_g value,tree_node<type_g> *root){
  if(root == nullptr) return root;

  if(value == root->getVal()){
    if(root->isLeaf()) return nullptr;
    if(!root->hasLeft()){
      tree_node<type_g> * righty = root->getRight();
      delete(root);
      return righty;
    }
    if(!root->hasRight()){
      tree_node<type_g> * lefty = root->getLeft();
      delete(root);
      return lefty;
    }
    type_g _min = this->_extract_min(root->getRight());
    root->setVal(_min);
    _remove(_min,root->getRight());
  }

  if(value > root->getVal()){
    root->setRight(_remove(value,root->getRight()));
  }
  
  if(value < root->getVal()){
    root->setLeft(_remove(value,root->getLeft()));
  }
  
  return root;
}


// traversals

// inorder

template<class type_g>
void bst<type_g>::in_order(){
  this->_in_order(this->root);
  cout << endl;
}

template<class type_g>
void bst<type_g>::_in_order(tree_node<type_g> * root){
  if(root == nullptr) return;
  _in_order(root->getLeft());
  cout << root->getVal() <<" ";
  _in_order(root->getRight());
}

// preorder

template<class type_g>
void bst<type_g>::pre_order(){
  this->_pre_order(this->root);
  cout << endl;
}

template<class type_g>
void bst<type_g>::_pre_order(tree_node<type_g> * root){
  if(root == nullptr) return;
  cout << root->getVal() <<" ";
  _pre_order(root->getLeft());
  _pre_order(root->getRight());
}

// postorder
template<class type_g>
void bst<type_g>::post_order(){
  this->_post_order(this->root);
  cout << endl;
}

template<class type_g>
void bst<type_g>::_post_order(tree_node<type_g> * root){
  if(root == nullptr) return;
  _post_order(root->getLeft());
  _post_order(root->getRight());
  cout << root->getVal() <<" ";
}


// print tree
template<class type_g>
void bst<type_g>::_print_tree(const string& prefix, tree_node<type_g>* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << node->getVal() << std::endl;
        // enter the next tree level - left and right branch
        _print_tree(prefix + (isLeft ? "|   " : "    "), node->getRight(), true);
        _print_tree(prefix + (isLeft ? "|   " : "    "), node->getLeft(), false);
    }
}

template<class type_g>
void bst<type_g>::print_tree()
{
    _print_tree("", this->root, false);
}


#endif // BST
