#include<bits/stdc++.h>
using namespace std;

// * Approach - 1: Using DFS and maintaining PATH Array
bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path) {
  vis[node] = true;
  path[node] = true;
  
  for(int &ele: adj[node]) {
      if(!vis[ele] && dfs(ele, adj, vis, path))
          return true;
      else if(path[ele]) // * Check if this is the SAME Path 
          return true;
  }
  path[node] = false; // * Mark FALSE while BACKTRACKING 
  return false; // * If no same path nodes found then it doesn't have a cycle
}

bool isCyclic(int V, vector<int> adj[]) {
  vector<bool> vis(V, false), path(V, false);
  
  for(int i = 0; i < V; i++){
      if(!vis[i]){
          if(dfs(i, adj, vis, path))
              return true;
      }
  }
  return false;
}

// * Approach - 2 : Kahn's Algorithm
bool isCyclic(int V, vector<int> adj[]) {
    int indegree[V] = {0};

  // * Count and STORE the indegree of every node
  for (int i = 0; i < V; i++) { // * Traversing on Each Vertex
    for (auto it : adj[i]) { // * If an element is found at any node, increase its indegree
      indegree[it]++;
    }
  }

  queue<int> q;
  // * Put all the nodes with 0 incoming edge (indegree) in a queue
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int cnt = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;
    
    for (auto it : adj[node]) {
      indegree[it]--; // * Decrement the outdegree
      if (indegree[it] == 0) q.push(it);
    }
  }

  return !(cnt == V);
}