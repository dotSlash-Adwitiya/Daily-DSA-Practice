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

// * O(logn) Approach
int cntBits(int n) {
  int cnt = 0;
  while(n){
    n = n >> 1;
    cnt++;
  }
  return cnt;
}
string decimalToBinLog(int n) {
  int size = cntBits(n);
  char bin[size];
  int k = size-1;

  while(n){
    int bit = n & 1;
    n = n >> 1;
    bin[k--] = (bit == 1 ? '1' : '0');
  }
  bin[size] = '\0';
  return bin;
}

int main()
{
  cout << "Binary is : " << decimalToBinLog(12) << endl;
  return 0;
}