#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node* reverseList(struct Node *head)
    {
        if(!head->next || !head)
            return head;
        
        Node* ptr = head; 
        Node *y = ptr->next;
        Node *prev = nullptr;
        
        while(ptr != nullptr ) {
            ptr->next = prev;
            prev = ptr;
            ptr = y;
            if(y == nullptr)
                break;
            y = y->next;
        }
        
        head = prev;
        return head;
    }
    

int main()
{

  return 0;
}

