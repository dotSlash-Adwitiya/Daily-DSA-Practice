/*
//*
//* The problem states that you should return the count of char occuring N times
//* Where N is given in the question
//* And the condition is that the same-consecutive char will be counted as 1 only
//*

*/

#include<bits/stdc++.h>
using namespace std;

int getCount (string S, int N)
{
  //* Count freq of every char
  int freq[26] = {0}, i = 0, cnt = 0;
  
  while(i < S.size()) {
      freq[S[i] - 'a']++;
      
      //* If the curr char and next char are same then inc i till we find diff chars
      if(i != S.size()) 
          while(S[i] == S[i+1]) i++;

      i++;
  }
  
  //* Traverse the freq arr and check for elements which has freq == N
  for(int j = 0; j < 26; j++)
      if(freq[j] == N)
          cnt++;
  
  return cnt;
}