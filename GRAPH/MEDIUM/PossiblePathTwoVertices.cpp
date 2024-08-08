#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int>&path, vector<int>adj[], int src, int dest){
  // * If dest reached
  if(src==dest) return 1;
  path[src]=1;
  int ans=0;
  
  for(int neigh:adj[src]){
      // * FOR EACH Neighbour, preform a DFS
      if(!path[neigh])
          ans+=dfs(path,adj,neigh,dest);
  }
  
  // * BACKTRACK, so the current node can be counted in OTHER PATHs AS WELL.
  path[src]=0;
  return ans;
}
// Function to count paths between two vertices in a directed graph.
int countPaths(int V, vector<int> adj[], int source, int destination) {
  // * VISITED ARR to keep track of PATHS
  vector<int>path(V,0);
  return dfs(path, adj, source, destination);
}