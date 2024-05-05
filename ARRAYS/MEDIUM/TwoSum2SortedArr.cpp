#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& num, int target) {
  
  int left = 0, right = num.size()-1;
  int a1 = -1, a2 = -1;

  while(left <= right) {
      if(num[left] + num[right] == target){
          a1 = left + 1;
          a2 = right + 1;
          left++;
          right--;
          break;
      }

      else if(num[left] + num[right] < target) left++;
      
      else 
          right--;
  }
  return {a1,a2};
}