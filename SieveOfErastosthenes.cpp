#include<bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int N) {
  
  vector<int> ans;
  //* MARK All index as prime 
  vector<bool> prime(N+1, true);

  //* Apply sieve
  for(int i = 2; i <= N; i++) 
    if(prime[i] == true) 
      for(int j = i*i; j <= N; j +=i) 
        if(prime[j] == true)
          prime[j] = false;

  //* Count all the values that are marked as true and push them into ans vector
  for(int i = 2; i <= N; i++) 
    if(prime[i])
      ans.push_back(i);

  return ans;
  
}

int main()
{

  return 0;
}