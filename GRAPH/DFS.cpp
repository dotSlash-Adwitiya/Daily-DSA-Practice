#include<bits/stdc++.h>
using namespace std;

void dfsCall(vector<int> adj[], vector<int> &dfs, int node, vector<int> &vis) {
  
  //* If the Node is not visited, then mark it as vis and push it into the ans
  if(!vis[node]){
      vis[node] = 1;
      dfs.push_back(node);
  }
  //* If its already visited, then simply RETURN.
  else return;
  
  //* Check next node that can be traversed from current Node, and make a Recursive Call
  for(auto ele : adj[node])
      dfsCall(adj, dfs, ele, vis);
  
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  
  //* ans vector and the visited vector to keep count of visited nodes
  vector<int> dfs;
  vector<int> vis(V);
  
  dfsCall(adj, dfs, 0, vis);
  
  return dfs;
}

int main()
{

  return 0;
}