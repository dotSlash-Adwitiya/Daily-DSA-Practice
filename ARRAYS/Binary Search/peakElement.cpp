#include<bits/stdc++.h>
using namespace std;

//* O(N) solution
int findPeakElement1(vector<int>& nums) {

  for(int i = 0; i < nums.size(); i++) {
      if((i == 0 || nums[i-1] < nums[i]) && (i == nums.size()-1 || nums[i] > nums[i+1]))
      return i;
  }

  return -1;
}

// * TC : O(Logn), SC : O(1)
int findPeakElement(vector<int>& nums) {
  int n = nums.size();
  //* If there's single element then it itself is a peak
  if(n == 1)
      return 0;
  if(nums[0] > nums[1])
      return 0;
  if(nums[n-1] > nums[n-2])
      return n-1;
  
  //* Trim down your search space
  int low = 1, high = n-2;

  while(low <= high) {
      int mid = low + (high-low)/2;
      //* check for Peak 
      if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
          return mid;
      //* If we're on increasing curve then its in the right
      else if(nums[mid] > nums[mid-1])
          low = mid + 1;

      //* If we're on decreasing curve then its in the left
      else 
          high = mid - 1;
  }  
  return -1;
}

int main()
{
  vector<int> arr = {1,2,3,1};
  cout << findPeakElement(arr) << endl;
  return 0;
}