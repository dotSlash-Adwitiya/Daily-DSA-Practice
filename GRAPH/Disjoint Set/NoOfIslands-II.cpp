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


bool isValid(int adjR, int adjC, int n, int m){
  return adjR >= 0 && adjC >= 0 && adjR < n && adjC < m;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
  DisjointSet ds(n * m);
  int vis[n][m];
  memset(vis, 0, sizeof vis);
  int islands = 0;
  
  vector<int> ans;
      
  for(auto it : operators){
      int row = it[0];
      int col = it[1];
      
      if(vis[row][col]){
          ans.push_back(islands);
          continue;
      } 
      vis[row][col] = 1;
      islands++;
      // * row - 1, col
      // * row, col + 1
      // * row + 1, col
      // * row, col - 1
      int delRow[4] = {-1, 0, +1, 0};
      int delCol[4] = {0, +1, 0, -1};
      
      for(int idx = 0; idx < 4; idx++) {
          int adjRow = row + delRow[idx];
          int adjCol = col + delCol[idx];
          
          if(isValid(adjRow, adjCol, n, m)){
              if(vis[adjRow][adjCol] == 1){
                  int nodeNo = row * m + col;
                  int adjNodeNo = adjRow * m + adjCol;
                  if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                      islands--;
                      ds.unionBySize(nodeNo, adjNodeNo);
                  }
              }
          }
      }
      ans.push_back(islands);
  }
  return ans;
}
