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
        //* Move the link ptr to the temp ptr, to keep track of the last node before null.
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

    //*Recursive procedure to Insert:
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

    int search(Node* root, int key) {
      if(root == NULL) return -1;

      if(root->data == key) 
        return root->data;
      
      else if(key < root->data)
        search(root->left, key);
      
      else 
        search(root->right, key);
    }

    Node* inSucc(Node* root) {
      while(root && root->right)
          root = root->right;
        return root;
    }

    Node* inPre(Node* root) {
      while(root && root->right)
        root = root->right;
      return root;
    }
    
//* YOu can either use inorder successor or inorder predecessor.
//* I've used inorder-sucessor
int findSucc(Node* root) {
   while(root && root->left)
    root = root->left;
   return root->data;    
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int key) {
    if(root == NULL) return root;
    
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    
    else {
        //* If we're at the node, that is to be deleted, then 3 cases possible : 
        
        //* CASE - 1 :  
        if(root->left == NULL) {
            //* Delete current node & return its right
            Node* r = root->right;
            delete root;
            return r;
        }
        
        //* CASE - 2 :
        else if(root->right == NULL) {
            //* Delete current node & return its left
            Node* q = root->left;
            delete root;
            return q;
        }
        
        //* CASE - 3 : if both child of the node to be deleted, EXISTS.
        else {
            //* Find inOrderSuccessor's data :
            int val = findSucc(root->right);
            root->data = val;
            
            //* Delete that inorder successor
            root->right = deleteNode(root->right, val);
        }
        
    }
    return root;
}

    void inOrder(Node* root) {
      if(root == NULL) return;
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
    }

    int height(Node* root) {
      if(!root) return 0;

      return max(height(root->left), height(root->right)) + 1;
    }
};


int main()
{
  Node* root1 = new Node(10);
  Node* root2 = new Node(5);

  BST tree;

  // //* Iterative insertion
  // tree.InsertNode(root1, 20);
  // tree.InsertNode(root1, 30);
  // tree.InsertNode(root1, 100);
  // tree.InsertNode(root1, 5);

  //* Recursive insertion
  tree.recursiveInsert(root2, 2);
  tree.recursiveInsert(root2, 8);
  tree.recursiveInsert(root2, 7);
  tree.recursiveInsert(root2, 10);
  tree.recursiveInsert(root2, 6);
  tree.recursiveInsert(root2, 9);
  tree.recursiveInsert(root2, 13);
  tree.recursiveInsert(root2, 12);
  
  tree.inOrder(root1);
  cout << endl;


  tree.inOrder(root2);

  cout << endl;
  //* Delete a node in BST : 
  tree.deleteNode(root2, 8);
  tree.inOrder(root2);

  return 0;
}