#include<bits/stdc++.h>
using namespace std;

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
  for(int i = 2; i < n; i++) 
    insert(arr, i);
  
  cout << "Elements After Max heap function : " << endl;

  for(int i = 1; i < n; i++) 
    cout << arr[i] << " ";

  return 0;
}