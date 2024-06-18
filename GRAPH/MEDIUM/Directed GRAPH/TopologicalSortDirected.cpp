#include<bits/stdc++.h>
using namespace std;


// * Works for DIRECTED Acyclic Graph (DAG) ONLY
// * T.C : O(V+2E) (Same as DFS)
void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &stk) {
  vis[node] = 1;
  
  for(int &ele : adj[node])
      if(!vis[ele]) 
          dfs(ele, adj, vis, stk);
      
  stk.push(node);
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
  vector<int> vis(V,0);
  stack<int> stk;
  
  for(int i = 0; i < V; i++)
      if(!vis[i])
          dfs(i, adj, vis, stk);
          
  vector<int> sorted;
  
  while(!stk.empty()){
      sorted.push_back(stk.top());
      stk.pop();
  }
  return sorted;
}