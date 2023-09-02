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
//* Only works if elements in given array are unique
int getPairsCount(int arr[], int n, int k) {
    int cnt = 0, i = 0, j = n-1;
    sort(arr, arr+n);
    
    while(i < j) {
        int sum = arr[i] + arr[j];
        if(sum == k) {
            cnt++;
            i++;
            j--;
        }
        else if(sum < k) i++;
        else j--;
    } 
    return cnt;
}


//* Best Approach --> TC : O(n), SC : O(n)
//* ---------->>>>>  Using HASH MAP <<<<<<<----------------
int getPairsCount(int arr[], int n, int k) {
    int cnt = 0;
    unordered_map<int, int> ump;
    
    for(int i = 0; i < n; i++) {
        //* Every time we find an element in array, we need to 
        //* add the count, along with the previous counts, so we basically add up all the frequencies
        if(ump[k-arr[i]] != 0) 
            cnt = cnt + ump[k-arr[i]];
        ump[arr[i]]++;
    }
    return cnt;
}



int main()
{
  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/ sizeof(arr[0]);
  
  return 0;
}