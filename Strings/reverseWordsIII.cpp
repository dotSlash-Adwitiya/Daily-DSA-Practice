#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  
  string temp = "", ans = "";
  
  for(char ele : s) {
      if(ele == ' '){            
          reverse(temp.begin(), temp.end());
          ans += temp + ' ';
          temp = "";
      }
      else
          temp += ele;            
  }           

  reverse(temp.begin(), temp.end());
  ans += temp;
  return ans;
}