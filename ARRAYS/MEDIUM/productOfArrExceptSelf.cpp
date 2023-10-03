#include<bits/stdc++.h>
using namespace std;

//* Fn to calculate product of arr except
vector<long long int> productOfArrExceptSelf(vector<long long int> arr, int n) {
  vector<long long int> ans;
  for(int i = 0; i < n; i++) {
    long long int currProd = 1;
    for(int j = 0; j < n; j++) {
      if(i == j)
        continue;
      currProd *= arr[j];
    }
    ans.push_back(currProd);
  }
  return ans;
}

int main()
{ 
  cout << 0/1 << endl;

  return 0;
}