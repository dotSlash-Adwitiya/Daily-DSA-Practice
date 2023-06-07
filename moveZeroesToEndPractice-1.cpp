#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int arr[], int n) {

  int left = 0;

  while(left < n && arr[left != 0]) {
    left++;
  }

  for(int right = left+1; right < n; right++) {
    if(arr[right] != 0){
      swap(arr[left], arr[right]);
      left++;     
    }
  }

}


int main()
{ 
  int arr[] = {12, 0,-1,0,5};

  moveZeroes(arr, 5);
  
  for(int i = 0; i < 5; ++i)
    cout << arr[i] << " ";

  return 0;
}