#include<bits/stdc++.h>
using namespace std;

//* Optimal Approach - TC : O(N), SC: O(26) (CONSTANT)
string UncommonChars(string A, string B)
{
    int ans[26] = {0};

    //* Create 2 maps for both strings
    int map_A[26] = {0};        
    int map_B[26] = {0};        
    
  
    for(auto it : A)
        map_A[it-'a']++;
  
    for(auto it : B)
        map_B[it-'a']++;
        
    //* Check if str-B char exists in str-A    
    for(int i = 0; i < B.size(); i++){
        //* IF char is not found in another string.
        if(map_A[B[i]-'a'] == 0 && ans[B[i] - 'a'] == 0)
            ans[B[i] - 'a']++;
        
    }
    
    //* Check if str-A char exists in str-B    
    for(int i = 0; i < A.size(); i++){
        //* IF char is not found in another string.
        if(map_B[A[i] - 'a'] == 0 && ans[A[i] - 'a'] == 0){
            ans[A[i] - 'a']++;
        }
    }
    string str = "";
    
    for(int i = 0; i < 26; i++) 
        if(ans[i] == 1)
          str += (char)(i+97);
    
    if(str.size() == 0)
        return "-1";
        
    return str;
}  

int main()
{
  cout<<UncommonChars("geeksforgeeks", "geeksquiz") << endl;
  return 0;
}
