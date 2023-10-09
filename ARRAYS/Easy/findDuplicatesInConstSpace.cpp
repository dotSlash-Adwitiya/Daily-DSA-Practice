#include<bits/stdc++.h>
using namespace std;

vector<int> duplicates(long long arr[], int n) {
  vector<int> result;
  
  // * Increment every index by the size of arr[], everytime you encounter it. 
  // * Doing arr[i]%n will increment an element at arr[i] by n, n times.
  for(int i=0; i<n; i++)
      arr[arr[i]%n]+=n;
  
  // * In every element, check if its frequency is >= 2. That means its a duplicate
  //* get original element by %n, and freqency by /n
  for(int i=0; i<n; i++){
      if(arr[i]/n>=2)
          result.push_back(i);
  }
  
  if(result.empty())
      result.push_back(-1);
  
  return result;
}