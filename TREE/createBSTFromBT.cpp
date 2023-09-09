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
  friend class Tree;
};

class Tree {
  public :

  void createBST(Node* &root, priority_queue<int> &pq) {
      if(!root) return;
      
      createBST(root->right, pq);
      root->data = pq.top();
      pq.pop();
      createBST(root->left, pq);
  }

  void traverse(Node* root, priority_queue<int> &pq) {
      if(!root) return;
      
      traverse(root->left, pq);
      pq.push(root->data);
      traverse(root->right, pq);
  }

  Node *binaryTreeToBST (Node *root)
  {
      priority_queue<int> pq;
      traverse(root, pq);
      createBST(root, pq);
      return root;
  }
};


int main()
{


  return 0;
}