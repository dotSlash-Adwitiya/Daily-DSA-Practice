#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};


class CircularQueueLL {
  public:
    Node* front, *rear;
  
    int size;

  CircularQueueLL(){
      front = rear = NULL;
      size = 0;
  }

  void enQueue(int x){
    Node* newNode = new Node(x);
    
    //* Insert first element
    if(rear == NULL) {
        rear = newNode;
        front = rear;
        size++;
        return;
    }
    rear->next = newNode;
    rear = rear->next;
    size++;
  }

  void deQueue() {
    if(front == NULL) {
      cout << "Queue is EMPTY !" << endl;
      return;
    }
    Node* temp;
    temp = front;
    front = front->next;
    delete temp;
    size--;
  }

  void printQueue() {
    if(front == NULL){
      cout <<"Queue is empty !" << endl;
      return;
    }
    Node* temp = front;
    while(temp != NULL) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
};

int main() {
  CircularQueueLL q;

  q.enQueue(10);
  q.enQueue(10);
  cout << q.size << endl;
  q.enQueue(10);
  q.enQueue(10);
  cout << q.size << endl;
  q.deQueue();
  q.deQueue();
  q.deQueue();
  cout << q.size << endl;
  q.deQueue();
  cout << q.size << endl;
  q.printQueue();
}