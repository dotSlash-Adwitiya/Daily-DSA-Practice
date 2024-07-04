#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x){
      data = x;
      left = right = NULL;
  }
};

void mirror(Node* node) {
    if(!node)
    return;
    mirror(node->left);
    mirror(node->right);
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}