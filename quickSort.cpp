#include<bits/stdc++.h>
using namespace std;



void quickSort(int arr[], int low, int high)
{
    if(low < high) {
        int partitionIdx = partition(arr, low, high);
        quickSort(arr, low, partitionIdx-1);
        quickSort(arr, partitionIdx+1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[low], i = low, j = high;
    
    while(i < j) {
        while(arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j++;
        
        if(i < j) 
            swap(arr[j], arr[low]);
    }
}