#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
  //* Basic maths to calculate size of 1st and 2nd array
  int size1 = m - l + 1;
  int size2 = h - m;
  
  int *arr1 = new int[size1];
  int *arr2 = new int[size2];
  
  int k = l;
  //* Copy array values : 
  for(int i = 0; i < size1; i++)
      arr1[i] = arr[k++];
      

  //* k = m+1; This line is [OPTIONAL], as k is having a post inc operator in 
  //* previous line so in this step, k will be at -> [m+1 index].

  for(int i = 0; i < size2; i++)
      arr2[i] = arr[k++];
  
  //* Merge 2 sorted array
  k = l;
  int i = 0, j = 0;   
  
  while(i < size1 && j < size2) {
      if(arr1[i] <= arr2[j]) 
        arr[k++] = arr1[i++];
          
      else arr[k++] = arr2[j++];
  }
  
  //* Its possible that some values are left in either of the array, So copy them.
  while(i < size1)
      arr[k++] = arr1[i++];
      
  while(j < size2)
      arr[k++] = arr2[j++];
}

void mergeSort(int arr[], int l, int r)
{
  //* BASE Case for recursion
  if(l >= r)
      return;

  //* Calculating MID    
  int mid = l + (r-l) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid+1, r);
  merge(arr, l, mid, r);
}

int main()
{
  int arr [] = {8,5,7,3,2};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Array before performing sorting : " << endl;
  
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  cout << endl;

  mergeSort(arr, 0, n-1);

  cout << "Array after performing sorting : " << endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  
  return 0;
}