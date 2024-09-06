#include<bits/stdc++.h>
using namespace std;

int minSubset(vector<int> &arr, int N) {
  long long totSum = accumulate(arr.begin(), arr.end(), 0LL);
  sort(arr.rbegin(), arr.rend());
  
  long long sum = 0;
  int count = 0;
  for(int i = 0; i < N; i++) {
      sum += arr[i];
      count++;
      if(sum > totSum - sum) break;
  }
  return count;
}