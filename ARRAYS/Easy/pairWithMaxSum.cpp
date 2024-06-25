#include<bits/stdc++.h>
using namespace std;

long long pairWithMaxSum(long long arr[], long long N)
{
  long long maxSum = 0;
  for(long long i = 0; i <= N-2; i++) { // * T.C : O(N-2) - O(N) Approx
      long long sum = 0;
      for(long long j = i, k = 0; k < 2; j++, k++){ // * T.C : O(1)
          sum += arr[j];
      }
      maxSum = max(maxSum, sum);
  }
  return maxSum;
}