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

void deleteNode(Node *del)
{
    //* Assign a temporary ptr on the current node 
    Node* temp = del;
    
    //* Move the temporary pointer to next node (because its guranteed that its not the tail node)
    temp = temp->next;
    
    //* Now Copy the data of next node (just after the node which is to be deleted)
    del->data = temp->data;
    
    //* Change links
    del->next = temp->next;
    
    //* Delete the next node
    delete temp;
}


int main()
{

  return 0;
}