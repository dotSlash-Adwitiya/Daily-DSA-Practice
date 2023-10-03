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

string reverseWordsII(string s){
  int n = s.size();
  int i = 0, j = 0, k = 0;


  while(j < n) {
    while(j < n && s[j] != ' ') j++;
    k = j - 1;

    while(k > i)
      swap(s[i++], s[k--]); 

    i = j + 1;
    j++;
  }
  return s;
}