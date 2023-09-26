#include<bits/stdc++.h>
using namespace std;

// * Simplest recursive approach
int solve(int n, int i) {
    if(i == n)
        return 1;
    if(i > n)
        return 0;
    return solve(n, i+1) + solve(n, i+2);
}

//* Imagining you're at stare 0 below stair 1
int climbStairs(int n) {
    return solve(n, 0);
}


//* Imagining you're at stair n and find ways to reach 0
int climbStairs(int n) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
        
    return climbStairs(n-2) + climbStairs(n-1);
}

//* Optimisation using memoization :-
int solve(vector<int> &dp, int n) {
    if(n == 1 || n == 0) 
        return 1;
    if(n < 0)
        return 0;

    if(dp[n] != 0)
        return dp[n];

    return dp[n] = solve(dp, n-1) + solve(dp, n-2);
}

int climbStairs(int n) {
    vector<int> dp(n+1, 0);
        return solve(dp, n);
}

int solve(vector<int> &dp, int n) {
    //* More optimisation : before 4, every number can be made in its position way.
    if(n <= 3) 
      return n;

    // * If the solution for recursive call already exists, then return it. 
    // * Don't make another redundant recursive call !
    if(dp[n] != 0)
        return dp[n];

    //* Store the solution of every recursive call
    return dp[n] = solve(dp, n-1) + solve(dp, n-2);
}

int climbStairs(int n) {
    vector<int> dp(n+1, 0);
        return solve(dp, n);
}


