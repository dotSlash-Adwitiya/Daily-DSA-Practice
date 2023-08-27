#include<bits/stdc++.h>
using namespace std;

long binarySubstring(int n, string a){
  
  int firstOneIdx = -1;
  for(int i = 0; i < n; i++) {
      if(a[i] == '1'){
          firstOneIdx = i;
          break;
      }
  }
  
  if(firstOneIdx == -1) return 0;
  
  long long cnt = 0, ans = 0;
  for(int i = firstOneIdx; i < n; i++) {
      if(a[i] == '1') {
          ans += cnt;
          cnt++;
      }
  }
  return ans;
};


int main()
{
  
  return 0;
}