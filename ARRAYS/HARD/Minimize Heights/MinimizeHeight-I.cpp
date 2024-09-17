#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
  sort(arr,arr+n);
  
  int minDiff = arr[n-1]-arr[0];
  
  for(int i=1; i<n; i++) {
      int minHeight= min(arr[0] + k, arr[i] - k);
      int maxHeight= max(arr[i - 1] + k, arr[n - 1] - k);
      minDiff = min(minDiff, maxHeight - minHeight);
  }
  return minDiff;
  
}