#include<unordered_map>
#include<iostream>

using namespace std;

int main()
{
  unordered_map<char, int> ump;

  ump['a']++;
  ump['a']++;
  ump['a']++;
  ump['b']++;
  ump['c']++;
  cout << ump.size() << endl;
  
  unordered_map<char, int>::iterator it;

  for(it = ump.begin(); it != ump.end(); it++)
    cout << it->first << " " << it->second << endl;

  ump['a']--;
  ump['a']--;
  ump['a']--;
  
  for(it = ump.begin(); it != ump.end(); it++)
    cout << it->first << " " << it->second << endl;
  cout << ump.size() << endl;
  return 0;
}