#include<bits/stdc++.h>
using namespace std;

class Heap {
  public :
    int heap[100];
    int size;

    Heap() {
      size = 0;
      heap[0] = -1;
    }
    void insertInHeap(int val) {
      size = size + 1;
      int currIdx = size;

      //* Insert element in the end, initially.
      heap[currIdx] = val;

      while(currIdx > 1){

        int parentIdx = currIdx/2;

        //* Check if the value parentIdx < currIdx
        if(heap[parentIdx] < heap[currIdx]) 
          swap(heap[currIdx], heap[parentIdx]);
        
        else 
          return;
          
          //* If any errror occurs keep the below statement in above if block.
          currIdx = parentIdx;
      }

    }

    void deleteEle() {
        
        if(size == 0) {
          cout << "HEAP is Empty !" << endl;
        }

        //* Step-1 Swap/copy root node with last node.
        swap(heap[1], heap[size]);
        size--;

        //* Step-2 : Find the right position for the root node.
        int idx = 1;
        
        while(idx < size) {
          int leftIdx = 2*idx;
          int rightIdx = 2*idx+1;

          if(leftIdx < size && heap[idx] < heap[leftIdx]) {
            swap(heap[leftIdx], heap[idx]);
            idx = leftIdx;
          }

          else if(rightIdx < size && heap[idx] < heap[rightIdx]){
            swap(heap[rightIdx], heap[idx]);
            idx = rightIdx;
          }
          else return;
        }
    }

    void printHeap() {
      for(int i = 1; i <= size; i++) 
        cout << heap[i] << " ";
      cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
  int left = 2*i;
  int right = 2*i+1;
  
  int largest = i;

  if(left < n && arr[left] > arr[largest])
    largest = left;

  if(right < n && arr[right] > arr[largest])
    largest = right;

  //* Check if largest ptr is updated  
  if(largest != i) {
    swap(arr[i], arr[largest]);

    //* Send element at largest to its right index.
    heapify(arr, n, largest);
  }
}


int main()
{
  Heap h;

  h.insertInHeap(50);
  h.insertInHeap(55);
  h.insertInHeap(53);
  h.insertInHeap(52);
  h.insertInHeap(54);

  h.printHeap();
  
  h.deleteEle();
  h.printHeap();
  // h.deleteEle();

  // h.deleteEle();

  int arr[6] = {-1, 54,53,55,52,50};

  // *Because we're excluding 0th element, so reduce size by 1.
  int n = sizeof(arr)/ sizeof(arr[0])-1;

  for(int i = n/2; i > 0; i--)
    heapifyMin(arr, n, i);

  cout << "Printing the heap now : " << endl;

  for(int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}