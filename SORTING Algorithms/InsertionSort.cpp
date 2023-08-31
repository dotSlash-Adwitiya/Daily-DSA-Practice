
//*
//* The basic Idea in this is to ASSUME, that 1st element is ALREADY SORTED
//* Then we start shifting elements directly
//* And shift until we find a correct position
//*

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
  for(int i = 1; i < n; i++) {
      int j = i-1, curr_ele = arr[i];
      //* Start shifting elements to right till we find the correct position
      //* for our current ith element
      while(j >= 0 && arr[j] > curr_ele) { 
              arr[j+1] = arr[j];
              j--;
      }
      arr[j+1] = curr_ele;
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