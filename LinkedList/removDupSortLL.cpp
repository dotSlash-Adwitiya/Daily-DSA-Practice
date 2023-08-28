/*
//*
//* The problem states that you're given a sorted linked list
//* You need to remove all the duplicates present in it. 
//* And keep at most 1 occurence of every element.
*/

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

//* A basic approach would be to, insert all the elements into set
//* And then the elements would become uniqe so insert them again into the linked list.
//* TC : O(N) + O(N), SC : O(N)
Node *removeDuplicates(Node *head)
{
    set<int> st;
    
    //* Two-ptr
    Node* ptr = head, *prev = NULL;
    
    //* STORE All elements int set data structure
    while(ptr) {
        st.insert(ptr->data);
        ptr = ptr->next;
    }
    
    ptr = head;
    
    //* Traverse the set and re-insert all unique elements into the list
    for(auto it = st.begin(); it != st.end(); it++) {
        ptr->data = *it;
        prev = ptr;
        ptr = ptr->next;
    }
    
    //* Delete LL from last node 
    //* And point NULL from prev( because prev will be on the last node)
    delete ptr;
    prev->next = NULL;
    
    return head;
}


//* More Optimized approach TC: O(N), SC : O(1)
//* Two-ptr approach
Node *removeDuplicates(Node *head)
{
  if(head->next == NULL) 
      return head;
      
  Node *ptr = head, *q = head->next;
  
  while(q != NULL) {
      while(q->data == ptr->data) {
          //* Change link
          ptr->next = q->next;
          
          //* DELETE the node (to avoid memory overflow) -- This is an optional step.
          delete q;

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