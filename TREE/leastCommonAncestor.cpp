
//* Step-1 Search for the node. If found, simply return it.
//* Step-2 : Check if some data was found after both recursive calls
//* Step-3 : Check if the any node returned from left or right Or its NULL ?

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
};

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root) return NULL;
    
    
    if(root->data == n1 || root->data == n2)
    return root;
    
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);
    
    //* After both recursive calls, we'll be back at root node
    //* So, check if some data was send from left and right
    //* If we received a node from both side then the current node is the ANCESTOR
    if(leftAns && rightAns) return root;

    //* If we received from right Side, then return that only.
    else if(leftAns == NULL && rightAns) return rightAns;
 
    //* If we received from left Side, then return that only.
    else return leftAns;
}

int main()
{


  return 0;
}