#include<bits/stdc++.h>
using namespace std;

bool check(char ch1, char ch2) {
  if(ch1 == '(' && ch2 == ')')
      return true;
  if(ch1 == '{' && ch2 == '}')
      return true;
  if(ch1 == '[' && ch2 == ']')
      return true;
  return false;
}

//Function to check if brackets are balanced or not.
bool ispar(string x)
{
  int left = -1;
  int n = x.size();
  for(int i = 0; i < n; i++) {
      
      //* Increment left ptr then copy the open bracket at left idx in the given string !
      if(x[i] == '(' || x[i] == '{' || x[i] == '[' )
          x[++left] = x[i];
          
      //* Every time encountering a closing bracket, check of they match.    
      else {
          if(check(x[left], x[i]))
              left--;
          else return false;   
      }
  }
  //* If some opening brackets are still left to be processed, then its not a VALID Parenthesis
  if(left != -1)
      return false;
  return true;
}

int main()
{

  return 0;
}