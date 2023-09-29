#include<bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &heights, vector<int> &dp)
{
    if(idx == 0)
        return 0;
    
    if(dp[idx] != -1)
        return dp[idx];

    int left = solve(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;

    //* Cannot make a call if the index is <= 1 because 1-2 = -1, 0-2 = -2. (Not a valid index)
    if(idx > 1)
        right = solve(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]);

    return dp[idx] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp);
}

//* Tabulation : TC : O(N), SC : O(N)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0; //* Base case from recursion
    
    for(int i = 1; i <= n-1; i++) {
        int left = dp[i-1] + abs(heights[i-1] -heights[i]);
        int right = INT_MAX;
        if(i > 1)
            right = dp[i-2] + abs(heights[i-2] -heights[i]);
        dp[i] = min(left, right);
    }

    return dp[n-1];

}

//* Without Space : TC : O(N), SC : O(1)
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;
    
    for(int i = 1; i <= n-1; i++) {
        int left = prev1 + abs(heights[i-1] - heights[i]);
        int right = INT_MAX;
        if(i > 1)
            right = prev2 + abs(heights[i-2] - heights[i]);
        curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

