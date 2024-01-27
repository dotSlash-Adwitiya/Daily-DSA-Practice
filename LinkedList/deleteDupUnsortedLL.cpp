#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


//* Approach-1 using HASHMAP
Node * removeDuplicates( Node *head) 
{
  if(!head || !head->next) 
      return head;
      
  unordered_map<int, int> ump;
  Node* curr = head, *prev = NULL;
  
  while(curr) {
      // * If duplicate, then till duplicate chain is there, skip it.
      if(ump.find(curr->data) != ump.end()) {
          while(curr != NULL && ump.find(curr->data) != ump.end())
              curr = curr->next;
          prev->next = curr;
      }    
      
      //* if NOT Duplicate, then insert in HASHMAP and move
      else {
          ump[curr->data]++;
          prev = curr;
          curr = curr->next;
      }
  }
  return head;
}