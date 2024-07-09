#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
  vector<pair<int, int>> adj[n+1];
  
  //  *Construct A Graph's Adjacency List using edges
  for(auto it : edges) {
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
  }
  
  priority_queue<pair<int, int>,vector<pair<int,int> >, 
  greater<pair<int,int>>> pq; 
  
  // * Distance arr for storing distance
  // * Parent arr for storing the parent of every node
  vector<int> dist(n+1, 1e9), parent(n+1);
  
  // * Initially, every node is its own parent
  for(int i = 1; i <= n; i++) parent[i] = i;
  dist[1] = 0; // * Src will be at 0 distance
  
  // * Pair: {distance, node}
  pq.push({0,1});
  
  while(!pq.empty()){
      int nodeDist = pq.top().first;
      int node = pq.top().second;
      
      pq.pop();
      
      for(auto it : adj[node]){
          int adjNode = it.first;
          int edgeWt = it.second;
          
          if(nodeDist + edgeWt < dist[adjNode]){
              dist[adjNode] = nodeDist + edgeWt;
              pq.push({dist[adjNode], adjNode});
              
              // * Store its parent -- THE ONLY MODIFICATION REQUIRED
              parent[adjNode] = node;
          }
      }
  }
  if(dist[n] == 1e9) return {-1};

  vector<int> path;
  int node = n;
  while(parent[node] != node) {
      path.push_back(node);
      node = parent[node];
  }    
  path.push_back(1);
  // * Insert shortest path's COST(Total Weight to reach destination node) 
  path.push_back(dist[n]);
  reverse(path.begin(), path.end());
  return path;
}