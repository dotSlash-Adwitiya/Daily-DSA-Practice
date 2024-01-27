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

bool detectLoop(Node* head)
{
  if(!head || !head->next)
      return false;

  //* Sundar and Sundari    
  Node* slow = head, *fast = head;
  
  while(fast) {
      slow = slow->next;
      fast = fast->next;
      
      if(fast)
          fast = fast->next;
      
      if(slow == fast)
          return true;
  }
  
  return false;
}