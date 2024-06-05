#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]) {
  vis[src] = 1; 
  // * store <source node, parent node>
  // * Initial Configuration
  queue<pair<int,int>> q; 
  q.push({src, -1}); 

  while(!q.empty()) {
      int node = q.front().first; 
      int parent = q.front().second; 
      q.pop(); 
      
      // Explore all adjacent nodes
      for(auto adjacentNode: adj[node]) {
          // if adjacent node is unvisited
          if(!vis[adjacentNode]) {
              vis[adjacentNode] = 1; 
              q.push({adjacentNode, node}); 
          }

          // * if adjacent node is visited and is not it's own parent node
          else if(parent != adjacentNode) {
              return true; // * yes it is a cycle
          }
      }
}
  // * No cycle
  return false; 
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
  // initialise them as unvisited 
  int vis[V] = {0};
  for(int i = 0;i<V;i++) {
      if(!vis[i]) {
          if(detect(i, adj, vis)) return true; 
      }
  }
  return false; 
}