//* STEP-1 : Sort both the given arr[]=
//* STEP-2 : Initialize the ans arr[] w/ -1
//* STEP-3 : Insert the smaller element, and before inserting,
//* Check if the last_inserted element was not same as the curr_ele !
//* STEP-4 : Its possible that either of the array, has some remaining elements in it.

#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
  
  //* STEP-1 : Sort both the given arr[]=
  sort(a, a+n);
  sort(b, b+m);
  
  int k = 0;
  int ans[n+m];
  
  //* STEP-2 : Initialize the ans arr[] w/ -1
  memset(ans,-1, n+m);
  
  int i = 0, j = 0;
  if(a[0] <= b[0])
      ans[k++] = a[i++];
  else             
      ans[k++] = b[j++];
  
  //* STEP-3 : Insert the smaller element, and before inserting,
  //* Check if the last_inserted element was not same as the curr_ele !
  while(i < n && j < m) {
      
    if(a[i] < b[j]) {
        if(ans[k-1] != a[i] )
            ans[k++] = a[i];
        i++;    
    }
    
    else if(a[i] == b[j]) {
        if(ans[k-1] != a[i])
            ans[k++] = a[i];
        i++;
        j++;
    }
    
    else {
        if(k > 0 && ans[k-1] != b[j])
            ans[k++] = b[j];
        j++;    
    }
  }
  
  //* STEP-4 : Its possible that either of the array, has some remaining elements in it.
  while(i < n) {
    if(a[i] != ans[k-1])
        ans[k++] = a[i];
    i++;
  }

  while(j < m) {
    if(b[j] != ans[k-1])
        ans[k++] = b[j];
    j++;
  }
  return k;
}

int main()
{

  return 0;
}