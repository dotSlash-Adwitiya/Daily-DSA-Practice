#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node *left;
    int data;
    Node *right;
};

bool check(Node* r1, Node* r2) {
    if(r1 == NULL && r2 == NULL) 
    return true;
    
    if(r1 == NULL && r2)
    return false;
    
    if(r2 == NULL && r1)
    return false;
  
    if(r1->data != r2->data)
    return false;
    
    bool f1 = check(r1->left, r2->left);
    bool f2 = check(r1->right, r2->right);
    
    return (f1 && f2);
}
bool isIdentical(Node *r1, Node *r2)
{
    return check(r1,r2);
}