#include<bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &heights, vector<int> &dp, int k)
{
    if(idx == 0 || k <= 0)
        return 0;
    
    if(dp[idx] != -1)
        return dp[idx];

    for(int i = 0; i < k; i++) {
      solve(i+1, heights, dp, k-1);
    }

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp, k);
}
