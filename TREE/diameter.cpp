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
    int findDia(Node* root, int &maxi);
    int diameter(Node* root);
};

// * Diameter - O(N) Approach (Simple Solution)
int Tree::findDia(Node* root, int &maxi) {
  if(root == NULL) return 0;
  
  int lh = findDia(root->left, maxi);
  int rh = findDia(root->right, maxi);
  
  maxi = max(maxi, lh + rh + 1);
  return max(lh, rh) + 1;
}

// Function to return the diameter of a Binary Tree.
int Tree::diameter(Node* root) {
  int maxi = -1;
  findDia(root, maxi);
  return maxi;
}


int main()
{


  return 0;
}