
#include<bits/stdc++.h>
using namespace std;


// * Optimised approach using Two Pts (Left and Right). T.C : O(N), S.C : O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
  
  long long left = 0, right = 0, len = 0;
  long long currSum = 0;

  while(left < a.size() && right < a.size()) {
      currSum += a[right];  // * Include currVal in currSum

      while(left < right && currSum > k){
          currSum -= a[left]; // * Decrement the value at left pointer
          left++; // * Increment left ptr 
      }

      // * We need to check this only after moving forward
      if(currSum == k) len = max(len, right - left + 1);
      
      right++;
  }
  return len;
}