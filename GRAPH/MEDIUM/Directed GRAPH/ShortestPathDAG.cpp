#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &stk){
  vis[node] = 1;
  
  for(auto it : adj[node]){
      int v = it.first;
      if(!vis[v])
        topoSort(v, adj, vis, stk); 
  }
  
  stk.push(node);
}


vector<int> shortestPath(int N,int M, vector<vector<int>>& edge){
  vector<pair<int,int>> adj[N];
  
  // * STEP-1: Create a GRAPH
  // * N = no of vertices
  // * M = no of edges
  // * < M because its the no of edges
  for(int i = 0; i < M; i++) {
      int u = edge[i][0];
      int v = edge[i][1];
      int wt = edge[i][2];
      
      adj[u].push_back({v,wt});
  }
  
  // * Step-2: Find the TOPOSORT
  // * Create Visited Arr[] and a STACK ▓
  // * N because its the no of vertices we meed to mark visited
  int vis[N] = {0};
  stack<int> stk;
  
  for(int i = 0; i < N; i++){
      if(!vis[i])
          topoSort(i, adj, vis, stk);
  }
  
  // * STEP-3: Minimize the distance (Actual Algo)
  vector<int> dist(N);
  for(int i = 0; i < N; i++) 
      dist[i] = 1e9;
  
  // * Because this is the src vertice
  // * Distance of 0th vertice from itself is - 0
  dist[0] = 0;
  
  while(!stk.empty()){
      int node = stk.top();
      stk.pop();
      
      for(auto it : adj[node]) {
          int v = it.first;
          int wt = it.second;
          
          if(dist[node] + wt < dist[v])
              dist[v] = dist[node] + wt;
      }
  }
  
  for(auto &d : dist)
      if(d == 1e9)d = -1; // * If the node is infinity, then it is unreachable
      
  return dist;
}

// * Practice- 1
void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &stk){
    vis[node] = 1;
    
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v])
        topoSort(v, adj, vis, stk); 
    }
    
    stk.push(node);
}

    vector<int> shortestPath(int N,int M, vector<vector<int>>& edge){
    vector<pair<int,int>> adj[N];
    
    // * STEP-1: Create a GRAPH
    // * N = no of vertices
    // * M = no of edges
    // * < M because its the no of edges
    for(int i = 0; i < M; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        
        adj[u].push_back({v,wt});
    }
    
    // * Step-2: Find the TOPOSORT
    // * Create Visited Arr[] and a STACK ▓
    // * N because its the no of vertices we meed to mark visited
    int vis[N] = {0};
    stack<int> stk;
    
    for(int i = 0; i < N; i++){
        if(!vis[i])
            topoSort(i, adj, vis, stk);
    }
    
    // * STEP-3: Minimize the distance (Actual Algo)
    vector<int> dist(N);
    for(int i = 0; i < N; i++) 
        dist[i] = 1e9;
    
    // * Because this is the src vertice
    // * Distance of 0th vertice from itself is - 0
    dist[0] = 0;
    
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        
        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;
            
            if(dist[node] + wt < dist[v])
                dist[v] = dist[node] + wt;
        }
    }
    
    for(auto &d : dist)
        if(d == 1e9)d = -1; // * If the node is infinity, then it is unreachable
        
    return dist;
}