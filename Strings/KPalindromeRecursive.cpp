#include<bits/stdc++.h>
using namespace std;

bool solve(string str, int start, int end, int k) {
  // * Base case
  if(start >= end){
      if(k >= 0)
          return true;
      return false;
  }
  
  if(str[start] == str[end])
      return solve(str, start+1, end-1, k);
  else{
      bool includeStart = solve(str, start, end-1, k-1);
      bool includeEnd = solve(str, start + 1, end, k-1);
      return includeStart || includeEnd;
  } 
}

int kPalindrome(string str, int n, int k)
{
  return solve(str, 0, n-1, k);
}