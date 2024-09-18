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

int Solve(int n, vector<vector<int>>& edge) {
  DisjointSet ds(n);
  int cntExtra = 0;
  for(auto &it : edge){
      int u = it[0];
      int v = it[1];
      if(ds.findUParent(u) == ds.findUParent(v))
          cntExtra++;
      else // * Connect u and v
          ds.unionBySize(u,v);
  }
  int components = 0;
  for(int i = 0; i < n; i++)
      if(ds.parent[i] == i)
          components++;
  if(cntExtra >= components - 1)
      return components - 1;
  return -1;
}
