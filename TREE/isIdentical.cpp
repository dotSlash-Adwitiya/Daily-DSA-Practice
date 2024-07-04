#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isIdentical(Node *r1, Node *r2)
{
  if(r1 == NULL && r2 == NULL)
      return true;
      
  if((r1 == NULL && r2 != NULL) || (r2 == NULL && r1 != NULL))
      return false;
      
  bool dataCheck = (r1->data == r2->data);    
  bool leftAns = isIdentical(r1->left, r2->left);
  
  bool rightAns = isIdentical(r1->right, r2->right);
  
  if(dataCheck && leftAns && rightAns)
      return true;
  return false;
}

//* One line code in C++ using NESTED Ternary OPERATORS :-
bool isIdentical(Node *r1, Node *r2)
{ 
    return ((r1 == NULL && r2 == NULL) ? true :(((r1 == NULL && r2 != NULL) || (r2 == NULL && r1 != NULL)) ? false : (r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right))));
}

// * Practice
bool isIdentical(Node *r1, Node *r2)
{
    if(!r1 && !r2)
        return true;
    if((!r1 && r2) || (r1 && !r2))
        return false;
    if (r1->data != r2->data)
        return false;
        
    bool left = isIdentical(r1->left, r2->left);  
    bool right = isIdentical(r1->right, r2->right);
    
    return left and right;
}