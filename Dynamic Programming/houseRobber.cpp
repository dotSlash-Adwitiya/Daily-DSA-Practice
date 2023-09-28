#include<bits/stdc++.h>
using namespace std;

//* Recursive Relation : 
// * Inclusion : arr[i] + idx+2. If including currEle, then we can take element beyond idx+1.
// * Exclusion : idx+1. If excluding currEle, then we can take element at idx+1.
// * And we need to findMax between these two ! max(include, exclude);

//* RECURSIVE Approach 
// * Starting from left towards right
int solve(vector<int>& house, int idx){
  if(idx >= house.size()) 
      return 0;
  

  int include = house[idx] + solve(house, idx+2);
  int exclude = solve(house, idx+1);

  return max(include, exclude);
}
int rob(vector<int>& house) {
  int ans = -1;
  return solve(house, 0);
}

// * Starting from right towards left
int solve(vector<int>& house, int idx){
    if(idx < 0) 
        return 0;
    
    int include = house[idx] + solve(house, idx-2);
    int exclude = solve(house, idx-1);

    return max(include, exclude);
}
int rob(vector<int>& house) {
    int n = house.size();
    if(n == 0)
        return house[0];
    return solve(house, n-1);
}

//* Optimisation using Memoization TC : O(N), SC : O(N)
int solve(vector<int>& house, int idx, vector<int> &dp){
  if(idx < 0) 
      return 0;
  
  //* If the answer is stored, then don't make another call
  if(dp[idx] != -1)
      return dp[idx];

  //* Either include or exclude
  int include = house[idx] + solve(house, idx-2, dp);
  int exclude = solve(house, idx-1, dp);

  // * Store the recursive relation in dp array[]
  // * Storing the max ans is imp
  dp[idx] = max(include, exclude);
  return dp[idx];
}
int rob(vector<int>& house) {
  int n = house.size();
  vector<int> dp(n+1, -1);

  if(n == 0)
      return house[0];
  return solve(house, n-1, dp);
}

