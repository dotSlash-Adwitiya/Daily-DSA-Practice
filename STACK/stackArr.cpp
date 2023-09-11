//* Stack implementation using array

#include<iostream>
using namespace std;

class Stack {
  public :
    int top = -1;
    int sz = 0;
    int *arr = new int[sz];

  Stack(int sz){
    this->sz = sz;
  } 

  void push(int x);
  int pop();
  bool isEmpty();
  int size();
  int peek();
};

void Stack::push(int x) {
  if(top == sz){
    cout << "Stack Overflow" << endl;
    return;
  }
  arr[++top] = x;
  sz++;
}

int Stack::pop() {
  if(top == -1) {
    cout << "Stack Underflow" << endl;
    return -1;
  }

  int x = arr[top--];
  sz--;
  return x;
}

bool Stack::isEmpty() {
  return top == -1;
}

int Stack::size() {
  return sz;
}

int Stack::peek() {
  if(top == -1) 
    return -1;
  return arr[top];
}
int main()
{
  Stack stk(10);

  stk.pop();
  stk.push(10);
  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);
  stk.push(50);

  while(!stk.isEmpty()){
    cout << stk.peek() << " ";
    stk.pop();
  }

  return 0;
}