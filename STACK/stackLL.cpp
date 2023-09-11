//* STACK Implementation using Linked List
#include<iostream>
using namespace std;

//* We need to declare that there exists a "class Stack"
class Stack;

class Node {
  private :
    int data;
    Node* next;

  public : 
  Node (int data) {
    this->data = data;
    next = NULL;
  }
  //* All the private members will be accessible inside Stack class , because its a friend.
  friend Stack;
};

class Stack {
  private :
    Node* top;

  public : 
  Stack() {
    top = NULL;
  }

  void push(int x);
  int pop();
  bool isEmpty();
  int size();
  int peek();
};

void Stack::push(int x) {
  //* Check if stack (heap) is full.
  //* Then inserting an element would
  //* lead to stack overflow
  Node* newNode = new Node(x);

  if(!newNode) {
    cout << "Stack Overflow" << endl;
    return;
  }

  newNode->next = top;

  top = newNode;
}

int Stack::pop() {
  if(top == NULL){
    cout << "Stack Underflow" << endl;
    return -1;
  }
  
  int ele = top->data;
  Node* temp = top;
  top = top->next;
  delete temp;
  return ele;
}

bool Stack::isEmpty() {
  return top == NULL;
}

int Stack::size() {
  Node* temp = top;
  int cnt = 0;
  while(temp) {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}

int Stack::peek() {
  if(isEmpty())
    return -1;
  
  return top->data;
}

int main()
{
  Stack stk;

  stk.pop();
  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);
  cout << stk.size() << endl;

  //* Print Stack
  while(!stk.isEmpty()) {
    cout << stk.peek() << " ";
    stk.pop();
  }
  cout << endl;

  cout << stk.size() << endl;

  return 0;
}
