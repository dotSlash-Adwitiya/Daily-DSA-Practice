#include<bits/stdc++.h>
using namespace std;

struct Node {
  Node* left;
  int data;
  Node* right;
};

bool helper(Node* leftNode, Node* rightNode) {
  if(!leftNode && !rightNode)
      return true;
      
  if(!leftNode && rightNode)
      return false;
      
  if(leftNode && !rightNode)
      return false;
      
  bool data = ((leftNode->data != rightNode->data)? false : true);
  
  bool leftAns = helper(leftNode->left, rightNode->left);
  bool rightAns = helper(leftNode->right, rightNode->right);
  
  if(data && leftAns && rightAns)
      return true;
  return false;
}

bool isSubTree(Node* T, Node* S) 
{
  if(!T && !S)
      return true;
      
  if(!T && S || !S && T)
      return false;
      
  //* Level Order Traversal    
  queue<Node*> q;
  q.push(T);
  
  while(!q.empty()) {
      Node* node = q.front();

      // * If the data is found to be same, 
      // * then compare each node in Main-Tree & the Sub-Tree !
      if(node->data == S->data) {
          bool flag = helper(node, S);
          if(flag) 
              return true;
      }
      
      if(node->left)
          q.push(node->left);
      if(node->right)
          q.push(node->right);
          
      q.pop();
  }
  
  return false;
}