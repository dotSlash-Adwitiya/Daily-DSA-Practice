#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
  public:
  vector<int> parent, rank, size;
  DisjointSet(int n) {
    // parent.resize(n, 0); // * For 0 based graphs (N-1 Nodes)
    // rank.resize(n, 0); // * For 0 based graphs (N-1 Nodes)
    parent.resize(n+1, 0); // * for 1 based graphs (N Nodes) But this works for both 0 and 1 based
    size.resize(n+1, 1); // * for 1 based graphs (N Nodes) But this works for both 0 and 1 based

    for(int i = 0; i <= n; i++){
      parent[i] = i;
    }
  }


  int findUParent(int node){
    if(node == parent[node]) 
    return node;
    // * 'parent[node]=' allows PATH COMPRESSION 
    return parent[node] = findUParent(parent[node]); 
  }

  /* 
  * Note: Both Union By Size and UnionByRank have T.C: O(4α) Has a very huge mathematical derivation. 
  * Hence not asked in interviews.
  */
  void unionBySize(int u, int v){
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }

  }
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
  unordered_map<string, int> mapMailNode;
  int n = accounts.size();
  DisjointSet ds(n);
  
  for(int person = 0; person < n; person++) {
      for(int j = 1; j < accounts[person].size(); j++ ){
          string mail = accounts[person][j];
          // * This mail is not alloted to any person yet
          // * So allot it to person[i]
          if(mapMailNode.find(mail) == mapMailNode.end())
              mapMailNode[mail] = person;
          // * Else if its already alloted,
          // * then simply attached it to that previous person
          else ds.unionBySize(person, mapMailNode[mail]);
      }
  }
  
  vector<string> mergedMail[n];
  
  for(auto it : mapMailNode){
      string mail = it.first;
      int node = ds.findUParent(it.second);
      mergedMail[node].push_back(mail);
  }
  
  vector<vector<string>> ans;
  for(int i = 0; i < n; i++){
      if(mergedMail[i].size() == 0) continue;
      sort(mergedMail[i].begin(),mergedMail[i].end());
      vector<string> temp;
      temp.push_back(accounts[i][0]);
      for(auto it : mergedMail[i])
          temp.push_back(it);
      ans.push_back(temp);
  }
  return ans;
}