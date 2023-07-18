#include<bits/stdc++.h>
using namespace std;

//* TC : O(N³), SC :O(N) - BRUTE FORCE 
string longestPalindrome(string s){
    int n = s.length();
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = s.substr(i, j - i + 1);
            int len = sub.length();

            //* A flag To keep track whether current substring is a palindrome or not.
            bool isPalindrome = true;
            for (int k = 0; k < len / 2; k++) {
                if (sub[k] != sub[len - k - 1]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome && len > maxLen) {
                maxLen = len;
                start = i;
            }
        }
    }
    return s.substr(start, maxLen);
}

//* A littile bit optimized : TC : O(N²), SC : O(1)
string longestPalin (string s) {
  
  int start = 0, end = 1;
  for(int i = 1; i < s.size(); i++) {
      
      //* For even length palindrome
      int low = i-1;
      int high = i;
      
      while(low >= 0 && high < s.size() && s[low] == s[high]) {
          
          //* The basic idea is to store the starting and ending indice of the string
          if(high-low+1 > end) {
              start = low;
              end = high - low + 1;
          }
          low--, high++;
      }
      
      //* For odd length palindrome
      low = i-1, high = i+1;
      
      while(low >= 0 && high < s.size() && s[low] == s[high]) {
          
          if(high-low+1 > end) {
              start = low;
              end = high - low + 1;
          }
          low--;
          high++;
      }
  
  }

  return s.substr(start, end);
}
    
int main()
{
    string s;
    cout << "Enter the string : " << endl;
    cin >> s;
    cout << "Longest Palindrome is : " << longestPalindrome(s) << endl;

    return 0;
}