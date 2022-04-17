#include "bst.hpp"

int main(){ 
  bst<int> binary_tree;
  cout << "binary_tree.isEmpty() : "<<(binary_tree.isEmpty()?"true":"false")<<" | expected : true"<<endl; 
  binary_tree.insert(10);
  binary_tree.insert(20);
  binary_tree.insert(5);
  binary_tree.insert(12);
  binary_tree.insert(13);
  binary_tree.insert(4);
  binary_tree.insert(1);
  binary_tree.insert(30);
  binary_tree.insert(70);
  cout << "binary_tree.isEmpty() : "<<(binary_tree.isEmpty()?"true":"false")<<" | expected : false"<<endl; 


  binary_tree.print_tree();

  cout << "binary_tree.max() : "<< binary_tree.max() <<" | expected : 70"<<endl; 
  cout << "binary_tree.min() : "<< binary_tree.min() <<" | expected : 1"<<endl; 


  binary_tree.in_order();
  binary_tree.post_order();
  binary_tree.pre_order();
  cout << "binary_tree.remove(70) :" << endl; 
  binary_tree.remove(70);
  binary_tree.print_tree();
  binary_tree.in_order();
  binary_tree.post_order();
  binary_tree.pre_order();

  cout << "binary_tree.remove(10) :" << endl; 
  binary_tree.remove(10);
  binary_tree.print_tree();
  binary_tree.in_order();
  binary_tree.post_order();
  binary_tree.pre_order();

  return 0;
}