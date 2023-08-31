
//*
//* In every pass, look for the smallest element's Index
//* And once that smallest ele index is found, send it to the ith index
//*

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
  for(int i = 0; i < n-1; i++) {
      int k = i;
      //* Every time look for the smallest element
      for(int j = i+1; j < n; j++) {
          if(arr[k] > arr[j]) k = j;
      }
      //* Once the smallest element is found, send it to the ith index.
      swap(arr[i], arr[k]);
  }
}

int main()
{
  int arr [] = {8,5,7,3,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Array before performing sorting : " << endl;
  
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  cout << endl;


  cout << "Array after performing sorting : " << endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  return 0;
}