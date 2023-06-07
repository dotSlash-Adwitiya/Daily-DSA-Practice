#include<bits/stdc++.h>
using namespace std;


//* Optimised Approach - TC : O(n), SC : O(n)
int doUnion(int arr[], int n, int brr[], int m)  {
        
    unordered_set<int> union_set;
    
    int i = 0;
    while(i < n) union_set.insert(arr[i++]);
    
    i = 0;
    while(i < m) union_set.insert(brr[i++]);
    
    return union_set.size();
}


//* BRUTE FORCE Approach - TC : O(nlogn), SC : O(1)
int DoUnionOptimized(int arr[], int n, int brr[], int m) {

  vector<int> temp(arr,arr+n);

  for(int i = 0; i < n; ++i) {
    int currEle = arr[i];
    bool flag = true;
    for(int j = 0; j < m; ++j) {
      if(arr[i] == brr[i])
        flag = false;
    }
  }

}


int main()
{

  return 0;
}