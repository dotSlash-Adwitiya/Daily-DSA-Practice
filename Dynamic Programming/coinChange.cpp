
// * Asked in Adobe & Amazon's OA round.

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int target, int startIdx) {

  if(target == 0)
    return 0;
  
  if(target < 0)
    return 0;
  
  int mini = INT_MAX;
  for(int i = startIdx; i < coins.size(); i++) {
   int ans = solve(coins, target - coins[i], startIdx+1);
  }
}

int coinChange(vector<int>& coins, int amount) {
        
}

