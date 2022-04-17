#include <iostream>
#include "tree_node.hpp"

using namespace std;

int main(){
  tree_node<int> * node1 = new tree_node<int>(5);
  tree_node<int> * node2 = new tree_node<int>(10 , node1 , nullptr);

  cout << "node1.getVal() :"    << (node1->getVal())                     <<" | expected : 5"<<endl;
  cout << "node1.isLeaf() :"    << (node1->isLeaf()?"true":"false")      <<" | expected : true"<<endl;
  cout << "node1.hasRight() :"  << (node1->hasRight()?"true":"false")    <<" | expected : false"<<endl;
  cout << "node1.hasLeft() :"   << (node1->hasLeft()?"true":"false")     <<" | expected : false"<<endl;

  cout << "node2.getVal() :"    << (node2->getVal())                     <<" | expected : 10"<<endl;
  cout << "node2.isLeaf() :"    << (node2->isLeaf()?"true":"false")      <<" | expected : false"<<endl;
  cout << "node2.hasRight() :"  << (node2->hasRight()?"true":"false")    <<" | expected : false"<<endl;
  cout << "node2.hasLeft() :"   << (node2->hasLeft()?"true":"false")     <<" | expected : true"<<endl;
  
  tree_node<int> * lefty = node2->getLeft();
  tree_node<int> * righty = node2->getRight();
  if(lefty){
    cout << "lefty.getVal() :"     << (lefty->getVal())                        <<" | expected : 10"<<endl;
    cout << "lefty.isLeaf() :"     << (lefty->isLeaf()?"true":"false")         <<" | expected : true"<<endl;
    cout << "lefty.hasRight() :"   << (lefty->hasRight()?"true":"false")       <<" | expected : false"<<endl;
    cout << "lefty.hasLeft() :"    << (lefty->hasLeft()?"true":"false")      <<" | expected : false"<<endl;
  }else{
    cout << "lefty == nullptre" << endl;
  }

  if(righty){
    cout << "righty.getVal() :"     << (righty->getVal())                        <<" | expected : 5"<<endl;
    cout << "righty.isLeaf() :"     << (righty->isLeaf()?"true":"false")         <<" | expected : true"<<endl;
    cout << "righty.hasRight() :"   << (righty->hasRight()?"true":"false")       <<" | expected : false"<<endl;
    cout << "righty.hasLeft() :"    << (righty->hasLeft()?"true":"false")      <<" | expected : false"<<endl;
  }else{
    cout << "righty == nullptre" << endl;
  }

  tree_node<int> * a = new tree_node<int>(5);
  tree_node<int> * b = new tree_node<int>(15);

  cout << "a > b :"    << (a > b?"true":"false")      <<" | expected : false"<<endl;
  cout << "b > a :"    << (b > a?"true":"false")      <<" | expected : true"<<endl;




  return 0;
}