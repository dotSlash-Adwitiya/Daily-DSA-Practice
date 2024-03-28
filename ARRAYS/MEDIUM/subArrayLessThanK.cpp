#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int prod = 1, cnt = 0, j = 0;

    for(int i = 0; i < nums.size(); i++) {
        
        // * Add to the product in every turn
        prod = prod * nums[i];
        
        // * Check if the prod becomes greater.
        while(prod >= k && j <= i){
            prod /= nums[j];
            j++;
        }

        // * if the left ptr is moved it will provide new size of valid subarray
        cnt += (i-j+1);
    }

    return cnt;
}