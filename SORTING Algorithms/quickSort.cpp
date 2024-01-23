//* 
//* Quick Sort does sorting in O(nlogn) Time for Best and Average case
//* But in Worst case QS gives O(n²) time (if the array is already sorted ASC or DESC)
//* In every step, take a pivot find its correct postion 
//* and return correct position's index
//* 

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


//* Solved Again on - 23-Jan-2024
int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low, j = high;
  
  do{ //* Look for largest element
      while(i <= high && arr[i] <= pivot) i++;
      
      //* Look for Smallest element
      while(j >= low && arr[j] > pivot) j--;
      
      //* If the two ptrs haven't crossed each other, then they can be swapped
      if(i < j)
          swap(arr[i], arr[j]);
          
  }while(i < j);
  
  //* In the end, at jth pointer, we'll have the smallest element.
  //* Which must be swapped with the pivot (which is the 1st element)
  swap(arr[j], arr[low]);
  return j;
}

void quickSort(int arr[], int low, int high)
{
  // * Array must have at least 2 elements to apply quick sort
  if(low < high) {
    int pvtIdx = partition(arr, low, high);
    quickSort(arr, low, pvtIdx-1);  
    quickSort(arr, pvtIdx+1, high);  
  }
}