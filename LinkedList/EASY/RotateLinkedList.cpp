#include<bits/stdc++.h>
using namespace std;

 class Node {
  public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

int countNodes(Node* head){
  int cnt = 0;
  Node* ptr = head;
  while(ptr){
      ptr = ptr->next;
      cnt++;
  }
  return cnt;
}

Node *rotate(Node *head, int k) {
  int n = countNodes(head);

  k %= n;

  int lastNode = n-k-1;
  
  Node* ptr = head;
  while(ptr && lastNode--)
      ptr = ptr->next;
  
  if(ptr->next == NULL) return head;
  
  Node* tail = ptr->next;
  
  while(tail->next)
      tail = tail->next;
  
  // * Connect with head
  tail->next = head;

  head = ptr->next;
  ptr->next = NULL;

  return head;
}