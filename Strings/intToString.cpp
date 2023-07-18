#include <bits/stdc++.h>
using namespace std;


string ToString(int n) {

  string str = "";

  while(n != 0){
    int digit = n % 10;
    
    str = str + (char)('0' + digit);
    n /= 10;
  }
  
  reverse(str.begin(), str.end());
  return str;

}


int main() {

  int arr[] = {1,2,3,4,5};

  vector<int> v;
  cout << ToString(323482) << endl;
  return 0;
}