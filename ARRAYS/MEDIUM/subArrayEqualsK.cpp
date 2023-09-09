#include<bits/stdc++.h>
using namespace std;


//* OPTIMISED Approach : O(NLogN)
int findSubArraySum(int arr[], int n, int k)
{
  unordered_map<int, int> prefixSum;
  int sum = 0, cnt = 0;
  for(int i = 0; i < n; i++) {
      sum += arr[i];
      if(sum == k) cnt++;
      
      if(prefixSum[sum-k] != 0) 
          cnt += prefixSum[sum-k];
      
      prefixSum[sum]++;
  }
  
  return cnt;
}

int main()
{

  return 0;
}