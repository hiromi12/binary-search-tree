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

/**
 * @brief The InorderTraversal function performs an in-order traversal of the BST starting from a given node. In-order traversal is a depth-first traversal method where the nodes are visited in the following order: left subtree, current node, right subtree. For a BST, this traversal method results in visiting the nodes in ascending order.
 * 
 * @param node 
 */
void BST::InorderTraversal(Node *node) {
  if (node == NULL)
    return;
  InorderTraversal(node->left);
  cout << node->data << " ";
  InorderTraversal(node->right);
}

/**
 * @brief The Height function is a recursive function that calculates the height of a BST starting from a given node. The height of a node in a BST is defined as the length of the longest path from that node to a leaf node. In other words, it measures how far away the deepest leaf node is from the given node.
 * 
 * @param node 
 * @return int 
 */
int BST::Height(Node *node) {
  if (node == NULL)   // Best case
    return -1;
  /**
   * Recursive Step:
   * The function calculates the height of the left and right subtrees of the current node recursively. The height of the current node is then determined by taking the maximum of the heights of its left and right subtrees, max(leftHeight, rightHeight), and adding 1 to it. The +1 accounts for the current node itself.
   */
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