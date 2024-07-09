#include<bits/stdc++.h>
using namespace std;

// * BRUTE FORCE T.C: O(n³)

vector<vector<int>> triplet(int n, vector<int> &arr)
{
  set<vector<int>> st;

  for(int i = 0; i < n-2; i++){
      for(int j = i+1; j < n-1; j++) {
          for(int k = j+1; k < n; k++) {
              if(arr[i] + arr[j] + arr[k] == 0){
                  // * Store the triplet in temp vector
                  vector<int> temp = {arr[i], arr[j], arr[k]};
                  // * Sort the elements to ensure uniqueness even in set
                  sort(temp.begin(), temp.end());

                  st.insert(temp);
              }
          }
      }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * Better Approach using HASHSET
// * T.C: O(n²)
// * S.C: O(n)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
  set<vector<int>> st;

  for(int i = 0; i < n; i++){
      set<int> hashSet;
      for(int j = i+1; j < n; j++) {
          int pair = -(arr[i] + arr[j]);
          if(hashSet.find(pair) != hashSet.end()){
              vector<int> temp = {arr[i], arr[j], pair};
              sort(temp.begin(), temp.end());
              st.insert(temp);
          }
          hashSet.insert(arr[j]);
      }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// * Optimised Approach using 2 Pointers
// * T.C: O(n²), S.C: O(1)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  
  for(int i = 0; i < n; i++) {
      if(i > 0 && arr[i] == arr[i-1]) continue;
      int j = i+1, k = n-1;
      while(j < k){
          int sum = arr[i] + arr[j] + arr[k];
          if(sum < 0)
              j++;
          else if(sum > 0)
              k--;
          else {
              ans.push_back({arr[i], arr[j], arr[k]});
              j++,k--;
              while(j < k && arr[j] == arr[j-1]) j++;
              while(k > j && arr[k] == arr[k+1]) k--; 
          }
      }
  }

  return ans;
}