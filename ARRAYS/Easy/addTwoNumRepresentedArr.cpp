#include<bits/stdc++.h>
using namespace std;

string calc_Sum(int *arr,int n,int *brr,int m){
  int i = n-1, j = m-1, carry = 0;
  string num = "";
  
  while(i >= 0 && j >= 0) {
      int add = arr[i] + brr[j] + carry;
      int digit = add % 10;
      
      num += to_string(digit);
          
      carry = add /= 10;
      i--;
      j--;
  }

  while(i >= 0){
      carry = arr[i] + carry;
      int digit = carry % 10;
      carry /= 10;
      // cout << digit << endl;
      num += to_string(digit);
      // cout << num << endl;
      i--;
  }
  
  while(j >= 0){
      carry = brr[j] + carry;
      int digit = carry % 10;
      carry /= 10;
      num += to_string(digit);
      j--;
  }
  
  while(carry != 0){
      num += to_string(carry % 10);
      carry /= 10;
  }
  
  reverse(num.begin(), num.end());
  num.erase(0, num.find_first_not_of('0'));
  
  return num;
}