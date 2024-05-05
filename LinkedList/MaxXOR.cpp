#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

int maximumDoubletXOR(struct Node* head) {
  if(!head) return 0;
  
  unordered_map<int, int> ump;
  
  Node* temp = head;
  int cnt = 0;
  while(temp) {
      ump[cnt] = temp->data;
      temp = temp->next;
      cnt++;
  }
  int sz = cnt;
  cnt = 0;
  int maxXOR = -1;
  temp = head;
  while(temp){
      if(sz - 1 - cnt <= sz){
          int currXor = temp->data ^ ump[sz - 1 - cnt];
          maxXOR = max(currXor, maxXOR);
      }
      
      temp = temp->next;
      cnt++;
  }
  return maxXOR;
}