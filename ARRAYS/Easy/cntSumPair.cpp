#include<bits/stdc++.h>
using namespace std;

//* BRUTE FORCE ->> TC : O(n²), SC : O(1) Approach
int getPairsCount(int arr[], int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == k) 
                cnt++;
        }
    }
    return cnt;
}

//* Optimized ->> TC : O(nlogn), SC : O(1)
//* ------->>>>>> Using SORTING <<<<<<<-----------



//* Best Approach --> TC : O(n), SC : O(n)
//* ---------->>>>>  Using HASH MAP <<<<<<<----------------



int main()
{
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/ sizeof(arr[0]);
  
  return 0;
}