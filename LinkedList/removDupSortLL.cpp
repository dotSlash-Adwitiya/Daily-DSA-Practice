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

Node *removeDuplicates(Node *head)
{
  if(head->next == NULL) 
      return head;
      
  Node *ptr = head, *q = head->next;
  
  while(q != NULL) {
      while(q->data == ptr->data) {
          //* Change link
          ptr->next = q->next;
          
          //* Check if we've reached the last node.
          if(ptr->next == NULL) break;
          
          q = ptr->next;
      }
      
      ptr = ptr->next;
      q = q->next;
  }
  
  return head;
}

int main()
{

  return 0;
}