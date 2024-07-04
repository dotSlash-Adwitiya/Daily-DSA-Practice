#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int listLength(ListNode* &head) {
  ListNode* ptr = head;
  int cnt = 0;
  while(ptr){
      ptr = ptr->next;
      cnt++;
  }
  return cnt;
}

ListNode* rotateRight(ListNode* head, int k) {
  if(!head)
      return head;
  
  int size = listLength(head);
  k %= size;
  int diff = size - k;
  ListNode* prevPtr = NULL, *ptr = head;
  while(ptr && diff) {
      prevPtr = ptr;
      ptr = ptr->next;
      diff--;
  }  

  if(prevPtr){
      prevPtr->next = NULL;
  }

  ListNode* temp = ptr;
  while(temp && temp->next){
      temp = temp->next;
  } 
  if(temp){
      temp->next = head;
      head = ptr;
  }
  return head;
}