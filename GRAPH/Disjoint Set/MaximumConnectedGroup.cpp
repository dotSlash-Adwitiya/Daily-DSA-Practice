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

bool isValid(int adjR, int adjC, int n){
  return adjR >= 0 && adjC >= 0 && adjR < n && adjC < n;
}

int MaxConnection(vector<vector<int>>& grid) {
  int n = grid.size(); // * We have a square matrix
  DisjointSet ds(n*n);
  
  // * Step-1 Connecting Components
  for(int row = 0; row < n; row++){
      for(int col = 0; col < n; col++) {
          if(grid[row][col] == 1){
              int delRow[] = {-1, 0, 1, 0};
              int delCol[] = {0, -1, 0, 1};
              for(int idx = 0; idx < 4; idx++){
                  int nrow = row + delRow[idx];
                  int ncol = col + delCol[idx];
                  
                  if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                      int nodeNo = row * n + col;
                      int adjNodeNo = nrow * n + ncol;
                      
                      // * Connect the currentNode with the adjacent one 
                      // * We calculated in previous step
                      ds.unionBySize(nodeNo, adjNodeNo);
                  }
              }
          }
      }
  }
  
  // * Step-2: Brute Force
  int maxIsland = 0;
  for(int row = 0; row < n; row++){
      for(int col = 0; col < n; col++) {
          if(grid[row][col] == 0){ // * if its a 0, only then try to connect them
              int delRow[] = {-1, 0, 1, 0};
              int delCol[] = {0, -1, 0, 1};
              set<int> components;
              for(int idx = 0; idx < 4; idx++){
                  int nrow = row + delRow[idx];
                  int ncol = col + delCol[idx];
                  
                  if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1){
                      // * Find the ultimate parent of this
                      // * ADJACENT NODE, and insert it into SET.
                      components.insert(ds.findUParent(nrow * n + ncol));
                  }
              }
              int sizeTotal = 0;
              for(auto it : components)
                  sizeTotal += ds.size[it];
              maxIsland = max(maxIsland, sizeTotal + 1);            
          }
      }
  }
  for(int cellNo = 0; cellNo < n*n; cellNo++)
      maxIsland = max(maxIsland, ds.size[ds.findUParent(cellNo)]);
  return maxIsland;
}