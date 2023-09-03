#include<bits/stdc++.h>
using namespace std;

//* Max HEAP Creation Function
void insert(int arr[], int idx) {
  
  int temp = arr[idx];
  int i = idx;

  //* Keep dividing / 2 till we find a smaller element on parent node
  while(i > 1 && arr[i/2] < temp) {
    arr[i] = arr[i/2];
    i /= 2;
  }
  arr[i] = temp;
}

//* Min HEAP Creation Function
void insertMini(int arr[], int idx) {
  
  int temp = arr[idx];
  int i = idx;

  //* Keep dividing / 2 till we find a smaller element on parent node
  while(i > 1 && arr[i/2] > temp) {
    arr[i] = arr[i/2];
    i /= 2;
  }
  arr[i] = temp;
}

int deletFromHeap(int A[], int n) {
  int i = 1,j = 2*i, val = A[1];
    //* Copy last element to root;
    A[1]=A[n];
  
    //* Copy root to last element
    A[n]=val;

    while(j < n) {

      //* Check which child is greater
      if(j<n-1 && A[j+1]>A[j]) j=j+1;
      
      //* Swap the greater child with the parent
      if(A[i]<A[j]) {
        swap(A[i], A[j]);
        i=j;
        j=2*j;
      }

      //* If parent is greater, then the element is in the right position
      else break;
    }

    return val; 
}

int main()
{
  //* Assuming that 1st element is already in heap.
  //* Indexing starts from 1 (Not 0)
  int arr[] = {0, 10, 20, 30, 25, 5, 40, 35};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Elements Before Max heap function : " << endl;
  for(int i = 1; i < n; i++) 
    cout << arr[i] << " ";

  cout << endl;
  //* Sending Index to the other function (not the element itself)
  for(int i = 1; i < n; i++) 
    insert(arr, i);
  
  cout << "Elements After Max heap function : " << endl;

  for(int i = 1; i < n; i++) 
    cout << arr[i] << " ";
  cout << endl;
  
  //* Calling delete function :-
  
//* HEAP SORT :-
 for(int i=7;i>1;i--)
  deletFromHeap(arr,i);
  
  for(int i = 1; i < n; i++) 
    cout << arr[i] << " ";
  cout << endl;


  return 0;
}