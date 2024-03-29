#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[],int n ,int x){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(arr[mid]==x){
            ans=mid;
            high=mid-1;
        }else if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int lastOccurence(int arr[],int n ,int x){
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid =(low+high)>>1;
        if(arr[mid]==x){
            ans=mid;
            low=mid+1;
        }else if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}
int count(int arr[], int n, int x) {
    int fo=firstOccurence(arr,n,x);
    int lo=lastOccurence(arr,n,x);
    if(lo==-1 && fo==-1)return 0;
    return lo-fo+1;
}