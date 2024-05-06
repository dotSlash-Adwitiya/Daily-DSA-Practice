#include<bits/stdc++.h>
using namespace std;


struct Node {
  int data;
  Node *next;
};

// * T.C : O(N), S.C : O(N) Due to recursion stack space
Node* removeNodes(Node* head) {
  if (head == nullptr) 
      return nullptr;

  Node* node = head;
  Node* nxtGreater = removeNodes(node->next);

  node->next = nxtGreater;
  if (nxtGreater == nullptr || node->data >= nxtGreater->data) 
    return node;
  else return nxtGreater;
}

int main()
{

  return 0;
}