#include<bits/stdc++.h>
using namespace std;

class Node {
  private : 
    Node* left;
    int data;
    Node* right;

    //* Constructor here is also private, as only tree class can access it.
    Node(int data) {
      this->left = NULL;
      this->data = data;
      this->right = NULL;
    }

//* Declaring tree as a friend -> so that it can access the private members as well
friend class Tree;
};

class Tree {
  public : 

  //* Iterative insertion using queue data structure :-
    Node* createTree() {
      cout << "ROOT->data : ";
      int root;
      cin >> root;
      
      Node* rootNode = new Node(root);
      queue<Node*> q;
      q.push(rootNode);

      while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << "Enter Left Child for : " << temp->data << " ";
        int lchild;
        cin >> lchild;

        if(lchild != -1) {
          Node * leftChild = new Node(lchild);
          q.push(leftChild);
          temp->left = leftChild;
        }

        cout << "Enter Right Child for : " << temp->data << " ";
        int rchild;
        cin >> rchild;

        if(rchild != -1) {
          Node * rightChild = new Node(rchild);
          q.push(rightChild);
          temp->right = rightChild;
        }
      }
      return rootNode;
    }

    void inOrder(Node* root) {
      if(root == NULL) return;
      inOrder(root->left);
      cout << root->data << " ";
      inOrder(root->right);
    }

    int height(Node* root) {
      if(!root) return 0;

      int lh = height(root->left);
      int rh = height(root->right);

      return ((lh > rh) ? lh : rh) + 1;
    }

};




int main()
{

  Tree t;

  Node*root = t.createTree();
  t.inOrder(root);

  cout << "Height of tree : " << t.height(root) << endl;

  return 0;
}