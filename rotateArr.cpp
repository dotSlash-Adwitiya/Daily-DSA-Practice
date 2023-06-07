#include<bits/stdc++.h>
using namespace std;


//* BRUTE Force - TC : O(n^2), SC : (1)
void rotateArr(int arr[], int d, int n){   
    for(int i = 0; i < d; ++i) {
        int temp = arr[0];
        for(int j = 0; j < n-1; ++j) 
            arr[j] = arr[j+1];
        arr[n-1] = temp;
    }
}

//* A better Approach - TC : O(n), SC : O(n)
void rotateArr(int arr[], int d, int n){   
  if(n == d)
    return;
  
  //* Reducing d to something less than n. Because after nth rotation, the array will become same as it was originally
  d %= n;

  int temp[n];

  //* Step - I : Copy d element in temp arr
  for(int i = 0; i < d; ++i)
    temp[i] = arr[i];
  
  //* Step-II : Shift all the remainig elements to 1st place
  for(int i = d; i < n; ++i)
    arr[i-d] = arr[i];

  //* Step-II : Copying elements from auxilary array to n-dth positions
  for(int i = n-d; i < n; ++i)
    arr[i] = temp[i-(n-d)];

}

//* The most Optimal approach :- 

void rotateArr(int arr[], int d, int n){
    if(n == d)
        return;
  
    d %= n;
    
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main()
{
  int a[] = {1,2,3,4,5};
  int d = 2;
  int n = 5;

  rotateArr(a,d,n);
  return 0;
}