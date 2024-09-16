#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
  vector<int> parent, rank, size;
  public:
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

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[]) {
  vector<pair<int, pair<int, int>>> edges;
  for(int i = 0; i < V; i++) {
      for(auto it : adj[i]){
          int adjNode = it[0];
          int wt = it[1];
          int node = i;
          
          edges.push_back({wt, {node,adjNode}});
      }
  }
  // * Create Disjoint Set
  DisjointSet ds(V);
  
  sort(edges.begin(), edges.end());
  
  int mstWt = 0;
  for(auto edge : edges){
      int wt = edge.first;
      int u = edge.second.first;
      int v = edge.second.second;
      
      if(ds.findUParent(u) != ds.findUParent(v)){
          mstWt += wt;
          ds.unionBySize(u, v);
      }
  }
  return mstWt;
}