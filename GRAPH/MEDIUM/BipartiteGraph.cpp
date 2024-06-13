#include<bits/stdc++.h>
using namespace std;

/*
  *                     ○ - ○ - ○
  *                   /           \
  * ○ - ○ - ○ - ○ - ○              ○ - ○ - ○ - ○ - ○
  *                  \            /
  *                   ○ - ○ - ○ - 
  * 
*/

bool checkBipartite(int V, int start, vector<int> adj[], vector<int> &color){
  queue<int> q;
  q.push(start);
  color[start] = 0; // * Initial coloring
  
  while(!q.empty()){
      int node = q.front();
      q.pop();
      
      for(int ele : adj[node]){
        if(color[ele] == -1){
            color[ele] = !color[node]; // * Coloring with opposite color
            q.push(ele);
        }else if(color[ele] == color[node]) // * If the adjacent node (ele) has the same color as its adjacent node, we extracted in (node)
          return false; // * Then its NOT BIPARTITE
      }
  }
  return true;
}

bool isBipartite(int V, vector<int>adj[]){
  vector<int> color(V+1, -1);
  
  // * Traversing every component
  for(int i = 0; i < V; i++) {
      if(color[i] == -1){ // * If the node is already colored, we won't traverse on it again
          if(!checkBipartite(V, i, adj, color))
              return false;
      }
  }
  return true;
}

