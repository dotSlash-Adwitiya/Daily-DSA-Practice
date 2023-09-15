#include<bits/stdc++.h>
using namespace std;

//* RECURSIVE
int fact(int n) {
  if(n <= 1)
    return 1;
  return n*fact(n-1);
}

//* Iterative
int factorial(int n) {
  int fact = 1;

  for(int i = 2; i <= n; i++)
    fact *= i;
  
  return fact;
}

int main()
{
  cout << fact(4) << endl;
  return 0;
}