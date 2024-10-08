#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
  priority_queue<pair<int, int>,
  vector<pair<int, int> >, greater<pair<int, int>>> pq;
  
  vector<int> vis(V, 0);
  
  pq.push({0,0});
  int sum = 0;
  while(!pq.empty()){
      auto it = pq.top();
      int node = it.second;
      int wt = it.first;
      pq.pop();
      
      if(!vis[node]){
          // * ADD to MST HERE, if ASKED
          vis[node] = 1;
          sum += wt;
          
          for(auto it : adj[node]){
              int adjNode = it[0]; // * Defined in the Problem statement
              int edW = it[1]; // * Defined in the Problem statement 
              if(!vis[adjNode])
                  pq.push({edW,adjNode});
          }
      }
  }
  return sum;
}