#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
  vis[node] = 1; 

  for(auto adjacentNode: adj[node]) {

      if(!vis[adjacentNode]) {
          if(dfs(adjacentNode, node, vis, adj) == true) 
              return true; 
      }

      else if(adjacentNode != parent) return true; 
  }
  return false; 
}

bool isCycle(int V, vector<int> adj[]) {
  int vis[V] = {0}; 

  // For Traversing all the connected components 
  for(int i = 0;i<V;i++) {
      if(!vis[i]) {
          if(dfs(i, -1, vis, adj) == true) return true; 
      }
  }
  return false; 
}

// * Practice session - 1 :

bool dfs(vector<int> adj[], int vis[], int parentNode, int currNode) {
  vis[currNode] = 1;
  
  for(int ele : adj[currNode]){
      if(vis[ele] && ele != parentNode)
          return true;
          
      else if(vis[ele] && ele == parentNode)
          continue;
          
      else {
          if(dfs(adj, vis, currNode, ele))
              return true;
      }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  int vis[V+1] = {0};
  vis[0] = 1;

    for(int i = 0; i < V; i++) {
      if(vis[i] == 0) {
          if(dfs(adj, vis, -1, i))
              return true;
      }
  }
  return false;

}