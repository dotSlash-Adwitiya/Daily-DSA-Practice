#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
}; 

//* Brute Force Appraoch using 1 extra array/ vector

//* Efficient approach : using 2 pointers.
int getMiddle(Node *head)
{
    if(!head)
        return 0;
        
    Node *slowPtr = head;
    Node *fastPtr = head;
    
    while(fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    
    return slowPtr->data;
}

int main()
{

  return 0;
}