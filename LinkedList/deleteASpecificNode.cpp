#include<bits/stdc++.h>
using namespace std;

class Node {
  public : 
    int data;
    Node *next;
    Node(int x) {
      data = x;
      next = NULL;
    }
};

Node* deleteNode(Node *head, int x)
{
  Node *curr = head, *prev = nullptr;
  
  if(x == 1) {
      head = head->next;
      delete curr;
      return head;
  }
  
  int cnt = 1;
  
  while(cnt++ < x && curr != NULL) {
      prev = curr;
      curr = curr->next;
  }
  
  //* If the x is greater than the size of Linked List, then we can't remove any node.
  if(curr != NULL) {
      prev->next = curr->next;
      delete curr;
  }
  
  return head;
}