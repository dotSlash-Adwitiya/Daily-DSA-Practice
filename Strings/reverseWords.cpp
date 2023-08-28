#include<bits/stdc++.h>
using namespace std;

//* TC : O(|S|), SC : O (|S|)
string reverseWords(string S) 
{ 
  string rev = "";
  
  for(int i = S.size() - 1; i >= 0; i--) {
      
      string temp = "";
      
      //* insert all elements into a temp string till a . is encountered
      while(S[i] != '.' && i >= 0) temp += S[i--];
      
      //* Reverse the temp string because chars will be present in rev way
      reverse(temp.begin(), temp.end());
      
      //* Add the temp string to ans string
      rev = rev + temp;
      
      //* If i hasn't reached beyond the length of string then only append a .
      if(i != -1)
          rev += '.';

  }
  
  return rev;
} 

int main()
{
  string str = "Abcdefghijklmnopqrstuvwxy";
  return 0;
}