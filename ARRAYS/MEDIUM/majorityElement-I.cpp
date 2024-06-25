#include<bits/stdc++.h>
using namespace std;

// * OPTIMISED Approach using moore's voting algorithm
// * Do not mug this up, the interviewer will provide hints, and intution then try to come up with this solution!!
// * T.C : O(n), S.C: O(1)
int majorityElement(vector<int>& nums) {
  int cnt = 0, ele = 0;

  for(int i = 0; i < nums.size(); i++) {
      if(cnt == 0) {
          cnt = 1;
          ele = nums[i];
      }
      else if(nums[i] == ele)
          cnt++;
      else 
          cnt--;
  }

  cnt = 0;
  for(int i = 0; i < nums.size(); i++)
      if(ele == nums[i])
          cnt++;
  
  if(cnt > nums.size()/2)
      return ele;
  return -1;
}