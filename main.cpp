// Binary Search Tree
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *parent;
  Node *left;
  Node *right;
  Node(int d) {
    data = d;
    parent = left = right = NULL;
  }
};

class BST {
private:
  Node *root;
public:
  BST() {
    root = NULL;
  }
  Node* getRoot();
  void Insert(int data);
  void InorderTraversal(Node *node);
  // void Delete(int data);   TODO: Implement delete function
  int Height(Node *node);
};

Node* BST::getRoot() {
  return root;
}

void BST::Insert(int data) {
  Node* newNode = new Node(data);

  if(root == NULL) {
    root = newNode;
    return;
  }

  Node* current = root;
  Node* parent = nullptr;

  // Traverse the tree to find the appropriate position for the new node
  while(current != nullptr) {
    parent = current;
    if(data < current->data) {
      current = current->left;
    } else {  // data > current->data
      current = current->right;
    }
  }

  // Insert the new node based on the comparison with the parent node
  newNode->parent = parent;
  if(data < parent->data) {
    parent->left = newNode;
  } else {    // data >= parent->data
    parent->right = newNode;
  }
}

void BST::InorderTraversal(Node *node) {
  if (node == NULL)
    return;
  InorderTraversal(node->left);
  cout << node->data << " ";
  InorderTraversal(node->right);
}

int BST::Height(Node *node) {
  if (node == NULL)
    return -1;
  int leftHeight = Height(node->left);
  int rightHeight = Height(node->right);
  return max(leftHeight, rightHeight) + 1;
}

int main() {
  BST tree;

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(7);
  tree.Insert(2);
  tree.Insert(4);

  int treeHeight = tree.Height(tree.getRoot());
  cout << "Height: " << treeHeight << endl;

  cout << "Inorder Traverse: ";
  tree.InorderTraversal(tree.getRoot());

  return 0;
}