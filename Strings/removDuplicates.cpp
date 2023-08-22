#include<iostream>
#include<unordered_map>

using namespace std;

//* Approach - TC :O(N), SC : O(N)
string removeDups(string S) 
{
  string ans = "";
  unordered_map<int, int> ump;
  
  for(int i = 0; i < S.size(); i++) {
      if(ump.find(S[i]) == ump.end())
          ans += S[i];
      ump[S[i]]++;
  }
  return ans;
}

//* Optimized approach - TC: O(N), SC : O(1)
string removeDups(string S) 
{
    char freq[26] = {0};
  
      for(auto it : S)
          freq[it - 'a']++;
      
      bool vis[26] = {0};
      
      //* For keeping track, of where we left our last duplicate char
      int k = 0;
      for(int i = 0; i < S.size(); i++) {
          //* If the char is not already visited, then only add it in the ans string
          if(vis[S[i] - 'a'] == 0) {
              S[k++] = S[i];
              vis[S[i] - 'a']++;
          }
      }
      
      return S.substr(0, k);
}