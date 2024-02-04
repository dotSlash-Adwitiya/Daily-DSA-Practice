#include<bits/stdc++.h>
using namespace std;

// * TC : O(2^n)
//* SC : O(2^n) -- ??
void findAllSubsets(vector<int> &A, vector<vector<int>> &ans, vector<int> subset,int idx) {
  if(idx >= A.size()){
      ans.push_back(subset);
      return;
  }

  subset.push_back(A[idx]);

  // * Current Element Included above in this call
  findAllSubsets(A,ans,subset, idx+1);

  subset.pop_back();

  // * Current Element Excluded above in this call
  findAllSubsets(A,ans,subset, idx+1);
}

vector<vector<int> > subsets(vector<int>& A) 
{
  vector<vector<int>> ans;
  vector<int> v;

  findAllSubsets(A,ans,v,0);
  sort(ans.begin(), ans.end());
  return ans;
}