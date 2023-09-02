//* Question asks us to return a string of 30-bits of length contaning binary represention of given integer/*

//* */

#include<bits/stdc++.h>
using namespace std;

//* METHOD-1, By dividing till we get 0 in number N.
//* TC:O(num)
string getBinaryRep(int N)
{
  int num = N;
  
  string ans = "000000000000000000000000000000";
  
  int k = 29;

  while(num) {
      int rem = num % 2;
      ans[k--] = (char) rem + '0';
      num /= 2;
  }
  
  return ans;
}

//* Method-2 BITWISE Approach :-
//* TC: O(32 (total bits in int))
//* SC : O(logn)
string getBinaryRep2(int N)
{
  int num = N;
  
  string ans = "000000000000000000000000000000";
  
  int k = 29;
  while(num) {
      //* Logic to convert int to char you can also add 48 rather than '0'
      //* Both are the same thing because 48 is the ASCII of '0'
      ans[k--] = (num & 1) + '0';

      //* SHIFT Bits by 1 in every step
      num >>= 1;
  }
  return ans;
}

int main()
{

  cout << getBinaryRep2(52) << endl;

  return 0;
}