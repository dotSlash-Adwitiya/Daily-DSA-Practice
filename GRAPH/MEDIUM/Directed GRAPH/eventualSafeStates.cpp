#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check) {
  // * Initally mark the node and its path as visited
  // * and the safeNode vector as false
  vis[node] = 1;
  pathVis[node] = 1;
  check[node] = 0;
  
  for(int ele : adj[node]){
      if(!vis[ele]) {
          if(dfs(ele, adj, vis, pathVis, check)){
              check[node] = 0;
              return true;
          }
      }
      else if(pathVis[ele]) // *If this node is already encountered at this path, then its not a safe node
          return true;
  }
  // * While backtracking
  check[node] = 1;
  pathVis[node] = 0;
  return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
  vector<int> safeNodes, check(V,0), vis(V+1, 0), pathVis(V,0);
  
  // * Traversing all components
  for(int i = 0; i < V; i++) {
      if(!vis[i])
          dfs(i, adj, vis, pathVis, check);
  }
  
  for(int i = 0; i < V; i++){
      if(check[i] == 1)
          safeNodes.push_back(i);
  }
  
  return safeNodes;
}