#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& stk) {
  vis[node] = 1;
  for (auto it : adj[node]) {
      if (!vis[it])
          dfs(it, vis, adj, stk);
  }
  stk.push(node);
}

void dfs3(int node, vector<int>& vis, vector<vector<int>>& adjT) {
  vis[node] = 1;
  for (auto it : adjT[node]) {
      if (!vis[it])
          dfs3(it, vis, adjT);
  }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>>& adj) {
  vector<int> vis(V, 0);
  stack<int> stk;
  for (int i = 0; i < V; i++) {
      if (!vis[i]) {
          dfs(i, vis, adj, stk);
      }
  }

  // * Reverse the Graph
  vector<vector<int>> adjT(V);
  for (int i = 0; i < V; i++) {
      for (auto it : adj[i]) {
          adjT[it].push_back(i);
      }
  }

  fill(vis.begin(), vis.end(), 0);  // Reset the visited array for the second DFS pass
  int scc = 0;
  while (!stk.empty()) {
      int node = stk.top();
      stk.pop();

      if (!vis[node]) {
          scc++;
          dfs3(node, vis, adjT);
      }
  }
  return scc;
}