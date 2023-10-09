#include<bits/stdc++.h>
using namespace std;

int findRightMost(vector<int>& nums, int target) {
    int l = 0, h = nums.size()-1;
    int ans = -1;
    while(l <= h) {
        int mid = l + (h-l) /2;

        if(nums[mid] == target) {
            ans = mid;
            h = mid - 1;
        }

        else if(nums[mid] < target) 
            l = mid + 1;
        else 
            h = mid - 1;
    }
    return ans;
}
int findLeftMost(vector<int>& nums, int target) {
    int l = 0, h = nums.size()-1;
    int ans = -1;
    while(l <= h) {
        int mid = l + (h-l) /2;

        if(nums[mid] == target) {
            ans = mid;
            l = mid + 1;
        }

        else if(nums[mid] < target) 
            l = mid + 1;
        else 
            h = mid - 1;
    }
    return ans;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = findLeftMost(nums, target);
    int idx2 = findRightMost(nums, target);
    return {idx2, idx1};
}