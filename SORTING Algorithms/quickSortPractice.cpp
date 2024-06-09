#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
  int pivot = arr[low];
  int i = low, j = high;

  do{
    while(i < high && arr[i] <= pivot) i++;
    while(j > low && arr[j] >= pivot) j--;

    if(i < j)
      swap(arr[i], arr[j]);
  }while(i<j);
  swap(arr[j], arr[low]);
  return j;
}

void quickSort(int arr[], int low, int high){
  if(low < high){
    int pivotIdx = partition(arr, low, high);
    quickSort(arr, low, pivotIdx-1);
    quickSort(arr, pivotIdx+1, high);
  }
}

void sortArr(int arr[], int n){
  quickSort(arr, 0, n-1);
}

int main(){

  int arr[6] = {5,6,2,10,11,7};
  sortArr(arr, 6);
  cout << "Hello" << endl;
  for(int i = 0; i < 6; i++){
    cout << arr[i] << " ";
  }

  cout << endl;
}