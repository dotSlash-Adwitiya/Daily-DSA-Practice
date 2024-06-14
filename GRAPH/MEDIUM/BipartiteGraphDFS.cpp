#include<bits/stdc++.h>
using namespace std;

bool dfs(int V, int node, vector<int> adj[], vector<int> &color, int col){
    color[node] = col;
    
    for(int ele : adj[node]){
        if(color[ele] == -1) {
            if(!dfs(V, ele, adj, color, !col)) // * if it returns false, we return false to it.
                return false;
        } else if(color[ele] == col) return false; 
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
  vector<int> color(V+1, -1);
  
  for(int i = 0; i < V; i++) {
      if(color[i] == -1){
          if(!dfs(V, i, adj, color, 0))
              return false;
      }
  }
  return true;
}