// *
// * 1. Observation is everything in this question
// * 2. Observe length and try to find out a pattern
// * 3. You have to find out the nth-row's kth-column

#include<bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
  if(n == 1)
      return 0;

  //* Shift 1 by n-2 times , so that the mid becomes 2^n
  int mid = 1 << (n-2);

  if(k <= mid)
      return kthGrammar(n-1, k);

  else  //* Else perform a NOT operation on elements of previous row
      return (kthGrammar(n-1, k-mid) ? 0 : 1);
}