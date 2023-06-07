#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int arr[], int n) {

  //* Step-I : Find the index at which 1st 0 is present
  int left = -1;
  for(int i = 0; i < n; ++i) {
    if(arr[i] == 0){
      left = i;
      break;
    }
  }

  //* Step-II After finding, the first 0 element, initialize right ptr with 1 greater than that.
  for(int i = left+1; i < n; ++i ){
      if(arr[i] != 0){
        swap(arr[i], arr[left]);
        left++;
      }
  }


}


int main()
{

  return 0;
}