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

int maxRemove(vector<vector<int>>& stones, int n) {
  int maxRow = 0, maxCol = 0;
  for(auto it : stones){
      maxRow = max(maxRow, it[0]);
      maxCol = max(maxCol, it[1]);
  }
  
  DisjointSet ds(maxRow + maxCol + 1);
  unordered_map<int, int> stoneNodes;
  for(auto it : stones){
      int nodeRow = it[0];
      int nodeCol = it[1] + maxRow + 1;
      ds.unionBySize(nodeRow, nodeCol);
      stoneNodes[nodeRow] = 1;
      stoneNodes[nodeCol] = 1;
  }
  
  int cnt = 0;
  for(auto it : stoneNodes){
      if(ds.findUParent(it.first) == it.first)
          cnt++;
  }
  return n - cnt;
}