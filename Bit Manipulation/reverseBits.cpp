#include<bits/stdc++.h>
using namespace std;

unsigned int reverseBits(unsigned int num)
{
  unsigned int ans = 0;
  while(num){
      //* Store the LSB
      int temp_bit = num & 1;
      
      //* Shift the ans number by 1 bit, to insert new bit LSB position
      ans = ans << 1;

      //* ORing will result in inserting the LSB in the ans number
      ans = ans | temp_bit;

      //* Shift the original number by 1 bit
      num = num >> 1;
  }
  
  return ans;
}

int main()
{
  cout << reverseBits(11) << endl;
  return 0;
}