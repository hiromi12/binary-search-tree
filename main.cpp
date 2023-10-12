// Binary Search Tree
#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *p, *l, *r;  // parent, left, right pointer
  node(int d) {
    data = d;
    p = l = r = NULL;
  };
};

class BST: public node {
public:
  void Insert(int data);
  void Delete(int data);
  void inorderTraversal();
  int Height();
};

void BST::Insert(int data) {
  // first commit
}
void BST::Delete(int data) {

}
void BST::inorderTraversal() {

}
int BST::Height() {
  int height;
  return height;
}

int main() {
  return 0;
}