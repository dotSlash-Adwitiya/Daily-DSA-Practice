// * Problem statement : With each step you have a cost associated with it - represented by arr[i];
// * Find the min cost to reach the nth stair

//* TIP : You can do this either starting from n & reaching till 0 || You can do this starting from 0 and reaching till - N.


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int n) {
  
  //* Intuition : Either we came from 1st stair or 2nd stair
  if(n == 1)
      return cost[1];
  if(n == 0)
      return cost[0];
  
  //* Add the cost of current stair. to the returned min-ans
  return cost[n] + min(solve(cost, n-1), solve(cost, n-2));
}

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();

  return min(solve(cost, n-2), solve(cost, n-1));
}

//* Optimization through memoization !
int solve(vector<int> &cost, int n, vector<int> &dp) {
  //* Stair 2 (cause arrIdx starts from 0)
  if(n == 1)
      return cost[1];
  //* Stair 1 (cause arrIdx starts from 0)
  if(n == 0)
      return cost[0];
  
  //* If the answer is already stored, then don't make a call
  if(dp[n] != -1)
      return dp[n];

  return dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
}

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();

  //* STEP - 1
  vector<int> dp(n+1, -1);

  return min(solve(cost, n-2, dp), solve(cost, n-1, dp));
}

//* TABULATION[]
int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();

  //* STEP - 1 Create tabulation vector
  vector<int> tab(n+1, -1);

  //* STEP - 2 : Store base cases
  tab[0] = cost[0];
  tab[1] = cost[1];

  for(int i = 2; i < n; i++) 
    tab[i] = cost[i] + min(tab[i-2],tab[i-1]);

  return min(tab[n-1], tab[n-2]);
}