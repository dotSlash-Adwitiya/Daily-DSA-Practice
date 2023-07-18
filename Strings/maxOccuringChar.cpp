#include <bits/stdc++.h>
using namespace std;

//*Naive Approach - TC: O(N), SC : O(N)
char getMaxOccuringChar(string str)
{
  int n = str.size();
  map<char, int> count;
  for(int i = 0; i < n; i++) count[str[i]]++;
  
  int maxFreq = -1;
  char maxChar;
  
  for(auto it = count.begin(); it != count.end(); it++) 
      if(it->second > maxFreq) {
          maxFreq = it->second;
          maxChar = it->first;
      }
  return maxChar;
}

//* Optimal approach - TC : O(N), SC : O(1)
char getMaxOccuringChar(string str)
{
    //*Constant Space
    int count[256]={0};
    int maxFreq = -1, n = str.size();
    char maxChar;
    
    //* Store all the frequencies in count array.
    for(int i = 0; i < n; i++) {
        char ch = str[i];
        count[ch-'a']++;
    }        
    
    for(int i = 0; i < 256; i++) {
        if(count[i] > maxFreq) {
            maxFreq = count[i];
            //* Access char by adding 97 || 'a' to the current Index and typecast to character!
            maxChar = (char)i + 97;
        }
    }
    
    return maxChar;
}


int main() {

int arr[] = {1,2,3,4,5};

vector<int> v;

cout << getMaxOccuringChar("adwitiyyyyaa") << endl;

return 0;
}