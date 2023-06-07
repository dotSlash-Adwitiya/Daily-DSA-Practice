#include<bits/stdc++.h>
using namespace std;


//* Basic BRUTE FORCE Approach : TC : O(n^2) , SC : O(1)
int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int ele = a[i];
        for(int j = 0; j < m; ++j) {
            if(ele == b[j])
                ans++;
        }
    }
    return ans;
}

int NumberofElementsInIntersection(int a[], int b[], int n, int m) {

  //* SMART WORK : rather than writing two separate codes, we change the parameters and call the same function      
    if(m > n) 
      return NumberofElementsInIntersection(b,a,m,n);
    
    int cnt = 0;
    //* We use set data structure because then we'd be able to store
    set<int> st;
    for(int i = 0; i < n; ++i) st.insert(a[i]);
    
    for(int i = 0; i < m; ++i) {
        if(st.find(b[i]) != st.end()) {
            cnt++;
            st.erase(b[i]);
        }
    }
    return cnt;
}

int main()
{

  return 0;
}