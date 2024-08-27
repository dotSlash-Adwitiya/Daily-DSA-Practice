#include<bits/stdc++.h>
using namespace std;

class Node {
  public : 
    Node* left;
    int data;
    Node* right;

    //* Constructor here is also private, as only tree class can access it.
    Node(int data) {
      this->left = NULL;
      this->data = data;
      this->right = NULL;
    }
};


void findSum(Node* &root, int sum) {
  if(!root) return;
  
  if(!root->left and !root->right){
      root->data = root->data + sum;
      return;
  }
  
  sum += root->data;
  root->data = sum;
  findSum(root->left, sum);
  findSum(root->right, sum);
}

int findMax(Node* root){
  
  if(!root->left and !root->right)
      return root->data;
  int left = INT_MIN, right = INT_MIN;
  
  if(root->left)
      left = findMax(root->left);
  if(root->right)
      right = findMax(root->right);
  
  return max(left, right);
}

int maxPathSum(Node* root)
{
  findSum(root, 0);
  return findMax(root);
}