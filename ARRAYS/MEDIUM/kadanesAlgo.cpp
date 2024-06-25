#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE Approach:
// * T.C : O (n³)
int maxSubArray(vector<int>& nums) {
  int currSum = 0, maxSum = INT_MIN;

  for(int i = 0; i < nums.size(); i++) { 
      for(int j = i; j < nums.size(); j++) {
  
          // * Calculate sum from i to j (i----j)
          int sum = 0;
          for(int k = i; k <= j; k++) {
              sum += nums[k];
          }
          // * Store the maxSum
          maxSum = max(sum, maxSum);
      }
  }
  return maxSum;
}


//* BETTER Approach, Calculating all the subarrays.
//* TC :O(N²), SC : O(1)
long long maxSubarraySum(int arr[], int n){
  long long maxSum = INT_MIN;
  for(int i = 0; i < n ; i++) {
      long long sum = 0;
      for(int j = i; j < n; j++) {
          sum += arr[j];
          maxSum = max(maxSum, sum);
      }
  } 
  return maxSum;
}

//* Optimised : Kadane's Algo - TC : O(N), SC : O(1)
long long maxSubarraySum(int arr[], int n){
  
  long long sum = 0, maxSum = INT_MIN;
  for(int i = 0; i < n; i++) {
      sum += arr[i];
      
      maxSum = max(maxSum, sum);
      
      if(sum <= 0)
          sum = 0;
      
  }
  return maxSum;
}

int main()
{

  return 0;
}