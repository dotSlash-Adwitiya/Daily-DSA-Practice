#include<bits/stdc++.h>
using namespace std;

// * T.C: O(n²)
// * S.C: O(1)
int trap(vector<int>& height) {
  int n = height.size(), ans = 0;  
  for(int i = 0; i < n; i++) {
      int left = 0, right = i+1;
      int leftMax = 0, rightMax = 0;
      while(left < i){
          leftMax = max(leftMax, height[left]);
          left++;
      }
      while(right < n){
          rightMax = max(rightMax, height[right]);
          right++;
      }
      int temp = min(leftMax, rightMax) - height[i];
      if(temp > 0)
          ans += temp;
  }
  return ans;
}

// * Better Approach using: Prefix and Suffix Sum logic
int trap(vector<int>& height) {
  int n = height.size(), ans = 0;  
  vector<int> prefixSum(n), suffixSum(n);
  int tempMax1 = 0, tempMax2 = 0;
  for(int i = 0, j = n-1; i < n; i++, j--){
      tempMax1 = max(tempMax1, height[i]);
      tempMax2 = max(tempMax2, height[j]);
      prefixSum[i] = tempMax1;
      suffixSum[j] = tempMax2;
  }

  for(int i = 0; i < n; i++) {
      int maxEle1 = prefixSum[i];
      int maxEle2 = suffixSum[i];

      int temp = min(maxEle1, maxEle2) - height[i];
      if(temp > 0)
          ans += temp;
  }
  return ans;
}

//  * STACK Approach yet to be explored
//  *Most Optimal Approach: Using 2 Pointers
