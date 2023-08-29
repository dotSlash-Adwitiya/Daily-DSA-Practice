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

Node *compute(Node *head)
{
    if(!head || !head->next)
        return head;
        
    stack<int> stk;
    Node* ptr = head->next;
    
    //* STACK Will initially contain the 1st node's data
    stk.push(head->data);
    
    while(ptr) {
        if(!stk.empty()){
            //* Check if the data in stack is less than the curr node's data 
            //* so pop until that's the case
            if(stk.top() < ptr->data)
                while(!stk.empty() && stk.top() < ptr->data) 
                    stk.pop();
        //* Push the node's data every time    
        stk.push(ptr->data);
        }
        else stk.push(ptr->data);
        ptr = ptr->next;
    }
    stack <int> stk2;
    
    //* Copy the data into another stack, because the ans list is in the reverse.
    while(!stk.empty()) {
        stk2.push(stk.top());
        stk.pop();
    }
    ptr = head;
    Node* prev = nullptr;
    
    while(!stk2.empty()) {
        ptr->data = stk2.top();
        stk2.pop();
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    return head;
}


int main()
{

  return 0;
}