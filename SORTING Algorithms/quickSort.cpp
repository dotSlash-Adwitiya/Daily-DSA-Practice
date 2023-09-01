#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
    // * Take low's index || or the element at low idx itself, in a pivot idx.
    int pivot = low;
    int i = low, j = high;
    do {
        //* Look for ele >= pivot ele
        while(i < high && arr[i] < arr[pivot]) i++;
        
        //* Look for ele < pivot ele
        while(j > low && arr[j] >= arr[pivot]) j--;
        
        //* If both the ptr's haven't crossed each other then swap
        if(i < j) swap(arr[i], arr[j]);
        
    }while(i < j);
    
    swap(arr[pivot], arr[j]);
    
    //* Return the idx of element who has found its correct position
    return j;
}

//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        int partitionIdx = partition(arr, low, high);
        
        //* Call for left side of pivot
        quickSort(arr, low, partitionIdx-1);
        
        //* Call for right side of pivot
        quickSort(arr, partitionIdx+1, high);
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