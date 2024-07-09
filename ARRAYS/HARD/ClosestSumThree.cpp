#include<bits/stdc++.h>
using namespace std;

/*
  * Given an array, arr of integers, and another number target, 
  * find three integers in the array such that their sum is closest to the target. 
  * Return the sum of the three integers.
  * Note: If there are multiple solutions, return the maximum one.
  * Input: arr[] = [5, 2, 7, 5], target = 13
  * Output: 14
  * Explanation: There is one triplet with sum 12 and other with sum 14 in the array. 
  * Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. 
  * Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
*/

int threeSumClosest(vector<int> arr, int target) {
  sort(arr.begin(), arr.end());
  
  int closestSum = INT_MAX, prevDiff = INT_MAX, n = arr.size();
  for(int i = 0; i < n; i++) {
      if(i > 0 && arr[i] == arr[i-1]) continue;
      int j = i+1, k = n-1;
      while(j < k){
          int sum = arr[i] + arr[j] + arr[k];
          int currDiff = abs(sum - target);
          
            // Update closestSum if a closer sum is found or if the same difference is found but sum is larger
          if(currDiff < prevDiff || (currDiff == prevDiff && sum > closestSum)){
              prevDiff = currDiff;
              closestSum = sum;
          }
          
          if(sum < target)
              j++;
          else if(sum > target){
              k--;
          }
          else return target;
      }
  }
  return closestSum;
}