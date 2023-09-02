//*
//* The following code proceeds on the assumption that, 
//* the real elements starts from 1st index not 0th.
//*

#include<bits/stdc++.h>
using namespace std;

//* For dynamic array (Vector)
void deleteFromVectorHeap(vector<int> &heap) {
  if(heap.size() == 0) return;

  int last_element = heap[heap.size()-1];
  heap.pop_back();
  heap[1] = last_element;
  
  int i = 1, j = 2*i;
  while(j < heap.size()) {
    if(heap[j] < heap[j+1]) j++;

    if(heap[i] < heap[j]) {
      swap(heap[i], heap[j]);
      i = j;
      j = 2 * j;
    }
    else break;
  }

}

//* For static array
void deleteFromHeap(int arr[], int &n) {
  arr[1] = arr[n-1];

  int i = 1, j = 2*i;

  while(j < n) {
    if(arr[j] < arr[j+1]) j++;

    if(arr[i] < arr[j]) {
     swap(arr[i], arr[j]);
     i = j;
     j = 2*j; 
    }
    else break;
  }
  n--;
}

void printHeap(int heap[], int n) {
  int i = 1, j = 2*i;
  //* Print root node
  cout << heap[1] << endl;

  //* While children are < n
  while(j < n) {
    //* If the left child exceed n, that means we don't have more children
    if(j > n) break;
    cout << heap[j] << " ";

    //* If the right child exceed n, that means we don't have more children
    if(j + 1 > n-1) break;
    cout << heap[j+1] << endl;
    
    i++;
    j = 2*i;
  }
} 

int main()
{ 
  int heap[] = {0,40, 35, 30, 15, 10, 25, 5};
  int n = sizeof(heap)/sizeof(heap[0]);

  cout << "Level Order Traversal of HEAP before deleting one element : "<< endl;
  
  printHeap(heap, n);
  deleteFromHeap(heap, n);
  
  cout << "Level Order Traversal of HEAP after deleting one element : "<< endl;
  printHeap(heap, n);

  cout << "For Dynamic Array : " << endl;
  //* For dynamic array.
  vector<int> v = {0,40, 35, 30, 15, 10, 25, 5};
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  deleteFromVectorHeap(v);
  

  int arr[v.size()];
  //* Check HEAP Underflow.
  if(v.size() != 1) {
    int k = 0;
    for(auto it : v) {
      arr[k++] = it;
    }
    printHeap(arr, v.size());
  }
  else cout << "HEAP Is Empty !" << endl;

  return 0;
}