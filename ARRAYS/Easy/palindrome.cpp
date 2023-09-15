#include<bits/stdc++.h>
using namespace std;

//* For String
bool isPalindrome(string str) {
  int i = 0, j = str.size()-1;
  while(i < j) {
    if(str[i] != str[j])
      return false;
    i++;
    j--;
  }
  return true;
}

//* For int Element
bool isPalindrome(int arr[], int n) {
  int i = 0, j = n-1;
  while(i < j) {
    if(arr[i] != arr[j])
      return false;
    i++;
    j--;
  }
  return true;
}

//* With single variable : 
bool isPalindrome2(int arr[], int n) {
  int i = 0;
  while(i < n/2) {
    //* Simultaneously check with last index
    if(arr[i] != arr[n-i-1])
      return false;
    i++;
  }
  return true;
}

int main()
{

  return 0;
}