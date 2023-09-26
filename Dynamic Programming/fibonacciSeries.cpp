#include<bits/stdc++.h>
using namespace std;

//* TC : O(n) - because we're storing the answers, SC : O(n);
int fib(int n, vector<int> &dp) {

  if(n == 1 || n == 0)
    return n;

  if(dp[n] != -1) 
    return dp[n];
  
  dp[n] = fib(n-1, dp) + fib(n-2, dp);

  return dp[n];
}

int fibonacci(int n) {
  vector<int> dp(n+1,-1);

  return fib(n, dp);
}

//* Iterative solution : Tabulation method.

int fibonacciTab(int n) {
  vector<int> dp(n+1);
  dp[0] = 0;
  dp[1] = 1;

  for(int i = 2; i <= n; i++) 
    dp[i] = dp[i-1] + dp[i-2];

  return dp[n];
}

// * Space optimisation : Intuition - We only need previous 2 numbers, 
// * and we don't care about the rest.

int fibonacci3(int n) {
  
  if(n == 1)
    return 0;
  if(n == 2)
    return 1;
  
  int prev1 = 0;
  int prev2 = 1;
  
  int curr = 0;

  for(int i = 2; i <= n; i++) {
    curr = prev1 + prev2;
    prev1 = prev2;
    prev2 = curr;
  }
  return curr;
}

int main()
{
  cout << fibonacci3(7) << endl;
  return 0;
}