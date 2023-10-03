#include<bits/stdc++.h>
using namespace std;

double compute(double x, double num, int n) {
  if(n==1)
    return x;

  double ans = compute(x*num, num, n-1);
  return ans;
}

double myPow(double x, int n) {
    int num = x;
    return (x,num,n);
}

int main()
{
  cout << myPow(2,10);
  return 0;
}