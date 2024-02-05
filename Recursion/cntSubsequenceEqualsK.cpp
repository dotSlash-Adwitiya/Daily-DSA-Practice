#include<bits/stdc++.h>
using namespace std;

int cntSub(int arr[], int k, int n, int idx, int sum) {
  
  // * Base Case
  if(idx == n) {
    if(sum == k) 
      return 1;
    return 0;
  }

  // * TAKE
  sum += arr[idx]; // * Include it 
  int take = cntSub(arr, k, n, idx+1, sum);

  sum -= arr[idx]; // * Exclude it.
  // * NOT TAKE
  int notTake = cntSub(arr, k, n, idx+1, sum);

  return take + notTake;
}

int countSubsequences(int arr[], int n, int k) {
  return cntSub(arr, k, n, 0, 0);
}


int main()
{
  int arr[] = {3, 2, 3, 5, 0};

  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Total Subsequence Count : " << countSubsequences(arr,n,5) << endl;

  return 0;
}