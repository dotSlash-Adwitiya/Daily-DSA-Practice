#include<bits/stdc++.h>
using namespace std;

string decimalToBin(int n) {
  if(n == 0)
    return "0";
  if(n == 1) 
    return "01";
  string bin = "";
  while(n){
    int rem = n % 2;
    char ch = (rem == 1 ? '1' : '0');
    bin += ch;
    n /= 2;
  }
  reverse(bin.begin(), bin.end());
  return bin;
}

int main()
{
  cout << "Binary is : " << decimalToBin(4) << endl;
  return 0;
}