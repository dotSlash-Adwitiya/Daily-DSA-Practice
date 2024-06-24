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


// * 2nd Approach: Using TOPOSort logic
// * Step-1: Reverse the GRAPH (Ex: If there exists an edge from ele1->ele2, then make it: ele2->ele1)
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int> adjRev[V];
    int indegree[V] = {0};
    
    for(int i = 0; i < V; i++) {
        // * Current there exists an edge b/w : i-> ele
        // * Convert it to: ele->i
        for(int ele: adj[i]){
            adjRev[ele].push_back(i);
            indegree[i]++; // * While reversing, count the no of incoming nodes
        }
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> safenodes;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // * We can pussh this node because, we know whichever node has an indegree == 0
        // * will ONLY be present in the QUEUE Data Structure
        safenodes.push_back(node);
        for(int &ele: adjRev[node]){
            indegree[ele]--;
            if(indegree[ele] == 0)
                q.push(ele);
        }
        
    }
    
    sort(safenodes.begin(), safenodes.end());
    return safenodes;
}