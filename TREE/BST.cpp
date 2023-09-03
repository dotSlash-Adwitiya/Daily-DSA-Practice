#include<bits/stdc++.h>
using namespace std;

class Node {
  public : 
    Node* left;
    int data;
    Node* right;
  public : 
    Node(int data) {
      this->left = NULL;
      this->data = data;
      this->right = NULL;
    }
  
  //* Class declared as friend
  friend class BST;
};

class BST {
  public :

    //* Iterative procedure :
    void InsertNode(Node* &root, int key) {

      //* Need link to last node, if the key isn't found
      Node* link = NULL;
      Node* temp = root;
      
      while(temp) {
        link = temp;

        if(temp->data == key) return;

        else if(key < temp->data) temp = temp->left;

        else  temp = temp->right;
      }
      Node* newNode = new Node(key);

      //* <= cannot be used here because we're not allowing duplicate elements
      if(key < link->data) link->left = newNode;
      else link->right = newNode;
    }

    //*Recursive procedure :
    Node* recursiveInsert(Node* &root, int key) {
      
      //* NULL means, we need to create new node, and attach it with previous link.
      if(root == NULL) {
        Node* newNode = new Node(key);
        return newNode;
      }

      if(key < root->data)
        root->left = recursiveInsert(root->left, key);
      else  
        root->right = recursiveInsert(root->right, key);

      return root;
    }

    void inOrder(Node* root) {
      if(root == NULL) return;
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
    }
};


int main()
{
  Node* root1 = new Node(10);
  Node* root2 = new Node(10);

  BST tree;

  //* Iterative insertion
  tree.InsertNode(root1, 20);
  tree.InsertNode(root1, 30);
  tree.InsertNode(root1, 100);
  tree.InsertNode(root1, 5);

  //* Recursive insertion
  tree.recursiveInsert(root2, 20);
  tree.recursiveInsert(root2, 30);
  tree.recursiveInsert(root2, 100);
  tree.recursiveInsert(root2, 5);
  
  tree.inOrder(root1);
  cout << endl;
  tree.inOrder(root2);

  return 0;
}