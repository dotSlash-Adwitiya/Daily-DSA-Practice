
// * Asked in Adobe & Amazon's OA round.

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int target, int startIdx) {

  
  
}

int coinChange(vector<int>& coins, int amount) {
  if(amount == 0)
    return 0;

  int ans = INT_MAX;

  for(int i = 0; i < coins.size(); i++) {
    
    if(amount-coins[i] >= 0) {
      int subAns = coinChange(coins, amount-coins[i]);

      if(subAns != INT_MAX && subAns + 1 < ans){
         
      }
    }
     
  }
}

