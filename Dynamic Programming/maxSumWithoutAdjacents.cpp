#include<bits/stdc++.h>
using namespace std; 

//User function template for C++
class Solution{
public:	
	
	// Only Recursive Solution!
	int calculate(int* arr, int n, int i) {
	    
	    if(i >= n)
	        return 0;
	        
	    int take = arr[i] + calculate(arr, n, i+2);
	    int notTake = calculate(arr, n, i+1);

	    return max(take, notTake);
	}
	
	int findMaxSum(int *arr, int n) {
	    int i = 0;
	    return calculate(arr, n, 0);
	}

  // Recursion + Memoization
  int calculate(int* arr, int n, int i, vector<int>& dp) {
	    
	    if(i >= n)
	        return 0;
        if(dp[i] != -1)
            return dp[i];
            
	    int take = arr[i] + calculate(arr, n, i+2, dp);
	    int notTake = calculate(arr, n, i+1, dp);

	    return dp[i] = max(take, notTake);
	}
	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    
	    int i = 0;
	    return calculate(arr, n, 0, dp);
	}
};

//  *Practice - 1
// Only Recursive Solution!
int calculate(int* arr, int n, int i) {	
	if(i >= n)
			return 0;
			
	int take = arr[i] + calculate(arr, n, i+2);
	int notTake = calculate(arr, n, i+1);

	return max(take, notTake);
}

int findMaxSum(int *arr, int n) {
	int i = 0;
	return calculate(arr, n, 0);
}

// Recursion + Memoization
int calculate(int* arr, int n, int i, vector<int>& dp) {
	
	if(i >= n)
			return 0;
		if(dp[i] != -1)
				return dp[i];
				
	//  *Add current Idx's Element and Call recursively
	int take = arr[i] + calculate(arr, n, i+2, dp);
	int notTake = calculate(arr, n, i+1, dp);

	return dp[i] = max(take, notTake);
}

int findMaxSum(int *arr, int n) {
	vector<int> dp(n+1, -1);
	
	int i = 0;
	return calculate(arr, n, 0, dp);
}