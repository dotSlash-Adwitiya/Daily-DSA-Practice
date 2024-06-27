#include<bits/stdc++.h>
using namespace std;

// * Approach using DFS (Gives TLE)
void dfs(int node, int distance,vector<int> adj[], vector<int> &dist) {
  
  dist[node] = distance;
  
  for(auto it : adj[node]){
      if(dist[it] > distance+1){ //  * Call for DFS if the distance is shorter than the one stored
          dfs(it, distance + 1, adj, dist);
      }
  }
}

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
  vector<int> adj[N];
  
  for(auto it: edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
  }
  
  vector<int> dist(N, 1e9);
  dist[src] = 0;
  
  dfs(src, 0, adj, dist);        

  vector<int> ans(N);
  for(int i = 0; i < N; i++){
      if(dist[i] == 1e9)
          ans[i] = -1;
      else
          ans[i] = dist[i];
  }
  
  return ans;
}

// * Approach using BFS (Optimal)
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
  vector<int> adj[N];
  
  for(auto it: edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
  }
  
  vector<int> dist(N, 1e9);
  dist[src] = 0;
  
  queue<pair<int,int>> q;
  
  q.push({src,0});
  
  while(!q.empty()) {
      int node = q.front().first;
      int distance = q.front().second;
      
      q.pop();
      
      for(auto ele: adj[node]){
          
          if(distance + 1 < dist[ele]){
              dist[ele] = distance + 1;
              q.push({ele, distance + 1});
          }
          
      }
      
  }
  
  vector<int> ans(N);
  for(int i = 0; i < N; i++){
      if(dist[i] == 1e9)
          ans[i] = -1;
      else
          ans[i] = dist[i];
  }
  
  return ans;
}