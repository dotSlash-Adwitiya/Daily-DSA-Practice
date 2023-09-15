//* Q : Search an element in the given ROTATED, and SORTED Array !
//* Approach : 
//* 1. Identify the sorted Part
//* 2. Check if the element will be there in the sorted part Or NOT.

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int h, int key){
  
  while(l <= h) {
      int mid = l+(h-l)/2;
      
      if(arr[mid] == key)
          return mid;

      //* Left part is SORTED    
      if(arr[l] <= arr[mid]){
        //* the ans lies in the sorted part
          if(key >= arr[l] && key <= arr[mid])  
              h = mid - 1;
        //* the ans DOESN'T lie in the sorted part, so search in the unsorted.
          else 
              l = mid + 1;
      } 
      
      //* Right part is SORTED    
      else  {
        //* the ans lies in the sorted part
          if(key >= arr[mid] && key <= arr[h])
              l = mid + 1;
        //* the ans DOESN'T lie in the sorted part
          else 
              h = mid - 1;
      }
  }
  return -1;
}

int main()
{
  int arr[] = {6,7,8,9,1,2,3,4,5};

  cout << search(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 9) << endl;
  
  return 0;
}