#include<bits/stdc++.h>
using namespace std;


int EqualString(string s, string t)
{
    if(s.size() != t.size())
        return 0;
    
    unordered_map<int, int> evenFreq;
    for(int i = 0; i < t.size(); i+=2) evenFreq[t[i]]++;

        for(int i = 0; i < s.size(); i+=2)
            evenFreq[s[i]]--;
            
        cout << "size of map " << " and " << evenFreq.size() << endl;
        if(evenFreq.size() != 0)
            return 0;

    unordered_map<int, int> oddFreq;
    for(int i = 1; i < t.size(); i+=2) oddFreq[t[i]]++;

        for(int i = 1; i < s.size(); i+=2)
            oddFreq[s[i]]--;
        
        if(oddFreq.size() != 0)
            return 0;
        
            
  return 1;
}
int main()
{
  int arr[] = {1,2,3,4,5};

  vector<int> v = {10,20,30,40,50};

  EqualString("ee", "ee");

  return 0;
}