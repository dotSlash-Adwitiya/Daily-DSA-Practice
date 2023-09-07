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

int main()
{
  cout << fibonacci(7) << endl;
  return 0;
}